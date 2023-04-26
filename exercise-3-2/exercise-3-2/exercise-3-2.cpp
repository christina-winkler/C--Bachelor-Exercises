// exercise-3-2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

//Function Prototype
bool read_array (double a[], int size, string filename);
bool write_array (double a[], int size , string fname);


int _tmain(int argc, _TCHAR* argv[])
{
	string filename,fname;
	double a[10];
	int size=9;

	do
	{
		cout <<"Name of Input file : " << endl;
		cin >> filename;
	}

	while(!(read_array(a, size, filename)));

		for (int i=0; i< size; i++)
		{ cout << a[i] << " " << endl;}
		

		do
		{
		cout <<"Name of Output file : " << endl;
		cin >> fname;
		}
	while(!(write_array(a, size, fname)));

		for (int j=0; j < size; j++)
		{ cout << a[j] << " " << endl;}


	system("pause");
	return 0;
}

bool read_array (double a[], int size, string filename)
{
	ifstream in;
	double x;
	in.open(filename);

	if(in.fail())
	{
		cout << "Error.Could not open file !  "<< endl << endl;
		return false;
	}

	in >> x;


	if( x < size)
		return false;


	for (int i=0; i<size; i++)
	{
		in >> a[i];
	}

	in.close();
	return true;

}
bool write_array (double a[], int size , string fname)
{
	ofstream out;
	int j;
	out.open(fname);
	if(out.fail())
	{
		cout << "could not open file "<< endl;
		return false;
	}

	out << size << endl;

	for( int j=0; j<size; j++)
	{
		out << a[j] << " ";
	}
	
	out.close();
	return true;
}