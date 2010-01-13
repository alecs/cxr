This is the CXR project:
   http://code.google.com/p/cxr/
which is a branch of the original CXR:
   http://www.codeproject.com/KB/string/cxr.aspx
   
   
BUILDING

This project requires CMake, a cross-platform meta-makefile tool.

   * On Windows, download the installer from:
         http://www.cmake.org/cmake/resources/software.html
     and make sure to choose "Add CMake to the system PATH for all users".
   
   * On Ubuntu, just run
      sudo apt-get install cmake
      
   * On Mac OS X, use MacPorts
      sudo port install cmake
   
Once you have cmake installed, do this:
   cd build
   cmake ..
   make
This will create the CXR tool under src/cxr and the example 
test program under test/test.


