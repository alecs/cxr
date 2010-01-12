PROJECT(cxr)
cmake_minimum_required(VERSION 2.6)

# cxr macro uses cxr tool to generate output c code
#
MACRO(CXR SourceFile DestFile)
   ADD_CUSTOM_COMMAND(
      OUTPUT ${DestFile}
      COMMAND cxr -i ${CMAKE_CURRENT_SOURCE_DIR}/${SourceFile} -o ${CMAKE_CURRENT_SOURCE_DIR}/${DestFile}
      DEPENDS cxr ${CMAKE_CURRENT_SOURCE_DIR}/${SourceFile}
     )   
ENDMACRO(CXR)

add_subdirectory(src)
add_subdirectory(test)