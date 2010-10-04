/* Directory manipulation module for the Lua/APR binding.
 *
 * Author: Peter Odding <peter@peterodding.com>
 * Last Change: September 25, 2010
 * Homepage: http://peterodding.com/code/lua/apr/
 * License: MIT
 */

#include "lua_apr.h"
#include <apr_file_io.h>
#include <apr_fnmatch.h>
#include <apr_strings.h>
#include <apr_lib.h>

/* apr.temp_dir_get() -> path {{{1
 *
 * Find an existing directory suitable as a temporary storage location. On
 * success the directory file path is returned, otherwise a nil followed by an
 * error message is returned.
 */

int lua_apr_temp_dir_get(lua_State *L)
{
  apr_pool_t* memory_pool;
  const char *filepath;
  apr_status_t status;

  memory_pool = to_pool(L);
  status = apr_temp_dir_get(&filepath, memory_pool);
  if (status != APR_SUCCESS) {
    return push_error_status(L, status);
  } else {
    lua_pushstring(L, filepath);
    return 1;
  }
}

/* apr.dir_make(path [, permissions]) -> status {{{1
 * 
 * Create the directory @path on the file system. On success true is returned,
 * otherwise a nil followed by an error message is returned. See the
 * documentation on @permissions for the optional second argument.
 */

int lua_apr_dir_make(lua_State *L)
{
  apr_status_t status;
  apr_pool_t *memory_pool;
  const char *filepath;
  apr_fileperms_t permissions;

  memory_pool = to_pool(L);
  filepath = luaL_checkstring(L, 1);
  permissions = check_permissions(L, 2, 0);
  status = apr_dir_make(filepath, permissions, memory_pool);

  return push_status(L, status);
}

/* apr.dir_make_recursive(path [, permissions]) -> status {{{1
 *
 * Create the directory @path on the file system, creating intermediate
 * directories as required. On success true is returned, otherwise a nil
 * followed by an error message is returned. See the documentation on
 * @permissions for the optional second argument.
 */

int lua_apr_dir_make_recursive(lua_State *L)
{
  apr_status_t status;
  apr_pool_t *memory_pool;
  const char *filepath;
  apr_fileperms_t permissions;

  memory_pool = to_pool(L);
  filepath = luaL_checkstring(L, 1);
  permissions = check_permissions(L, 2, 0);
  status = apr_dir_make_recursive(filepath, permissions, memory_pool);

  return push_status(L, status);
}

/* apr.dir_remove(path) -> status {{{1
 *
 * Remove the *empty* directory @path from the file system. On success true
 * is returned, otherwise a nil followed by an error message is returned.
 */

int lua_apr_dir_remove(lua_State *L)
{
  apr_status_t status;
  apr_pool_t *memory_pool;
  const char *filepath;

  memory_pool = to_pool(L);
  filepath = luaL_checkstring(L, 1);
  status = apr_dir_remove(filepath, memory_pool);

  return push_status(L, status);
}

/* apr.dir_remove_recursive(path) -> status {{{1
 *
 * Remove the directory @path *and all its contents* from the file system.
 * On success true is returned, otherwise a nil followed by an error message is
 * returned.
 *
 * Note: This function isn't part of the Apache Portable Runtime but has been
 * implemented on top of it by the author of the Lua/APR binding. *It also
 * hasn't been properly tested yet*.
 */

int lua_apr_dir_remove_recursive(lua_State *L)
{

  apr_status_t status;
  apr_pool_t *outer_pool; /* used to store todo/done arrays and directory pathnames */
  apr_pool_t *middle_pool; /* used to store directory handles (apr_dir_t structs) */
  apr_pool_t *inner_pool; /* used to store pathnames of non-subdirectory entries */
  apr_array_header_t *todo, *done;
  apr_dir_t *directory;
  apr_finfo_t info;
  char **top, *tmp;
  const char *filepath;
  int allocation_counter;

  directory = NULL;
  outer_pool = middle_pool = inner_pool = NULL;
  filepath = luaL_checkstring(L, 1);
  allocation_counter = 0;

  status = apr_pool_create(&outer_pool, NULL);
  if (APR_SUCCESS == status)
    status = apr_pool_create(&middle_pool, NULL);
  if (APR_SUCCESS == status)
    status = apr_pool_create(&inner_pool, NULL);
  if (APR_SUCCESS != status)
    goto cleanup;

# define out_of_memory do { \
    status = APR_ENOMEM; \
    goto cleanup; \
  } while (0)

# define push_filepath(stack, filepath) do { \
    const char **p = apr_array_push(stack); \
    if (p != NULL) *p = filepath; else out_of_memory; \
  } while (0)

  todo = apr_array_make(outer_pool, 0, sizeof filepath);
  done = apr_array_make(outer_pool, 0, sizeof filepath);
  if (todo == NULL || done == NULL)
    out_of_memory;

  push_filepath(todo, filepath);

  while ((top = apr_array_pop(todo))) {
    filepath = *(char**)top;
    apr_pool_clear(middle_pool);
    status = apr_dir_open(&directory, filepath, middle_pool);
    if (status != APR_SUCCESS) {
      directory = NULL;
      goto cleanup;
    }
    for (;;) {
      /* This is a compromise between having `inner_pool' grow almost unbounded
       * on very large directories (e.g. ~/Maildir/) and clearing it for every
       * non-subdirectory pathname that's allocated (very inefficient). */
      if (allocation_counter % 1000 == 0)
        apr_pool_clear(inner_pool);
      /* FIXME?! apr_dir_read() uses directory->pool (middle_pool) for allocation */
      status = apr_dir_read(&info, APR_FINFO_NAME|APR_FINFO_TYPE|APR_FINFO_LINK, directory);
      if (APR_STATUS_IS_ENOENT(status))
        break; /* no more entries */
      else if (status != APR_SUCCESS && status != APR_INCOMPLETE)
        goto cleanup; /* something went wrong */
      else if (filename_symbolic(info.name))
        continue; /* bogus entry */
      else if (info.filetype == APR_DIR) {
        /* recurse into subdirectory */
        status = apr_filepath_merge(&tmp, filepath, info.name, 0, outer_pool);
        if (status != APR_SUCCESS)
          goto cleanup;
        push_filepath(todo, tmp);
      } else {
        /* delete non-subdirectory entry */
        status = apr_filepath_merge(&tmp, filepath, info.name, 0, inner_pool);
        allocation_counter++;
        if (APR_SUCCESS == status)
          status = apr_file_remove(tmp, inner_pool);
        if (APR_SUCCESS != status)
          goto cleanup;
      }
    }
    status = apr_dir_close(directory);
    directory = NULL;
    if (status != APR_SUCCESS)
      goto cleanup;
    push_filepath(done, filepath);
  }

# undef out_of_memory
# undef push_filepath

  while ((top = apr_array_pop(done))) {
    filepath = *(char**)top;
    if (allocation_counter++ % 100 == 0)
      apr_pool_clear(middle_pool);
    status = apr_dir_remove(filepath, middle_pool);
    if (status != APR_SUCCESS)
      goto cleanup;
  }

cleanup:

  if (directory != NULL)
    apr_dir_close(directory);
  if (inner_pool != NULL)
    apr_pool_destroy(inner_pool);
  if (middle_pool != NULL)
    apr_pool_destroy(middle_pool);
  if (outer_pool != NULL)
    apr_pool_destroy(outer_pool);

  return push_status(L, status);
}

/* apr.dir_open(path) -> directory handle {{{1
 *
 * Open the directory @path for reading. On success a directory object is
 * returned, otherwise a nil followed by an error message is returned.
 */

int lua_apr_dir_open(lua_State *L)
{
  apr_status_t status;
  apr_pool_t *memory_pool;
  apr_dir_t *handle;
  lua_apr_dir *directory;
  const char *filepath;

  filepath = luaL_checkstring(L, 1);

  /* Create a memory pool for the lifetime of the directory object. */
  status = apr_pool_create(&memory_pool, NULL);
  if (APR_SUCCESS != status)
    return push_error_status(L, status);

  /* Try to open a handle to the directory. */
  status = apr_dir_open(&handle, filepath, memory_pool);
  if (APR_SUCCESS != status) {
    apr_pool_destroy(memory_pool);
    return push_error_status(L, status);
  }

  /* Initialize and return the directory object. */
  directory = new_object(L, &lua_apr_dir_type);
  directory->memory_pool = memory_pool;
  directory->filepath = filepath;
  directory->handle = handle;

  return 1;
}

lua_apr_dir *checkdir(lua_State *L, int idx, int check_open) /* {{{1 */
{
  lua_apr_dir *object;
 
  object = check_object(L, idx, &lua_apr_dir_type);
  if (check_open && object->handle == NULL)
    luaL_error(L, "attempt to use a closed directory");
  return object;
}

/* directory:entries([property, ...]) -> iterator, directory handle {{{1
 *
 * This method returns a function that iterates over the (remaining) directory
 * entries and returns the requested properties for each entry. The property
 * names and value types are documented under `apr.stat()`.
 */

int dir_entries(lua_State *L)
{
  lua_apr_stat_context *context;

  /* Check for a valid, open directory. */
  checkdir(L, 1, 1);

  /* Copy the stat() arguments to a userdatum. */
  context = lua_newuserdata(L, sizeof(*context));
  context->firstarg = 2; /* after directory handle */
  context->lastarg = lua_gettop(L) - 1; /* before stat context */
  check_stat_request(L, context, STAT_DEFAULT_TABLE);

  /* Return the iterator function and directory object. */
  lua_pushcclosure(L, dir_read, 1);
  lua_pushvalue(L, 1);

  return 2;
}

/* directory:read([property, ...]) -> value, ... {{{1
 *
 * Return the requested properties for the next directory entry. The
 * property names and value types are documented under `apr.stat()`.
 */

int dir_read(lua_State *L)
{
  apr_status_t status;
  lua_apr_dir *directory;
  lua_apr_stat_context *context, backup_ctx;

  directory = checkdir(L, 1, 1);

  if (lua_isuserdata(L, lua_upvalueindex(1))) {
    /* Iterator for directory:entries()  */
    context = lua_touserdata(L, lua_upvalueindex(1));
  } else {
    /* Standalone call to directory:read() */
    backup_ctx.firstarg = 2;
    backup_ctx.lastarg = lua_gettop(L);
    check_stat_request(L, &backup_ctx, STAT_DEFAULT_TABLE);
    context = &backup_ctx;
  }

  for (;;) {
    status = apr_dir_read(&context->info, context->wanted, directory->handle);
    if (APR_SUCCESS == status || APR_STATUS_IS_INCOMPLETE(status)) {
      if (!(context->info.valid & APR_FINFO_NAME \
          && filename_symbolic(context->info.name)))
        return push_stat_results(L, context, directory->filepath);
    } else if (APR_STATUS_IS_ENOENT(status)) {
      return 0;
    } else {
      return raise_error_status(L, status);
    }
  }
}

/* directory:rewind() -> status {{{1
 *
 * Rewind the directory handle to start from the first entry.
 */

int dir_rewind(lua_State *L)
{
  lua_apr_dir *directory;
  apr_status_t status;

  directory = checkdir(L, 1, 1);
  status = apr_dir_rewind(directory->handle);

  return push_status(L, status);
}

/* directory:close() -> status {{{1
 *
 * Close the directory handle.
 */

int dir_close(lua_State *L)
{
  lua_apr_dir *directory;
  apr_status_t status;

  directory = checkdir(L, 1, 1);
  status = apr_dir_close(directory->handle);
  directory->handle = NULL;

  return push_status(L, status);
}

int dir_tostring(lua_State *L) /* {{{1 */
{
  lua_apr_dir *directory;
  const char *prefix;

  directory = checkdir(L, 1, 0);
  prefix = directory->handle == NULL ? "closed " : "";
  lua_pushfstring(L, "%sdirectory (%s)", prefix, directory->filepath);

  return 1; 
}

int dir_gc(lua_State *L) /* {{{1 */
{
  lua_apr_dir *object;

  object = checkdir(L, 1, 0);

  if (object->handle) {
    apr_dir_close(object->handle);
    apr_pool_destroy(object->memory_pool);
    object->handle = NULL;
  }

  return 0;
}

/* vim: set ts=2 sw=2 et tw=79 fen fdm=marker : */