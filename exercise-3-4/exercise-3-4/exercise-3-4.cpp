// exercise-3-4.cpp : Defines the entry point for the console application.
//
//Christina Winkler,Svenja Kruessenberg
#include "stdafx.h"
#include<iostream>
#include<cmath>
#include<string>
#include<fstream>
#include<cstdlib>
using namespace std;
double inner_product (double a[], double b[], int size);
void normalize (double x[], int size);
bool read_array (double a[], int size, string filename);

int _tmain(int argc, _TCHAR* argv[])
{
	string filename;
	double a[2];
	int size=2;

	do
	{
		cout <<"Name of file : ";
		cin >> filename;
		cout << endl;
	}

	while(!(read_array(a, size, filename)));

	//Test inner product function
	cout << "Vector a : " << endl;
	for (int i=0; i< size; i++)
	{ cout << "Entry " << i+1 << " = " << a[i] << " " << endl;}


	cout << "Inner product a x a : " << inner_product(a,a,2) << " " << endl << endl;

	//Test normalize function
	normalize(a,size);
	cout << "Normalized vector : " << endl;

	for (int i=0; i< size; i++)
	{ cout << "Entry " << i+1 << " = " << a[i] << " " << endl;}
	cout << endl;

	system("pause");
	return 0;
}


double inner_product (double a[], double b[], int size)
{
	double sum=0;
	int i;

	for( i=0; i<size; i++)
		sum+=(a[i]*b[i]);

	return (sum);
}

void normalize(double x[], int size)
{

	int j;
	double inP=sqrt(inner_product(x,x,size));

	for( j=0; j<size; j++)
	{
		x[j] = (1/inP)* x[j];
	}

}



bool read_array (double a[], int size, string filename)
{
	ifstream in;
	double x;
	in.open(filename);

	if(in.fail()){
		cout << "could not open file "<< endl;
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


