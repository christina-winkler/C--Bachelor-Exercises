// exercise-5-2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include "randomvariable.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{ 
	randomvariable rv;
	string fname="a.txt";

	rv.read_array(fname);
	double expectedV = rv.expectedvalue();
	cout << expectedV << endl;

	system("pause");
	return 0;
}

