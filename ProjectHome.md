This is a branch of the CXR tool described in the article  ["Literal string encryption as part of the build process"](http://www.codeproject.com/Articles/2724/Literal-string-encryption-as-part-of-the-build-pro):

> Have you ever wished there was a way to use strings for messages,
> passwords or other text inside your app that didn't require you to
> use a literal string, because you were worried about someone finding
> the strings in your EXE? Wish no more, CXR is here.

The original CXR was MFC-based.  This project aims to make it cross-platform and add new features.


---


Jan-12-2010: v0.3
  * Now cross-platform using STL and CMake
  * Password is now itself encrypted (previously you could see the password in the binary)


---


To-Do List:
  * Change code generation to create a header file in addition to the .cpp file
  * Have decryption code (optionally) cache decrypted strings so that often-used strings don't have to be decrypted every time.
  * Other changes?