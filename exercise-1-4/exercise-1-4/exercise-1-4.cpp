// exercise-1-4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{
	int a, b, remainder, division;

	cout << "Type in an integer: ";
	cin >> a;

	cout << "Type in a second integer:";
	cin >> b;

	remainder = a%b; 
	division = a/b;

	cout << "Remainder:"<< remainder << endl;
	cout << "Division:" << division << endl;


	system("pause");
	return 0;
}

