#ifndef CTIME_H
#define CTIME_H

#define MAX_TIME 6

#include "stdafx.h"

class CTimer
{
public:

	CTimer() {};
	~CTimer() {};

	void vSetStartNow()
	{
		QueryPerformanceFrequency(&li_freq);
		QueryPerformanceCounter(&li_start);
	};

	void vSetTimePassed(double  *pdTimePassed)
	{
		LARGE_INTEGER li_now;
		QueryPerformanceCounter(&li_now);

		double  d_result;

		d_result = (li_now.QuadPart - li_start.QuadPart);
		d_result = d_result / li_freq.QuadPart;

		*pdTimePassed = d_result;
	};

private:

	LARGE_INTEGER li_start;
	LARGE_INTEGER li_freq;

};


#endif 
