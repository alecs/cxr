This is the CXR project:
   http://code.google.com/p/cxr/
   
BUILDING
   This project requires CMake, a cross-platform meta-makefile tool.
   
      * On Windows, download the CMake installer from:
            http://www.cmake.org/cmake/resources/software.html
        and make sure to choose "Add CMake to the system PATH for all users".
      
      * On Ubuntu, install CMake with apt:
         sudo apt-get install cmake
         
      * On Mac OS X, install CMake with MacPorts:
         sudo port install cmake
      
   Once you have cmake installed, you can build cxr.
   
   To build cxr on Unices:
      ./configure
      make

   To build cxr on Windows:
      configure
      nmake

   This will create the CXR tool under src/cxr and the example 
   test program under test/test.

   FYI, for this to work on Windows, you'll need to be running these 
   commands from the "Visual Studio Command Prompt".

RUNNING
   
   Once cxr is built, you give it the source cxr file and the output cpp filename.
   For example:
      ./bin/cxr -i something.cxr -o something.cpp
      
   See the CMakeLists.txt in the root of the project for an example of how to
   write a CXR macro that uses the cxr tool to generate files.
   
   For a more thorough discussion of how to use cxr, see the original article
   on CodeProject:
      http://www.codeproject.com/KB/string/cxr.aspx
   
TESTING
   
   The 'test' app makes use of cxr.  When you run it it should look something like:
      string 1="AbcdEfg1234  blah	blah"
      string 2="This is a long one, not that it should matter...blab blah blah blah. i love trash."

   "AbcdEfg1234..." and "This is a long one..." were encoded using cxr and are being decrypted and printed.
   
   To verify that these strings really are encrypted, use the 'strings' tool on the executable:
      strings ./bin/test
   On Windows you can get 'strings' here:
      http://technet.microsoft.com/en-us/sysinternals/bb897439.aspx
   
   You'll see output more or less like this on Mac OS X:
      string 1
      string 2
      PSt13runtime_error

   "string 1" and "string 2" here are the bare-string literals used in the test program's printing.
   Notice that you can't see the strings that were encrypted.  :)
   
   Depending on your platform you may see a lot more strings (from the CRT or other libs you've linked with).
