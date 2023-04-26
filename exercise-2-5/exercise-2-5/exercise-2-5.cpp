// exercise-2-5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int accountNumber;
	char code;
	float gallons,bill;

	//Enter Account number,code and gallons of water used

	cout << "Enter account number : ";
	cin >> accountNumber;
	cout << endl;
	cout << "Enter code (h,c,i): ";
	cin >> code;
	cout << endl;
	cout << "Enter gallons of water used : "; 
	cin >> gallons;
	cout << endl;
	
	//Printing the amount the user has to pay

	switch(code)
	{
	case 'h':
				bill=5+0.0005*gallons;
				cout << "Customer home, Nr." << accountNumber << "has to pay : " << bill <<"$"<< endl;
				break;
	case 'c':	
				if(gallons<=4000000)
				{
					bill=1000;
					cout << "Customer commercial, Nr." << accountNumber << "has to pay : " << bill <<"$"<< endl;
				}

				else
				{
					bill= 1000+ (gallons - 4000000)* 0.00025;
					cout << "Customer commercial, Nr." << accountNumber << " has to pay : " << bill <<"$"<< endl;
				}

				break;
	case 'i': 
				if(gallons<=4000000)
					{cout << "Customer industrial, Nr." << accountNumber << "has to pay 1000$"<< endl;}

				else if (gallons>4000000 && gallons<=10000000)
					{cout << "Customer industrial, Nr." << accountNumber << " has to pay 2000$"<< endl;}

				else if (gallons>10000000)
					{cout << "Customer industrial, Nr." << accountNumber << " has to pay 3000$"<< endl;}
					

				break;
	default:
		cout << "An invalid note was read." << endl;
	}
cout << endl;
system("pause");
return 0;
}