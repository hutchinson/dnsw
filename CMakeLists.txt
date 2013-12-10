# This is the top level CMakeLists.txt file - it can be used to store
# project wide settings and adding top level subdirectories.

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(dnsw)

SET(PROJECT_MAJOR_VERSION 1)
SET(PROJECT_MINOR_VERSION 0)
SET(PROJECT_VERSION ${PROJECT_MAJOR_VERSION}.${PROJECT_MINOR_VERSION})

CONFIGURE_FILE("${PROJECT_SOURCE_DIR}/dnsw_config.h.in" 
			   "${PROJECT_BINARY_DIR}/dnsw_config.h")
			   
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

# Project wide includes
SET(DNSW_INCLUDES "${PROJECT_SOURCE_DIR}/src/db/include" 
                  "${PROJECT_SOURCE_DIR}/src/resolver/include")

# Build settings
SET(DNSW_CXX_FLAGS "-Wall -Werror -pedantic -std=c++11 -stdlib=libc++")
SET(CMAKE_CXX_FLAGS ${DNSW_CXX_FLAGS})

# Build the project
ADD_SUBDIRECTORY(src)

# Unit Tests
# Unset compiler flags as gtest doesn't compile cleanly
SET(CMAKE_CXX_FLAGS "")
ADD_SUBDIRECTORY(thirdparty/gtest-1.7.0)
ENABLE_TESTING()
ADD_SUBDIRECTORY(tests)
