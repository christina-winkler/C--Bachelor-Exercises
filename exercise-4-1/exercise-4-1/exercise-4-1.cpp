// exercise-4-1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool read_array (double*& a, int & size, string filename);

int _tmain(int argc, _TCHAR* argv[])
{
	string filename;
	double* a;
	int size;

	do
	{
		cout <<"Name of file : " << endl;
		cin >> filename;
	}

	while(!(read_array(a, size, filename)));

	for (int i=0; i< size; i++)
	{ cout << a[i] << " ";}
	system ("pause");
	return 0;
}

bool read_array (double*& a, int & size, string filename)
{
	ifstream in;
	
	in.open(filename);

	if(in.fail()){
		cout << "could not open file "<< endl;
		return false;
	}

	in >> size;

	a = new double [size];


	for (int i=0; i<size; i++)
	{
		in >> a[i];
	}

	in.close();

	return true;
}
