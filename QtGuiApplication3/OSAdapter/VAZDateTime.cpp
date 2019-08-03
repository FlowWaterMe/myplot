#include <VAZDateTime.h>
#include <comdef.h>
#include <math.h>

CVAZDateTime::CVAZDateTime() throw() :m_dt( 0 )
{
}


 CVAZDateTime::CVAZDateTime( DATE dtSrc ) throw() :m_dt( dtSrc )
{
}


 CVAZDateTime::CVAZDateTime(int nYear, int nMonth, int nDay,
											 int nHour, int nMin, int nSec) throw()
{
	SetDateTime(nYear, nMonth, nDay, nHour, nMin, nSec);
}

 CVAZDateTime::CVAZDateTime(int nYear, int nMonth, int nDay,
	 int nHour, int nMin, int nSec , int iMillisecond) throw()
 {
	 SetDateTime(nYear, nMonth, nDay, nHour, nMin, nSec, iMillisecond);
 }

//
// CVAZDateTime& CVAZDateTime::operator=(DATE dtSrc) throw()
//{
//	m_dt = dtSrc;
//	return *this;
//}

bool CVAZDateTime::operator==( const CVAZDateTime& date ) const throw()
{
	return( m_dt == date.m_dt );
}

bool CVAZDateTime::operator!=( const CVAZDateTime& date ) const throw()
{
	return !operator==(date);
}

bool CVAZDateTime::operator<( const CVAZDateTime& date ) const throw()
{
	return( DoubleFromDate( m_dt ) < DoubleFromDate( date.m_dt ) );
}

bool CVAZDateTime::operator>( const CVAZDateTime& date ) const throw()
{
	return( DoubleFromDate( m_dt ) > DoubleFromDate( date.m_dt ) );
}

bool CVAZDateTime::operator<=( const CVAZDateTime& date ) const throw()
{
	return operator<(date) || operator==(date);
}

bool CVAZDateTime::operator>=( const CVAZDateTime& date ) const throw()
{
	return operator>(date) || operator==(date);
}

CVAZDateTime CVAZDateTime::operator+( DATE dateSpan ) const throw()
{
	return( CVAZDateTime( DateFromDouble( DoubleFromDate( m_dt )+(double)dateSpan ) ) );
}

CVAZDateTime CVAZDateTime::operator-( DATE dateSpan ) const throw()
{
	return( CVAZDateTime( DateFromDouble( DoubleFromDate( m_dt )-(double)dateSpan ) ) );
}

CVAZDateTime& CVAZDateTime::operator+=( DATE dateSpan ) throw()
{
	m_dt = DateFromDouble( DoubleFromDate( m_dt )+(double)dateSpan );
	return( *this );
}

CVAZDateTime& CVAZDateTime::operator-=( DATE dateSpan ) throw()
{
	m_dt = DateFromDouble( DoubleFromDate( m_dt )-(double)dateSpan );
	return( *this );
}

DATE CVAZDateTime::operator-(const CVAZDateTime& date) const throw()
{
	return DoubleFromDate(m_dt) - DoubleFromDate(date.m_dt);
}

CVAZDateTime::operator DATE() const throw()
{
	return( m_dt );
}

void CVAZDateTime::SetDateTime(int nYear, int nMonth, int nDay,
												int nHour, int nMin, int nSec) throw()
{
	SYSTEMTIME st;
	::ZeroMemory(&st, sizeof(SYSTEMTIME));

	st.wYear = WORD(nYear);
	st.wMonth = WORD(nMonth);
	st.wDay = WORD(nDay);
	st.wHour = WORD(nHour);
	st.wMinute = WORD(nMin);
	st.wSecond = WORD(nSec);

	SystemTimeToVariantTime(&st, &m_dt);
}

void CVAZDateTime::SetDateTime(int nYear, int nMonth, int nDay, int nHour, int nMin, int nSec, int iMillisecond) throw()
{
	SYSTEMTIME st;
	::ZeroMemory(&st, sizeof(SYSTEMTIME));

	st.wYear = WORD(nYear);
	st.wMonth = WORD(nMonth);
	st.wDay = WORD(nDay);
	st.wHour = WORD(nHour);
	st.wMinute = WORD(nMin);
	st.wSecond = WORD(nSec);
	st.wMilliseconds = iMillisecond;

	SystemTimeToVariantTime(&st, &m_dt);
}

void CVAZDateTime::SetDate(int nYear, int nMonth, int nDay) throw()
{
	return SetDateTime(nYear, nMonth, nDay, 0, 0, 0);
}

 void CVAZDateTime::SetTime(int nHour, int nMin, int nSec) throw()
{
	// Set date to zero date - 12/30/1899
	return SetDateTime(1899, 12, 30, nHour, nMin, nSec);
}

 double CVAZDateTime::DoubleFromDate( DATE date ) throw()
{
	double fTemp;

	// No problem if positive
	if( date >= 0 )
	{
		return( date );
	}

	// If negative, must convert since negative dates not continuous
	// (examples: -1.25 to -.75, -1.50 to -.50, -1.75 to -.25)
	fTemp = ceil( date );

	return( fTemp-(date-fTemp) );
}

 DATE CVAZDateTime::DateFromDouble( double f ) throw()
{
	double fTemp;

	// No problem if positive
	if( f >= 0 )
	{
		return( f );
	}

	// If negative, must convert since negative dates not continuous
	// (examples: -.75 to -1.25, -.50 to -1.50, -.25 to -1.75)
	fTemp = floor( f ); // fTemp is now whole part

	return( fTemp+(fTemp-f) );
}
