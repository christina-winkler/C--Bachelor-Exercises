#include "stdafx.h"
#include "Date.h"

#include <iostream>
#include <fstream>
#include <string>

date::date()
{

	day =1;
	month=1;
	year=1900;

	end[0]=31;
	end[1]=29;
	end[2]=31;
	end[3]=30;
	end[4]=31;
	end[5]=30;
	end[6]=31;
	end[7]=30;
	end[8]=31;
	end[9]=30;
	end[10]=31;
	end[11]=30;

}


date::date(int d , int m , int y )
{
	day=d;
	month=m;
	year=y;

	end[0]=31;
	end[1]=29;
	end[2]=31;
	end[3]=30;
	end[4]=31;
	end[5]=30;
	end[6]=31;
	end[7]=31;
	end[8]=30;
	end[9]=31;
	end[10]=30;
	end[11]=31;
}

void date:: displayDate() const
{
	cout << endl << day << "." << month << "." << year; 
}

bool date::leapYear()const
{
	if (year%100==0)
	{
		if(year%400)
			return true;
		else
			return false;
	}
	else if (year%4==0)
		return true;
	else return false;
}

void date::increment()
{
	
	if(leapYear() && (month==2) && (day==29))
	{
		month++;
		day=1;
	}
	else if((month==12) && (day==31))
	{
	month=1;
	day=1;
	}
	else if( day==end[month-1])
	{
	day =1;
	month++;
	}
	else 
	day=day++;
}

bool date::isEqual(date date2)
{

	if(date2.day == day && date2.month==month && date2.year==year )
	return true;

	else return false;


}

date::~date()
{
}
