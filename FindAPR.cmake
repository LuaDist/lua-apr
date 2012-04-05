# Copyright (C) 2012 LuaDist.
# Created by Peter Kapec <kapecp@gmail.com>
# Redistribution and use of this file is allowed according to the terms of the MIT license.
# For details see the COPYRIGHT file distributed with LuaDist.
#	Note:
#		Searching headers and libraries is very simple and is NOT as powerful as scripts
#		distributed with CMake, because LuaDist defines directories to search for.
#		Everyone is encouraged to contact the author with improvements. Maybe this file
#		becomes part of CMake distribution sometimes.

# - Find apr
# Find the native APR headers and libraries.
#
# APR_INCLUDE_DIRS	- where to find zzip/zzip.h, etc.
# APR_LIBRARIES	- List of libraries when using apr.
# APR_FOUND	- True if apr found.

# Look for the header file.
FIND_PATH(APR_INCLUDE_DIR NAMES apr.h)

# Look for the library.
FIND_LIBRARY(APR_LIBRARY NAMES apr)

# Handle the QUIETLY and REQUIRED arguments and set APR_FOUND to TRUE if all listed variables are TRUE.
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(APR DEFAULT_MSG APR_LIBRARY APR_INCLUDE_DIR)

# Copy the results to the output variables.
IF(APR_FOUND)
	SET(APR_LIBRARIES ${APR_LIBRARY})
	SET(APR_INCLUDE_DIRS ${APR_INCLUDE_DIR})
ELSE(APR_FOUND)
	SET(APR_LIBRARIES)
	SET(APR_INCLUDE_DIRS)
ENDIF(APR_FOUND)

MARK_AS_ADVANCED(APR_INCLUDE_DIRS APR_LIBRARIES)