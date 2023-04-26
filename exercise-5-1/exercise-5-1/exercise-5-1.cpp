// exercise-5-1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Date.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int day,month,year,d,m,y;
	date dateOne, dateTwo;

	//Enter first date
	cout << "First date " << endl;
	cout << "Enter a day : ";
	cin >> day; cout << endl;
	cout << "Enter a month : ";
	cin >> month; cout << endl;
	cout << "Enter a year : ";
	cin >> year;
	
	dateOne = date(day,month,year);
	dateOne.displayDate(); cout << endl << endl;

	//Enter second date
	cout << "Second date " << endl;
	cout << "Enter a day : ";
	cin >> d; cout << endl;
	cout << "Enter a month : ";
	cin >> m; cout << endl;
	cout << "Enter a year : ";
	cin >> y;
	dateTwo = date(d,m,y);
	dateTwo.displayDate(); cout << endl << endl;

	if (dateOne.isEqual(dateTwo)) 
		cout << "dates are same";	
	else
	{
		do
		{dateOne.increment();
		dateOne.displayDate(); cout << endl;}
		while(!(dateOne.isEqual(dateTwo)));

	}





	system("pause");
	return 0;
}

