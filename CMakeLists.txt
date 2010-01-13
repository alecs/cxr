PROJECT(cxr)
cmake_minimum_required(VERSION 2.6)

# change the default exe output dir
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

# macro to copy a file such that it has dependencies and can be clean
#
MACRO(COPY SourceFile DestFile)
   ADD_CUSTOM_COMMAND(
      OUTPUT ${DestFile}
      COMMAND ${CMAKE_COMMAND} -E copy ${SourceFile} ${DestFile}
      DEPENDS ${SourceFile}
     )
ENDMACRO(COPY)

# cxr macro uses cxr tool to generate output c code
#
MACRO(CXR SourceFile DestFile)
   ADD_CUSTOM_COMMAND(
      OUTPUT ${DestFile}
      COMMAND cxr -i ${CMAKE_CURRENT_SOURCE_DIR}/${SourceFile} -o ${CMAKE_CURRENT_BINARY_DIR}/${DestFile}
      DEPENDS cxr ${CMAKE_CURRENT_SOURCE_DIR}/${SourceFile}
     )

   COPY(${CMAKE_SOURCE_DIR}/src/cxr_inc.h ${CMAKE_CURRENT_BINARY_DIR}/cxr_inc.h)
   INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
ENDMACRO(CXR)

add_subdirectory(src)
add_subdirectory(test)

