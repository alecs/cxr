# get all the sources
FILE(GLOB CXR_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.cpp")

# create the exe
ADD_EXECUTABLE(cxr ${CXR_SRCS})
