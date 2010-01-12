PROJECT(cxr)
cmake_minimum_required(VERSION 2.6)

# cxr macro uses cxr tool to generate output c code
#
MACRO(CXR SourceFile DestFile)
   ADD_CUSTOM_COMMAND(
      OUTPUT ${DestFile}
      COMMAND cxr -i ${CMAKE_CURRENT_SOURCE_DIR}/${SourceFile} -o ${CMAKE_CURRENT_BINARY_DIR}/${DestFile}
      DEPENDS cxr ${CMAKE_CURRENT_SOURCE_DIR}/${SourceFile}
     )

   # copy the cxr header file so that the generated file will see it
   CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/src/cxr_inc.h ${CMAKE_CURRENT_BINARY_DIR}/cxr_inc.h COPYONLY) 
   INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
ENDMACRO(CXR)

add_subdirectory(src)
add_subdirectory(test)
