// exercise-2-4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int factorial(int n);

int _tmain(int argc, _TCHAR* argv[])
{
	int n;

	cout << "Enter a value n : ";
	cin >> n;
	cout << endl;
	cout << "Factorial n : " << factorial(n) << endl;
	cout << endl;

    system("pause");
	return 0;
}

int factorial(int n)
{
	if (n==1)
		return(1);
		else 
			return( n*factorial(n-1));
					

	}