# Build simple driver program that utilises the library.

SET(SOURCE_FILES main.cpp)

INCLUDE_DIRECTORIES(${DNSW_INCLUDES})

ADD_EXECUTABLE(driver ${SOURCE_FILES})
