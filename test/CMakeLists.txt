# get all the sources
FILE(GLOB TEST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.cpp")

# manually add files that haven't been generated or copied yet
SET(TEST_SRCS ${TEST_SRCS} strings.cpp cxr_inc.h)

# generate strings.cpp
CXR(strings.cxr strings.cpp)

# build the exe
ADD_EXECUTABLE(test ${TEST_SRCS})
