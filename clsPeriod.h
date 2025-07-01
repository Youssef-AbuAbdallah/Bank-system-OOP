#pragma once
#pragma warning(disable : 4996)

# include <iostream>
# include <vector>
# include "clsString.h"
# include "clsDate.h"
using namespace std;

class clsPeriod {

private:
	clsDate _StartDate;
	clsDate _EndDate;

public:

	clsPeriod(clsDate StartDate, clsDate EndDate)
	{
		this->_StartDate = StartDate;
		this->_EndDate = EndDate;
	}

	static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
	{
		if (
			clsDate::CompareDates(Period2._EndDate, Period1._StartDate) == clsDate::enDateCompare::Before
			||
			clsDate::CompareDates(Period2._StartDate, Period1._EndDate) == clsDate::enDateCompare::After
			)
			return false;
		else
			return true;
	}

	bool IsOverlapWith(clsPeriod Period2)
	{
		return IsOverlapPeriods(*this, Period2);
	}

	static int PeriodLengthInDays(clsPeriod Period, bool IncludeEndDate = false)
	{
		return clsDate::GetDifferenceInDays(Period._StartDate, Period._EndDate, IncludeEndDate);
	}

	int PeriodLengthInDays(bool IncludeEndDate = false)
	{
		return PeriodLengthInDays(*this, IncludeEndDate);
	}


	static bool isDateInPeriod(clsDate Date, clsPeriod Period)
	{
		return !(clsDate::CompareDates(Date, Period._StartDate) == clsDate::enDateCompare::Before
			||
			clsDate::CompareDates(Date, Period._EndDate) == clsDate::enDateCompare::After);
	}

	bool isDateInPeriod(clsDate Date)
	{
		return isDateInPeriod(Date, *this);
	}

	static int CountOverlapDays(clsPeriod Period1, clsPeriod Period2)
	{
		int Period1Length = PeriodLengthInDays(Period1, true);
		int Period2Length = PeriodLengthInDays(Period2, true);
		int OverlapDays = 0;

		// No overlapping 
		if (!IsOverlapPeriods(Period1, Period2))
			return 0;

		// Legth 2 is longer so iterate with period 1
		if (Period1Length < Period2Length)
		{
			while (clsDate::IsDate1BeforeDate2(Period1._StartDate, Period1._EndDate))
			{
				if (isDateInPeriod(Period1._StartDate, Period2))
					OverlapDays++;
				Period1._StartDate = clsDate::IncreaseDateByOneDay(Period1._StartDate);
			}
		}

		// Legth 1 is longer so iterate with period 2

		else
		{
			while (clsDate::IsDate1BeforeDate2(Period2._StartDate, Period2._EndDate))
			{
				if (isDateInPeriod(Period2._StartDate, Period1))
					OverlapDays++;
				Period2._StartDate = clsDate::IncreaseDateByOneDay(Period2._StartDate);
			}
		}
		return OverlapDays;
	}

	void Print()
	{
		cout << "\nStart Date : ";
		_StartDate.Print();


		cout << "\nEnd Date : ";
		_EndDate.Print();


	}


};