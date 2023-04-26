// exercise-2-7.cpp : Defines the entry point for the console application.
//
//Svenja Kruessenberg I6080302, Christina Winkler I6067928
#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	//Enter day,month and year

	int day, month, year;

	cout << "Enter a day : ";
	cin >> day; cout << endl;
	cout << "Enter a month : ";
	cin >> month; cout << endl;
	cout << "Enter a year : ";
	cin >> year; cout << endl;

	cout << "The day you typed in is weekday: ";
	
	//Calculating the Doomsday
	int firstStep =( year%100) / 12;
	int secondStep = ((year%100) - (firstStep*12));
	int thirdStep = secondStep/4;
	int anchorday;
		if(year <= 1899)
			anchorday= 5;
		else if ( year >= 1900 && year <= 1999)
			anchorday = 3;
		else if ( year >= 2000 && year <= 2099)
			anchorday = 2;
		else if (year>=20100)
			anchorday=0;

	int fourthStep;
	fourthStep = firstStep + secondStep + thirdStep + anchorday;

	int doomsday;
	doomsday = fourthStep;
	while (doomsday >= 7)
	{ 
		doomsday = doomsday - 7;
	}

	//Leap or Common Year
	int daysPerYear;
	if (year%4 == 0) 
		daysPerYear = 366;
	else daysPerYear=365;

	//Identifying Doomsday Date
	int doomsdayDate;
	if(month==1)
		{ if(daysPerYear=366)
			doomsdayDate=4;
			else 
			doomsdayDate=3;
		}
	if(month==2)
		{
			if(daysPerYear=366)
			doomsdayDate=29;
			else 
			doomsdayDate=28;
		}
	else if(month==3)
			doomsdayDate=7;
		
	else if(month==4)
			doomsdayDate=4;

	else if(month==5)
			doomsdayDate=9;

	else if(month==6)
			doomsdayDate=6;

	else if(month==7)
			doomsdayDate=11; // on purpose we left out july 4th to avoid complications later on
	
	else if(month==8)
			doomsdayDate=8;

	else if(month==9)
		doomsdayDate=5;

	else if(month==10)
		doomsdayDate=10; // on purpose we left out october 31st to avoid complications later on
	
	else if(month==11)
		doomsdayDate=7;

	else if(month==12)
		doomsdayDate=12;
	
	//Move from doomsday to the real date

	if ( day > doomsdayDate)
		{	int v, g, weekday; 
			v = day - doomsdayDate;
			g = v % 7;
			weekday = doomsday - g;
			if ( weekday <= 6 && weekday >=0) 
				weekday = weekday; 
			else weekday = weekday + 7;	
			
			if (weekday == 0) 
				cout << "Sunday";
			else if (weekday == 1) 
				cout << "Monday";
			else if (weekday == 2) 
				cout << "Tuesday";
			else if (weekday==3)
				cout << "Wednesday";
			else if (weekday == 4) 
				cout << "Thursday";
			else if (weekday == 5) 
				cout << "Friday";
			else if (weekday = 6)
				cout << "Saturday";
		}
	else
	{
			int f,h, weekday;
			f = doomsdayDate - day;
			h = f % 7;
			weekday = doomsday - h;
			if ( weekday <= 6 && weekday >=0) 
				weekday = weekday;
			else weekday = weekday + 7;
			if (weekday == 0) 
				cout << "Sunday";
			else if (weekday == 1) 
				cout << "Monday";
			else if (weekday == 2) 
				cout << "Tuesday";
			else if (weekday==3)
				cout << "Wednesday";
			else if (weekday == 4) 
				cout << "Thursday";
			else if (weekday == 5) 
				cout << "Friday";
			else if (weekday = 6)
				cout << "Saturday";
	}
	
	cout <<endl;

	system("pause");
	return 0;
}




// do not use too many nested else ifs, rather use switch
// also, not two of those are needed
// leap year decision is wrong
// 2/3 points
