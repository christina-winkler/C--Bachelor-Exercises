// exercise-3-6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<cmath>
#include<string>
#include<cstdlib>
#include<fstream>
using namespace std;
 bool eliminate(string x, string& y);

int _tmain(int argc, _TCHAR* argv[])
{

	system("pause");
	return 0;
}

//Function Definition

 bool eliminate(string x, string& y)
{
		int start;
		int count;
		string aString;
		string aString1;
		aString =y;
		aString1 = y;
		start = aString.find(x);
		count= x.length();
		if (start>=0)
			y = aString.erase(start, count);
		else 
			y=aString;
			
			return (y != aString1);
 }
	

void usingElimination(string u, string& v)
{
		bool trueOrFalse; 
		trueOrFalse = eliminate(u,v);
		while (trueOrFalse == 1)  
			{ trueOrFalse = eliminate (u,v);
		}
}