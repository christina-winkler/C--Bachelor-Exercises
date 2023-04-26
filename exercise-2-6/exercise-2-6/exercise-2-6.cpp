// exercise-2-6.cpp : Defines the entry point for the console application.
//
//Svenja Kruessenberg I6080302, Christina Winkler I6067928

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;


float evaluate_f(float x);
float bisection(float a,float b,float g);

int _tmain(int argc, _TCHAR* argv[])
{
// a) Value of the function f at x
	float x;
	cout << "Enter a real number x = ";
	cin >> x;
	cout << "Value of f at x: f(x) = " << evaluate_f(x) << endl << endl;

//Find a zero in the interval [-100,100]	
	float a,b,e;
	a=-100;
	b=100;
	e=0.001;

	cout << "Value of a = -100, value of b = 100 and value of e = 0,001 " << endl;

    cout << "The zero of f is at x = " << bisection(a,b,e) << endl;

	


	system("pause");
	return 0;
}

float evaluate_f(float x)
{
float y;
y = 4 * (pow(x,3)) + 5 * (pow(x,2)) - 10 * x + 50;
return(y);
}

float bisection(float a, float b,float e)
{ 
float g;
g = evaluate_f(a)*evaluate_f((a+b)/2);
	do 
	{
	 if(g<0)
		 b=(a+b)/2; 

	 else(g>=0);
	  a=(a+b)/2;
		  
	} while((b-a)>e);

	
	return(a);
}
	