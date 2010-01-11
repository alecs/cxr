/*********************************************************************

   Copyright (C) 2002 Smaller Animals Software, Inc.

   This software is provided 'as-is', without any express or implied
   warranty.  In no event will the authors be held liable for any damages
   arising from the use of this software.

   Permission is granted to anyone to use this software for any purpose,
   including commercial applications, and to alter it and redistribute it
   freely, subject to the following restrictions:

   1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.

   2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.

   3. This notice may not be removed or altered from any source distribution.

   http://www.smalleranimals.com
   smallest@smalleranimals.com

**********************************************************************/

#if !defined(AFX_TOKENIZER_H__3FA6DAB7_4E5E_11D3_A0FA_00500402F30B__INCLUDED_)
#define AFX_TOKENIZER_H__3FA6DAB7_4E5E_11D3_A0FA_00500402F30B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000



#include <vector>
#include <iterator>

#pragma warning(disable:4786)
using namespace std ;
using namespace std::rel_ops ;

//////////////////////////////////////////////////////////////////////

class CSAToken 
{
public:
   CSAToken()
   {
      iStart = iStop = -1;
      bIsQuotedString = false;
   }
   
   CSAToken(const TCHAR *p, int x, int y, bool q)
   {
      csToken = p;
      iStart = x;
      iStop = y;
      ASSERT(x <= y);

      bIsQuotedString = q;
   }

   CString  csToken;
   int         iStart;
   int         iStop;
   bool        bIsQuotedString;
};

//////////////////////////////////////////////////////////////////////

typedef vector<CSAToken> CSATokenVector;

//////////////////////////////////////////////////////////////////////

class CTokenizer  
{
public:
   enum {eErrorNone, eErrorSyntax,}eError;


	CTokenizer(TCHAR **pKeyWords, int iKeyWords, TCHAR *pMetaChars, int iMetaChars);
	virtual ~CTokenizer();
   void     Clear();
   void     Init();

   int      Tokenize(const TCHAR *pInputLine);
   
   bool     IsKeyWord(CString &str);
   bool     IsKeyWord(const TCHAR *pInput);

   void     Dump();
   
   bool     IsMetaChar(const TCHAR c); 
   bool     IsMetaChar(CString &str);

   _inline int    GetTokenCount()   {return m_tokens.size();}
   _inline CSAToken GetToken(int i)   {return m_tokens.at(i);}

protected:
   int      GetToken(const TCHAR *pInput, CString &out, bool &bQuotedString);
   
   TCHAR **  m_pKeyWords;
   int      m_iKeyWords;
   TCHAR *   m_MetaChars;
   int      m_iMetaChars;

   CSATokenVector m_tokens;
};

//////////////////////////////////////////////////////////////////////

extern bool operator < (const CSAToken &a, const CSAToken &b);
extern bool operator == (const CSAToken &a, const CSAToken &b);

#endif // !defined(AFX_TOKENIZER_H__3FA6DAB7_4E5E_11D3_A0FA_00500402F30B__INCLUDED_)
