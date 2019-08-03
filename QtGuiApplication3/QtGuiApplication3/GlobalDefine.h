#pragma once
#pragma once
#pragma execution_character_set("UTF-8")

#include <tchar.h>
#include <string>
#include <cassert>
#include <memory>
#include <comdef.h>
#include <sstream>
#include <vector>
#include <comutil.h>
using namespace std;

#define  CARD_VERSION_1ST       "1.0.0.0"
#define  CARD_VERSION_2ND       "2.0.0.0"
#define  CARD_VERSION_3RD       "3.0.0.0"
#define  CARD_VERSION_4TH       "4.0.0.0"
#define  CARD_VERSION_5TH       "5.0.0.0"

#define IN
#define OUT
#define INOUT
#define IN_OUT

#define NOMINMAX

#if (defined(_UNICODE) || defined(UNICODE))
typedef wchar_t tchar;
typedef wstring tstring;
typedef wostream tostream;
typedef wofstream tofstream;
typedef wifstream tifstream;
typedef wstringstream tstringstream;
typedef wistringstream tistringstream;
typedef wostringstream tostringstream;
#else
typedef char tchar
typedef string tstring
typedef ostream tostream
typedef ofstream tofstream
typedef ifstream tifstream
typedef stringstream tstringstream
typedef istringstream tistringstream
typedef ostringstream tostringstream
#endif // _UNICODE

typedef double DATE;

const float g_fFloatEPSINON = 1.0E-6;
const double g_dDoubleEPSINON = 1.0E-14;

//TODO
#ifdef USE_SYS_ASSERT
#undef ASSERT
#define ASSERT assert
#else
#undef  ASSERT
#pragma  warning( disable: 4005)

#define ASSERT(expr) \
	do{\
		if( (expr) )\
			;\
		else\
		{\
			assert(false);\
		}\
	}while(0)

#define ASSERT1(expr, szComment) \
	do{\
		if( (expr) )\
			;\
		else\
		{\
			assert(false);\
		}\
	}while(0)


#pragma  warning( default: 4005)
#endif

#define SAFE_DELETE(p) { if(p) { delete (p); (p)=nullptr; } }
#define MIN(a,b) ((a) > (b) ? (b) : (a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define	VAZConvToInt(Value)			VAZConvValue<int>(Value)



template< class out_type, class in_value >
out_type VAZConvValue(const in_value & t)
{
	tstringstream oss;
	out_type result;

	oss << t;
	oss >> result;

	return result;
};
//
//#include <QMetaType>
//Q_DECLARE_METATYPE(std::string);
