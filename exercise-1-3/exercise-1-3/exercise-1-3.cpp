// exercise-1-3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	double distanceinkm, petrolcons, costofpetrol, litersNeeded, petrolCost;

	cout << "Distance in km = ";
	cin >> distanceinkm; 

	cout << "Petrol consumption in liter = ";
	cin >> petrolcons;

	cout << "Cost of petrol per liter = ";
	cin >> costofpetrol;

	
	litersNeeded = distanceinkm*(petrolcons/100);
    cout << "Number of liters of petrol needed = "<< litersNeeded << endl;
	
	petrolCost = litersNeeded*costofpetrol;
	cout << "Cost of petrol needed for the trip = " << petrolCost << endl;

	system("pause");
	return 0;
}

