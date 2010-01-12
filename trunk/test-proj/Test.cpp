#include <iostream>
#include <string>

#include "../src/cxr_inc.h"

extern const char* pString1;
extern const char* pString2;

int main(int argc, char* argv[])
{
	int nRetCode = 0;

   // TODO: code your application's behavior here.
   std::string strHello= "hello";
   std::cout << strHello << std::endl;

   std::string t;
   
   t = _CXR(pString1);
   std::cout << "_CXR(" << pString1 << ") =" << std::endl << t << std::endl;

   t = _CXR(pString2);
   std::cout << "_CXR(" << pString2 << ") =" << std::endl << t << std::endl;

	return nRetCode;
}


