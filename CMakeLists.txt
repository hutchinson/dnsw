# This is the top level CMakeLists.txt file - it can be used to store
# project wide settings and adding top level subdirectories.
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(dnsw)

SET(PROJECT_MAJOR_VERSION 1)
SET(PROJECT_MINOR_VERSION 1)
SET(PROJECT_VERSION ${PROJECT_MAJOR_VERSION}.${PROJECT_MINOR_VERSION})

ADD_SUBDIRECTORY(src)
