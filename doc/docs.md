# Lua/APR binding documentation

The [Lua/APR binding] [homepage] aims to bring most of the functionality in the
[Apache Portable Runtime (APR)] [apr_wiki] to the small and flexible
[programming language Lua] [lua_wiki]. This document contains the documentation
for the Lua/APR binding. Some notes about this documentation:

 - Most of the documentation is based on the [official APR documentation]
   [apr_docs] but I've had to consult the APR source code here and there when
   the official documentation didn't suffice. If anything seems amiss [please
   let me know](mailto:peter@peterodding.com).

 - The entries for all functions are automatically generated from the C and Lua
   source code of the binding to prevent that documentation and implementation
   become out of sync.

*This document was generated from the Lua/APR **0.23.2** source code.*

[homepage]: http://peterodding.com/code/lua/apr/
[apr_wiki]: http://en.wikipedia.org/wiki/Apache_Portable_Runtime
[lua_wiki]: http://en.wikipedia.org/wiki/Lua_%28programming_language%29
[apr_docs]: http://apr.apache.org/docs/apr/trunk/modules.html

## Table of contents

<dl>
<dt style="margin: 1em 0; font-weight: bold"><a href="#base64_encoding">Base64 encoding</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.base64_encode" style="text-decoration:none">apr.base64_encode()</a></li>
<li style="float: left; width: 16em"><a href="#apr.base64_decode" style="text-decoration:none">apr.base64_decode()</a></li>
</ul><br style="clear: both"></dd>
<dt style="margin: 1em 0; font-weight: bold"><a href="#cryptography_routines">Cryptography routines</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.md5_encode" style="text-decoration:none">apr.md5_encode()</a></li>
<li style="float: left; width: 16em"><a href="#apr.password_validate" style="text-decoration:none">apr.password_validate()</a></li>
<li style="float: left; width: 16em"><a href="#apr.password_get" style="text-decoration:none">apr.password_get()</a></li>
<li style="float: left; width: 16em"><a href="#apr.md5_init" style="text-decoration:none">apr.md5_init()</a></li>
<li style="float: left; width: 16em"><a href="#md5_context:update" style="text-decoration:none">md5_context:update()</a></li>
<li style="float: left; width: 16em"><a href="#md5_context:digest" style="text-decoration:none">md5_context:digest()</a></li>
<li style="float: left; width: 16em"><a href="#md5_context:reset" style="text-decoration:none">md5_context:reset()</a></li>
<li style="float: left; width: 16em"><a href="#apr.sha1_init" style="text-decoration:none">apr.sha1_init()</a></li>
<li style="float: left; width: 16em"><a href="#sha1_context:update" style="text-decoration:none">sha1_context:update()</a></li>
<li style="float: left; width: 16em"><a href="#sha1_context:digest" style="text-decoration:none">sha1_context:digest()</a></li>
<li style="float: left; width: 16em"><a href="#sha1_context:reset" style="text-decoration:none">sha1_context:reset()</a></li>
<li style="float: left; width: 16em"><a href="#apr.md5" style="text-decoration:none">apr.md5()</a></li>
<li style="float: left; width: 16em"><a href="#apr.sha1" style="text-decoration:none">apr.sha1()</a></li>
</ul><br style="clear: both"></dd>
<dt style="margin: 1em 0; font-weight: bold"><a href="#date_parsing">Date parsing</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.date_parse_http" style="text-decoration:none">apr.date_parse_http()</a></li>
<li style="float: left; width: 16em"><a href="#apr.date_parse_rfc" style="text-decoration:none">apr.date_parse_rfc()</a></li>
</ul><br style="clear: both"></dd>
<dt style="margin: 1em 0; font-weight: bold"><a href="#relational_database_drivers">Relational database drivers</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.dbd" style="text-decoration:none">apr.dbd()</a></li>
<li style="float: left; width: 16em"><a href="#driver:open" style="text-decoration:none">driver:open()</a></li>
<li style="float: left; width: 16em"><a href="#driver:dbname" style="text-decoration:none">driver:dbname()</a></li>
<li style="float: left; width: 16em"><a href="#driver:driver" style="text-decoration:none">driver:driver()</a></li>
<li style="float: left; width: 16em"><a href="#driver:check" style="text-decoration:none">driver:check()</a></li>
<li style="float: left; width: 16em"><a href="#driver:query" style="text-decoration:none">driver:query()</a></li>
<li style="float: left; width: 16em"><a href="#driver:select" style="text-decoration:none">driver:select()</a></li>
<li style="float: left; width: 16em"><a href="#driver:transaction_start" style="text-decoration:none">driver:transaction_start()</a></li>
<li style="float: left; width: 16em"><a href="#driver:transaction_end" style="text-decoration:none">driver:transaction_end()</a></li>
<li style="float: left; width: 16em"><a href="#driver:transaction_mode" style="text-decoration:none">driver:transaction_mode()</a></li>
<li style="float: left; width: 16em"><a href="#driver:prepare" style="text-decoration:none">driver:prepare()</a></li>
<li style="float: left; width: 16em"><a href="#prepared_statement:query" style="text-decoration:none">prepared_statement:query()</a></li>
<li style="float: left; width: 16em"><a href="#prepared_statement:select" style="text-decoration:none">prepared_statement:select()</a></li>
<li style="float: left; width: 16em"><a href="#result_set:columns" style="text-decoration:none">result_set:columns()</a></li>
<li style="float: left; width: 16em"><a href="#result_set:row" style="text-decoration:none">result_set:row()</a></li>
<li style="float: left; width: 16em"><a href="#result_set:rows" style="text-decoration:none">result_set:rows()</a></li>
<li style="float: left; width: 16em"><a href="#result_set:tuple" style="text-decoration:none">result_set:tuple()</a></li>
<li style="float: left; width: 16em"><a href="#result_set:tuples" style="text-decoration:none">result_set:tuples()</a></li>
<li style="float: left; width: 16em"><a href="#result_set:pairs" style="text-decoration:none">result_set:pairs()</a></li>
<li style="float: left; width: 16em"><a href="#result_set:__len" style="text-decoration:none">#result_set</a></li>
<li style="float: left; width: 16em"><a href="#driver:close" style="text-decoration:none">driver:close()</a></li>
</ul><br style="clear: both"></dd>
<dt style="margin: 1em 0; font-weight: bold"><a href="#dbm_routines">DBM routines</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.dbm_open" style="text-decoration:none">apr.dbm_open()</a></li>
<li style="float: left; width: 16em"><a href="#apr.dbm_getnames" style="text-decoration:none">apr.dbm_getnames()</a></li>
<li style="float: left; width: 16em"><a href="#dbm:exists" style="text-decoration:none">dbm:exists()</a></li>
<li style="float: left; width: 16em"><a href="#dbm:fetch" style="text-decoration:none">dbm:fetch()</a></li>
<li style="float: left; width: 16em"><a href="#dbm:store" style="text-decoration:none">dbm:store()</a></li>
<li style="float: left; width: 16em"><a href="#dbm:delete" style="text-decoration:none">dbm:delete()</a></li>
<li style="float: left; width: 16em"><a href="#dbm:firstkey" style="text-decoration:none">dbm:firstkey()</a></li>
<li style="float: left; width: 16em"><a href="#dbm:nextkey" style="text-decoration:none">dbm:nextkey()</a></li>
<li style="float: left; width: 16em"><a href="#dbm:close" style="text-decoration:none">dbm:close()</a></li>
</ul><br style="clear: both"></dd>
<dt style="margin: 1em 0; font-weight: bold"><a href="#environment_manipulation">Environment manipulation</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.env_get" style="text-decoration:none">apr.env_get()</a></li>
<li style="float: left; width: 16em"><a href="#apr.env_set" style="text-decoration:none">apr.env_set()</a></li>
<li style="float: left; width: 16em"><a href="#apr.env_delete" style="text-decoration:none">apr.env_delete()</a></li>
</ul><br style="clear: both"></dd>
<dt style="margin: 1em 0; font-weight: bold"><a href="#file_path_manipulation">File path manipulation</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.filepath_root" style="text-decoration:none">apr.filepath_root()</a></li>
<li style="float: left; width: 16em"><a href="#apr.filepath_parent" style="text-decoration:none">apr.filepath_parent()</a></li>
<li style="float: left; width: 16em"><a href="#apr.filepath_name" style="text-decoration:none">apr.filepath_name()</a></li>
<li style="float: left; width: 16em"><a href="#apr.filepath_merge" style="text-decoration:none">apr.filepath_merge()</a></li>
<li style="float: left; width: 16em"><a href="#apr.filepath_list_split" style="text-decoration:none">apr.filepath_list_split()</a></li>
<li style="float: left; width: 16em"><a href="#apr.filepath_list_merge" style="text-decoration:none">apr.filepath_list_merge()</a></li>
<li style="float: left; width: 16em"><a href="#apr.filepath_get" style="text-decoration:none">apr.filepath_get()</a></li>
<li style="float: left; width: 16em"><a href="#apr.filepath_set" style="text-decoration:none">apr.filepath_set()</a></li>
<li style="float: left; width: 16em"><a href="#apr.filepath_which" style="text-decoration:none">apr.filepath_which()</a></li>
<li style="float: left; width: 16em"><a href="#apr.filepath_executable" style="text-decoration:none">apr.filepath_executable()</a></li>
</ul><br style="clear: both"></dd>
<dt style="margin: 1em 0; font-weight: bold"><a href="#filename_matching">Filename matching</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.fnmatch" style="text-decoration:none">apr.fnmatch()</a></li>
<li style="float: left; width: 16em"><a href="#apr.fnmatch_test" style="text-decoration:none">apr.fnmatch_test()</a></li>
<li style="float: left; width: 16em"><a href="#apr.glob" style="text-decoration:none">apr.glob()</a></li>
</ul><br style="clear: both"></dd>
<dt style="margin: 1em 0; font-weight: bold"><a href="#directory_manipulation">Directory manipulation</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.temp_dir_get" style="text-decoration:none">apr.temp_dir_get()</a></li>
<li style="float: left; width: 16em"><a href="#apr.dir_make" style="text-decoration:none">apr.dir_make()</a></li>
<li style="float: left; width: 16em"><a href="#apr.dir_make_recursive" style="text-decoration:none">apr.dir_make_recursive()</a></li>
<li style="float: left; width: 16em"><a href="#apr.dir_remove" style="text-decoration:none">apr.dir_remove()</a></li>
<li style="float: left; width: 16em"><a href="#apr.dir_remove_recursive" style="text-decoration:none">apr.dir_remove_recursive()</a></li>
<li style="float: left; width: 16em"><a href="#apr.dir_open" style="text-decoration:none">apr.dir_open()</a></li>
<li style="float: left; width: 16em"><a href="#directory:read" style="text-decoration:none">directory:read()</a></li>
<li style="float: left; width: 16em"><a href="#directory:rewind" style="text-decoration:none">directory:rewind()</a></li>
<li style="float: left; width: 16em"><a href="#directory:entries" style="text-decoration:none">directory:entries()</a></li>
<li style="float: left; width: 16em"><a href="#directory:close" style="text-decoration:none">directory:close()</a></li>
</ul><br style="clear: both"></dd>
<dt style="margin: 1em 0; font-weight: bold"><a href="#file_i_o_handling">File I/O handling</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.file_link" style="text-decoration:none">apr.file_link()</a></li>
<li style="float: left; width: 16em"><a href="#apr.file_copy" style="text-decoration:none">apr.file_copy()</a></li>
<li style="float: left; width: 16em"><a href="#apr.file_append" style="text-decoration:none">apr.file_append()</a></li>
<li style="float: left; width: 16em"><a href="#apr.file_rename" style="text-decoration:none">apr.file_rename()</a></li>
<li style="float: left; width: 16em"><a href="#apr.file_remove" style="text-decoration:none">apr.file_remove()</a></li>
<li style="float: left; width: 16em"><a href="#apr.file_mtime_set" style="text-decoration:none">apr.file_mtime_set()</a></li>
<li style="float: left; width: 16em"><a href="#apr.file_attrs_set" style="text-decoration:none">apr.file_attrs_set()</a></li>
<li style="float: left; width: 16em"><a href="#apr.file_perms_set" style="text-decoration:none">apr.file_perms_set()</a></li>
<li style="float: left; width: 16em"><a href="#apr.stat" style="text-decoration:none">apr.stat()</a></li>
<li style="float: left; width: 16em"><a href="#apr.file_open" style="text-decoration:none">apr.file_open()</a></li>
<li style="float: left; width: 16em"><a href="#file:stat" style="text-decoration:none">file:stat()</a></li>
<li style="float: left; width: 16em"><a href="#file:lines" style="text-decoration:none">file:lines()</a></li>
<li style="float: left; width: 16em"><a href="#file:truncate" style="text-decoration:none">file:truncate()</a></li>
<li style="float: left; width: 16em"><a href="#file:read" style="text-decoration:none">file:read()</a></li>
<li style="float: left; width: 16em"><a href="#file:write" style="text-decoration:none">file:write()</a></li>
<li style="float: left; width: 16em"><a href="#file:seek" style="text-decoration:none">file:seek()</a></li>
<li style="float: left; width: 16em"><a href="#file:flush" style="text-decoration:none">file:flush()</a></li>
<li style="float: left; width: 16em"><a href="#file:lock" style="text-decoration:none">file:lock()</a></li>
<li style="float: left; width: 16em"><a href="#file:unlock" style="text-decoration:none">file:unlock()</a></li>
<li style="float: left; width: 16em"><a href="#pipe:timeout_get" style="text-decoration:none">pipe:timeout_get()</a></li>
<li style="float: left; width: 16em"><a href="#pipe:timeout_set" style="text-decoration:none">pipe:timeout_set()</a></li>
<li style="float: left; width: 16em"><a href="#file:fd_get" style="text-decoration:none">file:fd_get()</a></li>
<li style="float: left; width: 16em"><a href="#file:inherit_set" style="text-decoration:none">file:inherit_set()</a></li>
<li style="float: left; width: 16em"><a href="#file:inherit_unset" style="text-decoration:none">file:inherit_unset()</a></li>
<li style="float: left; width: 16em"><a href="#file:close" style="text-decoration:none">file:close()</a></li>
<li style="float: left; width: 16em"><a href="#apr.file_truncate" style="text-decoration:none">apr.file_truncate()</a></li>
</ul><br style="clear: both"></dd>
<dt style="margin: 1em 0; font-weight: bold"><a href="#network_i_o_handling">Network I/O handling</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.socket_create" style="text-decoration:none">apr.socket_create()</a></li>
<li style="float: left; width: 16em"><a href="#apr.hostname_get" style="text-decoration:none">apr.hostname_get()</a></li>
<li style="float: left; width: 16em"><a href="#apr.host_to_addr" style="text-decoration:none">apr.host_to_addr()</a></li>
<li style="float: left; width: 16em"><a href="#apr.addr_to_host" style="text-decoration:none">apr.addr_to_host()</a></li>
<li style="float: left; width: 16em"><a href="#socket:connect" style="text-decoration:none">socket:connect()</a></li>
<li style="float: left; width: 16em"><a href="#socket:bind" style="text-decoration:none">socket:bind()</a></li>
<li style="float: left; width: 16em"><a href="#socket:listen" style="text-decoration:none">socket:listen()</a></li>
<li style="float: left; width: 16em"><a href="#socket:recvfrom" style="text-decoration:none">socket:recvfrom()</a></li>
<li style="float: left; width: 16em"><a href="#socket:accept" style="text-decoration:none">socket:accept()</a></li>
<li style="float: left; width: 16em"><a href="#socket:read" style="text-decoration:none">socket:read()</a></li>
<li style="float: left; width: 16em"><a href="#socket:write" style="text-decoration:none">socket:write()</a></li>
<li style="float: left; width: 16em"><a href="#socket:lines" style="text-decoration:none">socket:lines()</a></li>
<li style="float: left; width: 16em"><a href="#socket:timeout_get" style="text-decoration:none">socket:timeout_get()</a></li>
<li style="float: left; width: 16em"><a href="#socket:timeout_set" style="text-decoration:none">socket:timeout_set()</a></li>
<li style="float: left; width: 16em"><a href="#socket:opt_get" style="text-decoration:none">socket:opt_get()</a></li>
<li style="float: left; width: 16em"><a href="#socket:opt_set" style="text-decoration:none">socket:opt_set()</a></li>
<li style="float: left; width: 16em"><a href="#socket:addr_get" style="text-decoration:none">socket:addr_get()</a></li>
<li style="float: left; width: 16em"><a href="#socket:fd_get" style="text-decoration:none">socket:fd_get()</a></li>
<li style="float: left; width: 16em"><a href="#socket:fd_set" style="text-decoration:none">socket:fd_set()</a></li>
<li style="float: left; width: 16em"><a href="#socket:shutdown" style="text-decoration:none">socket:shutdown()</a></li>
<li style="float: left; width: 16em"><a href="#socket:close" style="text-decoration:none">socket:close()</a></li>
</ul><br style="clear: both"></dd>
<dt style="margin: 1em 0; font-weight: bold"><a href="#pipe_i_o_handling">Pipe I/O handling</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.pipe_open_stdin" style="text-decoration:none">apr.pipe_open_stdin()</a></li>
<li style="float: left; width: 16em"><a href="#apr.pipe_open_stdout" style="text-decoration:none">apr.pipe_open_stdout()</a></li>
<li style="float: left; width: 16em"><a href="#apr.pipe_open_stderr" style="text-decoration:none">apr.pipe_open_stderr()</a></li>
<li style="float: left; width: 16em"><a href="#apr.namedpipe_create" style="text-decoration:none">apr.namedpipe_create()</a></li>
<li style="float: left; width: 16em"><a href="#apr.pipe_create" style="text-decoration:none">apr.pipe_create()</a></li>
</ul><br style="clear: both"></dd>
<dt style="margin: 1em 0; font-weight: bold"><a href="#ldap_connection_handling">LDAP connection handling</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.ldap" style="text-decoration:none">apr.ldap()</a></li>
<li style="float: left; width: 16em"><a href="#apr.ldap_info" style="text-decoration:none">apr.ldap_info()</a></li>
<li style="float: left; width: 16em"><a href="#apr.ldap_url_parse" style="text-decoration:none">apr.ldap_url_parse()</a></li>
<li style="float: left; width: 16em"><a href="#apr.ldap_url_check" style="text-decoration:none">apr.ldap_url_check()</a></li>
<li style="float: left; width: 16em"><a href="#ldap_conn:bind" style="text-decoration:none">ldap_conn:bind()</a></li>
<li style="float: left; width: 16em"><a href="#ldap_conn:unbind" style="text-decoration:none">ldap_conn:unbind()</a></li>
<li style="float: left; width: 16em"><a href="#ldap_conn:option_get" style="text-decoration:none">ldap_conn:option_get()</a></li>
<li style="float: left; width: 16em"><a href="#ldap_conn:option_set" style="text-decoration:none">ldap_conn:option_set()</a></li>
<li style="float: left; width: 16em"><a href="#ldap_conn:rebind_add" style="text-decoration:none">ldap_conn:rebind_add()</a></li>
<li style="float: left; width: 16em"><a href="#ldap_conn:rebind_remove" style="text-decoration:none">ldap_conn:rebind_remove()</a></li>
<li style="float: left; width: 16em"><a href="#ldap_conn:search" style="text-decoration:none">ldap_conn:search()</a></li>
<li style="float: left; width: 16em"><a href="#ldap_conn:add" style="text-decoration:none">ldap_conn:add()</a></li>
<li style="float: left; width: 16em"><a href="#ldap_conn:compare" style="text-decoration:none">ldap_conn:compare()</a></li>
<li style="float: left; width: 16em"><a href="#ldap_conn:delete" style="text-decoration:none">ldap_conn:delete()</a></li>
<li style="float: left; width: 16em"><a href="#ldap_conn:modify" style="text-decoration:none">ldap_conn:modify()</a></li>
<li style="float: left; width: 16em"><a href="#ldap_conn:rename" style="text-decoration:none">ldap_conn:rename()</a></li>
</ul><br style="clear: both"></dd>
<dt style="margin: 1em 0; font-weight: bold"><a href="#memcached_client">Memcached client</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.memcache" style="text-decoration:none">apr.memcache()</a></li>
<li style="float: left; width: 16em"><a href="#mc_client:hash" style="text-decoration:none">mc_client:hash()</a></li>
<li style="float: left; width: 16em"><a href="#mc_client:find_server_hash" style="text-decoration:none">mc_client:find_server_hash()</a></li>
<li style="float: left; width: 16em"><a href="#mc_client:add_server" style="text-decoration:none">mc_client:add_server()</a></li>
<li style="float: left; width: 16em"><a href="#mc_client:find_server" style="text-decoration:none">mc_client:find_server()</a></li>
<li style="float: left; width: 16em"><a href="#mc_client:enable_server" style="text-decoration:none">mc_client:enable_server()</a></li>
<li style="float: left; width: 16em"><a href="#mc_client:disable_server" style="text-decoration:none">mc_client:disable_server()</a></li>
<li style="float: left; width: 16em"><a href="#mc_client:get" style="text-decoration:none">mc_client:get()</a></li>
<li style="float: left; width: 16em"><a href="#mc_client:set" style="text-decoration:none">mc_client:set()</a></li>
<li style="float: left; width: 16em"><a href="#mc_client:add" style="text-decoration:none">mc_client:add()</a></li>
<li style="float: left; width: 16em"><a href="#mc_client:replace" style="text-decoration:none">mc_client:replace()</a></li>
<li style="float: left; width: 16em"><a href="#mc_client:delete" style="text-decoration:none">mc_client:delete()</a></li>
<li style="float: left; width: 16em"><a href="#mc_client:incr" style="text-decoration:none">mc_client:incr()</a></li>
<li style="float: left; width: 16em"><a href="#mc_client:decr" style="text-decoration:none">mc_client:decr()</a></li>
<li style="float: left; width: 16em"><a href="#mc_client:version" style="text-decoration:none">mc_client:version()</a></li>
<li style="float: left; width: 16em"><a href="#mc_client:stats" style="text-decoration:none">mc_client:stats()</a></li>
</ul><br style="clear: both"></dd>
<dt style="margin: 1em 0; font-weight: bold"><a href="#command_argument_parsing">Command argument parsing</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.getopt" style="text-decoration:none">apr.getopt()</a></li>
</ul><br style="clear: both"></dd>
<dt style="margin: 1em 0; font-weight: bold"><a href="#http_request_parsing">HTTP request parsing</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.parse_headers" style="text-decoration:none">apr.parse_headers()</a></li>
<li style="float: left; width: 16em"><a href="#apr.parse_multipart" style="text-decoration:none">apr.parse_multipart()</a></li>
<li style="float: left; width: 16em"><a href="#apr.parse_cookie_header" style="text-decoration:none">apr.parse_cookie_header()</a></li>
<li style="float: left; width: 16em"><a href="#apr.parse_query_string" style="text-decoration:none">apr.parse_query_string()</a></li>
<li style="float: left; width: 16em"><a href="#apr.header_attribute" style="text-decoration:none">apr.header_attribute()</a></li>
<li style="float: left; width: 16em"><a href="#apr.uri_encode" style="text-decoration:none">apr.uri_encode()</a></li>
<li style="float: left; width: 16em"><a href="#apr.uri_decode" style="text-decoration:none">apr.uri_decode()</a></li>
</ul><br style="clear: both"></dd>
<dt style="margin: 1em 0; font-weight: bold"><a href="#pollset">Pollset</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.pollset" style="text-decoration:none">apr.pollset()</a></li>
<li style="float: left; width: 16em"><a href="#pollset:add" style="text-decoration:none">pollset:add()</a></li>
<li style="float: left; width: 16em"><a href="#pollset:remove" style="text-decoration:none">pollset:remove()</a></li>
<li style="float: left; width: 16em"><a href="#pollset:poll" style="text-decoration:none">pollset:poll()</a></li>
<li style="float: left; width: 16em"><a href="#pollset:destroy" style="text-decoration:none">pollset:destroy()</a></li>
</ul><br style="clear: both"></dd>
<dt style="margin: 1em 0; font-weight: bold"><a href="#process_handling">Process handling</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.proc_create" style="text-decoration:none">apr.proc_create()</a></li>
<li style="float: left; width: 16em"><a href="#apr.proc_detach" style="text-decoration:none">apr.proc_detach()</a></li>
<li style="float: left; width: 16em"><a href="#apr.proc_fork" style="text-decoration:none">apr.proc_fork()</a></li>
<li style="float: left; width: 16em"><a href="#process:addrspace_set" style="text-decoration:none">process:addrspace_set()</a></li>
<li style="float: left; width: 16em"><a href="#process:user_set" style="text-decoration:none">process:user_set()</a></li>
<li style="float: left; width: 16em"><a href="#process:group_set" style="text-decoration:none">process:group_set()</a></li>
<li style="float: left; width: 16em"><a href="#process:cmdtype_set" style="text-decoration:none">process:cmdtype_set()</a></li>
<li style="float: left; width: 16em"><a href="#process:env_set" style="text-decoration:none">process:env_set()</a></li>
<li style="float: left; width: 16em"><a href="#process:dir_set" style="text-decoration:none">process:dir_set()</a></li>
<li style="float: left; width: 16em"><a href="#process:detach_set" style="text-decoration:none">process:detach_set()</a></li>
<li style="float: left; width: 16em"><a href="#process:error_check_set" style="text-decoration:none">process:error_check_set()</a></li>
<li style="float: left; width: 16em"><a href="#process:io_set" style="text-decoration:none">process:io_set()</a></li>
<li style="float: left; width: 16em"><a href="#process:in_set" style="text-decoration:none">process:in_set()</a></li>
<li style="float: left; width: 16em"><a href="#process:out_set" style="text-decoration:none">process:out_set()</a></li>
<li style="float: left; width: 16em"><a href="#process:err_set" style="text-decoration:none">process:err_set()</a></li>
<li style="float: left; width: 16em"><a href="#process:in_get" style="text-decoration:none">process:in_get()</a></li>
<li style="float: left; width: 16em"><a href="#process:out_get" style="text-decoration:none">process:out_get()</a></li>
<li style="float: left; width: 16em"><a href="#process:err_get" style="text-decoration:none">process:err_get()</a></li>
<li style="float: left; width: 16em"><a href="#process:exec" style="text-decoration:none">process:exec()</a></li>
<li style="float: left; width: 16em"><a href="#process:wait" style="text-decoration:none">process:wait()</a></li>
<li style="float: left; width: 16em"><a href="#process:kill" style="text-decoration:none">process:kill()</a></li>
</ul><br style="clear: both"></dd>
<dt style="margin: 1em 0; font-weight: bold"><a href="#shared_memory">Shared memory</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.shm_create" style="text-decoration:none">apr.shm_create()</a></li>
<li style="float: left; width: 16em"><a href="#apr.shm_attach" style="text-decoration:none">apr.shm_attach()</a></li>
<li style="float: left; width: 16em"><a href="#apr.shm_remove" style="text-decoration:none">apr.shm_remove()</a></li>
<li style="float: left; width: 16em"><a href="#shm:read" style="text-decoration:none">shm:read()</a></li>
<li style="float: left; width: 16em"><a href="#shm:write" style="text-decoration:none">shm:write()</a></li>
<li style="float: left; width: 16em"><a href="#shm:seek" style="text-decoration:none">shm:seek()</a></li>
<li style="float: left; width: 16em"><a href="#shm:detach" style="text-decoration:none">shm:detach()</a></li>
<li style="float: left; width: 16em"><a href="#shm:destroy" style="text-decoration:none">shm:destroy()</a></li>
</ul><br style="clear: both"></dd>
<dt style="margin: 1em 0; font-weight: bold"><a href="#signal_handling">Signal handling</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.signal" style="text-decoration:none">apr.signal()</a></li>
<li style="float: left; width: 16em"><a href="#apr.signal_raise" style="text-decoration:none">apr.signal_raise()</a></li>
<li style="float: left; width: 16em"><a href="#apr.signal_block" style="text-decoration:none">apr.signal_block()</a></li>
<li style="float: left; width: 16em"><a href="#apr.signal_unblock" style="text-decoration:none">apr.signal_unblock()</a></li>
<li style="float: left; width: 16em"><a href="#apr.signal_names" style="text-decoration:none">apr.signal_names()</a></li>
</ul><br style="clear: both"></dd>
<dt style="margin: 1em 0; font-weight: bold"><a href="#string_routines">String routines</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.strnatcmp" style="text-decoration:none">apr.strnatcmp()</a></li>
<li style="float: left; width: 16em"><a href="#apr.strnatcasecmp" style="text-decoration:none">apr.strnatcasecmp()</a></li>
<li style="float: left; width: 16em"><a href="#apr.strfsize" style="text-decoration:none">apr.strfsize()</a></li>
<li style="float: left; width: 16em"><a href="#apr.tokenize_to_argv" style="text-decoration:none">apr.tokenize_to_argv()</a></li>
</ul><br style="clear: both"></dd>
<dt style="margin: 1em 0; font-weight: bold"><a href="#multi_threading">Multi threading</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.thread" style="text-decoration:none">apr.thread()</a></li>
<li style="float: left; width: 16em"><a href="#apr.thread_yield" style="text-decoration:none">apr.thread_yield()</a></li>
<li style="float: left; width: 16em"><a href="#thread:join" style="text-decoration:none">thread:join()</a></li>
<li style="float: left; width: 16em"><a href="#thread:status" style="text-decoration:none">thread:status()</a></li>
</ul><br style="clear: both"></dd>
<dt style="margin: 1em 0; font-weight: bold"><a href="#thread_queues">Thread queues</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.thread_queue" style="text-decoration:none">apr.thread_queue()</a></li>
<li style="float: left; width: 16em"><a href="#queue:push" style="text-decoration:none">queue:push()</a></li>
<li style="float: left; width: 16em"><a href="#queue:pop" style="text-decoration:none">queue:pop()</a></li>
<li style="float: left; width: 16em"><a href="#queue:trypush" style="text-decoration:none">queue:trypush()</a></li>
<li style="float: left; width: 16em"><a href="#queue:trypop" style="text-decoration:none">queue:trypop()</a></li>
<li style="float: left; width: 16em"><a href="#queue:interrupt" style="text-decoration:none">queue:interrupt()</a></li>
<li style="float: left; width: 16em"><a href="#queue:terminate" style="text-decoration:none">queue:terminate()</a></li>
<li style="float: left; width: 16em"><a href="#queue:close" style="text-decoration:none">queue:close()</a></li>
</ul><br style="clear: both"></dd>
<dt style="margin: 1em 0; font-weight: bold"><a href="#time_routines">Time routines</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.sleep" style="text-decoration:none">apr.sleep()</a></li>
<li style="float: left; width: 16em"><a href="#apr.time_now" style="text-decoration:none">apr.time_now()</a></li>
<li style="float: left; width: 16em"><a href="#apr.time_explode" style="text-decoration:none">apr.time_explode()</a></li>
<li style="float: left; width: 16em"><a href="#apr.time_implode" style="text-decoration:none">apr.time_implode()</a></li>
<li style="float: left; width: 16em"><a href="#apr.time_format" style="text-decoration:none">apr.time_format()</a></li>
</ul><br style="clear: both"></dd>
<dt style="margin: 1em 0; font-weight: bold"><a href="#uniform_resource_identifier_parsing">Uniform resource identifier parsing</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.uri_parse" style="text-decoration:none">apr.uri_parse()</a></li>
<li style="float: left; width: 16em"><a href="#apr.uri_unparse" style="text-decoration:none">apr.uri_unparse()</a></li>
<li style="float: left; width: 16em"><a href="#apr.uri_port_of_scheme" style="text-decoration:none">apr.uri_port_of_scheme()</a></li>
</ul><br style="clear: both"></dd>
<dt style="margin: 1em 0; font-weight: bold"><a href="#user_group_identification">User/group identification</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.user_get" style="text-decoration:none">apr.user_get()</a></li>
<li style="float: left; width: 16em"><a href="#apr.user_homepath_get" style="text-decoration:none">apr.user_homepath_get()</a></li>
</ul><br style="clear: both"></dd>
<dt style="margin: 1em 0; font-weight: bold"><a href="#universally_unique_identifiers">Universally unique identifiers</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.uuid_get" style="text-decoration:none">apr.uuid_get()</a></li>
<li style="float: left; width: 16em"><a href="#apr.uuid_format" style="text-decoration:none">apr.uuid_format()</a></li>
<li style="float: left; width: 16em"><a href="#apr.uuid_parse" style="text-decoration:none">apr.uuid_parse()</a></li>
</ul><br style="clear: both"></dd>
<dt style="margin: 1em 0; font-weight: bold"><a href="#character_encoding_translation">Character encoding translation</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.xlate" style="text-decoration:none">apr.xlate()</a></li>
</ul><br style="clear: both"></dd>
<dt style="margin: 1em 0; font-weight: bold"><a href="#xml_parsing">XML parsing</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.xml" style="text-decoration:none">apr.xml()</a></li>
<li style="float: left; width: 16em"><a href="#xml_parser:feed" style="text-decoration:none">xml_parser:feed()</a></li>
<li style="float: left; width: 16em"><a href="#xml_parser:done" style="text-decoration:none">xml_parser:done()</a></li>
<li style="float: left; width: 16em"><a href="#xml_parser:geterror" style="text-decoration:none">xml_parser:geterror()</a></li>
<li style="float: left; width: 16em"><a href="#xml_parser:getinfo" style="text-decoration:none">xml_parser:getinfo()</a></li>
<li style="float: left; width: 16em"><a href="#xml_parser:close" style="text-decoration:none">xml_parser:close()</a></li>
</ul><br style="clear: both"></dd>
<dt style="margin: 1em 0; font-weight: bold"><a href="#serialization">Serialization</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.ref" style="text-decoration:none">apr.ref()</a></li>
<li style="float: left; width: 16em"><a href="#apr.deref" style="text-decoration:none">apr.deref()</a></li>
<li style="float: left; width: 16em"><a href="#apr.serialize" style="text-decoration:none">apr.serialize()</a></li>
<li style="float: left; width: 16em"><a href="#apr.unserialize" style="text-decoration:none">apr.unserialize()</a></li>
</ul><br style="clear: both"></dd>
<dt style="margin: 1em 0; font-weight: bold"><a href="#miscellaneous_functions">Miscellaneous functions</a></dt>
<dd><ul>
<li style="float: left; width: 16em"><a href="#apr.platform_get" style="text-decoration:none">apr.platform_get()</a></li>
<li style="float: left; width: 16em"><a href="#apr.version_get" style="text-decoration:none">apr.version_get()</a></li>
<li style="float: left; width: 16em"><a href="#apr.os_default_encoding" style="text-decoration:none">apr.os_default_encoding()</a></li>
<li style="float: left; width: 16em"><a href="#apr.os_locale_encoding" style="text-decoration:none">apr.os_locale_encoding()</a></li>
<li style="float: left; width: 16em"><a href="#apr.type" style="text-decoration:none">apr.type()</a></li>
</ul><br style="clear: both"></dd>
<dt style="padding: 1em 0; font-weight: bold">Miscellaneous sections</dt>
<dd><ul>
<li><a href="#file_system_permissions">File system permissions</a></li>
<li><a href="#error_handling">Error handling</a></li>
<li><a href="#example_http_client">Example: HTTP client</a></li>
<li><a href="#example_single_threaded_webserver">Example: Single threaded webserver</a></li>
<li><a href="#example_multi_threaded_webserver">Example: Multi threaded webserver</a></li>
<li><a href="#example_asynchronous_webserver">Example: Asynchronous webserver</a></li>
</ul></dd>
</dl>

## <a name="base64_encoding" href="#base64_encoding">Base64 encoding</a>

The functions in this module can be used to encode strings in base64 and to
decode base64 encoded strings. The base64 format uses the printable
characters `A-Z`, `a-z`, `0-9`, `+` and `/` to encode binary data. This can
be useful when your data is used in a context that isn't 8-bit clean, for
example in e-mail attachments and [data:] [data_uris] URLs. You can read
more about base64 encoding in [this] [base64] Wikipedia article.

[base64]: http://en.wikipedia.org/wiki/Base64
[data_uris]: http://en.wikipedia.org/wiki/Data_URI_scheme

###  <a name="apr.base64_encode" href="#apr.base64_encode">`apr.base64_encode(plain) → coded`</a>

Encode the string <tt>*plain*</tt> using base64 encoding. On success the coded string
is returned, otherwise a <tt>*nil*</tt> followed by an error message is returned. As an
example, here is how to convert an image file into a [data: URL]
[data_uris]:

    > image = io.open 'lua-logo.png'
    > encoded_data = apr.base64_encode(image:read '*a')
    > data_url = 'data:image/png;base64,' .. encoded_data
    > = '<img src="' .. url .. '" width=16 height=16 alt="Lua logo">'
    <img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABAAAAAQCAYAAAAf8/9hAAAAAXNSR0IArs4c6QAAAm5JREFUOMt9k01LW0EUhp+Z5CaxatSbljRioaQgmCIKoUo3XXRRF241tUuhIEgWIgRSKzhtNLZbKf0BulL6C1x234WgoS0otIoWP4Ji48ed3Dtd9CoSW18YBs45z8uZjyOokVKqGQgBzZZlHQshHM/zGqrVaiCRSGyOjOwmhXDngZgxjAUvwLm5uXC5XI5Ho9G98fHxQ2AXVNS3/QFQLBZjdXXuu7MzegCE4IO4CiulfoK6LSUTxvAcaPX9t4Vg0fMoSskbYxj14ysBgN7e3oRSahPepoUwn4FnQONFd11d8cZstvexbUderq0dKCk5iUTEL63lqCgWi3eklE4+fxYWghXg7tU7aWmJsLExRlNTGIC+voWD5eWtDqUcY9v2sXRdtyGfzx9JyataGKCtLXoJA7S3x2JSOhNKqf1yuXxPuq57DGAML/iHVld3WVpaA6BU2mNxce2yNhgMnkrLsgIw2wLEC4Wn1wyMgaGhT9j2ezo7P7K/fwIQB2VXq9VT6XleFIRXC05OPrncM5mHDAykGB19dLXEC4VCASml/A35I2CL/+jkRHN6qkkm7YvQFqhDx3GapNZa+59iIRAQZLM9DA93U6k4DA6miMVukU4n0NrDtusIhQIIwfyFt1BKtaVSqZ1MptQoBF+AJDdrwxjSs7NhEQwGHamU2iqVSg9AHRpDP7B+A7xuDP3GTB2dn5/X53K5ivQH6HuhUOgA9dUYuo3hNbAKaH+tGiMm/uamvk1PT99PpVI7AKJmEpPAtlLqzH9EPy8MwMzMTEJrHfh75Ix7zcA3abUsy9VaG8AGDgEHiNbX1+/lcrnK1fo/txYAMvuVJrYAAAAASUVORK5CYII=" width=16 height=16 alt="Lua logo">

This is what the result looks like (might not work in older web browsers):
<img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABAAAAAQCAYAAAAf8/9hAAAAAXNSR0IArs4c6QAAAm5JREFUOMt9k01LW0EUhp+Z5CaxatSbljRioaQgmCIKoUo3XXRRF241tUuhIEgWIgRSKzhtNLZbKf0BulL6C1x234WgoS0otIoWP4Ji48ed3Dtd9CoSW18YBs45z8uZjyOokVKqGQgBzZZlHQshHM/zGqrVaiCRSGyOjOwmhXDngZgxjAUvwLm5uXC5XI5Ho9G98fHxQ2AXVNS3/QFQLBZjdXXuu7MzegCE4IO4CiulfoK6LSUTxvAcaPX9t4Vg0fMoSskbYxj14ysBgN7e3oRSahPepoUwn4FnQONFd11d8cZstvexbUderq0dKCk5iUTEL63lqCgWi3eklE4+fxYWghXg7tU7aWmJsLExRlNTGIC+voWD5eWtDqUcY9v2sXRdtyGfzx9JyataGKCtLXoJA7S3x2JSOhNKqf1yuXxPuq57DGAML/iHVld3WVpaA6BU2mNxce2yNhgMnkrLsgIw2wLEC4Wn1wyMgaGhT9j2ezo7P7K/fwIQB2VXq9VT6XleFIRXC05OPrncM5mHDAykGB19dLXEC4VCASml/A35I2CL/+jkRHN6qkkm7YvQFqhDx3GapNZa+59iIRAQZLM9DA93U6k4DA6miMVukU4n0NrDtusIhQIIwfyFt1BKtaVSqZ1MptQoBF+AJDdrwxjSs7NhEQwGHamU2iqVSg9AHRpDP7B+A7xuDP3GTB2dn5/X53K5ivQH6HuhUOgA9dUYuo3hNbAKaH+tGiMm/uamvk1PT99PpVI7AKJmEpPAtlLqzH9EPy8MwMzMTEJrHfh75Ix7zcA3abUsy9VaG8AGDgEHiNbX1+/lcrnK1fo/txYAMvuVJrYAAAAASUVORK5CYII=" width=16 height=16 alt="Lua logo">

*This function is binary safe.*

###  <a name="apr.base64_decode" href="#apr.base64_decode">`apr.base64_decode(coded) → plain`</a>

Decode the base64 encoded string <tt>*coded*</tt>. On success the decoded string is
returned, otherwise a <tt>*nil*</tt> followed by an error message is returned.

*This function is binary safe.*

## <a name="cryptography_routines" href="#cryptography_routines">Cryptography routines</a>

These functions support the [MD5] [md5] and [SHA1] [sha1] cryptographic hash
functions. You can also use them to encrypt plain text passwords using a
[salt] [salt], validate plain text passwords against their encrypted, salted
digest and read passwords from standard input while masking the characters
typed by the user.

The MD5 and SHA1 functions can be used to hash binary data. This is useful
because the hash is only 16 or 32 bytes long, yet it still changes
significantly when the binary data changes by just one byte.

If that doesn't look useful consider the following scenario: The Lua authors
have just finished a new release of Lua and are about to publish the source
code on <http://lua.org>. Before they publish the [tarball] [tar] they first
calculate its MD5 and SHA1 hashes. They then publish the archive and hashes
on the [downloads page] [lua_downloads]. When a user downloads the tarball
they can verify whether it was corrupted or manipulated since it was
published on <http://lua.org> by comparing the published hash against the
hash of the tarball they just downloaded:

    > handle = io.open('lua-5.1.4.tar.gz', 'rb')
    > data = handle:read('*a'); handle:close()
    > = apr.md5(data) == 'd0870f2de55d59c1c8419f36e8fac150'
    true
    > = apr.sha1(data) == '2b11c8e60306efb7f0734b747588f57995493db7'
    true

[md5]: http://en.wikipedia.org/wiki/MD5
[sha1]: http://en.wikipedia.org/wiki/SHA1
[salt]: http://en.wikipedia.org/wiki/Salt_(cryptography)
[tar]: http://en.wikipedia.org/wiki/Tar_(file_format)
[lua_downloads]: http://www.lua.org/ftp/

###  <a name="apr.md5" href="#apr.md5">`apr.md5(input [, binary]) → digest`</a>

Calculate the [MD5] [md5] message digest of the string <tt>*input*</tt>. On success
the digest is returned as a string of 32 hexadecimal characters, or a string
of 16 bytes if <tt>*binary*</tt> evaluates to <tt>*true*</tt>. Otherwise a <tt>*nil*</tt> followed by an
error message is returned.

*This function is binary safe.*


###  <a name="apr.md5_encode" href="#apr.md5_encode">`apr.md5_encode(password, salt) → digest`</a>

Encode the string <tt>*password*</tt> using the [MD5] [md5] algorithm and a [salt]
[salt] string. On success the digest is returned, otherwise a <tt>*nil*</tt> followed
by an error message is returned.

*This function is not binary safe.*

###  <a name="apr.password_validate" href="#apr.password_validate">`apr.password_validate(password, digest) → valid`</a>

Validate the string <tt>*password*</tt> against a <tt>*digest*</tt> created by one of the
APR-supported algorithms ([MD5] [md5] and [SHA1] [sha1]). On success <tt>*true*</tt> is
returned, otherwise a <tt>*nil*</tt> followed by an error message is returned.

Hashes created by crypt are supported only on platforms that provide
[crypt(3)] [crypt_fun], so don't rely on that function unless you know that
your application will be run only on platforms that support it. On platforms
that don't support crypt(3), this falls back to a clear text string
comparison.

[crypt_fun]: http://linux.die.net/man/3/crypt

*This function is not binary safe.*

###  <a name="apr.password_get" href="#apr.password_get">`apr.password_get(prompt) → password`</a>

Display the string <tt>*prompt*</tt> on the command-line prompt and read in a password
from standard input. If your platform allows it, the typed password will be
masked by a placeholder like `*`. On success the password is returned,
otherwise a <tt>*nil*</tt> followed by an error message is returned.

*This function is not binary safe.*

###  <a name="apr.md5_init" href="#apr.md5_init">`apr.md5_init() → md5_context`</a>

Create and return an object that can be used to calculate [MD5] [md5]
message digests in steps. If an error occurs a <tt>*nil*</tt> followed by an error
message is returned. This can be useful when you want to calculate message
digests of large inputs, for example files like [ISO images] [isoimg] and
backups:

    > function md5_file(path, binary)
    >>  local handle = assert(io.open(path, 'rb'))
    >>  local context = assert(apr.md5_init())
    >>  while true do
    >>    local block = handle:read(1024 * 1024)
    >>    if not block then break end
    >>    assert(context:update(block))
    >>  end
    >>  return context:digest(binary)
    >> end
    >
    > md5_file 'ubuntu-10.04-desktop-i386.iso'
    'd044a2a0c8103fc3e5b7e18b0f7de1c8'

[isoimg]: http://en.wikipedia.org/wiki/ISO_image

###  <a name="md5_context:update" href="#md5_context:update">`md5_context:update(input) → status`</a>

Continue an [MD5] [md5] message digest operation by processing another
message block and updating the context. On success <tt>*true*</tt> is returned,
otherwise a <tt>*nil*</tt> followed by an error message is returned.

*This function is binary safe.*

###  <a name="md5_context:digest" href="#md5_context:digest">`md5_context:digest([binary]) → digest`</a>

End an [MD5] [md5] message digest operation. On success the digest is
returned as a string of 32 hexadecimal characters, or a string of 16 bytes
if <tt>*binary*</tt> evaluates to <tt>*true*</tt>. Otherwise a <tt>*nil*</tt> followed by an error message
is returned.

If you want to re-use the context object after calling this method
see [md5\_context:reset()](#md5_context:reset).

###  <a name="md5_context:reset" href="#md5_context:reset">`md5_context:reset() → status`</a>

Use this method to reset the context after calling [md5\_context:digest()](#md5_context:digest).
This enables you to re-use the same context to perform another message
digest calculation. On success <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed by
an error message is returned.

###  <a name="apr.sha1" href="#apr.sha1">`apr.sha1(input [, binary]) → digest`</a>

Calculate the [SHA1] [sha1] message digest of the string <tt>*input*</tt>. On success
the digest is returned as a string of 40 hexadecimal characters, or a string
of 20 bytes if <tt>*binary*</tt> evaluates to <tt>*true*</tt>. Otherwise a <tt>*nil*</tt> followed by an
error message is returned.

*This function is binary safe.*


###  <a name="apr.sha1_init" href="#apr.sha1_init">`apr.sha1_init() → sha1_context`</a>

Create and return an object that can be used to calculate [SHA1] [sha1]
message digests in steps. See also the example for [apr.md5\_init()](#apr.md5_init).

###  <a name="sha1_context:update" href="#sha1_context:update">`sha1_context:update(input) → status`</a>

Continue an [SHA1] [sha1] message digest operation by processing another
message block and updating the context.

*This function is binary safe.*

###  <a name="sha1_context:digest" href="#sha1_context:digest">`sha1_context:digest([binary]) → digest`</a>

End an [SHA1] [sha1] message digest operation. On success the digest is
returned as a string of 40 hexadecimal characters, or a string of 20 bytes
if <tt>*binary*</tt> evaluates to <tt>*true*</tt>. Otherwise a <tt>*nil*</tt> followed by an error message
is returned.

If you want to re-use the context object after calling this method
see [sha1\_context:reset()](#sha1_context:reset).

###  <a name="sha1_context:reset" href="#sha1_context:reset">`sha1_context:reset() → status`</a>

Use this method to reset the context after calling [sha1\_context:digest()](#sha1_context:digest).
This enables you to re-use the same context to perform another message
digest calculation.

## <a name="date_parsing" href="#date_parsing">Date parsing</a>

###  <a name="apr.date_parse_http" href="#apr.date_parse_http">`apr.date_parse_http(string) → time`</a>

Parses an [HTTP] [http] date in one of three standard forms:

 - `'Sun, 06 Nov 1994 08:49:37 GMT'` - [RFC 822] [rfc822], updated by [RFC 1123][rfc1123]
 - `'Sunday, 06-Nov-94 08:49:37 GMT'` - [RFC 850] [rfc850], obsoleted by [RFC 1036][rfc1036]
 - `'Sun Nov  6 08:49:37 1994'` - ANSI C's [asctime()] [asctime] format

On success the date is returned as a number like documented under [time
routines](#time_routines). If the date string is out of range or invalid <tt>*nil*</tt>
is returned.

[http]: http://en.wikipedia.org/wiki/Hypertext_Transfer_Protocol
[rfc822]: http://tools.ietf.org/html/rfc822
[rfc1123]: http://tools.ietf.org/html/rfc1123
[rfc850]: http://tools.ietf.org/html/rfc850
[rfc1036]: http://tools.ietf.org/html/rfc1036
[asctime]: http://linux.die.net/man/3/asctime

*This function is not binary safe.*

###  <a name="apr.date_parse_rfc" href="#apr.date_parse_rfc">`apr.date_parse_rfc(string) → time`</a>

Parses a string resembling an [RFC 822] [rfc822] date. This is meant to be
lenient in its parsing of dates and hence will parse a wider range of dates
than [apr.date\_parse\_http()](#apr.date_parse_http).

The prominent mailer (or poster, if mailer is unknown) that has been seen in
the wild is included for the unknown formats:

 - `'Sun, 06 Nov 1994 08:49:37 GMT'` - [RFC 822] [rfc822], updated by [RFC 1123] [rfc1123]
 - `'Sunday, 06-Nov-94 08:49:37 GMT'` - [RFC 850] [rfc850], obsoleted by [RFC 1036] [rfc1036]
 - `'Sun Nov  6 08:49:37 1994'` - ANSI C's [asctime()] [asctime] format
 - `'Sun, 6 Nov 1994 08:49:37 GMT'` - [RFC 822] [rfc822], updated by [RFC 1123] [rfc1123]
 - `'Sun, 06 Nov 94 08:49:37 GMT'` - [RFC 822] [rfc822]
 - `'Sun, 6 Nov 94 08:49:37 GMT'` - [RFC 822] [rfc822]
 - `'Sun, 06 Nov 94 08:49 GMT'` - Unknown [drtr@ast.cam.ac.uk]
 - `'Sun, 6 Nov 94 08:49 GMT'` - Unknown [drtr@ast.cam.ac.uk]
 - `'Sun, 06 Nov 94 8:49:37 GMT'` - Unknown [Elm 70.85]
 - `'Sun, 6 Nov 94 8:49:37 GMT'` - Unknown [Elm 70.85]

On success the date is returned as a number like documented under [time
routines](#time_routines). If the date string is out of range or invalid <tt>*nil*</tt>
is returned.

*This function is not binary safe.*

## <a name="relational_database_drivers" href="#relational_database_drivers">Relational database drivers</a>

The APR DBD module makes it possible to query relational database engines
like [SQLite] [sqlite], [MySQL] [mysql], [PostgreSQL] [pgsql], [Oracle]
[oracle], [ODBC] [odbc] and [FreeTDS] [freetds]. This module currently has
some drawbacks which appear to be unavoidable given the design of the Apache
Portable Runtime DBD framework:

 - Booleans and numbers are returned as strings because result set types are
   not known to the Lua/APR binding (and type guessing is too error prone)

 - String arguments and results are not binary safe, this means they will
   be truncated at the first zero byte (see the [apr-dev mailing list]
   [apr_dev] thread ["current dbd initiatives"] [dbd_binary_discuss] for
   discussion about this limitation of APR)

Note that if you control the data going into the database you can overcome
the second limitation by using APR's built in support for
[Base64 encoding](#base64_encoding).

### Installing drivers

On Debian/Ubuntu Linux you can install one or more of the following packages
to enable support for the corresponding database driver (dependencies will
be installed automatically by the package management system):

 - [libaprutil1-dbd-sqlite3][sqlite3_pkg]
 - [libaprutil1-dbd-mysql](http://packages.ubuntu.com/lucid/libaprutil1-dbd-mysql)
 - [libaprutil1-dbd-pgsql](http://packages.ubuntu.com/lucid/libaprutil1-dbd-pgsql)
 - [libaprutil1-dbd-odbc](http://packages.ubuntu.com/lucid/libaprutil1-dbd-odbc)
 - [libaprutil1-dbd-freetds](http://packages.ubuntu.com/lucid/libaprutil1-dbd-freetds)

### Debugging "DSO load failed" errors

In my initial tests on Ubuntu I installed [libaprutil1-dbd-sqlite3]
[sqlite3_pkg] but kept getting an error when trying to load the driver:

    $ lua -e "print(require('apr').dbd('sqlite3'))"
    nil  DSO load failed  EDSOOPEN

After a while I found the problem using [LD_DEBUG] [ld_debug]:

    $ LD_DEBUG=libs lua -e "require('apr').dbd('sqlite3')" 2>&1 | grep undefined
    /usr/lib/apr-util-1/apr_dbd_sqlite3-1.so: error: symbol lookup error: undefined symbol: apr_pool_cleanup_null (fatal)

Having identified the problem, finding a workaround was easy:

    $ export LD_PRELOAD='/usr/lib/libapr-1.so.0:/usr/lib/libaprutil-1.so.0'
    $ lua -e "print(require('apr').dbd('sqlite3'))"
    database driver (0x853bdfc)

[sqlite]: http://en.wikipedia.org/wiki/SQLite
[mysql]: http://en.wikipedia.org/wiki/MySQL
[pgsql]: http://en.wikipedia.org/wiki/PostgreSQL
[oracle]: http://en.wikipedia.org/wiki/Oracle_Database
[odbc]: http://en.wikipedia.org/wiki/ODBC
[freetds]: http://en.wikipedia.org/wiki/FreeTDS
[apr_dev]: http://apr.apache.org/mailing-lists.html
[dbd_binary_discuss]: http://marc.info/?l=apr-dev&m=114969441721086&w=2
[sqlite3_pkg]: http://packages.ubuntu.com/lucid/libaprutil1-dbd-sqlite3
[ld_debug]: http://www.wlug.org.nz/LD_DEBUG

###  <a name="apr.dbd" href="#apr.dbd">`apr.dbd(name) → driver`</a>

Create a database driver object. The string <tt>*name*</tt> decides which database
engine to use. On success the driver object is returned, otherwise a <tt>*nil*</tt>
followed by an error message is returned. Currently supported engines
include:

 - `'mysql'`
 - `'pgsql'`
 - `'sqlite3'`
 - `'sqlite2'`
 - `'oracle'`
 - `'freetds'`
 - `'odbc'`

Note that in its default configuration the Apache Portable Runtime uses
dynamic loading to load database drivers which means [apr.dbd()](#apr.dbd) can fail
because a driver can't be loaded.

###  <a name="driver:open" href="#driver:open">`driver:open(params) → status`</a>

Open a connection to a backend. The string <tt>*params*</tt> contains the arguments to
the driver (implementation-dependent). On success <tt>*true*</tt> is returned,
otherwise a <tt>*nil*</tt> followed by an error message is returned. The syntax of
<tt>*params*</tt> is as follows:

 - __PostgreSQL:__ <tt>*params*</tt> is passed directly to the [PQconnectdb()]
   [pqconnectdb] function, check the PostgreSQL documentation for more
   details on the syntax

 - __SQLite2:__ <tt>*params*</tt> is split on a colon, with the first part used as the
   filename and the second part converted to an integer and used as the file
   mode

 - __SQLite3:__ <tt>*params*</tt> is passed directly to the [sqlite3_open()]
   [sqlite3_open] function as a filename to be opened, check the SQLite3
   documentation for more details (hint: if <tt>*params*</tt> is `':memory:'` a
   private, temporary in-memory database is created for the connection)

 - __Oracle:__ <tt>*params*</tt> can have 'user', 'pass', 'dbname' and 'server' keys,
   each followed by an equal sign and a value. Such key/value pairs can be
   delimited by space, CR, LF, tab, semicolon, vertical bar or comma

 - __MySQL:__ <tt>*params*</tt> can have 'host', 'port', 'user', 'pass', 'dbname',
   'sock', 'flags' 'fldsz', 'group' and 'reconnect' keys, each followed by
   an equal sign and a value. Such key/value pairs can be delimited by
   space, CR, LF, tab, semicolon, vertical bar or comma. For now, 'flags'
   can only recognize `CLIENT_FOUND_ROWS` (check MySQL manual for details).
   The value associated with 'fldsz' determines maximum amount of memory (in
   bytes) for each of the fields in the result set of prepared statements.
   By default, this value is 1 MB. The value associated with 'group'
   determines which group from configuration file to use (see
   `MYSQL_READ_DEFAULT_GROUP` option of [mysql_options()] [mysql_options] in
   MySQL manual). Reconnect is set to 1 by default (i.e. <tt>*true*</tt>)

 - __FreeTDS:__ <tt>*params*</tt> can have 'username', 'password', 'appname',
   'dbname', 'host', 'charset', 'lang' and 'server' keys, each followed by
   an equal sign and a value

 [pqconnectdb]: http://www.postgresql.org/docs/current/interactive/libpq-connect.html#LIBPQ-PQCONNECTDB
 [sqlite3_open]: http://www.sqlite.org/c3ref/open.html
 [mysql_options]: http://dev.mysql.com/doc/refman/5.5/en/mysql-options.html

*This function is not binary safe.*

###  <a name="driver:dbname" href="#driver:dbname">`driver:dbname(name) → status`</a>

Select the database <tt>*name*</tt>. On succes <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt>
followed by an error message is returned. Not supported for all drivers
(e.g. SQLite by definition only knows a single database).

*This function is not binary safe.*

###  <a name="driver:driver" href="#driver:driver">`driver:driver() → name`</a>

Get the name of the database driver. Returns one of the strings listed for
[apr.dbd()](#apr.dbd).

###  <a name="driver:check" href="#driver:check">`driver:check() → status`</a>

Check the status of the database connection. When the connection is still
alive <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned.

###  <a name="driver:query" href="#driver:query">`driver:query(sql) → status, affected_rows`</a>

Execute an SQL query that doesn't return a result set. On success <tt>*true*</tt>
followed by the number of affected rows is returned, otherwise a <tt>*nil*</tt>
followed by an error message is returned.

*This function is not binary safe.*

###  <a name="driver:select" href="#driver:select">`driver:select(sql [, random_access]) → result_set`</a>

Execute an SQL query that returns a result set. On success a result set
object is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned. To enable support for random access you can pass the optional
argument <tt>*random_access*</tt> as <tt>*true*</tt>.

*This function is not binary safe.*

###  <a name="driver:transaction_start" href="#driver:transaction_start">`driver:transaction_start() → status`</a>

Start a transaction. May be a no-op. On success <tt>*true*</tt> is returned, otherwise
a <tt>*nil*</tt> followed by an error message is returned.

Note that transaction modes, set by calling [driver:transaction\_mode()](#driver:transaction_mode),
will affect all query/select calls within a transaction. By default, any
error in query/select during a transaction will cause the transaction to
inherit the error code and any further query/select calls will fail
immediately. Put transaction in `'ignore-errors'` mode to avoid that. Use
`'rollback'` mode to do explicit rollback.

TODO Support for transaction objects that have query(), select(), prepare() methods?

###  <a name="driver:transaction_end" href="#driver:transaction_end">`driver:transaction_end() → status`</a>

End a transaction (commit on success, rollback on error). May be a no-op. On
success <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned.

###  <a name="driver:transaction_mode" href="#driver:transaction_mode">`driver:transaction_mode([mode]) → mode`</a>

Get or set the transaction mode, one of:

 - `'commit'`: commit the transaction
 - `'rollback'`: rollback the transaction
 - `'ignore-errors'`: ignore transaction errors

On success the new transaction mode is returned, otherwise a <tt>*nil*</tt> followed by
an error message is returned.

###  <a name="driver:prepare" href="#driver:prepare">`driver:prepare(sql [, random_access]) → prepared_statement`</a>

Prepare an SQL statement. On success a prepared statement object is
returned, otherwise a <tt>*nil*</tt> followed by an error message is returned. The
string <tt>*sql*</tt> gives the query to prepare. If the optional argument
<tt>*random_access*</tt> is <tt>*true*</tt>, result sets created by the prepared statement will
support random access.

To specify parameters of the prepared query, use `%s`, `%d` etc. (see below
for full list) in place of database specific parameter syntax (e.g. for
PostgreSQL, this would be `$1`, `$2`, for SQLite3 this would be `?`, etc.).
For instance: `SELECT name FROM customers WHERE name = %s` would be a query
that this function understands. Here is the list of supported format
specifiers and what they map to in SQL (generally you'll only need the types
marked in bold text):

 - `%hhd`: TINY INT
 - `%hhu`: UNSIGNED TINY INT
 - `%hd`: SHORT
 - `%hu`: UNSIGNED SHORT
 - __`%d`: INT__
 - __`%u`: UNSIGNED INT__
 - `%ld`: LONG
 - `%lu`: UNSIGNED LONG
 - `%lld`: LONG LONG
 - `%llu`: UNSIGNED LONG LONG
 - __`%f`: FLOAT, REAL__
 - __`%lf`: DOUBLE PRECISION__
 - __`%s`: VARCHAR__
 - __`%pDt`: TEXT__
 - `%pDi`: TIME
 - `%pDd`: DATE
 - `%pDa`: DATETIME
 - `%pDs`: TIMESTAMP
 - `%pDz`: TIMESTAMP WITH TIME ZONE
 - `%pDn`: NULL

*This function is not binary safe.*

###  <a name="prepared_statement:query" href="#prepared_statement:query">`prepared_statement:query(...) → status`</a>

Using a prepared statement, execute an SQL query that doesn't return a
result set. On success <tt>*true*</tt> followed by the number of affected rows is
returned, otherwise a <tt>*nil*</tt> followed by an error message is returned.

If you pass a list then the values in the list become query parameters,
otherwise all function arguments become query parameters.

*This function is not binary safe.*

###  <a name="prepared_statement:select" href="#prepared_statement:select">`prepared_statement:select(...) → result_set`</a>

Using a prepared statement, execute an SQL query that returns a result set.
On success a result set object is returned, otherwise a <tt>*nil*</tt> followed by an
error message is returned. To enable support for random access pass
<tt>*random_access*</tt> as <tt>*true*</tt>, otherwise pass it as <tt>*false*</tt>.

If you pass a list then the values in the list become query parameters,
otherwise all function arguments after <tt>*random_access*</tt> become query
parameters.

*This function is not binary safe.*

###  <a name="result_set:columns" href="#result_set:columns">`result_set:columns([num]) → name [, ...]`</a>

If no arguments are given return the names of all columns in the result set,
otherwise return the name of the column with index <tt>*num*</tt> (counting from one).
For example:

    > driver = assert(apr.dbd 'sqlite3')
    > assert(driver:open ':memory:')
    > results = assert(driver:select [[ SELECT 1 AS col1, 2 AS col2 ]])
    > = assert(results:columns())
    { 'col1', 'col2' }

*This function is not binary safe.*

###  <a name="result_set:row" href="#result_set:row">`result_set:row(num) → row`</a>

Return a table with named fields for the next row in the result set or the
row with index <tt>*rownum*</tt> if given. When there are no more rows nothing is
returned, in case of an error a <tt>*nil*</tt> followed by an error message is
returned.

*This function is not binary safe.*

###  <a name="result_set:rows" href="#result_set:rows">`result_set:rows() → iterator`</a>

Return an iterator that produces a table with named fields for each
(remaining) row in the result set.

In Lua 5.2 you can also use `pairs(result_set)`.

*This function is not binary safe.*

###  <a name="result_set:tuple" href="#result_set:tuple">`result_set:tuple([rownum]) → value [, ...]`</a>

Return a tuple for the next row in the result set or the row with index
<tt>*rownum*</tt> if given. If more than one value is returned, the return values will
be in the same order as the column list in the SQL query. When there are no
more rows nothing is returned, in case of an error a <tt>*nil*</tt> followed by an
error message is returned.

*This function is not binary safe.*

###  <a name="result_set:tuples" href="#result_set:tuples">`result_set:tuples() → iterator`</a>

Return an iterator that produces a tuple for each (remaining) row in the
result set. The tuples produced by the iterator are in the same order as the
column list in the SQL query, for example:

    > driver = assert(apr.dbd 'sqlite3')
    > assert(driver:open 'quotes.sqlite3')
    > results = assert(driver:select [[ SELECT author, quote FROM quotes ]])
    > for author, quote in results:tuples() do
    >>  print(author, 'wrote:')
    >>  print(quote)
    >>  print()
    >> end

*This function is not binary safe.*

###  <a name="result_set:pairs" href="#result_set:pairs">`result_set:pairs() → iterator`</a>

Return an iterator that produces a row number and a table with named fields
for each (remaining) row in the result set.

In Lua 5.2 you can also use `ipairs(result_set)`.

*This function is not binary safe.*

###  <a name="result_set:__len" href="#result_set:__len">`#result_set → num_tuples`</a>

Get the number of rows in a result set of a synchronous select. If the
results are asynchronous -1 is returned.

###  <a name="driver:close" href="#driver:close">`driver:close() → status`</a>

Close a connection to a backend.

## <a name="dbm_routines" href="#dbm_routines">DBM routines</a>

This module enables the creation and manipulation of [dbm] [dbm] databases.
If you've never heard of dbm before you can think of it as a Lua table that
only supports string keys and values but is backed by a file, so that you
can stop and restart your application and find the exact same contents.
This module supports the following libraries/implementations:

 - `'db'` for [Berkeley DB] [bdb] files
 - `'gdbm'` for GDBM files
 - `'ndbm'` for NDBM files
 - `'sdbm'` for SDBM files (the default)

The SDBM format is the default database format for Lua/APR because APR has
built-in support for SDBM while the other libraries need to be separately
installed. This is why not all types may be available at run time.

[dbm]: http://en.wikipedia.org/wiki/dbm
[bdb]: http://en.wikipedia.org/wiki/Berkeley_DB

###  <a name="apr.dbm_open" href="#apr.dbm_open">`apr.dbm_open(path [, mode [, permissions [, type ]]]) → dbm object`</a>

Open a [dbm] [dbm] file by <tt>*path*</tt>. On success a database object is returned,
otherwise a <tt>*nil*</tt> followed by an error message is returned. The following
<tt>*mode*</tt> strings are supported:

 - `'r'` to open an existing database for reading only (this is the default)
 - `'w'` to open an existing database for reading and writing
 - `'c'` to open a database for reading and writing, creating it if it
   doesn't exist
 - `'n'` to open a database for reading and writing, truncating it if it
   already exists

The [permissions](#file_system_permissions) string is documented elsewhere. Valid values for <tt>*type*</tt> are
listed in the introductory text for this module. Also note that the <tt>*path*</tt>
string may not be a real file name, as many [dbm] [dbm] packages append
suffixes for separate data and index files (see also
[apr.dbm\_getnames()](#apr.dbm_getnames)).

*This function is not binary safe.*

###  <a name="apr.dbm_getnames" href="#apr.dbm_getnames">`apr.dbm_getnames(path [, type]) → used1 [, used2]`</a>

If the specified <tt>*path*</tt> were passed to [apr.dbm\_open()](#apr.dbm_open), return the actual
pathnames which would be (created and) used. At most, two files may be used;
<tt>*used2*</tt> is <tt>*nil*</tt> if only one file is used. The [dbm] [dbm] file(s) don't need
to exist because this function only manipulates the pathnames. Valid values
for <tt>*type*</tt> are listed in the introductory text for this module.

*This function is not binary safe.*

###  <a name="dbm:exists" href="#dbm:exists">`dbm:exists(key) → status`</a>

Check whether the [dbm] [dbm] record with the given string <tt>*key*</tt> exists.

*This function is binary safe.*

###  <a name="dbm:fetch" href="#dbm:fetch">`dbm:fetch(key) → value`</a>

Fetch the [dbm] [dbm] record with the given string <tt>*key*</tt>. On success the
fetched value is returned as a string, if the key doesn't exist nothing is
returned and on error a <tt>*nil*</tt> followed by an error message is returned.

*This function is binary safe.*

###  <a name="dbm:store" href="#dbm:store">`dbm:store(key, value) → status`</a>

Store the [dbm] [dbm] record <tt>*value*</tt> (a string) by the given string <tt>*key*</tt>. On
success <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned.

*This function is binary safe.*

###  <a name="dbm:delete" href="#dbm:delete">`dbm:delete(key) → status`</a>

Delete the [dbm] [dbm] record with the given string <tt>*key*</tt>. On success <tt>*true*</tt> is
returned, otherwise a <tt>*nil*</tt> followed by an error message is returned.

*This function is binary safe.*

###  <a name="dbm:firstkey" href="#dbm:firstkey">`dbm:firstkey() → key`</a>

Retrieve the first record key from a [dbm] [dbm]. On success the first key
is returned as a string, when there are no keys nothing is returned. In case
of error a <tt>*nil*</tt> followed by an error message is returned.

*This function is binary safe.*

###  <a name="dbm:nextkey" href="#dbm:nextkey">`dbm:nextkey(key1) → key2`</a>

Retrieve the next record key from a [dbm] [dbm]. This function works just
like Lua's [next()](http://www.lua.org/manual/5.1/manual.html#pdf-next) function: On success the next key is returned as a
string, when there are no more keys nothing is returned. In case of error a
<tt>*nil*</tt> followed by an error message is returned.

*This function is binary safe.*

###  <a name="dbm:close" href="#dbm:close">`dbm:close() → status`</a>

Close a [dbm] [dbm] database handle and return <tt>*true*</tt> (this can't fail).

## <a name="environment_manipulation" href="#environment_manipulation">Environment manipulation</a>

Operating systems organize tasks into processes. One of the simplest means
of communication between processes is the use of environment variables. If
you're not familiar with environment variables, picture every process on
your computer having an associated Lua table with string key/value pairs.
When a process creates or overwrites a key/value pair only the table of that
process changes. When the process spawns a child process the child gets a
copy of the table which from that point onwards is no longer associated with
the parent process.

###  <a name="apr.env_get" href="#apr.env_get">`apr.env_get(name) → value`</a>

Get the value of the environment variable <tt>*name*</tt>. On success the string value
is returned. If the variable does not exist nothing is returned. Otherwise a
<tt>*nil*</tt> followed by an error message is returned.

*This function is not binary safe.*

###  <a name="apr.env_set" href="#apr.env_set">`apr.env_set(name, value) → status`</a>

Set the value of the environment variable <tt>*name*</tt> to the string <tt>*value*</tt>. On
success <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned.

*This function is not binary safe.*

###  <a name="apr.env_delete" href="#apr.env_delete">`apr.env_delete(name) → status`</a>

Delete the environment variable <tt>*name*</tt>. On success <tt>*true*</tt> is returned,
otherwise a <tt>*nil*</tt> followed by an error message is returned.

*This function is not binary safe.*

## <a name="file_path_manipulation" href="#file_path_manipulation">File path manipulation</a>

###  <a name="apr.filepath_root" href="#apr.filepath_root">`apr.filepath_root(path [, option, ...]) → root, path`</a>

Extract the root from the file path <tt>*path*</tt>. On success the extracted root and
the relative path following the root are returned, otherwise a <tt>*nil*</tt> followed
by an error message is returned. Either or both of the following options may
be given after <tt>*path*</tt>:

 - `'true-name'` verifies that the root exists and resolves its <tt>*true*</tt> case.
   If the root does not exist, a <tt>*nil*</tt> followed by an error message is
   returned
 - `'native'` uses the file system's native path format (e.g. path delimiters
   of `:` on MacOS9, <code>\\</code> on Win32, etc.) in the resulting root

These options only influence the resulting root. The path after the root is
returned as is. If you want to convert a whole file path to its <tt>*true*</tt> case
and/or native format use [apr.filepath\_merge()](#apr.filepath_merge) instead.

*This function is not binary safe.*

###  <a name="apr.filepath_parent" href="#apr.filepath_parent">`apr.filepath_parent(path [, option, ...]) → parent, filename`</a>

Split the file path <tt>*path*</tt> into its parent path and filename. This function
supports the same options as [apr.filepath\_root()](#apr.filepath_root). If any options are given
they're applied to <tt>*path*</tt> before it is split, so the options influence both
of the resulting values. If <tt>*path*</tt> is a filename and the `'true-name'` option
isn't given then the returned parent path will be an empty string.

*This function is not binary safe.*

###  <a name="apr.filepath_name" href="#apr.filepath_name">`apr.filepath_name(path [, split]) → filename [, extension]`</a>

Extract the filename (the final element) from the file path <tt>*path*</tt>. If <tt>*split*</tt>
evaluates <tt>*true*</tt> then the extension will be split from the filename and
returned separately. Some examples of what is considered a filename or an
extension:

    > -- regular file path
    > = apr.filepath_name('/usr/bin/lua', true)
    'lua', ''

    > -- hidden file on UNIX
    > = apr.filepath_name('/home/xolox/.vimrc', true)
    '.vimrc', ''

    > -- multiple extensions
    > = apr.filepath_name('index.html.en', true)
    'index.html', '.en'

*This function is not binary safe.*

###  <a name="apr.filepath_merge" href="#apr.filepath_merge">`apr.filepath_merge(root, path [, option, ...]) → merged`</a>

Merge the file paths <tt>*root*</tt> and <tt>*path*</tt>. On success the merged file path is
returned, otherwise a <tt>*nil*</tt> followed by an error message is returned. Any
combination of one or more of the following options may be given:

 - `'true-name'` resolves the <tt>*true*</tt> case of existing elements in <tt>*path*</tt>,
   resolving any aliases on Windows, and appends a trailing slash if the
   final element is a directory
 - `'native'` uses the file system's native path format (e.g. path delimiters
   of `:` on MacOS9, <code>\\</code> on Win32, etc.)
 - `'not-above-root'` fails if <tt>*path*</tt> is above <tt>*root*</tt>, e.g. if <tt>*root*</tt> is
   `/foo/bar` and <tt>*path*</tt> is `../baz`
 - `'not-absolute'` fails if the merged path is absolute
 - `'not-relative'` fails if the merged path is relative
 - `'secure-root'` fails if <tt>*path*</tt> is above <tt>*root*</tt>, even given the <tt>*root*</tt>
   `/foo/bar` and the <tt>*path*</tt> `../bar/bash`

This function can be used to generate absolute file paths as follows:

    apr.filepath_merge('.', 'filepath.c', 'not-relative')
    -- the above is equivalent to the below:
    apr.filepath_merge(apr.filepath_get(), 'filepath.c', 'not-relative')

*This function is not binary safe.*

###  <a name="apr.filepath_list_split" href="#apr.filepath_list_split">`apr.filepath_list_split(searchpath) → components`</a>

Split a search path string into a table of separate components. On success
the table of components is returned, otherwise a <tt>*nil*</tt> followed by an error
message is returned. Empty elements do not become part of the returned
table.

An example of a search path is the [$PATH] [path_var] environment variable
available in UNIX and Windows operating systems which controls the way
program names are resolved to absolute pathnames (see
[apr.filepath\_which()](#apr.filepath_which)).

[path_var]: http://en.wikipedia.org/wiki/PATH_(variable)

*This function is not binary safe.*

###  <a name="apr.filepath_list_merge" href="#apr.filepath_list_merge">`apr.filepath_list_merge(components) → searchpath`</a>

Merge a table of search path components into a single search path string. On
success the table of components is returned, otherwise a <tt>*nil*</tt> followed by an
error message is returned.

*This function is not binary safe.*

###  <a name="apr.filepath_get" href="#apr.filepath_get">`apr.filepath_get([native]) → path`</a>

Get the default filepath for relative filenames. If <tt>*native*</tt> evaluates <tt>*true*</tt>
the file system's native path format is used. On success the filepath is
returned, otherwise a <tt>*nil*</tt> followed by an error message is returned.

On at least Windows and UNIX the default file path for relative file names
is the current working directory. Because some operating systems supported
by APR don't use this convention Lua/APR uses the term 'default filepath'
instead.

*This function is not binary safe.*

###  <a name="apr.filepath_set" href="#apr.filepath_set">`apr.filepath_set(path) → status`</a>

Set the default file path for relative file names to the string <tt>*path*</tt>. On
success <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned. Also see the notes for [apr.filepath\_get()](#apr.filepath_get).

*This function is not binary safe.*

###  <a name="apr.filepath_which" href="#apr.filepath_which">`apr.filepath_which(program [, find_all]) → pathname`</a>

Find the full pathname of <tt>*program*</tt> by searching the directories in the
[$PATH] [path_var] environment variable and return the pathname of the
first program that's found. If <tt>*find_all*</tt> is <tt>*true*</tt> then a list with the
pathnames of all matching programs is returned instead.

[path_var]: http://en.wikipedia.org/wiki/PATH_%28variable%29


###  <a name="apr.filepath_executable" href="#apr.filepath_executable">`apr.filepath_executable(path) → is_executable`</a>

Check whether the file pointed to by <tt>*path*</tt> is executable.
Returns <tt>*true*</tt> when the file is executable, <tt>*false*</tt> otherwise.


## <a name="filename_matching" href="#filename_matching">Filename matching</a>

###  <a name="apr.fnmatch" href="#apr.fnmatch">`apr.fnmatch(pattern, input [, ignorecase]) → status`</a>

Try to match a string against a filename pattern. When the string matches
the pattern <tt>*true*</tt> is returned, otherwise <tt>*false*</tt>. The supported pattern items
are the following subset of shell wild cards:

 - `?` matches one character (any character)
 - `*` matches zero or more characters (any character)
 - `\x` escapes the special meaning of the character `x`
 - `[set]` matches one character within set. A range of characters can be
   specified by separating the characters of the range with a
   <code>-</code> character
 - `[^set]` matches the complement of set, where set is defined as above

If the optional argument <tt>*ignorecase*</tt> is <tt>*true*</tt>, characters are compared
case-insensitively.

*This function is not binary safe.*

###  <a name="apr.fnmatch_test" href="#apr.fnmatch_test">`apr.fnmatch_test(pattern) → status`</a>

Determine if a file path <tt>*pattern*</tt> contains one or more of the wild cards
that are supported by [apr.fnmatch()](#apr.fnmatch). On success <tt>*true*</tt> is returned,
otherwise <tt>*false*</tt>.

*This function is not binary safe.*

###  <a name="apr.glob" href="#apr.glob">`apr.glob(pattern [, ignorecase]) → iterator`</a>

Split <tt>*pattern*</tt> into a directory path and a filename pattern and return an
iterator which returns all filenames in the directory that match the
extracted filename pattern. The [apr.fnmatch()](#apr.fnmatch) function is used for
filename matching so the documentation there applies.

*This function is not binary safe.*


## <a name="directory_manipulation" href="#directory_manipulation">Directory manipulation</a>

###  <a name="apr.temp_dir_get" href="#apr.temp_dir_get">`apr.temp_dir_get() → path`</a>

Find an existing directory suitable as a temporary storage location. On
success the directory file path is returned, otherwise a <tt>*nil*</tt> followed by an
error message is returned.

*This function is not binary safe.*

###  <a name="apr.dir_make" href="#apr.dir_make">`apr.dir_make(path [, permissions]) → status`</a>

Create the directory <tt>*path*</tt> on the file system. On success <tt>*true*</tt> is returned,
otherwise a <tt>*nil*</tt> followed by an error message is returned. See the
documentation on [permissions](#file_system_permissions) for the optional second argument.

*This function is not binary safe.*

###  <a name="apr.dir_make_recursive" href="#apr.dir_make_recursive">`apr.dir_make_recursive(path [, permissions]) → status`</a>

Create the directory <tt>*path*</tt> on the file system, creating intermediate
directories as required. On success <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt>
followed by an error message is returned. See the documentation on
[permissions](#file_system_permissions) for the optional second argument.

*This function is not binary safe.*

###  <a name="apr.dir_remove" href="#apr.dir_remove">`apr.dir_remove(path) → status`</a>

Remove the *empty* directory <tt>*path*</tt> from the file system. On success <tt>*true*</tt>
is returned, otherwise a <tt>*nil*</tt> followed by an error message is returned.

*This function is not binary safe.*

###  <a name="apr.dir_remove_recursive" href="#apr.dir_remove_recursive">`apr.dir_remove_recursive(path) → status`</a>

Remove the directory <tt>*path*</tt> *and all its contents* from the file system.
On success <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned.

Note: This function isn't part of the Apache Portable Runtime but has been
implemented on top of it by the author of the Lua/APR binding. *It also
hasn't been properly tested yet*.

*This function is not binary safe.*

###  <a name="apr.dir_open" href="#apr.dir_open">`apr.dir_open(path) → directory handle`</a>

Open the directory <tt>*path*</tt> for reading. On success a directory object is
returned, otherwise a <tt>*nil*</tt> followed by an error message is returned.

*This function is not binary safe.*

###  <a name="directory:read" href="#directory:read">`directory:read([property, ...]) → value, ...`</a>

Return the requested properties for the next directory entry. On success the
requested properties are returned, otherwise a <tt>*nil*</tt> followed by an error
message is returned. This function implements the same interface as
[apr.stat()](#apr.stat).

###  <a name="directory:rewind" href="#directory:rewind">`directory:rewind() → status`</a>

Rewind the directory handle to start from the first entry. On success <tt>*true*</tt>
is returned, otherwise a <tt>*nil*</tt> followed by an error message is returned.

###  <a name="directory:entries" href="#directory:entries">`directory:entries([property, ...]) → iterator, directory handle`</a>

Return a function that iterates over the (remaining) directory entries and
returns the requested properties for each entry. If you don't request any
properties, a table with the available properties will be returned for each
directory entry:

    > directory = apr.dir_open 'examples'
    > for info in directory:entries() do print(info) end
    {
      type = 'file', name = 'webserver.lua',
      user = 'peter', group = 'peter', protection = 'rw-r--r--',
      size = 2789, csize = 4096, inode = 12455648, dev = 64514, nlink = 1,
      path = '/home/peter/Development/Lua/APR/examples/webserver.lua',
      mtime = 1293753884.3382, atime = 1293994993.3855, ctime = 1293753884.3382,
    }
    {
     type = 'file', name = 'download.lua',
     user = 'peter' group = 'peter', protection = 'rw-r--r--',
     size = 2580, csize = 4096, inode = 12455598, dev = 64514, nlink = 1,
     path = '/home/peter/Development/Lua/APR/examples/download.lua',
     mtime = 1293753884.3382, atime = 1293994993.3855, ctime = 1293753884.3382,
    }

This function implements the same interface as [apr.stat()](#apr.stat) with one
exception: If you pass property names to [directory:entries()](#directory:entries) that are not
available they will be returned as <tt>*false*</tt> instead of <tt>*nil*</tt> because of a
technical limitation in the [Lua iterator protocol] [iterators]:

> "On each iteration, the iterator function is called to
> produce a new value, stopping when this new value is <tt>*nil*</tt>."

[iterators]: http://www.lua.org/manual/5.1/manual.html#2.4.5

###  <a name="directory:close" href="#directory:close">`directory:close() → status`</a>

Close the directory handle. On success <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt>
followed by an error message is returned.

## <a name="file_i_o_handling" href="#file_i_o_handling">File I/O handling</a>

###  <a name="apr.file_link" href="#apr.file_link">`apr.file_link(source, target) → status`</a>

Create a [hard link] [hard_link] to the specified file. On success <tt>*true*</tt> is
returned, otherwise a <tt>*nil*</tt> followed by an error message is returned. Both
files must reside on the same device.

Please note that this function will only be available when the Lua/APR
binding is compiled against APR 1.4 or newer because the [apr\_file\_link()]
[apr_file_link] function wasn't available in earlier releases.

[hard_link]: http://en.wikipedia.org/wiki/Hard_link
[apr_file_link]: http://apr.apache.org/docs/apr/trunk/group__apr__file__io.html#ga7911275c0e97edc064b8167be658f9e

*This function is not binary safe.*

###  <a name="apr.file_copy" href="#apr.file_copy">`apr.file_copy(source, target [, permissions]) → status`</a>

Copy the file <tt>*source*</tt> to <tt>*target*</tt>. On success <tt>*true*</tt> is returned, otherwise a
<tt>*nil*</tt> followed by an error message is returned. The [permissions](#file_system_permissions) argument is
documented elsewhere. The new file does not need to exist, it will be
created if required. If the new file already exists, its contents will be
overwritten.

*This function is not binary safe.*

###  <a name="apr.file_append" href="#apr.file_append">`apr.file_append(source, target [, permissions]) → status`</a>

Append the file <tt>*source*</tt> to <tt>*target*</tt>. On success <tt>*true*</tt> is returned, otherwise a
<tt>*nil*</tt> followed by an error message is returned. The [permissions](#file_system_permissions) argument is
documented elsewhere. The new file does not need to exist, it will be
created if required.

*This function is not binary safe.*

###  <a name="apr.file_rename" href="#apr.file_rename">`apr.file_rename(source, target) → status`</a>

Rename the file <tt>*source*</tt> to <tt>*target*</tt>. On success <tt>*true*</tt> is returned, otherwise a
<tt>*nil*</tt> followed by an error message is returned. If a file exists at the new
location, then it will be overwritten. Moving files or directories across
devices may not be possible.

*This function is not binary safe.*

###  <a name="apr.file_remove" href="#apr.file_remove">`apr.file_remove(path) → status`</a>

Delete the file pointed to by <tt>*path*</tt>. On success <tt>*true*</tt> is returned, otherwise
a <tt>*nil*</tt> followed by an error message is returned. If the file is open, it
won't be removed until all instances of the file are closed.

*This function is not binary safe.*

###  <a name="apr.file_truncate" href="#apr.file_truncate">`apr.file_truncate(path [, offset]) → status`</a>

Truncate the file's length to the specified <tt>*offset*</tt> (defaults to 0). On
success <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned.


###  <a name="apr.file_mtime_set" href="#apr.file_mtime_set">`apr.file_mtime_set(path, mtime) → status`</a>

Set the last modified time of the file pointed to by <tt>*path*</tt> to <tt>*mtime*</tt>. On
success <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned.

*This function is not binary safe.*

###  <a name="apr.file_attrs_set" href="#apr.file_attrs_set">`apr.file_attrs_set(path, attributes) → status`</a>

Set the attributes of the file pointed to by <tt>*path*</tt>. On success <tt>*true*</tt> is
returned, otherwise a <tt>*nil*</tt> followed by an error message is returned.

The table <tt>*attributes*</tt> should consist of string keys and boolean values. The
supported attributes are `readonly`, `hidden` and `executable`.

This function should be used in preference to explicit manipulation of the
file permissions, because the operations to provide these attributes are
platform specific and may involve more than simply setting permission bits.

*This function is not binary safe.*

###  <a name="apr.file_perms_set" href="#apr.file_perms_set">`apr.file_perms_set(path, permissions) → status`</a>

Set the permissions of the file specified by <tt>*path*</tt>. On success <tt>*true*</tt> is
returned, otherwise a <tt>*nil*</tt> followed by an error message is returned.

Warning: Some platforms may not be able to apply all of the available
permission bits, in this case a third value `'INCOMPLETE'` is returned (see
[error handling](#error_handling)).

*This function is not binary safe.*

###  <a name="apr.stat" href="#apr.stat">`apr.stat(path [, property, ...]) → value, ...`</a>

Get the status of the file pointed to by <tt>*path*</tt>. On success, if no properties
are given a table of property name/value pairs is returned, otherwise the
named properties are returned in the same order as the arguments. On failure
a <tt>*nil*</tt> followed by an error message is returned.

The following fields are supported:

 - `name` is a string containing the name of the file in proper case
 - `path` is a string containing the absolute pathname of the file
 - `type` is one of the strings `'directory'`, `'file'`, `'link'`, `'pipe'`,
   `'socket'`, `'block device'`, `'character device'` or `'unknown'`
 - `user` is a string containing the name of user that owns the file
 - `group` is a string containing the name of the group that owns the file
 - `size` is a number containing the size of the file in bytes
 - `csize` is a number containing the storage size consumed by the file
 - `ctime` is the time the file was created, or the inode was last changed
 - `atime` is the time the file was last accessed
 - `mtime` is the time the file was last modified
 - `nlink` is the number of hard links to the file
 - `inode` is a unique number within the file system on which the file
   resides
 - `dev` is a number identifying the device on which the file is stored
 - `protection` is a 9 character string with the file system [permissions](#file_system_permissions)
 - `link` *is a special flag that does not return a field*, instead it is
   used to signal that symbolic links should not be followed, i.e. the
   status of the link itself should be returned

Here are some examples:

    > -- Here's an example of a table with all properties:
    > = apr.stat('lua-5.1.4.tar.gz')
    {
     name = 'lua-5.1.4.tar.gz',
     path = 'lua-5.1.4.tar.gz',
     type = 'file',
     user = 'peter',
     group = 'peter',
     size = 216679,
     csize = 217088,
     ctime = 1284159662.7264,
     atime = 1287954158.6019,
     mtime = 1279317348.194,
     nlink = 1,
     inode = 1838576,
     dev  = 64514,
     protection = 'rw-r--r--',
    }
    > -- To check whether a directory exists:
    > function isdir(p) return apr.stat(p, 'type') == 'directory' end
    > = isdir('.')
    true
    > -- To get a file's size in bytes:
    > function filesize(p) return apr.stat(p, 'size') end
    > = filesize('lua-5.1.4.tar.gz')
    216679

*This function is not binary safe.*

###  <a name="apr.file_open" href="#apr.file_open">`apr.file_open(path [, mode [, permissions]]) → file`</a>

<em>This function imitates Lua's [io.open()](http://www.lua.org/manual/5.1/manual.html#pdf-io.open) function with one exception: On
UNIX you can pass a file descriptor (number) instead of a path string (see
also [file:fd\_get()](#file:fd_get)). Now follows the documentation for [io.open()](http://www.lua.org/manual/5.1/manual.html#pdf-io.open):</em>

This function opens a file, in the mode specified in the string <tt>*mode*</tt>. It
returns a new file handle, or, in case of errors, <tt>*nil*</tt> plus an error
message. The <tt>*mode*</tt> string can be any of the following:

 - `'r'`: read mode (the default)
 - `'w'`: write mode
 - `'a'`: append mode
 - `'r+'`: update mode, all previous data is preserved
 - `'w+'`: update mode, all previous data is erased
 - `'a+'`: append update mode, previous data is preserved, writing is only
   allowed at the end of file

The <tt>*mode*</tt> string may also have a `b` at the end, which is needed in some
systems to open the file in binary mode. This string is exactly what is used
in the standard C function [fopen()] [fopen]. The [permissions](#file_system_permissions) argument is
documented elsewhere.

[fopen]: http://linux.die.net/man/3/fopen

*This function is not binary safe.*

###  <a name="file:stat" href="#file:stat">`file:stat([field, ...]) → value, ...`</a>

This method works like [apr.stat()](#apr.stat) except that it uses a file handle
instead of a filepath to access the file.

###  <a name="file:lines" href="#file:lines">`file:lines() → iterator`</a>

_This function implements the interface of the [file:lines()] [flines] function described in the Lua 5.1 reference manual. Here is the description from the reference manual:_

Return an iterator function that, each time it is called, returns a new line read from the file. Therefore, the construction

    for line in file:lines() do body end

will iterate over all lines. This function does not close the file when the loop ends.

[flines]: http://www.lua.org/manual/5.1/manual.html#pdf-file:lines

###  <a name="file:truncate" href="#file:truncate">`file:truncate([offset]) → status`</a>

Truncate the file's length to the specified <tt>*offset*</tt> (defaults to 0). On
success <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned. Note that the read/write file offset is repositioned to the
selected offset.

###  <a name="file:read" href="#file:read">`file:read([format, ...]) → mixed value, ...`</a>

_This function implements the interface of the [file:read()] [fread] function described in the Lua 5.1 reference manual. Here is the description from the reference manual:_

Read from file, according to the given formats, which specify what to read. For each format, the function returns a string (or a number) with the characters read, or <tt>*nil*</tt> if it cannot read data with the specified format. When called without formats, it uses a default format that reads the entire next line (see below).

The available formats are:

 - `'*n'`: reads a number; this is the only format that returns a number instead of a string
 - `'*a'`: reads all data from the file, starting at the current position. On end of input, it returns the empty string
 - `'*l'`: reads the next line (skipping the end of line), returning <tt>*nil*</tt> on end of input (this is the default format)
 - `number`: reads a string with up to this number of characters, returning <tt>*nil*</tt> on end of input. If number is zero, it reads nothing and returns an empty string, or <tt>*nil*</tt> on end of input

[fread]: http://www.lua.org/manual/5.1/manual.html#pdf-file:read

###  <a name="file:write" href="#file:write">`file:write(value [, ...]) → status`</a>

_This function implements the interface of the [file:write()] [fwrite] function described in the Lua 5.1 reference manual. Here is the description from the reference manual:_

Write the value of each argument to file. The arguments must be strings or numbers. To write other values, use [tostring()](http://www.lua.org/manual/5.1/manual.html#pdf-tostring) or [string.format()](http://www.lua.org/manual/5.1/manual.html#pdf-string.format) before this function.

[fwrite]: http://www.lua.org/manual/5.1/manual.html#pdf-file:write

###  <a name="file:seek" href="#file:seek">`file:seek([whence [, offset]]) → offset`</a>

_This function implements the interface of the [file:seek()] [fseek] function described in the Lua 5.1 reference manual. Here is the description from the reference manual:_

Sets and gets the file position, measured from the beginning of the file, to
the position given by <tt>*offset*</tt> plus a base specified by the string <tt>*whence*</tt>, as
follows:

 - `'set'`:  base is position 0 (beginning of the file)
 - `'cur'`:  base is current position
 - `'end'`:  base is end of file

In case of success, function `seek` returns the final file position, measured
in bytes from the beginning of the file. If this function fails, it returns
<tt>*nil*</tt>, plus a string describing the error.

The default value for <tt>*whence*</tt> is `'cur'`, and for offset is 0. Therefore, the
call [file:seek()](#file:seek) returns the current file position, without changing it; the
call `file:seek('set')` sets the position to the beginning of the file (and
returns 0); and the call `file:seek('end')` sets the position to the end of the
file, and returns its size.

[fseek]: http://www.lua.org/manual/5.1/manual.html#pdf-file:seek

###  <a name="file:flush" href="#file:flush">`file:flush() → status`</a>

Saves any written data to <tt>*file*</tt>. On success <tt>*true*</tt> is returned, otherwise a
<tt>*nil*</tt> followed by an error message is returned.

###  <a name="file:lock" href="#file:lock">`file:lock(type [, nonblocking ]) → status`</a>

Establish a lock on the open file <tt>*file*</tt>. On success <tt>*true*</tt> is returned,
otherwise a <tt>*nil*</tt> followed by an error message is returned. The <tt>*type*</tt> must be
one of:

 - `'shared'`: Shared lock. More than one process or thread can hold a
   shared lock at any given time. Essentially, this is a "read lock",
   preventing writers from establishing an exclusive lock
 - `'exclusive'`: Exclusive lock. Only one process may hold an exclusive
   lock at any given time. This is analogous to a "write lock"

If <tt>*nonblocking*</tt> is <tt>*true*</tt> the call will not block while acquiring the file
lock.

The lock may be advisory or mandatory, at the discretion of the platform.
The lock applies to the file as a whole, rather than a specific range. Locks
are established on a per-thread/process basis; a second lock by the same
thread will not block.

###  <a name="file:unlock" href="#file:unlock">`file:unlock() → status`</a>

Remove any outstanding locks on the file. On success <tt>*true*</tt> is returned,
otherwise a <tt>*nil*</tt> followed by an error message is returned.

###  <a name="pipe:timeout_get" href="#pipe:timeout_get">`pipe:timeout_get() → timeout`</a>

Get the timeout value or blocking state of <tt>*pipe*</tt>. On success the timeout
value is returned, otherwise a <tt>*nil*</tt> followed by an error message is returned.

The <tt>*timeout*</tt> <tt>*true*</tt> means wait forever, <tt>*false*</tt> means don't wait at all and a
number is the microseconds to wait.

###  <a name="pipe:timeout_set" href="#pipe:timeout_set">`pipe:timeout_set(timeout) → status`</a>

Set the timeout value or blocking state of <tt>*pipe*</tt>. On success <tt>*true*</tt> is
returned, otherwise a <tt>*nil*</tt> followed by an error message is returned.

The <tt>*timeout*</tt> <tt>*true*</tt> means wait forever, <tt>*false*</tt> means don't wait at all and a
number is the microseconds to wait. For example:

    -- Configure read end of pipe to block for a maximum of 5 seconds.
    pipe:timeout_set(1000000 * 5)
    for line in pipe:lines() do
      print(line)
    end

###  <a name="file:fd_get" href="#file:fd_get">`file:fd_get() → fd`</a>

Get the underlying [file descriptor] [fildes] for this file. On success a
number is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned.

To convert a file descriptor into a Lua/APR file object you can pass the
file descriptor (number) to [apr.file\_open()](#apr.file_open) instead of the pathname.

Note that this function is only available on platforms where file
descriptors are numbers (this includes UNIX and excludes Windows).

###  <a name="file:inherit_set" href="#file:inherit_set">`file:inherit_set() → status`</a>

Set a file to be inherited by child processes. By default, file descriptors
will not be inherited by child processes created by [apr.proc\_create()](#apr.proc_create).

At the time of writing this [seems to only apply to UNIX] [inherit] where
APR will close all open file handles after performing a [fork()] [fork]
unless you explicitly set your files to be inheritable.

[inherit]: http://marc.info/?l=apache-httpd-dev&m=104361635329125&w=2

###  <a name="file:inherit_unset" href="#file:inherit_unset">`file:inherit_unset() → status`</a>

Unset a file from being inherited by child processes.

###  <a name="file:close" href="#file:close">`file:close() → status`</a>

Close <tt>*file*</tt>. On success <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed by an
error message is returned.

## <a name="network_i_o_handling" href="#network_i_o_handling">Network I/O handling</a>

To get started with network programming using the Lua/APR binding, have a
look at any of the following examples:

 - [HTTP client](#example_http_client)
 - [Single threaded webserver](#example_single_threaded_webserver)
 - [Multi threaded webserver](#example_multi_threaded_webserver)
 - [Asynchronous webserver](#example_asynchronous_webserver)

###  <a name="apr.socket_create" href="#apr.socket_create">`apr.socket_create([protocol [, family]]) → socket`</a>

Create a network socket. On success the new socket object is returned,
otherwise a <tt>*nil*</tt> followed by an error message is returned. Valid values for
the <tt>*protocol*</tt> argument are:

 - `'tcp'` to create a [TCP] [tcp] socket (this is the default)
 - `'udp'` to create a [UDP] [udp] socket

These are the valid values for the <tt>*family*</tt> argument:

 - `'inet'` to create a socket using the [IPv4] [ipv4] address family (this
   is the default)
 - `'inet6'` to create a socket using the [IPv6] [ipv6] address family
 - `'unspec'` to pick the system default type

Note that `'inet6'` is only supported when `apr.socket_supports_ipv6` is
<tt>*true*</tt>.

[tcp]: http://en.wikipedia.org/wiki/Transmission_Control_Protocol
[udp]: http://en.wikipedia.org/wiki/User_Datagram_Protocol
[ipv4]: http://en.wikipedia.org/wiki/IPv4
[ipv6]: http://en.wikipedia.org/wiki/IPv6

###  <a name="apr.hostname_get" href="#apr.hostname_get">`apr.hostname_get() → name`</a>

Get the name of the current machine. On success the host name string is
returned, otherwise a <tt>*nil*</tt> followed by an error message is returned.

*This function is not binary safe.*

###  <a name="apr.host_to_addr" href="#apr.host_to_addr">`apr.host_to_addr(hostname [, family]) → ip_address, ...`</a>

Resolve a host name to one or more IP addresses. On success one or more IP
addresses are returned as strings, otherwise a <tt>*nil*</tt> followed by an error
message is returned. The optional <tt>*family*</tt> argument is documented under
[apr.socket\_create()](#apr.socket_create).

    > = apr.host_to_addr 'www.lua.org'
    '89.238.129.35'
    > = apr.host_to_addr 'google.com'
    '173.194.65.104' '173.194.65.106' '173.194.65.147' '173.194.65.103' '173.194.65.105' '173.194.65.99'
    > = apr.host_to_addr('ipv6.google.com', 'inet6')
    '2a00:1450:8005::67'

*This function is not binary safe.*

###  <a name="apr.addr_to_host" href="#apr.addr_to_host">`apr.addr_to_host(ip_address [, family]) → hostname`</a>

Look up the host name from an IP-address (also known as a reverse [DNS]
[dns] lookup). On success the host name is returned as a string, otherwise a
<tt>*nil*</tt> followed by an error message is returned. The optional <tt>*family*</tt> argument
is documented under [apr.socket\_create()](#apr.socket_create).

    > = apr.addr_to_host '89.238.129.35'
    'flounder.pepperfish.net'

[dns]: http://en.wikipedia.org/wiki/Domain_Name_System

*This function is not binary safe.*

###  <a name="socket:connect" href="#socket:connect">`socket:connect(host, port) → status`</a>

Issue a connection request to a socket either on the same machine or a
different one, as indicated by the <tt>*host*</tt> string and <tt>*port*</tt> number. On success
<tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned.

*This function is not binary safe.*

###  <a name="socket:bind" href="#socket:bind">`socket:bind(host, port) → status`</a>

Bind the socket to the given <tt>*host*</tt> string and <tt>*port*</tt> number. On success <tt>*true*</tt>
is returned, otherwise a <tt>*nil*</tt> followed by an error message is returned. The
special <tt>*host*</tt> value `'*'` can be used to select the default 'any' address.
For example if you want to create a web server you can start with the
following:

    -- Basic single threaded server
    server = assert(apr.socket_create())
    assert(server:bind('*', 80))
    assert(server:listen(10))
    while true do
      local client = assert(server:accept())
      -- Here you can receive data from the client by calling client:read()
      -- and send data to the client by calling client:write()
    end

This function can fail if you try to bind a port below 1000 without
superuser privileges or if another process is already bound to the given
port number.

*This function is not binary safe.*

###  <a name="socket:listen" href="#socket:listen">`socket:listen(backlog) → status`</a>

To listen for incoming network connections three steps must be performed:

1. First a socket is created with [apr.socket\_create()](#apr.socket_create)
2. Next a willingness to accept incoming connections and a queue limit for
   incoming connections are specified with [socket:listen()](#socket:listen) (this call
   doesn't block)
3. Finally [socket:accept()](#socket:accept) is called to wait for incoming connections

On success <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned. The <tt>*backlog*</tt> argument indicates the number of outstanding
connections allowed in the socket's listen queue. If this value is less than
zero, the listen queue size is set to zero. As a special case, if you pass
the string `'max'` as <tt>*backlog*</tt> then a platform specific maximum value is
chosen based on the compile time constant [SOMAXCONN] [SOMAXCONN].

[SOMAXCONN]: http://www.google.com/search?q=SOMAXCONN

###  <a name="socket:recvfrom" href="#socket:recvfrom">`socket:recvfrom([bufsize]) → address, data`</a>

Read data from an [UDP] [udp] socket that has been bound to an interface
and/or port. On success two values are returned: A table with the address of
the peer from which the data was sent and a string with the received data.
If the call fails it returns <tt>*nil*</tt> followed by an error message.

By default <tt>*bufsize*</tt> is 1024, this means the resulting <tt>*data*</tt> string will be
truncated to a maximum of 1024 bytes. If you want to receive larger
messages, pass a larger <tt>*bufsize*</tt>.

The returned <tt>*address*</tt> table contains the following fields:

 - `address` is the IP address (a string)
 - `port` is the port number
 - `family` is one of the strings `'inet'`, `'inet6'` or `'unspec'`

*This function is binary safe.*

[udp]: http://en.wikipedia.org/wiki/User_Datagram_Protocol

###  <a name="socket:accept" href="#socket:accept">`socket:accept() → client_socket`</a>

Accept a connection request on a server socket. On success a socket is
returned which forms the connection to the client, otherwise a <tt>*nil*</tt> followed
by an error message is returned. This function blocks until a client
connects.

###  <a name="socket:read" href="#socket:read">`socket:read([format, ...]) → mixed value, ...`</a>

_This function implements the interface of the [file:read()] [fread] function described in the Lua 5.1 reference manual. Here is the description from the reference manual:_

Read from socket, according to the given formats, which specify what to read. For each format, the function returns a string (or a number) with the characters read, or <tt>*nil*</tt> if it cannot read data with the specified format. When called without formats, it uses a default format that reads the entire next line (see below).

The available formats are:

 - `'*n'`: reads a number; this is the only format that returns a number instead of a string
 - `'*a'`: reads all data from the socket, starting at the current position. On end of input, it returns the empty string
 - `'*l'`: reads the next line (skipping the end of line), returning <tt>*nil*</tt> on end of input (this is the default format)
 - `number`: reads a string with up to this number of characters, returning <tt>*nil*</tt> on end of input. If number is zero, it reads nothing and returns an empty string, or <tt>*nil*</tt> on end of input

[fread]: http://www.lua.org/manual/5.1/manual.html#pdf-file:read

###  <a name="socket:write" href="#socket:write">`socket:write(value [, ...]) → status`</a>

_This function implements the interface of the [file:write()] [fwrite] function described in the Lua 5.1 reference manual. Here is the description from the reference manual:_

Write the value of each argument to socket. The arguments must be strings or numbers. To write other values, use [tostring()](http://www.lua.org/manual/5.1/manual.html#pdf-tostring) or [string.format()](http://www.lua.org/manual/5.1/manual.html#pdf-string.format) before this function.

[fwrite]: http://www.lua.org/manual/5.1/manual.html#pdf-file:write

###  <a name="socket:lines" href="#socket:lines">`socket:lines() → iterator`</a>

_This function implements the interface of the [file:lines()] [flines] function described in the Lua 5.1 reference manual. Here is the description from the reference manual:_

Return an iterator function that, each time it is called, returns a new line read from the socket. Therefore, the construction

    for line in socket:lines() do body end

will iterate over all lines. This function does not close the socket when the loop ends.

[flines]: http://www.lua.org/manual/5.1/manual.html#pdf-file:lines

###  <a name="socket:timeout_get" href="#socket:timeout_get">`socket:timeout_get() → timeout`</a>

Get the timeout value or blocking state of <tt>*socket*</tt>. On success the timeout
value is returned, otherwise a <tt>*nil*</tt> followed by an error message is returned.

The <tt>*timeout*</tt> <tt>*true*</tt> means wait forever, <tt>*false*</tt> means don't wait at all and a
number is the microseconds to wait.

###  <a name="socket:timeout_set" href="#socket:timeout_set">`socket:timeout_set(timeout) → status`</a>

Set the timeout value or blocking state of <tt>*socket*</tt>. On success <tt>*true*</tt> is
returned, otherwise a <tt>*nil*</tt> followed by an error message is returned.

The <tt>*timeout*</tt> <tt>*true*</tt> means wait forever, <tt>*false*</tt> means don't wait at all and a
number is the microseconds to wait.

###  <a name="socket:opt_get" href="#socket:opt_get">`socket:opt_get(name) → value`</a>

Query socket options for the specified socket. Valid values for <tt>*name*</tt> are:

 - `'debug'`: turn on debugging information
 - `'keep-alive'`: keep connections active
 - `'linger'`: lingers on close if data is present
 - `'non-block'`: turns blocking on/off for socket
 - `'reuse-addr'`: the rules used in validating addresses supplied to bind
   should allow reuse of local addresses
 - `'sndbuf'`: set the send buffer size
 - `'rcvbuf'`: set the receive buffer size
 - `'disconnected'`: query the disconnected state of the socket (currently only used on Windows)

The `'sndbuf'` and `'rcvbuf'` options have integer values, all other options
have a boolean value.

###  <a name="socket:opt_set" href="#socket:opt_set">`socket:opt_set(name, value) → status`</a>

Setup socket options for the specified socket. Valid values for <tt>*name*</tt> are
documented under [socket:opt\_get()](#socket:opt_get), <tt>*value*</tt> should be a boolean or integer
value. On success <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed by an error
message is returned.

###  <a name="socket:addr_get" href="#socket:addr_get">`socket:addr_get([type]) → ip_address, port [, hostname]`</a>

Get one of the IP-address / port pairs associated with <tt>*socket*</tt>, according to
<tt>*type*</tt>:

 - `'local'` to get the address/port to which the socket is bound locally
 - `'remote'` to get the address/port of the peer to which the socket is
   connected (this is the default)

On success the local or remote IP-address (a string) and the port (a number)
are returned, otherwise a <tt>*nil*</tt> followed by an error message is returned. If a
host name is available that will be returned as the third value.

*This function is not binary safe.*

###  <a name="socket:fd_get" href="#socket:fd_get">`socket:fd_get() → fd`</a>

Get the underlying [file descriptor] [fildes] for this socket. On success a
number is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned.

[fildes]: http://en.wikipedia.org/wiki/File_descriptor

###  <a name="socket:fd_set" href="#socket:fd_set">`socket:fd_set(fd) → status`</a>

Set the underlying file descriptor (a number) of an existing socket. On
success <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned.

###  <a name="socket:shutdown" href="#socket:shutdown">`socket:shutdown(mode) → status`</a>

Shutdown either reading, writing, or both sides of a socket. On success <tt>*true*</tt>
is returned, otherwise a <tt>*nil*</tt> followed by an error message is returned. Valid
values for <tt>*mode*</tt> are:

 - `'read'`: no longer allow read requests
 - `'write'`: no longer allow write requests
 - `'both'`: no longer allow read or write requests

This does not actually close the socket descriptor, it just controls which
calls are still valid on the socket. To close sockets see [socket:close()](#socket:close).

###  <a name="socket:close" href="#socket:close">`socket:close() → status`</a>

Close <tt>*socket*</tt>. On success <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed by an
error message is returned.

## <a name="pipe_i_o_handling" href="#pipe_i_o_handling">Pipe I/O handling</a>

Lua/APR represents [pipes] [pipeline] as files just like Lua's standard
library function [io.popen()](http://www.lua.org/manual/5.1/manual.html#pdf-io.popen) does because it works fairly well, however
there are some differences between files and pipes which impact the API:

 - File objects implement [pipe:timeout\_get()](#pipe:timeout_get) and [pipe:timeout\_set()](#pipe:timeout_set) even
 though these methods only make sense for pipe objects

 - Pipe objects implement [file:seek()](#file:seek) but don't support it

One of the reasons that file/pipe support is so interwoven in APR and thus
Lua/APR is that you can create a named pipe with [apr.namedpipe\_create()](#apr.namedpipe_create)
and access it using [apr.file\_open()](#apr.file_open) and APR won't know or even care that
you're reading/writing a pipe instead of a file.

[pipeline]: http://en.wikipedia.org/wiki/Pipeline_(Unix)

###  <a name="apr.pipe_open_stdin" href="#apr.pipe_open_stdin">`apr.pipe_open_stdin() → pipe`</a>

Open standard input as a pipe. On success the pipe is returned, otherwise a
<tt>*nil*</tt> followed by an error message is returned.

###  <a name="apr.pipe_open_stdout" href="#apr.pipe_open_stdout">`apr.pipe_open_stdout() → pipe`</a>

Open standard output as a pipe. On success the pipe is returned, otherwise a
<tt>*nil*</tt> followed by an error message is returned.

###  <a name="apr.pipe_open_stderr" href="#apr.pipe_open_stderr">`apr.pipe_open_stderr() → pipe`</a>

Open standard error as a pipe. On success the pipe is returned, otherwise a
<tt>*nil*</tt> followed by an error message is returned.

###  <a name="apr.namedpipe_create" href="#apr.namedpipe_create">`apr.namedpipe_create(name [, permissions]) → status`</a>

Create a [named pipe] [named_pipe]. On success <tt>*true*</tt> is returned, otherwise a
<tt>*nil*</tt> followed by an error message is returned. The [permissions](#file_system_permissions) argument is
documented elsewhere.

Named pipes can be used for interprocess communication:

1. Check if the named pipe already exists, if it doesn't then create it
2. Have each process access the named pipe using [apr.file\_open()](#apr.file_open)
3. Communicate between the two processes over the read/write ends of the
   named pipe and close it when the communication is finished.

Note that APR supports named pipes on UNIX but not on Windows. If you try
anyhow the error message "This function has not been implemented on this
platform" is returned.

[named_pipe]: http://en.wikipedia.org/wiki/Named_pipe

*This function is not binary safe.*

###  <a name="apr.pipe_create" href="#apr.pipe_create">`apr.pipe_create() → input, output`</a>

Create an [anonymous pipe] [anon_pipe]. On success the write and read ends
of the pipe are returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned. There's an example use of this function in the documentation for
[process:in\_set()](#process:in_set).

[anon_pipe]: http://en.wikipedia.org/wiki/Anonymous_pipe

## <a name="ldap_connection_handling" href="#ldap_connection_handling">LDAP connection handling</a>

The Lightweight Directory Access Protocol ([LDAP] [ldap]) enables querying
and modifying data hosted on [directory servers] [dirs]. LDAP databases are
similar to [relational databases] [reldbs] in the sense that both types of
databases store records with attributes and allow clients to search records
based on those attributes. Notable differences between LDAP and relational
databases are that LDAP stores all records in a [hierarchy] [hierarchy] and
records can have an arbitrary number of attributes. LDAP is frequently used
by (large) organizations to provide a centralized address book for all
employees and to store system account information like user names and
passwords in a central place (one piece of the puzzle towards [roaming
profiles] [roaming]).

This module is based on [LuaLDAP] [lualdap] by Roberto Ierusalimschy, André
Carregal and Tomás Guisasola.

[ldap]: http://en.wikipedia.org/wiki/LDAP
[dirs]: http://en.wikipedia.org/wiki/Directory_(databases)
[reldbs]: http://en.wikipedia.org/wiki/Relational_database
[hierarchy]: http://en.wikipedia.org/wiki/Hierarchical_database_model
[roaming]: http://en.wikipedia.org/wiki/Roaming_user_profile
[lualdap]: http://www.keplerproject.org/lualdap/

###  <a name="apr.ldap" href="#apr.ldap">`apr.ldap([url [, secure ]]) → ldap_conn`</a>

Create an LDAP connection. The <tt>*url*</tt> argument is a URL string with the
following components:

 - One of the URL schemes `ldap://` (the default) or `ldaps://` (for secure
   connections)
 - The host name or IP-address of the LDAP server (defaults to 127.0.0.1)
 - An optional port number (defaults to 389)

If <tt>*secure*</tt> is <tt>*true*</tt> the connection will use [STARTTLS] [starttls] even if the
URL scheme is `ldap://`. On success an LDAP connection object is returned,
otherwise a <tt>*nil*</tt> followed by an error message is returned.

[starttls]: http://en.wikipedia.org/wiki/STARTTLS

###  <a name="apr.ldap_info" href="#apr.ldap_info">`apr.ldap_info() → string`</a>

This function returns a string describing the LDAP [SDK] [sdk] (library)
currently in use. On success a string is returned, otherwise a <tt>*nil*</tt> followed
by an error message is returned. The resulting string is intended to be
displayed to the user, it's not meant to be parsed (although you can of
course decide to do this :-). According to [apr_ldap.h] [ldap_docs] the
following LDAP SDKs can be used:

 - Netscape (I assume this been superseded by the Mozilla SDK below)
 - Solaris
 - [Novell](http://www.novell.com/developer/ndk/ldap_libraries_for_c.html)
 - [Mozilla](https://wiki.mozilla.org/Directory)
 - [OpenLDAP](http://www.openldap.org/software/man.cgi?query=ldap)
 - [Microsoft] [ms_ldap_sdk]
 - [Tivoli](http://en.wikipedia.org/wiki/IBM_Tivoli_Directory_Server)
 - [zOS](http://www.lsu.edu/departments/ocs/tsc/ldap/ldappref.html)
 - 'Others' (implying there is support for other SDKs?)

[sdk]: http://en.wikipedia.org/wiki/Software_development_kit
[ms_ldap_sdk]: http://msdn.microsoft.com/en-us/library/aa367008(v=vs.85).aspx
[ldap_docs]: http://apr.apache.org/docs/apr/trunk/group___a_p_r___util___l_d_a_p.html

###  <a name="apr.ldap_url_parse" href="#apr.ldap_url_parse">`apr.ldap_url_parse(string) → table`</a>

Parse an [LDAP URL] [ldap_urls] into a table of URL components. On success a
table is returned, otherwise a <tt>*nil*</tt> followed by an error message and one of
the following strings is returned:

 - **MEM**: can't allocate memory space
 - **PARAM**: parameter is bad
 - **BADSCHEME**: URL doesn't begin with `ldap://`, `ldapi://` or `ldaps://`
 - **BADENCLOSURE**: URL is missing trailing `>`
 - **BADURL**: URL is bad
 - **BADHOST**: host port is bad
 - **BADATTRS**: bad (or missing) attributes
 - **BADSCOPE**: scope string is invalid (or missing)
 - **BADFILTER**: bad or missing filter
 - **BADEXTS**: bad or missing extensions

LDAP URLs look like this:

    ldap[is]://host:port[/[dn[?[attributes][?[scope][?[filter][?exts]]]]]]

Where:

 - <tt>*attributes*</tt> is a comma separated list
 - <tt>*scope*</tt> is one of the three strings **base**, **one** or **sub** (the default is **base**)
 - <tt>*filter*</tt> is an string-represented filter as in RFC 2254

For example:

    > = apr.ldap_url_parse 'ldap://root.openldap.org/dc=openldap,dc=org'
    {
      scheme = 'ldap',
      host = 'root.openldap.org',
      port = 389,
      scope = 'sub',
      dn = 'dc=openldap,dc=org',
      crit_exts = 0,
    }

[ldap_urls]: http://en.wikipedia.org/wiki/LDAP#LDAP_URLs

###  <a name="apr.ldap_url_check" href="#apr.ldap_url_check">`apr.ldap_url_check(url) → type`</a>

Checks whether the given URL is an LDAP URL. On success one of the strings
below is returned, otherwise <tt>*nil*</tt> is returned:

 - **ldap** for regular LDAP URLs (`ldap://`)
 - **ldapi** for socket LDAP URLs (`ldapi://`)
 - **ldaps** for SSL LDAP URLs (`ldaps://`)

###  <a name="ldap_conn:bind" href="#ldap_conn:bind">`ldap_conn:bind([who [, passwd]]) → status`</a>

Bind to the LDAP directory. If no arguments are given an anonymous bind is
attempted, otherwise <tt>*who*</tt> should be a string with the relative distinguished
name (RDN) of the user in the form `'cn=admin,dc=example,dc=com'`. On
success <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned.

###  <a name="ldap_conn:unbind" href="#ldap_conn:unbind">`ldap_conn:unbind() → status`</a>

Unbind from the directory. On success <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt>
followed by an error message is returned.

###  <a name="ldap_conn:option_get" href="#ldap_conn:option_get">`ldap_conn:option_get(name) → value`</a>

Get an LDAP option by its <tt>*name*</tt> (one of the strings documented below). On
success the option value is returned, otherwise a <tt>*nil*</tt> followed by an error
message is returned. These are the supported LDAP options:

 - **defbase** (string)
 - **deref** (integer)
 - **network-timeout** (fractional number of seconds)
 - **protocol-version** (integer)
 - **refhop-limit** (integer)
 - **referral-urls** (list of strings)
 - **referrals** (boolean)
 - **restart** (boolean)
 - **size-limit** (integer)
 - **time-limit** (integer)
 - **timeout** (fractional number of seconds)
 - **uri** (string with space separated URIs)

###  <a name="ldap_conn:option_set" href="#ldap_conn:option_set">`ldap_conn:option_set(name, value) → status`</a>

Set the LDAP option <tt>*name*</tt> (one of the strings documented for
[ldap\_conn:option\_get()](#ldap_conn:option_get)) to <tt>*value*</tt>. On success <tt>*true*</tt> is returned, otherwise
a <tt>*nil*</tt> followed by an error message is returned.

###  <a name="ldap_conn:rebind_add" href="#ldap_conn:rebind_add">`ldap_conn:rebind_add([who [, password]]) → status`</a>

LDAP servers can return referrals to other servers for requests the server
itself will not/can not serve. This function creates a cross reference entry
for the specified LDAP connection. The rebind callback function will look up
this LDAP connection so it can retrieve the <tt>*who*</tt> and <tt>*password*</tt> fields for
use in any binds while referrals are being chased.

On success <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned.

When the LDAP connection is garbage collected the cross reference entry is
automatically removed, alternatively [ldap\_conn:rebind\_remove()](#ldap_conn:rebind_remove) can be
called to explicitly remove the entry.

###  <a name="ldap_conn:rebind_remove" href="#ldap_conn:rebind_remove">`ldap_conn:rebind_remove() → status`</a>

Explicitly remove an LDAP cross reference entry (also done automatically
when the LDAP connection is garbage collected). On success <tt>*true*</tt> is returned,
otherwise a <tt>*nil*</tt> followed by an error message is returned.

###  <a name="ldap_conn:search" href="#ldap_conn:search">`ldap_conn:search(parameters) → iterator`</a>

_The implementation of this method is based on LuaLDAP and the following
documentation was based on the [LuaLDAP manual] [lualdap]:_

Performs a search operation on the directory. The parameters are described
below. The search method will return a search iterator which is a function
that requires no arguments. The search iterator is used to get the search
result and will return a string representing the distinguished name and a
table of attributes as returned by the search request.

Supported parameters:

 - **attrs**: a string or a list of attribute names to be retrieved (default
   is to retrieve all attributes)

 - **attrsonly**: a boolean value that must be either <tt>*false*</tt> (default) if
   both attribute names and values are to be retrieved, or <tt>*true*</tt> if only
   names are wanted

 - **base**: The [distinguished name] [distinguished_name] of the entry at
   which to start the search

 - **filter**: A string representing the search filter as described in [The
   String Representation of LDAP Search Filters] [rfc2254] (RFC 2254)

 - **scope**: A string indicating the scope of the search. The valid strings
   are: _base_, _one_ and _sub_. The empty string and <tt>*nil*</tt> will be treated as
   the default scope

 - **sizelimit**: The maximum number of entries to return (default is no
   limit)

 - **timeout**: The timeout in seconds (default is no timeout). The
   precision is microseconds

[distinguished_name]: http://www.keplerproject.org/lualdap/manual.html#dn
[rfc2254]: http://www.ietf.org/rfc/rfc2254.txt
[lualdap]: http://www.keplerproject.org/lualdap/manual.html#connection

###  <a name="ldap_conn:add" href="#ldap_conn:add">`ldap_conn:add(dn, attrs) → future`</a>

Add a new entry to the directory. The string <tt>*dn*</tt> is the distinguished name
of the new entry. The table <tt>*attrs*</tt> contains the attributes and values.
Returns a function to process the LDAP result.

*This function is not binary safe.*

###  <a name="ldap_conn:compare" href="#ldap_conn:compare">`ldap_conn:compare(dn, attr, value) → future`</a>

Compare a value against an entry. The string <tt>*dn*</tt> contains the distinguished
name of the entry, the string <tt>*attr*</tt> is the name of the attribute to compare
and the string <tt>*value*</tt> is the value to compare against. Returns a function to
process the LDAP result.

*This function is not binary safe.*

###  <a name="ldap_conn:delete" href="#ldap_conn:delete">`ldap_conn:delete(dn) → future`</a>

Delete an entry. The string <tt>*dn*</tt> is the distinguished name of the entry to
delete. Returns a function to process the LDAP result.

*This function is not binary safe.*

###  <a name="ldap_conn:modify" href="#ldap_conn:modify">`ldap_conn:modify(dn, mods [, ...]) → future`</a>

Modify an entry. The string <tt>*dn*</tt> is the distinguished name of the entry to
modify. The table <tt>*mods*</tt> contains modifications to apply. You can pass any
number of additional tables with modifications to apply. On success <tt>*true*</tt> is
returned, otherwise a <tt>*nil*</tt> followed by an error message is returned.

*This function is not binary safe.*

###  <a name="ldap_conn:rename" href="#ldap_conn:rename">`ldap_conn:rename(dn, new_rdn [, new_parent [, delete]]) → future`</a>

Change the distinguished name of an entry. The string <tt>*dn*</tt> is the
distinguished name of the entry to rename. The string <tt>*new_rdn*</tt> gives the new
root distinguished name. The optional string <tt>*new_parent*</tt> gives the
distinguished name of the new parent for the entry. If the optional argument
<tt>*delete*</tt> is <tt>*true*</tt> the entry is removed from it's old parent. Returns a
function to process the LDAP result.

*This function is not binary safe.*

## <a name="memcached_client" href="#memcached_client">Memcached client</a>

[Memcached] [memcached] is a "distributed memory object caching system".
It's designed as an in-memory key-value store for small chunks of arbitrary
data (strings, objects) from results of database calls, API calls, or page
rendering. The memcached client module makes it possible to read from and
write to one or more memcached servers over a network socket in Lua.

To-do: Find out if "flags" can be any 32 bits value and how useful it is
to Lua.

[memcached]: http://memcached.org/

###  <a name="apr.memcache" href="#apr.memcache">`apr.memcache([max_servers]) → mc_client`</a>

Create a memcached client. The optional argument <tt>*max_servers*</tt> determines the
maximum number of memcached servers supported by the client (defaults to
10). On success the client object is returned, otherwise <tt>*nil*</tt> followed by an
error message is returned.

###  <a name="mc_client:hash" href="#mc_client:hash">`mc_client:hash(str) → hash`</a>

Create a [CRC32] [crc] hash used to split keys between servers.
The hash is not compatible with old memcached clients.

[crc]: http://en.wikipedia.org/wiki/Cyclic_redundancy_check

*This function is binary safe.*

###  <a name="mc_client:find_server_hash" href="#mc_client:find_server_hash">`mc_client:find_server_hash(hash) → mc_server`</a>

Picks a server based on a hash. Returns the info of the server that controls
the specified hash.

###  <a name="mc_client:add_server" href="#mc_client:add_server">`mc_client:add_server(host, port [, min [, smax [, max [, ttl]]]]) → mc_server`</a>

Create a new server object and add it to the client object. On success the
server object is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned. The parameters have the following meaning:

 - <tt>*host*</tt>: hostname of server
 - <tt>*port*</tt>: port of server (usually 11211)
 - <tt>*min*</tt>:  minimum number of client sockets to open (defaults to 0)
 - <tt>*smax*</tt>: soft maximum number of client connections to open (defaults to 1)
 - <tt>*max*</tt>:  hard maximum number of client connections (defaults to 1)
 - <tt>*ttl*</tt>:  time to live in microseconds of a client connection (defaults to 60000)

Note that <tt>*min*</tt>, <tt>*smax*</tt> and <tt>*max*</tt> are only used when APR was compiled with
threads. Also a word of caution: Changing servers after startup may cause
keys to go to different servers.

###  <a name="mc_client:find_server" href="#mc_client:find_server">`mc_client:find_server(host, port) → mc_server`</a>

Finds a server object based on a (hostname, port) pair. On success the
server with matching host name and port is returned, otherwise nothing is
returned.

###  <a name="mc_client:enable_server" href="#mc_client:enable_server">`mc_client:enable_server(mc_server) → status`</a>

Enable a server for use again after disabling the server with
[mc\_client:disable\_server()](#mc_client:disable_server). On success <tt>*true*</tt> is returned,
otherwise <tt>*nil*</tt> followed by an error message is returned.

###  <a name="mc_client:disable_server" href="#mc_client:disable_server">`mc_client:disable_server(mc_server) → status`</a>

Disable a server. On success <tt>*true*</tt> is returned, otherwise <tt>*nil*</tt> followed by an
error message is returned.

###  <a name="mc_client:get" href="#mc_client:get">`mc_client:get(key [, ...]) → status, value [, ...]`</a>

Get one or more values from the server. On success <tt>*true*</tt> is returned followed
by the retrieved value(s), otherwise <tt>*nil*</tt> followed by an error message is
returned. The keys are null terminated strings and the return values are
binary safe strings. Keys that don't have an associated value result in <tt>*nil*</tt>.

###  <a name="mc_client:set" href="#mc_client:set">`mc_client:set(key, value [, timeout]) → status`</a>

Sets a value by key on the server. If the key already exists the old value
will be overwritten. The <tt>*key*</tt> is a null terminated string, the <tt>*value*</tt> is a
binary safe string and <tt>*timeout*</tt> is the time in seconds for the data to live
on the server (a number, defaults to 60 seconds). On success <tt>*true*</tt> is
returned, otherwise <tt>*nil*</tt> followed by an error message is returned.

###  <a name="mc_client:add" href="#mc_client:add">`mc_client:add(key, value [, timeout]) → status`</a>

Adds a value by key on the server. If the key already exists this call will
fail and the old value will be preserved. The arguments and return values
are documented under [mc\_client:set()](#mc_client:set).

###  <a name="mc_client:replace" href="#mc_client:replace">`mc_client:replace(key, value [, timeout]) → status`</a>

Replace a value by key on the server. If the key doesn't exist no value will
be set. The arguments and return values are documented under
[mc\_client:set()](#mc_client:set).

###  <a name="mc_client:delete" href="#mc_client:delete">`mc_client:delete(key [, timeout]) → status`</a>

Delete a key from the server. The <tt>*key*</tt> is a null terminated string and
<tt>*timeout*</tt> is the time in seconds for the delete to stop other clients from
adding (a number, defaults to 10 seconds). On success <tt>*true*</tt> is returned,
otherwise <tt>*nil*</tt> followed by an error message is returned.

###  <a name="mc_client:incr" href="#mc_client:incr">`mc_client:incr(key [, number]) → value`</a>

Increment a value. The <tt>*key*</tt> is a null terminated string and the optional
argument <tt>*number*</tt> is the number to increment by (defaults to 1). On success
the new value after incrementing is returned, otherwise <tt>*nil*</tt> followed by an
error message is returned.

###  <a name="mc_client:decr" href="#mc_client:decr">`mc_client:decr(key [, number]) → value`</a>

Decrement a value. The <tt>*key*</tt> is a null terminated string and the optional
argument <tt>*number*</tt> is the number to decrement by (defaults to 1). On success
the new value after decrementing is returned, otherwise <tt>*nil*</tt> followed by an
error message is returned.

###  <a name="mc_client:version" href="#mc_client:version">`mc_client:version(mc_server) → version`</a>

Query a server's version. On success the version string is returned,
otherwise <tt>*nil*</tt> followed by an error message is returned.

###  <a name="mc_client:stats" href="#mc_client:stats">`mc_client:stats() → statistics`</a>

Query a server for statistics. On success a table with information is
returned, otherwise <tt>*nil*</tt> followed by an error message is returned. The
following fields are supported:

 - <tt>*version*</tt>: version string of the server
 - <tt>*pid*</tt>: process ID of the server process
 - <tt>*uptime*</tt>: number of seconds this server has been running
 - <tt>*time*</tt>: current UNIX time according to the server
 - <tt>*rusage_user*</tt>: accumulated user time for this process
 - <tt>*rusage_system*</tt>: accumulated system time for this process
 - <tt>*curr_items*</tt>: current number of items stored by the server
 - <tt>*total_items*</tt>: total number of items stored by this server
 - <tt>*bytes*</tt>: current number of bytes used by this server to store items
 - <tt>*curr_connections*</tt>: number of open connections
 - <tt>*total_connections*</tt>: total number of connections opened since the server started running
 - <tt>*connection_structures*</tt>: number of connection structures allocated by the server
 - <tt>*cmd_get*</tt>: cumulative number of retrieval requests
 - <tt>*cmd_set*</tt>: Cumulative number of storage requests
 - <tt>*get_hits*</tt>: number of keys that have been requested and found present
 - <tt>*get_misses*</tt>: number of items that have been requested and not found
 - <tt>*evictions*</tt>: number of items removed from cache because they passed their expiration time
 - <tt>*bytes_read*</tt>: total number of bytes read by this server
 - <tt>*bytes_written*</tt>: total number of bytes sent by this server
 - <tt>*limit_maxbytes*</tt>: number of bytes this server is allowed to use for storage
 - <tt>*threads*</tt>: number of threads the server is running (if built with threading)

## <a name="command_argument_parsing" href="#command_argument_parsing">Command argument parsing</a>

###  <a name="apr.getopt" href="#apr.getopt">`apr.getopt(usage [, config ]) → options, arguments`</a>

Parse the [command line arguments] [cmdargs] according to the option letters
and/or long options defined in the string <tt>*usage*</tt> (see the example below) and
return a table with the matched options and a table with any remaining
positional arguments. When an option is matched multiple times, the
resulting value in <tt>*options*</tt> depends on the following context:

 * If the option doesn't take an argument, the value will be a number
   indicating the number of times that the option was matched

 * If the option takes an argument and only one option/argument pair is
   matched, the value will be the argument (a string). When more than one
   pair is matched for the same option letter/name, the values will be
   collected in a table

The optional <tt>*config*</tt> table can be used to change the following defaults:

 * When <tt>*usage*</tt> mentions `-h` or `--help` and either of these options is
   matched in the arguments, [apr.getopt()](#apr.getopt) will print the usage message
   and call [os.exit()](http://www.lua.org/manual/5.1/manual.html#pdf-os.exit). To avoid this set `config.show_usage` to <tt>*false*</tt>
   (not <tt>*nil*</tt>!)

 * When an error is encountered during argument parsing, [apr.getopt()](#apr.getopt) will
   print a warning about the invalid argument and call [os.exit()](http://www.lua.org/manual/5.1/manual.html#pdf-os.exit). To avoid
   this set `config.handle_errors` to <tt>*false*</tt> (not <tt>*nil*</tt>!)

 * By default the arguments in the global variable [arg] [arg-global] will
   be used, but you can set `config.args` to a table of arguments to be
   used instead

Here is a short example of a valid Lua script that doesn't really do
anything useful but demonstrates the use of [apr.getopt()](#apr.getopt):

    apr = require 'apr'
    opts, args = apr.getopt [[
    Usage: echo.lua [OPTIONS] ARG...
      -h, --help     show this message and exit
      -v, --verbose  make more noise
          --version  print version and exit
    ]]
    if opts.version then
      print "This is version 0.1"
    else
      if opts.verbose then
        print("Got", #args, "arguments")
      end
      if opts.verbose >= 2 then
        print "Here they are:"
      end
      for i = 1, #args do print(args[i]) end
    end

The [apr.getopt()](#apr.getopt) function is very similar to [Lapp] [lapp] by Steve
Donovan although Lapp is more full featured, for example it validates and
converts argument types.

[cmdargs]: http://en.wikipedia.org/wiki/Command-line_argument
[arg-global]: http://www.lua.org/manual/5.1/manual.html#6
[lapp]: http://lua-users.org/wiki/LappFramework


## <a name="http_request_parsing" href="#http_request_parsing">HTTP request parsing</a>

This module is an experimental binding to the [apreq2] [apreq2] library
which enables [HTTP] [http] request parsing of [query strings] [qstrings],
[headers] [headers] and [multipart messages] [multipart]. Some general notes
about the functions in this module:

 - None of the extracted strings (except maybe for request bodies) are
   binary safe because (AFAIK) HTTP headers are not binary safe

 - Parsed name/value pairs are converted to a Lua table using two rules:
   names without a value get the value <tt>*true*</tt> and duplicate names result in a
   table that collects all values for the given name

 - When a parse error is encountered after successfully parsing part of the
   input, the results of the function are followed by an error message and
   error code (see below)

The functions in this module return three values on error: a <tt>*nil*</tt> followed by
an error message and an error code. This module defines the following error
codes (in addition to the [generic Lua/APR error codes](#error_handling)):

 - `'EBADARG'`: bad arguments
 - `'GENERAL'`: internal apreq2 error
 - `'TAINTED'`: attempted to perform unsafe action with tainted data
 - `'INTERRUPT'`: parsing interrupted
 - `'BADDATA'`: invalid input data
 - `'BADCHAR'`: invalid character
 - `'BADSEQ'`: invalid byte sequence
 - `'BADATTR'`: invalid attribute
 - `'BADHEADER'`: invalid header
 - `'BADUTF8'`: invalid UTF-8 encoding
 - `'NODATA'`: missing input data
 - `'NOTOKEN'`: missing required token
 - `'NOATTR'`: missing attribute
 - `'NOHEADER'`: missing header
 - `'NOPARSER'`: missing parser
 - `'MISMATCH'`: conflicting information
 - `'OVERLIMIT'`: exceeds configured maximum limit
 - `'UNDERLIMIT'`: below configured minimum limit
 - `'NOTEMPTY'`: setting already configured

[apreq2]: http://httpd.apache.org/apreq/
[http]: http://en.wikipedia.org/wiki/Hypertext_Transfer_Protocol
[qstrings]: http://en.wikipedia.org/wiki/Query_string
[headers]: http://en.wikipedia.org/wiki/List_of_HTTP_header_fields
[multipart]: http://en.wikipedia.org/wiki/MIME#Multipart_messages

###  <a name="apr.parse_headers" href="#apr.parse_headers">`apr.parse_headers(request) → headers, body`</a>

Parse the [headers] [headers] in a [HTTP] [http] request string according to
[RFC 822] [rfc822]. On success a table of header name/value pairs and the
request body string are returned, otherwise <tt>*nil*</tt> followed by an error message
is returned.

There are some gotchas in using this function:

 - It will fail if anything comes before the headers, so be sure to strip
   the status line from the request string before calling this function

 - If the request string doesn't contain an empty line to separate the
   headers from the body, the last header might be silently discarded

[rfc822]: http://tools.ietf.org/html/rfc822

###  <a name="apr.parse_multipart" href="#apr.parse_multipart">`apr.parse_multipart(request, enctype [, limit [, tempdir]]) → parts`</a>

Parse a [multipart/form-data] [mp_formdata] or [multipart/related]
[mp_related] HTTP request body according to [RFC 2388] [rfc2388] and the
boundary string in <tt>*enctype*</tt>. On success the table with parameter name/value
pairs is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned.

The optional number <tt>*limit*</tt> gives the maximum in-memory bytes that the data
structure used to parse the request may use (it defaults to 1024 KB), but be
aware that because of internal copying [apr.parse\_multipart()](#apr.parse_multipart) can use more
than double this amount of memory while parsing a request.

The optional string <tt>*tempdir*</tt> is the directory used for temporary storage of
large uploads.

[mp_formdata]: http://en.wikipedia.org/wiki/MIME#Form_Data
[mp_related]: http://en.wikipedia.org/wiki/MIME#Related
[rfc2388]: http://tools.ietf.org/html/rfc2388

###  <a name="apr.parse_cookie_header" href="#apr.parse_cookie_header">`apr.parse_cookie_header(header) → cookies`</a>

Parse a cookie header and store the cookies in a Lua table. On success the
table with cookie name/value pairs is returned, otherwise <tt>*nil*</tt> followed by an
error message and error code is returned.

###  <a name="apr.parse_query_string" href="#apr.parse_query_string">`apr.parse_query_string(query_string) → parameters`</a>

Parse a URL encoded string into a Lua table. On success the table with
parameter name/value pairs is returned, otherwise <tt>*nil*</tt> followed by an error
message and error code is returned.

This function uses `&` and `;` as the set of tokens to delineate words, and
will treat a word without `=` as a name/value pair with the value <tt>*true*</tt>.

###  <a name="apr.header_attribute" href="#apr.header_attribute">`apr.header_attribute(header, name) → value`</a>

Search a header string for the value of a particular named attribute. On
success the matched value is returned, otherwise <tt>*nil*</tt> followed by an error
message is returned.

*This function is not binary safe.*

###  <a name="apr.uri_encode" href="#apr.uri_encode">`apr.uri_encode(string) → encoded`</a>

Encode unsafe bytes in <tt>*string*</tt> using [percent-encoding] [percenc] so that
the string can be embedded in a [URI] [uri] query string.

[percenc]: http://en.wikipedia.org/wiki/Percent-encoding

*This function is not binary safe.*

###  <a name="apr.uri_decode" href="#apr.uri_decode">`apr.uri_decode(encoded) → string`</a>

Decode all [percent-encoded] [percenc] bytes in the string <tt>*encoded*</tt>.

*This function is binary safe.*

## <a name="pollset" href="#pollset">Pollset</a>

The pollset module enables [asynchronous I/O] [wp_async_io] which can
improve throughput, latency and/or responsiveness. It works as follows:

 1. Create a pollset object by calling [apr.pollset()](#apr.pollset)
 2. Add one or more sockets to the pollset (e.g. a server socket listening
    for connections or a bunch of sockets receiving data)
 3. Call [pollset:poll()](#pollset:poll) in a loop to process readable/writable sockets

You can keep adding and removing sockets from the pollset at runtime, just
keep in mind that the size given to [apr.pollset()](#apr.pollset) is a hard limit. There
is an example of a [simple asynchronous webserver] [async_server] that uses
a pollset.

[wp_async_io]: http://en.wikipedia.org/wiki/Asynchronous_I/O
[async_server]: #example_asynchronous_webserver

###  <a name="apr.pollset" href="#apr.pollset">`apr.pollset(size) → pollset`</a>

Create a pollset object. The number <tt>*size*</tt> is the maximum number of sockets
that the pollset can hold. On success a pollset object is returned,
otherwise a <tt>*nil*</tt> followed by an error message is returned.

###  <a name="pollset:add" href="#pollset:add">`pollset:add(socket, flag [, ...]) → status`</a>

Add a network socket to the pollset. On success <tt>*true*</tt> is returned, otherwise
a <tt>*nil*</tt> followed by an error message is returned. One or two of the following
flags should be provided:

 - `'input'` indicates that the socket can be read without blocking
 - `'output'` indicates that the socket can be written without blocking

If the socket is already in the pollset the flags of the existing entry in
the pollset will be combined with the new flags. If you want to *change* a
socket from readable to writable or the other way around, you have to first
remove the socket from the pollset and then add it back with the new flag.

###  <a name="pollset:remove" href="#pollset:remove">`pollset:remove(socket) → status`</a>

Remove a <tt>*socket*</tt> from the pollset. On success <tt>*true*</tt> is returned, otherwise a
<tt>*nil*</tt> followed by an error message is returned. It is not an error if the
socket is not contained in the pollset.

###  <a name="pollset:poll" href="#pollset:poll">`pollset:poll(timeout) → readable, writable`</a>

Block for activity on the descriptor(s) in a pollset. The <tt>*timeout*</tt> argument
gives the amount of time in microseconds to wait. This is a maximum, not a
minimum.  If a descriptor is signaled, we will wake up before this time. A
negative number means wait until a descriptor is signaled. On success a
table with sockets waiting to be read followed by a table with sockets
waiting to be written is returned, otherwise a <tt>*nil*</tt> followed by an error
message is returned.

###  <a name="pollset:destroy" href="#pollset:destroy">`pollset:destroy() → status`</a>

Destroy a pollset. On success <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed by
an error message is returned. Note that pollset objects are automatically
destroyed when they are garbage collected.

## <a name="process_handling" href="#process_handling">Process handling</a>

###  <a name="apr.proc_create" href="#apr.proc_create">`apr.proc_create(program) → process`</a>

Create a child process that will execute the given <tt>*program*</tt> when started.
Once you've called this function you still need to execute the process using
the [process:exec()](#process:exec) function. Here's a simple example that emulates Lua's
[os.execute()](http://www.lua.org/manual/5.1/manual.html#pdf-os.execute) function:

    function execute(command)
      local arguments = apr.tokenize_to_argv(command)
      local progname = table.remove(arguments, 1)
      local process = apr.proc_create(progname)
      process:cmdtype_set('shellcmd/env')
      process:exec(arguments)
      local done, code, why = process:wait(true)
      return code
    end

    execute 'echo This can be any process...'

*This function is not binary safe.*

###  <a name="apr.proc_detach" href="#apr.proc_detach">`apr.proc_detach(daemonize) → status`</a>

Detach the current process from the controlling terminal. If <tt>*daemonize*</tt>
evaluates to <tt>*true*</tt> the process will [daemonize] [daemons] and become a
background process, otherwise it will stay in the foreground. On success
<tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned.

[daemons]: http://en.wikipedia.org/wiki/Daemon_(computer_software)

###  <a name="apr.proc_fork" href="#apr.proc_fork">`apr.proc_fork() → process, context`</a>

This is currently the only non-portable function in APR and by extension
Lua/APR. It performs a [standard UNIX fork][fork]. If the fork succeeds a
<tt>*process*</tt> object and <tt>*context*</tt> string (`'parent'` or `'child'`) are returned,
otherwise a <tt>*nil*</tt> followed by an error message is returned. The parent process
can use the returned <tt>*process*</tt> object to wait for the child process to die:

    if apr.proc_fork then -- forking supported?
      process, context = assert(apr.proc_fork())
      if context == 'parent' then
        print "Parent waiting for child.."
        process:wait(true)
        print "Parent is done!"
      else -- context == 'child'
        print "Child simulating activity.."
        apr.sleep(10)
        print "Child is done!"
      end
    end

As the above example implies the [apr.proc\_fork()](#apr.proc_fork) function will only be
defined when forking is supported on the current platform.

[fork]: http://en.wikipedia.org/wiki/Fork_(operating_system)

###  <a name="process:addrspace_set" href="#process:addrspace_set">`process:addrspace_set(separate) → status`</a>

If <tt>*separate*</tt> evaluates to <tt>*true*</tt> the child process will start in its own
address space, otherwise the child process executes in the current address
space from its parent. On success <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed
by an error message is returned. The default is no on NetWare and yes on
other platforms.

###  <a name="process:user_set" href="#process:user_set">`process:user_set(username [, password]) → status`</a>

Set the user under which the child process will run. On success <tt>*true*</tt> is
returned, otherwise a <tt>*nil*</tt> followed by an error message is returned.

On Windows and other platforms where `apr.user_set_requires_password` is
<tt>*true*</tt> this method _requires_ a password.

*This function is not binary safe.*

###  <a name="process:group_set" href="#process:group_set">`process:group_set(groupname) → status`</a>

Set the group under which the child process will run. On success <tt>*true*</tt> is
returned, otherwise a <tt>*nil*</tt> followed by an error message is returned.

*This function is not binary safe.*

###  <a name="process:cmdtype_set" href="#process:cmdtype_set">`process:cmdtype_set(type) → status`</a>

Set what type of command the child process will execute. On success <tt>*true*</tt> is
returned, otherwise a <tt>*nil*</tt> followed by an error message is returned. The
argument <tt>*type*</tt> must be one of:

 - `'shellcmd'`: Use the shell to invoke the program
 - `'shellcmd/env'`: Use the shell to invoke the program, replicating our environment
 - `'program'`: Invoke the program directly, without copying the environment
 - `'program/env'`: Invoke the program directly, replicating our environment
 - `'program/env/path'`: Find program in `$PATH`, replicating our environment

###  <a name="process:env_set" href="#process:env_set">`process:env_set(environment) → status`</a>

Set the environment variables of the child process to the key/value pairs in
the table <tt>*environment*</tt>. On success <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt>
followed by an error message is returned.

Please note that the environment table is ignored for the command types
`'shellcmd/env'`, `'program/env'` and `'program/env/path'` (set using the
[process:cmdtype\_set()](#process:cmdtype_set) method).

*This function is not binary safe.*

###  <a name="process:dir_set" href="#process:dir_set">`process:dir_set(path) → status`</a>

Set which directory the child process should start executing in. On success
<tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed by an error message is returned.

By default child processes inherit this directory from their parent process
at the moment when the [process:exec()](#process:exec) call is made. To find out the
current directory see the [apr.filepath\_get()](#apr.filepath_get) function.

*This function is not binary safe.*

###  <a name="process:detach_set" href="#process:detach_set">`process:detach_set(detach) → status`</a>

Determine if the child should start in detached state. On success <tt>*true*</tt> is
returned, otherwise a <tt>*nil*</tt> followed by an error message is returned. Default
is no.

###  <a name="process:error_check_set" href="#process:error_check_set">`process:error_check_set(enabled) → nothing`</a>

Specify that [process:exec()](#process:exec) should do whatever it can to report failures
directly, rather than find out in the child that something is wrong. This
leads to extra overhead in the calling process, but it may help you handle
these errors more gracefully.

Note that this option is only useful on platforms where [fork()][fork] is
used.

[fork]: http://linux.die.net/man/2/fork

###  <a name="process:io_set" href="#process:io_set">`process:io_set(stdin, stdout, stderr) → status`</a>

Determine if the child process should be linked to its parent through one or
more pipes. On success <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed by an
error message is returned.

Each argument gives the blocking mode of a pipe, which can be one of the
following strings:

 - `'none'`: Don't create a pipe
 - `'full-block'`: Create a pipe that blocks until the child process writes to the pipe or dies
 - `'full-nonblock'`: Create a pipe that doesn't block
 - `'parent-block'`: Create a pipe that only blocks on the parent's end
 - `'child-block'`: Create a pipe that only blocks on the child's end

*Once the child process has been started* with [process:exec()](#process:exec), the pipes
can be accessed with the methods [process:in\_get()](#process:in_get), [process:out\_get()](#process:out_get)
and [process:err\_get()](#process:err_get).

Here's an example that executes the external command `tr a-z A-Z` to
translate some characters to uppercase:

    > p = apr.proc_create 'tr'
    > p:cmdtype_set('shellcmd/env')
    > p:io_set('child-block', 'parent-block', 'none')
    > p:exec{'a-z', 'A-Z'}
    > input = p:in_get()
    > output = p:out_get()
    > input:write('Testing, 1, 2, 3\n')
    > input:close()
    > print(output:read())
    TESTING, 1, 2, 3
    > output:close()
    > p:wait(true)

###  <a name="process:in_set" href="#process:in_set">`process:in_set(child_in [, parent_in]) → status`</a>

Initialize the [standard input pipe] [stdin] of the child process to an
existing pipe or a pair of pipes. This can be useful if you have already
opened a pipe (or multiple files) that you wish to use, perhaps persistently
across multiple process invocations - such as a log file. On success <tt>*true*</tt> is
returned, otherwise a <tt>*nil*</tt> followed by an error message is returned. Here's
a basic example that connects two processes using an anonymous pipe:

    -- Create a gzip process to decompress the Lua source code archive.
    gzip = apr.proc_create 'gunzip'
    gzip:cmdtype_set 'shellcmd/env'
    gzip:in_set(apr.file_open('lua-5.1.4.tar.gz', 'rb'))

    -- Create a tar process to list the files in the decompressed archive.
    tar = apr.proc_create 'tar'
    tar:cmdtype_set 'shellcmd/env'
    tar:out_set(apr.pipe_open_stdout())

    -- Connect the two processes using an anonymous pipe.
    input, output = assert(apr.pipe_create())
    gzip:out_set(output)
    tar:in_set(input)

    -- Start the pipeline by executing both processes.
    gzip:exec()
    tar:exec{'-t'}

[stdin]: http://en.wikipedia.org/wiki/Standard_streams#Standard_input_.28stdin.29

###  <a name="process:out_set" href="#process:out_set">`process:out_set(child_out [, parent_out]) → status`</a>

Initialize the [standard output pipe] [stdout] of the child process to an
existing pipe or a pair of pipes. This can be useful if you have already
opened a pipe (or multiple files) that you wish to use, perhaps persistently
across multiple process invocations - such as a log file. On success <tt>*true*</tt> is
returned, otherwise a <tt>*nil*</tt> followed by an error message is returned.

[stdout]: http://en.wikipedia.org/wiki/Standard_streams#Standard_output_.28stdout.29

###  <a name="process:err_set" href="#process:err_set">`process:err_set(child_err [, parent_err]) → status`</a>

Initialize the [standard error pipe] [stderr] of the child process to an
existing pipe or a pair of pipes. This can be useful if you have already
opened a pipe (or multiple files) that you wish to use, perhaps persistently
across multiple process invocations - such as a log file. On success <tt>*true*</tt> is
returned, otherwise a <tt>*nil*</tt> followed by an error message is returned.

[stderr]: http://en.wikipedia.org/wiki/Standard_streams#Standard_error_.28stderr.29

###  <a name="process:in_get" href="#process:in_get">`process:in_get() → pipe`</a>

Get the parent end of the standard input pipe (a writable pipe).

###  <a name="process:out_get" href="#process:out_get">`process:out_get() → pipe`</a>

Get the parent end of the standard output pipe (a readable pipe).

###  <a name="process:err_get" href="#process:err_get">`process:err_get() → pipe`</a>

Get the parent end of the standard error pipe (a readable pipe).

###  <a name="process:exec" href="#process:exec">`process:exec([args]) → status`</a>

Create the child process and execute a program or shell command inside it.
On success <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned. If the <tt>*args*</tt> array is given the contained strings become the
command line arguments to the child process. The [program name] [progname]
for the child process defaults to the name passed into [apr.proc\_create()](#apr.proc_create),
but you can change it by setting `args[0]`.

[progname]: http://en.wikipedia.org/wiki/BusyBox#Single_binary

*This function is not binary safe.*

###  <a name="process:wait" href="#process:wait">`process:wait(how) → done [, why, code]`</a>

Wait for the child process to die. If <tt>*how*</tt> is <tt>*true*</tt> the call blocks until the
process dies, otherwise the call returns immediately regardless of if the
process is dead or not. The first return value is <tt>*false*</tt> if the process isn't
dead yet. If it's <tt>*true*</tt> the process died and two more return values are
available. The second return value is the reason the process died, which is
one of:

 - `'exit'`: Process exited normally
 - `'signal'`: Process exited due to a signal
 - `'signal/core'`: Process exited and dumped [a core file] [coredump]

The third return value is the exit code of the process. If an error occurs a
<tt>*nil*</tt> followed by an error message is returned.

[coredump]: http://en.wikipedia.org/wiki/Core_dump

###  <a name="process:kill" href="#process:kill">`process:kill(how) → status`</a>

Terminate a running child process. On success <tt>*true*</tt> is returned, otherwise a
<tt>*nil*</tt> followed by an error message is returned. The parameter <tt>*how*</tt> must be one
of:

 - `'never'`: The process is never sent any signals
 - `'always'`: The process is sent the [SIGKILL] [sigkill] signal when its
   Lua userdata is garbage collected
 - `'timeout'`: Send the [SIGTERM] [sigterm] signal, wait for 3 seconds,
   then send the [SIGKILL] [sigkill] signal
 - `'wait'`: Wait forever for the process to complete
 - `'once'`: Send the [SIGTERM] [sigterm] signal and then wait

[sigkill]: http://en.wikipedia.org/wiki/SIGKILL
[sigterm]: http://en.wikipedia.org/wiki/SIGTERM

## <a name="shared_memory" href="#shared_memory">Shared memory</a>

[Shared memory] [shm] is memory that may be simultaneously accessed by
multiple programs with an intent to provide communication among them. The
Lua/APR binding represents shared memory as file objects through the
[shm:read()](#shm:read), [shm:write()](#shm:write) and [shm:seek()](#shm:seek) methods.

[shm]: http://en.wikipedia.org/wiki/Shared_memory

###  <a name="apr.shm_create" href="#apr.shm_create">`apr.shm_create(filename, size) → shm object`</a>

Create and make accessible a shared memory segment. The <tt>*filename*</tt> argument
is the file to use for shared memory on platforms that require it. The <tt>*size*</tt>
argument is the desired size of the segment.

A note about anonymous vs. named shared memory segments: Not all platforms
support anonymous shared memory segments, but in some cases it is preferred
over other types of shared memory implementations. Passing a <tt>*nil*</tt> <tt>*filename*</tt>
parameter to this function will cause the subsystem to use anonymous shared
memory segments. If such a system is not available, the error `'ENOTIMPL'`
is returned as the third return value (the first and second being <tt>*nil*</tt> and an
error message string).

*This function is not binary safe.*

###  <a name="apr.shm_attach" href="#apr.shm_attach">`apr.shm_attach(filename) → shm object`</a>

Attach to a shared memory segment that was created by another process. The
<tt>*filename*</tt> argument is the file used to create the original segment (this
must match the original filename). On success a shared memory object is
returned, otherwise a <tt>*nil*</tt> followed by an error message is returned.

*This function is not binary safe.*

###  <a name="apr.shm_remove" href="#apr.shm_remove">`apr.shm_remove(filename) → status`</a>

Remove the named resource associated with a shared memory segment,
preventing attachments to the resource, but not destroying it. On success
<tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned.

This function is only supported on platforms which support name-based shared
memory segments, and will return the error code `'ENOTIMPL'` on platforms
without such support. Removing the file while the shared memory is in use is
not entirely portable, caller may use this to enhance obscurity of the
resource, but be prepared for the the call to fail, and for concurrent
attempts to create a resource of the same name to also fail.

Note that the named resource is also removed when a shared memory object
created by [apr.shm\_create()](#apr.shm_create) is garbage collected.

*This function is not binary safe.*

###  <a name="shm:read" href="#shm:read">`shm:read([format, ...]) → mixed value, ...`</a>

_This function implements the interface of the [file:read()] [fread] function described in the Lua 5.1 reference manual. Here is the description from the reference manual:_

Read from shared memory, according to the given formats, which specify what to read. For each format, the function returns a string (or a number) with the characters read, or <tt>*nil*</tt> if it cannot read data with the specified format. When called without formats, it uses a default format that reads the entire next line (see below).

The available formats are:

 - `'*n'`: reads a number; this is the only format that returns a number instead of a string
 - `'*a'`: reads all data from the shared memory, starting at the current position. On end of input, it returns the empty string
 - `'*l'`: reads the next line (skipping the end of line), returning <tt>*nil*</tt> on end of input (this is the default format)
 - `number`: reads a string with up to this number of characters, returning <tt>*nil*</tt> on end of input. If number is zero, it reads nothing and returns an empty string, or <tt>*nil*</tt> on end of input

[fread]: http://www.lua.org/manual/5.1/manual.html#pdf-file:read

###  <a name="shm:write" href="#shm:write">`shm:write(value [, ...]) → status`</a>

_This function implements the interface of the [file:write()] [fwrite] function described in the Lua 5.1 reference manual. Here is the description from the reference manual:_

Write the value of each argument to shared memory. The arguments must be strings or numbers. To write other values, use [tostring()](http://www.lua.org/manual/5.1/manual.html#pdf-tostring) or [string.format()](http://www.lua.org/manual/5.1/manual.html#pdf-string.format) before this function.

[fwrite]: http://www.lua.org/manual/5.1/manual.html#pdf-file:write

###  <a name="shm:seek" href="#shm:seek">`shm:seek([whence [, offset]]) → offset`</a>

_This function implements the interface of the [file:seek()] [fseek] function described in the Lua 5.1 reference manual. Here is the description from the reference manual:_

Sets and gets the shared memory position, measured from the beginning of the shared memory, to
the position given by <tt>*offset*</tt> plus a base specified by the string <tt>*whence*</tt>, as
follows:

 - `'set'`:  base is position 0 (beginning of the shared memory)
 - `'cur'`:  base is current position
 - `'end'`:  base is end of shared memory

In case of success, function `seek` returns the final shared memory position, measured
in bytes from the beginning of the shared memory. If this function fails, it returns
<tt>*nil*</tt>, plus a string describing the error.

The default value for <tt>*whence*</tt> is `'cur'`, and for offset is 0. Therefore, the
call [shm:seek()](#shm:seek) returns the current shared memory position, without changing it; the
call `shm:seek('set')` sets the position to the beginning of the shared memory (and
returns 0); and the call `shm:seek('end')` sets the position to the end of the
shared memory, and returns its size.

[fseek]: http://www.lua.org/manual/5.1/manual.html#pdf-file:seek

###  <a name="shm:detach" href="#shm:detach">`shm:detach() → status`</a>

Detach from a shared memory segment without destroying it. On success <tt>*true*</tt>
is returned, otherwise a <tt>*nil*</tt> followed by an error message is returned.

###  <a name="shm:destroy" href="#shm:destroy">`shm:destroy() → status`</a>

Destroy a shared memory segment and associated memory. On success <tt>*true*</tt> is
returned, otherwise a <tt>*nil*</tt> followed by an error message is returned. Note
that this will be done automatically when the shared memory object is
garbage collected and has not already been destroyed.

## <a name="signal_handling" href="#signal_handling">Signal handling</a>

[Signals] [signals] provide a limited form of inter-process communication.
On UNIX they are for example used to communicate to [daemons] [daemons] that
they should reload their configuration or stop gracefully. This module works
on Linux and most if not all UNIX systems but it's not very useful on
Windows, because [Windows has poor support for signals] [msdn_signals]:

> `SIGINT` is not supported for any Win32 application, including Windows
> 98/Me and Windows NT/2000/XP. When a CTRL+C interrupt occurs, Win32
> operating systems generate a new thread to specifically handle that
> interrupt. This can cause a single-thread application such as UNIX,
> to become multithreaded, resulting in unexpected behavior.  
> ...  
> The `SIGILL`, `SIGSEGV`, and `SIGTERM` signals are not generated under
> Windows NT. They are included for ANSI compatibility. Thus you can set
> signal handlers for these signals with signal(), and you can also
> explicitly generate these signals by calling raise().

The following signal related functionality is not exposed by the Lua/APR
binding because the Apache Portable Runtime doesn't wrap the required
functions:

 - APR doesn't expose [kill()] [kill] except through [process:kill()](#process:kill) which
   only supports two signals (`SIGTERM` and `SIGKILL`) which means users of
   the Lua/APR binding cannot send arbitrary signals to processes (use
   [luaposix] [lposix] instead)

 - APR doesn't expose [alarm()][alarm] and Windows doesn't support it which
   means the `SIGALRM` signal is useless (use [lalarm] [lalarm] instead)

[signals]: http://en.wikipedia.org/wiki/Signal_(computing)
[daemons]: http://en.wikipedia.org/wiki/Daemon_(computing)
[msdn_signals]: http://msdn.microsoft.com/en-us/library/xdkz3x12(v=vs.71).aspx
[kill]: http://linux.die.net/man/3/kill
[lposix]: http://luaforge.net/projects/luaposix/
[alarm]: http://linux.die.net/man/3/alarm
[lalarm]: http://www.tecgraf.puc-rio.br/~lhf/ftp/lua/#lalarm

###  <a name="apr.signal" href="#apr.signal">`apr.signal(name [, handler]) → status`</a>

Set the signal handler function for a given signal. The argument <tt>*name*</tt> must
be a string with the name of the signal to handle ([apr.signal\_names()](#apr.signal_names)
returns a table of available names on your platform). The argument <tt>*handler*</tt>
must be of type function, unless it is <tt>*nil*</tt> in which case default handling
is restored for the given signal. On success <tt>*true*</tt> is returned, otherwise a
<tt>*nil*</tt> followed by an error message is returned.

###  <a name="apr.signal_raise" href="#apr.signal_raise">`apr.signal_raise(name) → status`</a>

Send a signal to *the current process*. The result is <tt>*true*</tt> when the call
succeeded, <tt>*false*</tt> otherwise. This function is useful to test your own signal
handlers:

    > = apr.signal('SIGSEGV', function() print 'almost crashed :-)' end)
    true
    > = apr.signal_raise('SIGSEGV')
    almost crashed :-)
    true
    > = apr.signal('SIGSEGV', nil)
    true
    > = apr.signal_raise('SIGSEGV')
    zsh: segmentation fault  lua

###  <a name="apr.signal_block" href="#apr.signal_block">`apr.signal_block(name) → status`</a>

Block the delivery of a particular signal. On success <tt>*true*</tt> is returned,
otherwise a <tt>*nil*</tt> followed by an error message is returned.

###  <a name="apr.signal_unblock" href="#apr.signal_unblock">`apr.signal_unblock(name) → status`</a>

Enable the delivery of a particular signal. On success <tt>*true*</tt> is returned,
otherwise a <tt>*nil*</tt> followed by an error message is returned.

###  <a name="apr.signal_names" href="#apr.signal_names">`apr.signal_names() → names`</a>

Return a table with available signal names on your platform. The keys of the
table are the names of the signals and the values are the integer codes
associated with the signals.

As the previous paragraph implies the result of this function can differ
depending on your operating system and processor architecture. For example
on my Ubuntu Linux 10.04 installation I get these results:

    > signals = {}
    > for k, v in pairs(apr.signal_names()) do
    >>  table.insert(signals, { name = k, value = v })
    >> end
    > table.sort(signals, function(a, b)
    >>  return a.value < b.value
    >> end)
    > for _, s in ipairs(signals) do
    >>  print(string.format('% 2i: %s', s.value, s.name))
    >> end
     1: SIGHUP
     2: SIGINT
     3: SIGQUIT
     4: SIGILL
     5: SIGTRAP
     6: SIGIOT
     6: SIGABRT
     7: SIGBUS
     8: SIGFPE
     9: SIGKILL
    10: SIGUSR1
    11: SIGSEGV
    12: SIGUSR2
    13: SIGPIPE
    14: SIGALRM
    15: SIGTERM
    16: SIGSTKFLT
    17: SIGCHLD
    17: SIGCLD
    18: SIGCONT
    19: SIGSTOP
    20: SIGTSTP
    21: SIGTTIN
    22: SIGTTOU
    23: SIGURG
    24: SIGXCPU
    25: SIGXFSZ
    26: SIGVTALRM
    27: SIGPROF
    28: SIGWINCH
    29: SIGPOLL
    29: SIGIO
    30: SIGPWR
    31: SIGSYS

After creating the above table I was surprised to see several numbers which
have two names in the above output, but after looking up the names it turns
out that these are just synonyms.

Note that just because a signal is included in this table doesn't
necessarily mean the signal is usable from Lua! For example [SIGALRM]
[sigalrm] is only useful when you can call the alarm() function defined by
[POSIX][posix] but that function isn't exposed by the Apache Portable
Runtime (you can use [lalarm] [lalarm] instead in this case).

[sigalrm]: http://en.wikipedia.org/wiki/SIGALRM
[posix]: http://en.wikipedia.org/wiki/POSIX

## <a name="string_routines" href="#string_routines">String routines</a>

###  <a name="apr.strnatcmp" href="#apr.strnatcmp">`apr.strnatcmp(left, right) → status`</a>

Do a [natural order comparison] [natsort] of two strings. Returns <tt>*true*</tt> when
the <tt>*left*</tt> string is less than the <tt>*right*</tt> string, <tt>*false*</tt> otherwise. This
function can be used as a callback for Lua's standard library function
[table.sort()](http://www.lua.org/manual/5.1/manual.html#pdf-table.sort).

    > -- the canonical example:
    > list = { 'rfc1.txt', 'rfc2086.txt', 'rfc822.txt' }
    > -- collate order:
    > table.sort(list)
    > for _, name in ipairs(list) do print(name) end
    rfc1.txt
    rfc2086.txt
    rfc822.txt
    > -- natural order:
    > table.sort(list, apr.strnatcmp)
    > for _, name in ipairs(list) do print(name) end
    rfc1.txt
    rfc822.txt
    rfc2086.txt

[natsort]: http://sourcefrog.net/projects/natsort/

*This function is not binary safe.*

###  <a name="apr.strnatcasecmp" href="#apr.strnatcasecmp">`apr.strnatcasecmp(left, right) → status`</a>

Like [apr.strnatcmp()](#apr.strnatcmp), but ignores the case of the strings.

*This function is not binary safe.*

###  <a name="apr.strfsize" href="#apr.strfsize">`apr.strfsize(number [, padding]) → readable`</a>

Format a binary size positive <tt>*number*</tt> to a compacted human readable string.
If the optional <tt>*padding*</tt> argument evaluates to <tt>*true*</tt> the resulting string
will be padded with spaces to make it four characters wide, otherwise no
padding will be applied.

    > = apr.strfsize(1024)
    '1.0K'
    > = apr.strfsize(1024 ^ 2)
    '1.0M'
    > = apr.strfsize(1024 ^ 3)
    '1.0G'

Here's a simplified implementation of the [UNIX] [unix] command `ls -l
--human-readable` which makes use of the <tt>*padding*</tt> argument to nicely line up
 the fields following the size:

    function ls(dirpath)
      local directory = assert(apr.dir_open(dirpath))
      for info in directory:entries() do
        io.write(info.protection, ' ')
        io.write(info.user, ' ')
        io.write(info.group, ' ')
        io.write(apr.strfsize(info.size, true), ' ')
        io.write(apr.time_format('%Y-%m-%d %H:%I', info.ctime), ' ')
        io.write(info.name, '\n')
      end
      assert(directory:close())
    end

This is what the result looks like for the [source code directory] [srcdir]
of the Lua/APR project:

    > ls 'lua-apr/src'
    rw-r--r-- peter peter 5.4K 2011-01-02 22:10 apr.lua
    rw-r--r-- peter peter 4.7K 2011-01-02 06:06 base64.c
    rw-r--r-- peter peter  11K 2010-10-27 13:01 buffer.c
    rw-r--r-- peter peter  13K 2011-01-02 21:09 crypt.c
    rw-r--r-- peter peter 2.8K 2010-12-31 01:01 date.c
    rw-r--r-- peter peter 9.4K 2011-01-01 16:04 dbm.c
    rw-r--r-- peter peter 2.5K 2010-09-25 23:11 env.c
    rw-r--r-- peter peter  17K 2011-01-02 22:10 errno.c
    rw-r--r-- peter peter  10K 2011-01-02 22:10 filepath.c
    rw-r--r-- peter peter 1.9K 2011-01-02 04:04 fnmatch.c
    rw-r--r-- peter peter  12K 2010-12-31 01:01 io_dir.c
    rw-r--r-- peter peter  25K 2011-01-02 04:04 io_file.c
    rw-r--r-- peter peter  17K 2010-12-31 01:01 io_net.c
    rw-r--r-- peter peter 4.6K 2011-01-02 22:10 io_pipe.c
    rw-r--r-- peter peter  11K 2011-01-02 11:11 lua_apr.c
    rw-r--r-- peter peter 9.0K 2011-01-02 11:11 lua_apr.h
    rw-r--r-- peter peter 6.9K 2010-12-29 14:02 permissions.c
    rw-r--r-- peter peter  26K 2011-01-02 22:10 proc.c
    rw-r--r-- peter peter 866  2010-10-23 00:12 refpool.c
    rw-r--r-- peter peter 4.8K 2010-12-29 14:02 stat.c
    rw-r--r-- peter peter 3.5K 2011-01-02 22:10 str.c
    rw-r--r-- peter peter 9.8K 2010-12-31 01:01 time.c
    rw-r--r-- peter peter 4.7K 2010-09-25 23:11 uri.c
    rw-r--r-- peter peter 2.5K 2010-09-25 23:11 user.c
    rw-r--r-- peter peter 2.9K 2010-10-22 19:07 uuid.c
    rw-r--r-- peter peter 3.8K 2011-01-02 04:04 xlate.c

Note: It seems that [apr.strfsize()](#apr.strfsize) doesn't support terabyte range sizes.

[srcdir]: https://github.com/xolox/lua-apr/tree/master/src

###  <a name="apr.tokenize_to_argv" href="#apr.tokenize_to_argv">`apr.tokenize_to_argv(cmdline) → arguments`</a>

Convert the string <tt>*cmdline*</tt> to a table of arguments. On success the table of
arguments is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned.

*This function is not binary safe.*

## <a name="multi_threading" href="#multi_threading">Multi threading</a>

This is an experimental multi threading module that makes it possible to
execute Lua functions in dedicated [Lua states] [Lua_state] and [operating
system threads] [threading]. When you create a thread you can pass it any
number of arguments and when a thread exits it can return any number of
return values. For details about supported Lua values see the documentation
of the [serialization](#serialization) module.

Please consider the following issues when using this module:

 - When you pass a userdata object to another thread you shouldn't use it
   from the original thread after that, because the Lua/APR binding doesn't
   protect object access with a thread safe lock. This will probably be
   fixed in the near future (hey, I said it was experimental)

 - When you start a thread and let it get garbage collected without having
   called [thread:join()](#thread:join), the thread will be joined for you (because
   failing to do so while the main thread is terminating can crash the
   process)

[Lua_state]: http://www.lua.org/manual/5.1/manual.html#lua_State
[threading]: http://en.wikipedia.org/wiki/Thread_%28computer_science%29
[libc]: http://en.wikipedia.org/wiki/C_standard_library

###  <a name="apr.thread" href="#apr.thread">`apr.thread(f [, ...]) → thread`</a>

Execute the Lua function <tt>*f*</tt> in a dedicated Lua state and operating system
thread. Any extra arguments are passed onto the function. On success a
thread object is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned. You can use [thread:join()](#thread:join) to wait for the thread to finish and
get the return values of the thread function.

*This function is binary safe.*

###  <a name="apr.thread_yield" href="#apr.thread_yield">`apr.thread_yield() → nothing`</a>

Force the current thread to yield the processor. This causes the currently
executing thread to temporarily pause and allow other threads to execute.

###  <a name="thread:status" href="#thread:status">`thread:status() → status`</a>

Returns a string describing the state of the thread:

 - `'running'`: the thread is currently running
 - `'done'`: the thread terminated successfully
 - `'error'`: the thread encountered an error

###  <a name="thread:join" href="#thread:join">`thread:join() → status [, result, ...]`</a>

Block until a thread stops executing and return its result. If the thread
terminated with an error a <tt>*nil*</tt> followed by an error message is returned,
otherwise <tt>*true*</tt> is returned, followed by any return values of the thread
function.

*This function is binary safe.*

## <a name="thread_queues" href="#thread_queues">Thread queues</a>

The valid types that can be transported through thread queues are documented
under the [serialization](#serialization) module. The example of a [multi
threaded webserver](#example_multi_threaded_webserver) uses a thread queue
to pass sockets between the main server thread and several worker threads.

###  <a name="apr.thread_queue" href="#apr.thread_queue">`apr.thread_queue([capacity]) → queue`</a>

Create a [FIFO] [fifo] [queue] [wp:queue]. The optional argument <tt>*capacity*</tt>
controls the maximum size of the queue and defaults to 1. On success the
queue object is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned.

The capacity of a thread queue cannot be changed after construction.

[wp:fifo]: http://en.wikipedia.org/wiki/FIFO
[wp:queue]: http://en.wikipedia.org/wiki/Queue_%28abstract_data_type%29

###  <a name="queue:push" href="#queue:push">`queue:push(value [, ...]) → status`</a>

Add a tuple of one or more Lua values to the queue. This call will block if
the queue is full. On success <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed by
an error message and error code is returned:

 - `'EINTR'`: the blocking was interrupted (try again)
 - `'EOF'`: the queue has been terminated

*This function is binary safe.*

###  <a name="queue:pop" href="#queue:pop">`queue:pop() → value [, ...]`</a>

Get one or more Lua values from the queue. This call will block if the queue
is empty. On success <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed by an error
message and error code is returned:

 - `'EINTR'`: the blocking was interrupted (try again)
 - `'EOF'`: the queue has been terminated

*This function is binary safe.*

###  <a name="queue:trypush" href="#queue:trypush">`queue:trypush(value [, ...]) → status`</a>

Add a tuple of one or more Lua values to the queue. This call doesn't block
if the queue is full. On success <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed
by an error message and error code is returned:

 - `'EINTR'`: the blocking was interrupted (try again)
 - `'EAGAIN'`: the queue is full
 - `'EOF'`: the queue has been terminated

*This function is binary safe.*

###  <a name="queue:trypop" href="#queue:trypop">`queue:trypop() → value [, ...]`</a>

Get a tuple of Lua values from the queue. This call doesn't block if the
queue is empty. On success <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed by an
error message and error code is returned:

 - `'EINTR'`: the blocking was interrupted (try again)
 - `'EAGAIN'`: the queue is empty
 - `'EOF'`: the queue has been terminated

*This function is binary safe.*

###  <a name="queue:interrupt" href="#queue:interrupt">`queue:interrupt() → status`</a>

Interrupt all the threads blocking on this queue. On success <tt>*true*</tt> is
returned, otherwise a <tt>*nil*</tt> followed by an error message is returned.

###  <a name="queue:terminate" href="#queue:terminate">`queue:terminate() → status`</a>

Terminate the queue, sending an interrupt to all the blocking threads. On
success <tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned.

###  <a name="queue:close" href="#queue:close">`queue:close() → status`</a>

Close the handle <tt>*queue*</tt> and (if no other threads are using the queue)
destroy the queue and release the associated memory. This function always
returns <tt>*true*</tt> (it cannot fail).

This will be done automatically when the <tt>*queue*</tt> object is garbage collected
which means you don't need to call this unless you want to reclaim memory as
soon as possible.

## <a name="time_routines" href="#time_routines">Time routines</a>

Lua represents dates as numbers though the meaning of these numbers is not
specified. The manual does state (in the documentation for [os.time()](http://www.lua.org/manual/5.1/manual.html#pdf-os.time)) that
on [POSIX] [posix], Windows and some other systems these numbers count the
number of seconds since some given start time called the epoch. This epoch
is 00:00:00 January 1, 1970 [UTC] [utc]. The Apache Portable Runtime
[represents] [apr_time_t] dates as the number of microseconds since that
same epoch. As a compromise between the two units Lua/APR uses seconds but
supports sub-second resolution in the decimal part of floating point numbers
(see [this thread] [2007-03] on [lua-l] [lua-l] for discussion about the
API).

[posix]: http://en.wikipedia.org/wiki/POSIX
[apr_time_t]: http://apr.apache.org/docs/apr/trunk/group__apr__time.html#gdb4bde16055748190eae190c55aa02bb
[2007-03]: http://lua-users.org/lists/lua-l/2007-03/threads.html#00309
[lua-l]: http://lua-users.org/lists/lua-l/

###  <a name="apr.sleep" href="#apr.sleep">`apr.sleep(seconds) → nothing`</a>

Sleep for the specified number of <tt>*seconds*</tt>. Sub-second resolution is
supported so you can for example give 0.5 to sleep for half a second. This
function may sleep for longer than the specified time because of platform
limitations.

###  <a name="apr.time_now" href="#apr.time_now">`apr.time_now() → time`</a>

Get the current time as the number of seconds since 00:00:00 January 1, 1970
[UTC] [utc]. If Lua is compiled with floating point support then more
precision will be available in the decimal part of the returned number.

###  <a name="apr.time_explode" href="#apr.time_explode">`apr.time_explode([time [, timezone]]) → components`</a>

Convert the numeric value <tt>*time*</tt> (current time if none given) to its human
readable components. If <tt>*timezone*</tt> isn't given or evaluates to <tt>*false*</tt> the
local timezone is used. If its a number then this number is used as the
offset in seconds from [GMT] [gmt]. The value <tt>*true*</tt> is treated the same as 0,
i.e. GMT. On success the table of components is returned, otherwise a <tt>*nil*</tt>
followed by an error message is returned. The resulting table contains the
following fields:

 - `usec` is the number of microseconds past `sec`
 - `sec` is the number of seconds past `min` (0-61)
 - `min` is the number of minutes past `hour` (0-59)
 - `hour` is the number of hours past midnight (0-23)
 - `day` is the day of the month (1-31)
 - `month` is the month of the year (0-11).
 - `year` is the year since 1900
 - `wday` is the number of days since Sunday (0-6)
 - `yday` is the number of days since January 1 (0-365)
 - `gmtoff` is the number of seconds east of [UTC] [utc]
 - `isdst` is <tt>*true*</tt> when [daylight saving time] [dst] is in effect

All of these fields are numbers except for `isdst` which is a boolean.
Here's an example of the output returned by [apr.time\_explode()](#apr.time_explode):

    > -- Note that numeric dates are always in UTC while tables with
    > -- date components are in the local timezone by default.
    > components = apr.time_explode(1032030336.18671)
    > = components
    {
     usec = 186710,
     sec = 36,
     min = 5,
     hour = 21,
     day = 14,
     month = 9,
     year = 2002,
     wday = 7,
     yday = 257,
     gmtoff = 7200, -- my local timezone
     isdst = true,
    }
    > -- To convert a table of date components back into a number
    > -- you can use the apr.time_implode() function as follows:
    > = apr.time_implode(components)
    1032030336.18671

[gmt]: http://en.wikipedia.org/wiki/Greenwich_Mean_Time
[utc]: http://en.wikipedia.org/wiki/Coordinated_Universal_Time
[dst]: http://en.wikipedia.org/wiki/Daylight_saving_time

###  <a name="apr.time_implode" href="#apr.time_implode">`apr.time_implode(components) → time`</a>

Convert a table of time <tt>*components*</tt> to its numeric value. On success the
time is returned, otherwise a <tt>*nil*</tt> followed by an error message is returned.
See [apr.time\_explode()](#apr.time_explode) for a list of supported components.

###  <a name="apr.time_format" href="#apr.time_format">`apr.time_format(format [, time]) → formatted`</a>

Format <tt>*time*</tt> (current time if none given) according to string <tt>*format*</tt>. On
success the formatted time is returned, otherwise a <tt>*nil*</tt> followed by an error
message is returned. The two special formats `'ctime'` and `'rfc822'` result
in a fixed length string of 24 or 29 characters in length. The <tt>*time*</tt>
argument may be either a number or a table with components like those
returned by [apr.time\_explode()](#apr.time_explode).

    > = apr.time_format('%Y-%m-%d %H:%I:%S', apr.time_now())
    '2010-09-25 17:05:08'
    > = apr.time_format('ctime', apr.time_now())
    'Sat Sep 25 17:26:22 2010'
    > = apr.time_format('rfc822', apr.time_now())
    'Sat, 25 Sep 2010 15:26:36 GMT'

*This function is not binary safe.*

## <a name="uniform_resource_identifier_parsing" href="#uniform_resource_identifier_parsing">Uniform resource identifier parsing</a>

###  <a name="apr.uri_parse" href="#apr.uri_parse">`apr.uri_parse(uri) → components`</a>

Parse the [Uniform Resource Identifier] [uri] <tt>*uri*</tt>. On success a table of
components is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned. The table of components can have the following fields, all
strings:

 - `scheme` is the part of the URI before `://` (as in `http`, `ftp`, etc.)
 - `user` is the user name, as in `scheme://user:pass@host:port/`
 - `password` is the password, as in `scheme://user:pass@host:port/`
 - `hostinfo` is the combined `[user[:password]@]hostname[:port]`
 - `hostname` is the host name or IP address
 - `port` is the port number
 - `path` is the request path (`/` if only `scheme://hostname` was given)
 - `query` is everything after a `?` in the path, if present
 - `fragment` is the trailing `#fragment` string, if present

[uri]: http://en.wikipedia.org/wiki/Uniform_Resource_Identifier

*This function is not binary safe.*

###  <a name="apr.uri_unparse" href="#apr.uri_unparse">`apr.uri_unparse(components [, option]) → uri`</a>

Convert a table of [URI] [uri] <tt>*components*</tt> into a URI string. On success the
URI string is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned. The list of fields in the <tt>*components*</tt> table is available in the
documentation for [apr.uri\_parse()](#apr.uri_parse). The argument <tt>*option*</tt> may be one of the
following:

 - `hostinfo` to unparse the components `[user[:password]@]hostname[:port]`
 - `pathinfo` to unparse the components `path[?query[#fragment]]`

*This function is not binary safe.*

###  <a name="apr.uri_port_of_scheme" href="#apr.uri_port_of_scheme">`apr.uri_port_of_scheme(scheme) → port`</a>

Return the default port for the given [URI] [uri] <tt>*scheme*</tt> string. [Since at
least APR 1.2.8] [uri_ports] the following schemes are supported: `acap`,
`ftp`, `gopher`, `http`, `https`, `imap`, `ldap`, `nfs`, `nntp`, `pop`,
`prospero`, `rtsp`, `sip`, `snews`, `ssh`, `telnet`, `tip`, `wais`,
`z39.50r` and `z39.50s`.

[uri_ports]: http://svn.apache.org/viewvc/apr/apr/trunk/uri/apr_uri.c?view=markup#l43

## <a name="user_group_identification" href="#user_group_identification">User/group identification</a>

###  <a name="apr.user_get" href="#apr.user_get">`apr.user_get() → username, groupname`</a>

Get the username and groupname of the calling process. On success the
username and groupname are returned, otherwise a <tt>*nil*</tt> followed by an error
message is returned.

*This function is not binary safe.*

###  <a name="apr.user_homepath_get" href="#apr.user_homepath_get">`apr.user_homepath_get(username) → homepath`</a>

Get the [home directory] [home] for the named user. On success the directory
pathname is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned.

[home]: http://en.wikipedia.org/wiki/Home_directory

*This function is not binary safe.*

## <a name="universally_unique_identifiers" href="#universally_unique_identifiers">Universally unique identifiers</a>

[Universally unique identifiers] [uuid] are a standard for generating unique
strings that are specific to the machine on which they are generated and/or
the time at which they are generated. They can be used as primary keys in
databases and are used to uniquely identify file system types and instances
on modern operating systems. This is what a standard format UUID looks like:

    > = apr.uuid_format(apr.uuid_get())
    '0ad5d4a4-591e-41f7-8be4-07d7961a8079'

[uuid]: http://en.wikipedia.org/wiki/Universally_unique_identifier

###  <a name="apr.uuid_get" href="#apr.uuid_get">`apr.uuid_get() → binary`</a>

Generate and return a UUID as a binary string of 16 bytes.

###  <a name="apr.uuid_format" href="#apr.uuid_format">`apr.uuid_format(binary) → formatted`</a>

Format a UUID of 16 bytes following the standard format of 32 hexadecimal
digits, displayed in 5 groups separated by hyphens, in the form `8-4-4-4-12`
for a total of 36 characters, like `f5dc3464-6c8f-654e-a407-b15b7a30f038`.
On success the formatted UUID is returned, otherwise a <tt>*nil*</tt> followed by an
error message is returned.

###  <a name="apr.uuid_parse" href="#apr.uuid_parse">`apr.uuid_parse(formatted) → binary`</a>

Parse a standard format UUID and return its 16-byte equivalent. On success
the parsed UUID is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned.

## <a name="character_encoding_translation" href="#character_encoding_translation">Character encoding translation</a>

###  <a name="apr.xlate" href="#apr.xlate">`apr.xlate(input, from, to) → translated`</a>

Translate a string of text from one [character encoding] [charenc] to
another. The <tt>*from*</tt> and <tt>*to*</tt> arguments are strings identifying the source and
target character encoding. The special value `'locale'` indicates the
character set of the [current locale] [locale]. On success the translated
string is returned, otherwise a <tt>*nil*</tt> followed by an error message is
returned.

Which character encodings are supported by [apr.xlate()](#apr.xlate) is system dependent
because APR can use both the system's [iconv] [iconv] implementation and the
bundled library [apr-iconv] [apr_iconv]. To get a list of valid character
encoding names you can look through the [apr-iconv/ccs] [iconv_ccs] and
[apr-iconv/ces] [iconv_ces] directories (those are links to the web
interface of the apr-iconv repository).

[charenc]: http://en.wikipedia.org/wiki/Character_encoding
[locale]: http://en.wikipedia.org/wiki/Locale
[iconv]: http://en.wikipedia.org/wiki/Iconv
[apr_iconv]: http://apr.apache.org/docs/apr-iconv/trunk/group__apr__iconv.html
[iconv_ccs]: http://svn.apache.org/viewvc/apr/apr-iconv/trunk/ccs/
[iconv_ces]: http://svn.apache.org/viewvc/apr/apr-iconv/trunk/ces/

*This function is binary safe.*

## <a name="xml_parsing" href="#xml_parsing">XML parsing</a>

This module enables parsing of [XML] [xml] documents. Unlike [LuaExpat]
[lxp] the parsers returned by [apr.xml()](#apr.xml) don't use callbacks, instead they
parse XML into a [document object model] [dom] which is then exposed to Lua.
Because of this you can't use [apr.xml()](#apr.xml) for incremental parsing. To parse
an XML document you follow these steps:

1. Create an XML parser object by calling [apr.xml()](#apr.xml)
2. Parse the document by calling [xml\_parser:feed()](#xml_parser:feed) repeatedly until the
   full document has been parsed
3. Signal to the parser that the full document has been parsed by calling
   [xml\_parser:done()](#xml_parser:done)
4. Get the parse information by calling [xml\_parser:getinfo()](#xml_parser:getinfo)

Right now the only way to get the parse information is by calling
[xml\_parser:getinfo()](#xml_parser:getinfo) which converts the information to a Lua table
following the [Lua object model] [lom] defined by [LuaExpat] [lxp]. The Lua
object model is a mapping of XML to Lua tables that's not 100% complete
(e.g. it doesn't include namespaces) but makes it a lot easier to deal with
XML in Lua.

In the future this module might expose the full XML parse tree to Lua as
userdata objects, so that Lua has access to all parse information. This
would also make it possible to expose the [apr\_xml\_to\_text()]
[xml_to_text] function.

[xml]: http://en.wikipedia.org/wiki/XML
[lxp]: http://www.keplerproject.org/luaexpat/
[lom]: http://www.keplerproject.org/luaexpat/lom.html
[dom]: http://en.wikipedia.org/wiki/XML#Document_Object_Model_.28DOM.29
[xml_to_text]: http://apr.apache.org/docs/apr/trunk/group___a_p_r___util___x_m_l.html#g4485edce130dc1e9a3da3a633a75ffb3

###  <a name="apr.xml" href="#apr.xml">`apr.xml([filename]) → xml_parser`</a>

Create an XML parser. If the optional string <tt>*filename*</tt> is given, the file
pointed to by <tt>*filename*</tt> will be parsed. On success the parser object is
returned, otherwise a <tt>*nil*</tt> followed by an error message is returned.

*This function is not binary safe.*

###  <a name="xml_parser:feed" href="#xml_parser:feed">`xml_parser:feed(input) → status`</a>

Feed the string <tt>*input*</tt> into the XML parser. On success <tt>*true*</tt> is returned,
otherwise a <tt>*nil*</tt> followed by an error message is returned.

*This function is binary safe.*

###  <a name="xml_parser:done" href="#xml_parser:done">`xml_parser:done() → status`</a>

Terminate the parsing and save the resulting parse information. On success
<tt>*true*</tt> is returned, otherwise a <tt>*nil*</tt> followed by an error message is returned.

###  <a name="xml_parser:geterror" href="#xml_parser:geterror">`xml_parser:geterror() → message`</a>

Fetch additional error information from the parser after one of its methods
has failed.

###  <a name="xml_parser:getinfo" href="#xml_parser:getinfo">`xml_parser:getinfo() → table`</a>

Convert the parse information to a Lua table following the
[Lua Object Model] [lom] defined by [LuaExpat] [lxp].

###  <a name="xml_parser:close" href="#xml_parser:close">`xml_parser:close() → status`</a>

Close the XML parser and destroy any parse information. This will be done
automatically when the <tt>*xml_parser*</tt> object is garbage collected which means
you don't need to call this unless you want to reclaim memory as soon as
possible (e.g. because you just parsed a large XML document).

## <a name="serialization" href="#serialization">Serialization</a>

The Lua/APR binding contains a serialization function based on the [Metalua
table-to-source serializer] [metalua_serializer] extended to support
function upvalues and userdata objects created by the Lua/APR binding. The
following Lua values can be serialized:

 - strings, numbers, booleans, <tt>*nil*</tt> (scalars)
 - Lua functions (including upvalues)
 - userdata objects created by the Lua/APR binding
 - tables thereof. There is no restriction on keys; recursive and shared
   sub-tables are handled correctly.

Restrictions:

 - *Metatables and environments aren't saved*;
   this might or might not be what you want.

 - *If multiple functions share a scalar upvalue they will each get their
   own copy.* Because it is impossible to join upvalues of multiple
   functions in Lua 5.1 this won't be fixed any time soon.

The following functions in the Lua/APR binding internally use serialization
to transfer Lua functions and other values between operating system threads:

 - [apr.thread()](#apr.thread) and [thread:wait()](#thread:wait)
 - [queue:push()](#queue:push) and [queue:pop()](#queue:pop)
 - [queue:try\_push()](#queue:try_push) and [queue:try\_pop()](#queue:try_pop)

[metalua_serializer]: https://github.com/fab13n/metalua/blob/master/src/lib/serialize.lua

###  <a name="apr.serialize" href="#apr.serialize">`apr.serialize(...) → string`</a>

Serialize any number of Lua values (a tuple) into a source code string. When
passed to [apr.unserialize()](#apr.unserialize) this string results in a tuple of values that
is structurally identical to the original tuple.


###  <a name="apr.unserialize" href="#apr.unserialize">`apr.unserialize(string) → ...`</a>

Unserialize a source code string into one or more Lua values.


###  <a name="apr.ref" href="#apr.ref">`apr.ref(object) → uuid`</a>

Prepare the Lua/APR userdata <tt>*object*</tt> so that it can be referenced from
another Lua state in the same operating system process and associate a
[UUID] [uuid] with the object. The UUID is returned as a string. When you
pass this UUID to [apr.deref()](#apr.deref) you'll get the same object back. This only
works once, but of course you're free to generate another UUID for the same
object.

[uuid]: http://en.wikipedia.org/wiki/Universally_unique_identifier

###  <a name="apr.deref" href="#apr.deref">`apr.deref(uuid) → object`</a>

Convert a UUID that was previously returned by [apr.ref()](#apr.ref) into a userdata
object and return the object. You can only dereference a UUID once, but of
course you're free to generate another UUID for the same object.

## <a name="miscellaneous_functions" href="#miscellaneous_functions">Miscellaneous functions</a>

###  <a name="apr.platform_get" href="#apr.platform_get">`apr.platform_get() → name`</a>

Get the name of the platform for which the Lua/APR binding was compiled.
Returns one of the following strings:

 - `'UNIX'`
 - `'WIN32'`
 - `'NETWARE'`
 - `'OS2'`

Please note that the labels returned by [apr.platform\_get()](#apr.platform_get) don't imply
that these platforms are fully supported; the author of the Lua/APR binding
doesn't have NETWARE and OS2 environments available for testing.

###  <a name="apr.version_get" href="#apr.version_get">`apr.version_get() → versions_table`</a>

Get the versions of the libraries used by the Lua/APR binding.
Returns a table with one or more of the following fields:

 - **apr**: The version of the Apache Portable Runtime library. This field
   is always available.

 - **aprutil**: The version of the APR utility library. This field is only
   available when Lua/APR is compiled against APR and APR-util 1.x because
   in version 2.x the utility library has been absorbed back into the APR
   library; there is no longer a distinction between the APR core and APR
   utility libraries.

 - **apreq**: The version of the HTTP request parsing library. This field is
   only available when the libapreq2 library is installed.

Each field is a string containing three numbers separated by dots. These
numbers have the following meaning:

1. Major [API] [api] changes that can cause compatibility problems between
   the Lua/APR binding and APR library

2. Minor API changes that shouldn't impact existing functionality in the
   Lua/APR binding

3. Used exclusively for bug fixes

This function can be useful when you want to know whether a certain bug fix
has been applied to APR and/or APR-util or if you want to report a bug in
APR, APR-util or the Lua/APR binding.

If you're looking for the version of the Lua/APR binding you can use the
`apr._VERSION` string, but note that Lua/APR currently does not adhere to
the above versioning rules.

[api]: http://en.wikipedia.org/wiki/Application_programming_interface

###  <a name="apr.os_default_encoding" href="#apr.os_default_encoding">`apr.os_default_encoding() → name`</a>

Get the name of the system default character set as a string.

###  <a name="apr.os_locale_encoding" href="#apr.os_locale_encoding">`apr.os_locale_encoding() → name`</a>

Get the name of the current locale character set as a string. If the current
locale's data cannot be retrieved on this system, the name of the system
default character set is returned instead.

###  <a name="apr.type" href="#apr.type">`apr.type(object) → name`</a>

Return the type of a userdata object created by the Lua/APR binding. If
<tt>*object*</tt> is of a known type one of the following strings will be returned,
otherwise nothing is returned:

 - `'file'`
 - `'directory'`
 - `'socket'`
 - `'thread'`
 - `'process'`
 - `'dbm'`
 - `'database driver'`
 - `'prepared statement'`
 - `'result set'`
 - `'memcache client'`
 - `'memcache server'`
 - `'md5 context'`
 - `'sha1 context'`
 - `'xml parser'`

## <a name="file_system_permissions" href="#file_system_permissions">File system permissions</a>

The Apache Portable Runtime represents file system permissions somewhat
similar to those of [UNIX] [unix]. There are three categories of
permissions: the user, the group and everyone else (the world). Each
category supports read and write permission bits while the meaning of the
third permission bit differs between categories.

[unix]: http://en.wikipedia.org/wiki/Unix

### How Lua/APR presents permissions

The Lua/APR binding uses a string of 9 characters to represent file system
permissions such as those returned by [apr.stat()](#apr.stat). Here's an example:

    > = apr.stat('.', 'protection')
    'rwxr-xr-x'

This is the syntax of these permissions strings:

 - Character 1: `r` if the user has read permissions, `-` otherwise
 - Character 2: `w` if the user has write permissions, `-` otherwise
 - Character 3: `x` if the user has execute permissions, `S` if the user
   has set user id permissions or `s` if the user has both permissions
 - Characters 4..6: the same respective permissions for the group
 - Characters 7..8: the same respective permissions for the world
 - Character 9: `x` if the world has execute permissions, `T` if the world
   has sticky permissions or `t` if the world has both permissions

As an example, `rwxrwx---` means the user and group have full permissions
while the world has none. Another example: `r-xr-xr-x` means no-one has
write permissions.

### How you can request permissions

When you need to request file system permissions for an operation like
[reading](#apr.file_open) or [copying](#apr.file_copy) a file there are two
string formats you can use. The first format is a string of nine characters
that lists each permission explicitly. This is the format documented above.

The second format is very flexible and is one of the formats accepted by the
Linux command line program [chmod] [chmod]. The permissions are split in
three groups with a one-letter code: user is `u`, group is `g` and world is
`o` (for "others"). One or more permissions can then be assigned to one or
more of these groups. Here's an example that requests read permission for
user, group and others: `ugo=r`. Now when you also need write permission for
user and group, you can use `ugo=r,ug=w`.

[chmod]: http://en.wikipedia.org/wiki/chmod

## <a name="error_handling" href="#error_handling">Error handling</a>

Most functions in the Lua/APR binding follow the Lua idiom of returning <tt>*nil*</tt>
followed by an error message string. These functions also return a third
argument which is the symbolic name of the error (or the error code in case
a symbolic name cannot be determined). The following symbolic names are
currently defined (there's actually a lot more but they shouldn't be
relevant when working in Lua):

 - `'ENOSTAT'`: APR was unable to perform a stat on the file
 - `'EBADDATE'`: APR was given an invalid date
 - `'EINVALSOCK'`: APR was given an invalid socket
 - `'ENOPROC'`: APR was not given a process structure
 - `'ENOTIME'`: APR was not given a time structure
 - `'ENODIR'`: APR was not given a directory structure
 - `'ENOTHREAD'`: APR was not given a thread structure
 - `'EBADIP'`: the specified IP address is invalid
 - `'EBADMASK'`: the specified netmask is invalid
 - `'EDSOOPEN'`: APR was unable to open the DSO object
 - `'EABSOLUTE'`: the given path was absolute
 - `'ERELATIVE'`: the given path was relative
 - `'EINCOMPLETE'`: the given path was neither relative nor absolute
 - `'EABOVEROOT'`: the given path was above the root path
 - `'EBADPATH'`: the given path was bad
 - `'EPATHWILD'`: the given path contained wildcards
 - `'ESYMNOTFOUND'`: could not find the requested symbol
 - `'EPROC_UNKNOWN'`: the given process was not recognized by APR
 - `'ENOTENOUGHENTROPY'`: APR could not gather enough [entropy] [entropy] to continue
 - `'TIMEUP'`: the operation did not finish before the timeout
 - `'INCOMPLETE'`: the operation was incomplete although some processing was performed and the results are partially valid
 - `'EOF'`: APR has encountered the end of the file
 - `'ENOTIMPL'`: the APR function has not been implemented on this platform, either because nobody has gotten to it yet, or the function is impossible on this platform
 - `'EMISMATCH'`: two passwords do not match
 - `'EACCES'`: permission denied
 - `'EEXIST'`: file exists
 - `'ENAMETOOLONG'`: path name is too long
 - `'ENOENT'`: no such file or directory
 - `'ENOTDIR'`: not a directory
 - `'ENOSPC'`: no space left on device
 - `'ENOMEM'`: not enough memory
 - `'EMFILE'`: too many open files
 - `'ENFILE'`: file table overflow
 - `'EBADF'`: bad file number
 - `'EINVAL'`: invalid argument
 - `'ESPIPE'`: illegal seek
 - `'EAGAIN'`: operation would block
 - `'EINTR'`: interrupted system call
 - `'ENOTSOCK'`: socket operation on a non-socket
 - `'ECONNREFUSED'`: connection refused
 - `'EINPROGRESS'`: operation now in progress
 - `'ECONNABORTED'`: software caused connection abort
 - `'ECONNRESET'`: connection Reset by peer
 - `'ETIMEDOUT'`: operation timed out (deprecated)
 - `'EHOSTUNREACH'`: no route to host
 - `'ENETUNREACH'`: network is unreachable
 - `'EFTYPE'`: inappropriate file type or format
 - `'EPIPE'`: broken pipe
 - `'EXDEV'`: cross device link
 - `'ENOTEMPTY'`: directory not empty
 - `'EAFNOSUPPORT'`: address family not supported

Note that the error descriptions above were copied verbatim from [apr_errno.h] [errno].

[entropy]: http://en.wikipedia.org/wiki/Entropy_%28computing%29
[errno]: http://svn.apache.org/viewvc/apr/apr/trunk/include/apr_errno.h?view=markup

## <a name="example_http_client" href="#example_http_client">Example: HTTP client</a>

The following Lua script implements a minimal [HTTP client] [http] which can
be used to download a given [URL] [url] on the command line (comparable to
[wget] [wget] and [curl] [curl]):

    $ FILE=lua-5.1.4.tar.gz
    $ URL=http://www.lua.org/ftp/$FILE
    $ time curl -s $URL > $FILE
    0,01s user 0,02s system 6% cpu 0,465 total
    $ time lua examples/download.lua $URL > $FILE
    0,03s user 0,02s system 9% cpu 0,549 total

Note that this script and Lua/APR in general are a bit handicapped in that
they don't support [HTTPS] [https] because the Apache Portable Runtime does
not support encrypted network communication.

[url]: http://en.wikipedia.org/wiki/Uniform_Resource_Locator
[wget]: http://en.wikipedia.org/wiki/wget
[curl]: http://en.wikipedia.org/wiki/cURL
[https]: http://en.wikipedia.org/wiki/HTTPS

    local apr = require 'apr'
    
    -- Report errors without stack traces.
    local function assert(...)
      local status, message = ...
      if not status then
        io.stderr:write('Error: ', message or '(no message)', '\n')
        os.exit(1)
      end
      return ...
    end
    
    local function getpage(url)
      local components = assert(apr.uri_parse(url))
      assert(components.scheme == 'http', "invalid protocol!")
      local port = assert(components.port or apr.uri_port_of_scheme(components.scheme))
      local socket = assert(apr.socket_create())
      assert(socket:connect(components.hostname, port))
      local pathinfo = assert(apr.uri_unparse(components, 'pathinfo'))
      assert(socket:write('GET ', pathinfo, ' HTTP/1.0\r\n',
                          'Host: ', components.hostname, '\r\n',
                          '\r\n'))
      local statusline = assert(socket:read(), 'HTTP response missing status line!')
      local protocol, statuscode, reason = assert(statusline:match '^(%S+)%s+(%S+)%s+(.-)$')
      local redirect = statuscode:find '^30[123]$'
      for line in socket:lines() do
        local name, value = line:match '^(%S+):%s+(.-)\r?$'
        if name and value then
          if redirect and name:lower() == 'location' then
            io.stderr:write("Following redirect to ", value, " ..\n")
            return getpage(value)
          end
        else
          return (assert(socket:read '*a', 'HTTP response missing body?!'))
        end
      end
      if statuscode ~= '200' then error(reason) end
    end
    
    local usage = "Please provide a URL to download as argument"
    io.write(getpage(assert(arg and arg[1], usage)))
    
    -- vim: ts=2 sw=2 et

## <a name="example_single_threaded_webserver" href="#example_single_threaded_webserver">Example: Single threaded webserver</a>

The following script implements a minimalistic webserver on top of Lua/APR
[network sockets] [socket_module]. It should work out of the box on Windows
and UNIX, although you might get a prompt from your firewall. Once the server
is running you can open <http://localhost:8080> in your web browser to see
the server in action. Because the server is single threaded I was curious how
bad it would perform, so I tested it with [ApacheBench] [ab]:

    $ lua examples/webserver.lua &
    $ ab -qt5 http://localhost:8080/ | grep 'Requests per second\|Transfer rate'
    Requests per second:    3672.19 [#/sec] (mean)
    Transfer rate:          2201.88 [Kbytes/sec] received

That's not too bad for 40 lines of code! For more complex webservers see the
[multi threaded] [threaded_server] and [asynchronous] [async_server]
webserver examples.

*Note that all benchmarks are run on my Compaq Presario CQ60 laptop (which
features an Intel Core 2 Duo T5800 processor clocked at 2 GHz and 3 GB of
RAM) and that the Lua/APR binding was compiled without debugging symbols.*

[socket_module]: #network_i_o_handling
[ab]: http://en.wikipedia.org/wiki/ApacheBench
[threaded_server]: #example_multi_threaded_webserver
[async_server]: #example_asynchronous_webserver

    local port_number = tonumber(arg[1]) or 8080
    local bind_address = arg[2] or '*'
    
    -- Load the Lua/APR binding.
    local apr = require 'apr'
    
    -- Initialize the server socket.
    local server = assert(apr.socket_create())
    assert(server:bind(bind_address, port_number))
    assert(server:listen(1))
    print("Running webserver on http://" .. bind_address .. ":" .. port_number .. " ..")
    
    -- Wait for clients to serve.
    local visitor = 1
    local template = [[
    <html>
      <head>
        <title>Hello from Lua/APR!</title>
        <style type="text/css">
          body { font-family: sans-serif; }
          dt { font-weight: bold; }
          dd { font-family: monospace; margin: -1.4em 0 0 14em; }
        </style>
      </head>
      <body>
        <h1>Hello from Lua/APR!</h1>
        <p><em>You are visitor number %010i.</em></p>
        <p>The headers provided by your web browser:</p>
        <dl>%s</dl>
      </body>
    </html>
    ]]
    while true do
      local status, message = pcall(function()
        local client = assert(server:accept())
        -- Read the HTTP request so that the client can receive data.
        local request = assert(client:read(), "Failed to receive request from client!")
        local method, location, protocol = assert(request:match '^(%w+)%s+(%S+)%s+(%S+)')
        local headers = {}
        for line in client:lines() do
          local name, value = line:match '^(%S+):%s+(.-)$'
          if not name then break end
          table.insert(headers, '<dt>' .. name .. ':</dt><dd>' .. value .. '</dd>')
        end
        -- Generate the HTTP response.
        table.sort(headers)
        content = template:format(visitor, table.concat(headers))
        client:write(protocol, ' 200 OK\r\n',
                     'Content-Type: text/html\r\n',
                     'Content-Length: ' .. #content .. '\r\n',
                     'Connection: close\r\n',
                     '\r\n',
                     content)
        assert(client:close())
        visitor = visitor + 1
      end)
      if not status then
        print('Error while serving request:', message)
      end
    end
    
    -- vim: ts=2 sw=2 et

## <a name="example_multi_threaded_webserver" href="#example_multi_threaded_webserver">Example: Multi threaded webserver</a>

Thanks to the [multi threading] [threading_module] and [thread queue]
[thread_queues] modules in the Apache Portable Runtime it is possible to
improve the performance of the [single threaded webserver] [simple_server]
from the previous example. Here is a benchmark of the multi threaded code
listed below (again using [ApacheBench] [ab], but now with the `-c`
argument):

    $ CONCURRENCY=4
    $ lua examples/threaded-webserver.lua $CONCURRENCY &
    $ ab -qt5 -c$CONCURRENCY http://localhost:8080/ | grep 'Requests per second\|Transfer rate'
    Requests per second:    9210.72 [#/sec] (mean)
    Transfer rate:          5594.79 [Kbytes/sec] received

Comparing these numbers to the benchmark of the [single threaded webserver]
[simple_server] we can see that the number of requests per second went from
3670 to 9210, more than doubling the throughput of the webserver on a dual
core processor. If you want to know how we can make it even faster, have a
look at the [asynchronous webserver] [async_server] example.

[threading_module]: #multi_threading
[thread_queues]: #thread_queues
[simple_server]: #example_single_threaded_webserver
[ab]: http://en.wikipedia.org/wiki/ApacheBench
[thread_pool]: http://en.wikipedia.org/wiki/Thread_pool_pattern
[async_server]: #example_asynchronous_webserver

    local num_threads = tonumber(arg[1]) or 2
    local port_number = tonumber(arg[2]) or 8080
    
    local template = [[
    <html>
      <head>
        <title>Hello from Lua/APR!</title>
        <style type="text/css">
          body { font-family: sans-serif; }
          dt { font-weight: bold; }
          dd { font-family: monospace; margin: -1.4em 0 0 14em; }
        </style>
      </head>
      <body>
        <h1>Hello from Lua/APR!</h1>
        <p><em>This web page was served by worker %i.</em></p>
        <p>The headers provided by your web browser:</p>
        <dl>%s</dl>
      </body>
    </html>
    ]]
    
    -- Load the Lua/APR binding.
    local apr = require 'apr'
    
    -- Initialize the server socket.
    local server = assert(apr.socket_create())
    assert(server:bind('*', port_number))
    assert(server:listen(num_threads * 2))
    print("Running webserver with " .. num_threads .. " client threads on http://localhost:" .. port_number .. " ..")
    
    -- Create the thread queue (used to pass sockets between threads).
    local queue = apr.thread_queue(num_threads)
    
    -- Define the function to execute in each child thread.
    function worker(thread_id, queue, template)
      pcall(require, 'luarocks.require')
      local apr = require 'apr'
      while true do
        local client, msg, code = queue:pop()
        assert(client or code == 'EINTR', msg)
        if client then
          local status, message = pcall(function()
            local request = assert(client:read(), "Failed to receive request from client!")
            local method, location, protocol = assert(request:match '^(%w+)%s+(%S+)%s+(%S+)')
            local headers = {}
            for line in client:lines() do
              local name, value = line:match '^(%S+):%s+(.-)$'
              if not name then
                break
              end
              table.insert(headers, '<dt>' .. name .. ':</dt><dd>' .. value .. '</dd>')
            end
            table.sort(headers)
            local content = template:format(thread_id, table.concat(headers))
            client:write(protocol, ' 200 OK\r\n',
                         'Content-Type: text/html\r\n',
                         'Content-Length: ' .. #content .. '\r\n',
                         'Connection: close\r\n',
                         '\r\n',
                         content)
            assert(client:close())
          end)
          if not status then
            print('Error while serving request:', message)
          end
        end
      end
    end
    
    -- Create the child threads and keep them around in a table (so that they are
    -- not garbage collected while we are still using them).
    local pool = {}
    for i = 1, num_threads do
      table.insert(pool, apr.thread(worker, i, queue, template))
    end
    
    -- Enter the accept() loop in the parent thread.
    while true do
      local status, message = pcall(function()
        local client = assert(server:accept())
        assert(queue:push(client))
      end)
      if not status then
        print('Error while serving request:', message)
      end
    end
    
    -- vim: ts=2 sw=2 et

## <a name="example_asynchronous_webserver" href="#example_asynchronous_webserver">Example: Asynchronous webserver</a>

We can do even better than the performance of the multi threaded webserver by
using the [APR pollset module] [pollset_module]. The following webserver uses
asynchronous network communication to process requests from multiple clients
'in parallel' without using multiple threads or processes. Here is a
benchmark of the asynchronous code listed below (again using [ApacheBench]
[ab] with the `-c` argument):

    $ CONCURRENCY=4
    $ POLLSET_SIZE=10
    $ lua examples/async-webserver.lua $POLLSET_SIZE 8080 cheat &
    $ ab -qt5 -c$CONCURRENCY http://localhost:8080/ | grep 'Requests per second\|Transfer rate'
    Requests per second:    11312.64 [#/sec] (mean)
    Transfer rate:          6219.74 [Kbytes/sec] received

The [single threaded webserver] [simple_server] handled 3670 requests per
second, the [multi threaded webserver] [threaded_server] handled 9210
requests per second and the asynchronous webserver below can handle 11310
requests per second. Actually in the above benchmark I may have cheated a bit
(depending on whether your goal is correct usage or performance). When I
started writing this asynchronous server example I didn't bother to add
writable sockets to the pollset, instead I handled the request and response
once the client socket was reported as readable by the pollset. Later on I
changed the code to handle writing using the pollset and I noticed that the
performance dropped. This is probably because the example is so contrived.
Anyway here's the performance without cheating:

    $ lua examples/async-webserver.lua $POLLSET_SIZE 8080 &
    $ ab -qt5 -c$CONCURRENCY http://localhost:8888/ | grep 'Requests per second\|Transfer rate'
    Requests per second:    9867.17 [#/sec] (mean)
    Transfer rate:          5425.03 [Kbytes/sec] received

Now follows the implementation of the asynchronous webserver example:

[pollset_module]: #pollset
[ab]: http://en.wikipedia.org/wiki/ApacheBench
[simple_server]: #example_single_threaded_webserver
[threaded_server]: #example_multi_threaded_webserver

    local pollset_size = tonumber(arg[1]) or 10
    local port_number = tonumber(arg[2]) or 8080
    local cheat = arg[3] == 'cheat' -- cheat to make it faster?
    
    local template = [[
    <html>
      <head>
        <title>Hello from Lua/APR!</title>
        <style type="text/css">
          body { font-family: sans-serif; }
          dt { font-weight: bold; }
          dd { font-family: monospace; margin: -1.4em 0 0 14em; }
        </style>
      </head>
      <body>
        <h1>Hello from Lua/APR!</h1>
        <p>The headers provided by your web browser:</p>
        <dl>%s</dl>
      </body>
    </html>
    ]]
    
    -- Load the Lua/APR binding.
    local apr = require 'apr'
    
    -- Initialize the server socket.
    local server = assert(apr.socket_create())
    assert(server:bind('*', port_number))
    assert(server:listen(pollset_size))
    
    -- Create the pollset.
    local pollset = assert(apr.pollset(pollset_size))
    assert(pollset:add(server, 'input'))
    
    -- Use a table indexed with socket objects to keep track of "sessions".
    local sessions = setmetatable({}, {__mode='k'})
    
    -- Enter the I/O loop.
    print("Running webserver on http://localhost:" .. port_number .. " ..")
    while true do
      local readable, writable = assert(pollset:poll(-1))
      -- Process requests.
      for _, socket in ipairs(readable) do
        if socket == server then
          local client = assert(server:accept())
          assert(pollset:add(client, 'input'))
        else
          local request = assert(socket:read(), "Failed to receive request from client!")
          local method, location, protocol = assert(request:match '^(%w+)%s+(%S+)%s+(%S+)')
          local headers = {}
          for line in socket:lines() do
            local name, value = line:match '^(%S+):%s+(.-)$'
            if not name then
              break
            end
            table.insert(headers, '<dt>' .. name .. ':</dt><dd>' .. value .. '</dd>')
          end
          table.sort(headers)
          local content = template:format(table.concat(headers))
          assert(socket:write(
            protocol, ' 200 OK\r\n',
            'Content-Type: text/html\r\n',
            'Content-Length: ', #content, '\r\n',
            'Connection: close\r\n',
            '\r\n'))
          if cheat then
            assert(socket:write(content))
            assert(pollset:remove(socket))
            assert(socket:close())
          else
            sessions[socket] = content
            assert(pollset:remove(socket))
            assert(pollset:add(socket, 'output'))
          end
        end
      end
      if not cheat then
        -- Process responses.
        for _, socket in ipairs(writable) do
          assert(socket:write(sessions[socket]))
          -- I don't like that when I switch the order of these
          -- calls, it breaks... Seems like a fairly big gotcha.
          assert(pollset:remove(socket))
          assert(socket:close())
        end
      end
    end
    
    -- vim: ts=2 sw=2 et