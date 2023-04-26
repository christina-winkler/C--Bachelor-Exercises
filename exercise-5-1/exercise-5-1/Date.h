#pragma once

#ifndef DATE_H
#define DATE_H

using namespace std;

class date
{
public:

	//Member Functions
	//Constructor
	date();
	date(int d, int m, int y);

	//Display Date
	void displayDate()const;
	//leap Year
	bool leapYear()const;
	//Increment 
	void increment();
	//isEqual
	bool isEqual(date);
	

	~date(void);

private:
	int day;
	int month;
	int year;
	int end[12];
};

#endif