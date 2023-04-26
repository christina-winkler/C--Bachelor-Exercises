#include "stdafx.h"
#include "randomvariable.h"
#include <string>
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

randomvariable::randomvariable(void)
{
}

double randomvariable::expectedvalue()

{

	double expValue;
	int i;
	expValue=0;

	for( i=0; i<rows; i++)
		expValue += A[i][0]* A[i][1];
	return expValue;
}


bool randomvariable::read_array(string fname)
{
{	ifstream in;
	int i,j;
	in.open(fname);
	if(in.fail())
		return false;
	in >> rows;


	A = new double *[rows];
	for (i=0;i<rows;i++)
	{
		A[i]= new double [2];
		for(j=0; j<2; j ++)
			in >> A[i][j];
	}

	in.close();
	return true;
	
}}

randomvariable::~randomvariable(void)
{
	//delete:
	for(int i=0; i<rows; i++)
		delete[] A[i];
	delete[] A;
}
