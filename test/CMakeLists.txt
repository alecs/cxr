# get all the sources
FILE(GLOB TEST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.cpp")

# manually add strings.cpp, because it hasn't been generated yet
SET(TEST_SRCS ${TEST_SRCS} strings.cpp)

# generate strings.cpp
CXR(strings.cxr strings.cpp)

# build the exe
ADD_EXECUTABLE(test ${TEST_SRCS})
