SET(GTEST_INCLUDE_PATH "${GTEST_ROOT}/src/include")
SET(GTEST_LIB_PATH "${GTEST_ROOT}/out")

# Where Google Test's .h files can be found.
INCLUDE_DIRECTORIES(${GTEST_INCLUDE_PATH})

# Where Google Test's libraries can be found.
LINK_DIRECTORIES(${GTEST_LIB_PATH})

ADD_EXECUTABLE(sampletest sampletest.cpp)
TARGET_LINK_LIBRARIES(sampletest gtest_main) 