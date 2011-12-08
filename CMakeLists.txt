# Copyright (C) 2011 LuaDist.
# Created by Michal Kottman
# Redistribution and use of this file is allowed according to the terms of the MIT license.
# For details see the COPYRIGHT file distributed with LuaDist.
# Please note that the package source code is licensed under its own license.

project(lua-apr C)
cmake_minimum_required(VERSION 2.6)
include(dist.cmake)

find_package(APR REQUIRED)

set(SOURCES src/base64.c
	src/buffer.c
	src/crypt.c
	src/date.c
	src/dbd.c
	src/dbm.c
	src/env.c
	src/errno.c
	src/filepath.c
	src/fnmatch.c
	src/getopt.c
	src/http.c
	src/io_dir.c
	src/io_file.c
	src/io_net.c
	src/io_pipe.c
	src/ldap.c
	src/lua_apr.c
	src/memcache.c
	src/memory_pool.c
	src/object.c
	src/permissions.c
	src/pollset.c
	src/proc.c
	src/serialize.c
	src/shm.c
	src/signal.c
	src/stat.c
	src/str.c
	src/thread.c
	src/thread_queue.c
	src/time.c
	src/uri.c
	src/user.c
	src/uuid.c
	src/xlate.c
	src/xml.c)

include_directories(${APR_INCLUDE_DIR} ${APRUTIL_INCLUDE_DIR})

if(APPLE)
   set(CMAKE_SHARED_MODULE_CREATE_C_FLAGS
       "${CMAKE_SHARED_MODULE_CREATE_C_FLAGS} -flat_namespace -undefined dynamic_lookup")
endif(APPLE)

# Binary
install_lua_module ( apr.core ${SOURCES} LINK ${APR_LIBRARIES} ${APRUTIL_LIBRARIES} )
# Lua 
install_lua_module ( apr src/apr.lua )
install_lua_module ( apr.serialize src/apr.lua )

install_foo ( etc/ )
install_test ( test/ )
install_example ( examples/ )
install_doc ( doc/ )
install_data ( README.md NOTES.md TODO.md benchmarks )
