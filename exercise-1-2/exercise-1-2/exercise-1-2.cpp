// exercise-1-2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	char firstcharacter, secondcharacter, thirdcharacter ; 
	cout << " First Character = " << endl;
	cin >> firstcharacter ;
	cout << "Second Character = " << endl;
	cin >> secondcharacter ;
	cout << "Third Character = " << endl;
	cin >> thirdcharacter; 
	cout << "The word is =" << firstcharacter << secondcharacter << thirdcharacter;
	system("pause");

	return 0;
}

