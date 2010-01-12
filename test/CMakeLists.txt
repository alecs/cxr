SET(TEST_SRCS Test.cpp strings.cpp)

CXR(strings.cxr strings.cpp)
ADD_EXECUTABLE(test ${TEST_SRCS})
