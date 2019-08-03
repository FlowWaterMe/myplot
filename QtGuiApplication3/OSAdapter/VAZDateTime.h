#pragma once

#include "GlobalDefines.h"
#include "common_global.h"

class COMMON_EXPORT CVAZDateTime
{
	// Constructors
public:
	CVAZDateTime() throw();
	CVAZDateTime(DATE dtSrc) throw();
	CVAZDateTime(int nYear, int nMonth, int nDay, int nHour, int nMin, int nSec) throw();
	CVAZDateTime(int nYear, int nMonth, int nDay, int nHour, int nMin, int nSec, int iMillisecond) throw();
	// Attributes
	DATE m_dt;

	// Operations
	//CVAZDateTime& operator=(DATE dtSrc) throw();

	bool operator==(const CVAZDateTime& date) const throw();
	bool operator!=(const CVAZDateTime& date) const throw();
	bool operator<(const CVAZDateTime& date) const throw();
	bool operator>(const CVAZDateTime& date) const throw();
	bool operator<=(const CVAZDateTime& date) const throw();
	bool operator>=(const CVAZDateTime& date) const throw();

	// DateTime math
	CVAZDateTime operator+(DATE dateSpan) const throw();
	CVAZDateTime operator-(DATE dateSpan) const throw();
	CVAZDateTime& operator+=(DATE dateSpan) throw();
	CVAZDateTime& operator-=(DATE dateSpan) throw();

	// Date math
	DATE operator-(const CVAZDateTime& date) const throw();

	operator DATE() const throw();

	void SetDateTime(int nYear, int nMonth, int nDay,int nHour, int nMin, int nSec) throw();
	void SetDateTime(int nYear, int nMonth, int nDay, int nHour, int nMin, int nSec, int iMillisecond) throw();	
	void SetDate(int nYear, int nMonth, int nDay) throw();
	void SetTime(int nHour, int nMin, int nSec) throw();

protected:
	static double DoubleFromDate( DATE date ) throw();
	static DATE DateFromDouble( double f ) throw();
};
