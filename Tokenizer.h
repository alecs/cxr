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

#if !defined(__TOKENIZER_H)
#define __TOKENIZER_H

#include <vector>
#include <iterator>

//////////////////////////////////////////////////////////////////////

class CSAToken 
{
public:
   CSAToken()
   {
      iStart = iStop = -1;
      bIsQuotedString = false;
   }
   
   CSAToken(const char *p, int x, int y, bool q)
   {
      csToken = p;
      iStart = x;
      iStop = y;
      //ASSERT(x <= y);

      bIsQuotedString = q;
   }

   std::string  csToken;
   int         iStart;
   int         iStop;
   bool        bIsQuotedString;
};

//////////////////////////////////////////////////////////////////////

typedef std::vector<CSAToken> CSATokenVector;

//////////////////////////////////////////////////////////////////////

class CTokenizer  
{
public:
   enum {eErrorNone, eErrorSyntax,}eError;


	CTokenizer(char **pKeyWords, int iKeyWords, char *pMetaChars, int iMetaChars);
	virtual ~CTokenizer();
   void     Clear();
   void     Init();

   int      Tokenize(const char *pInputLine);
   
   bool     IsKeyWord(std::string &str);
   bool     IsKeyWord(const char *pInput);

   void     Dump();
   
   bool     IsMetaChar(const char c); 
   bool     IsMetaChar(std::string &str);

   inline int    GetTokenCount()   {return m_tokens.size();}
   inline CSAToken GetToken(int i)   {return m_tokens.at(i);}

protected:
   int      GetToken(const char *pInput, std::string &out, bool &bQuotedString);
   
   char **  m_pKeyWords;
   int      m_iKeyWords;
   char *   m_MetaChars;
   int      m_iMetaChars;

   CSATokenVector m_tokens;
};

//////////////////////////////////////////////////////////////////////

extern bool operator < (const CSAToken &a, const CSAToken &b);
extern bool operator == (const CSAToken &a, const CSAToken &b);

#endif
