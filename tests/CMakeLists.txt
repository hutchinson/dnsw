# Where Google Test's .h files can be found.
INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR})

INCLUDE_DIRECTORIES(${DNSW_INCLUDES})

SET(TEST_BINARIES "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/tests")

# Test Basic Node functionality
ADD_EXECUTABLE(basic_node_tests basic_node_tests.cpp)
TARGET_LINK_LIBRARIES(basic_node_tests gtest_main)
SET_TARGET_PROPERTIES(basic_node_tests PROPERTIES
					            RUNTIME_OUTPUT_DIRECTORY ${TEST_BINARIES})
ADD_TEST(basic_node_tests ${TEST_BINARIES}/basic_node_tests)

# Test basic resource record functionality
ADD_EXECUTABLE(basic_rr_tests basic_rr_tests.cpp)
TARGET_LINK_LIBRARIES(basic_rr_tests gtest_main)
SET_TARGET_PROPERTIES(basic_rr_tests PROPERTIES
					            RUNTIME_OUTPUT_DIRECTORY ${TEST_BINARIES})
ADD_TEST(basic_rr_tests ${TEST_BINARIES}/basic_rr_tests)

###############################################################################
# The following can be used as boiler plate code for adding a new test unit.
#ADD_EXECUTABLE(sampletest sampletest.cpp)
#TARGET_LINK_LIBRARIES(sampletest gtest_main)
#SET_TARGET_PROPERTIES(sampletest PROPERTIES
#					  RUNTIME_OUTPUT_DIRECTORY ${TEST_BINARIES})
#ADD_TEST(TestUnit1 ${TEST_BINARIES}/sampletest)
###############################################################################
