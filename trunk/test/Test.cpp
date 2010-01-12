#include <iostream>
#include <string>

#include "cxr_inc.h"

extern const char* pString1;
extern const char* pString2;

int main(int argc, char* argv[])
{
	int nRetCode = 0;

   std::string t;
   char quote= '\"';
   
   t = _CXR(pString1);
   std::cout << "string 1" << "=" << quote << t << quote << std::endl;

   t = _CXR(pString2);
   std::cout << "string 2" << "=" << quote << t << quote << std::endl;

	return nRetCode;
}


