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
      
   Once you have cmake installed, you can build cxr:
      cd build
      cmake ..
      make
   This will create the CXR tool under src/cxr and the example 
   test program under test/test.

RUNNING
   
   Once cxr is built, you give it the source cxr file and the output cpp filename.
   For example:
      ./src/cxr -i something.cxr -o something.cpp
      
   See the CMakeLists.txt in the root of the project for an example of how to
   write a CXR macro that uses the cxr tool to generate files.
   
TESTING
   
   The 'test' app make use of cxr.  When you run it it should look something like:
      string 1="AbcdEfg1234  blah	blah"
      string 2="This is a long one, not that it should matter...blab blah blah blah. i love trash."

   "string 1" and "string 2" were encoded using cxr and are being decrypted and printed.
   
   To verify that these strings really are encrypted, use the 'strings' tool on the executable:
      strings ./test/test
   
   You'll see output more or less like this on Mac OS X:
      string 1
      string 2
      PSt13runtime_error

   If you're on Windows, use a hex-editor on the executable.

   "string 1" and "string 2" here are the bare-string literals used in the test program's printing.
   Notice that you can't see the strings that were encrypted.  :)
   