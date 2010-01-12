#ifndef CRXHeaderH
#define CRXHeaderH

#define _USING_CXR

#ifndef _USING_CXR
#define _CXR(x) x
#else
#define _CXR(x) __CXRDecrypt(x)
extern CString __CXRDecrypt(const char *pIn);
#endif

#endif