// exercise-4-5.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <time.h>
using namespace std;

bool read_array (double **&A, int & rows, string fname);
double expected_value(double **&A, int rows);
void cdf(double **&A, int rows, double **&cdfVal);
double quantile ( double **B, int rowsB);



int _tmain(int argc, _TCHAR* argv[])
{
	double **A, **cdfVal;
	int rows;
	string fname;
	fname = "a.txt" ;

	read_array(A, rows, fname);
	for (int i = 0 ; i<rows; i++)
		{
		cout << "[";
		for (int j=0; j<2 ; j++)
		{
		cout << A[i][j] << " " ; }
		cout << "]" << endl;
		}
		cout << "Expected Value : " <<  expected_value(A, rows) << endl << endl;


	cdf(A, rows, cdfVal);
	for (int k = 0 ; k<rows; k++)
		{
		cout << "[";
		for (int l=0; l<2 ; l++)
		{
		cout << cdfVal[k][l] << " " ; }
		cout << "]" << endl;
		}
	
	quantile(cdfVal,rows);


			system("pause");

			return 0;
			delete []A;
			delete []cdfVal;
	}


	bool read_array (double **&A, int & rows, string fname)
	{	ifstream in;
	int i,j;
	in.open(fname);
	if(in.fail())
		return false;
	in >> rows;


	A = new double *[2];
	for (i=0;i<rows;i++)
	{
		A[i]= new double [2];
		for(j=0; j<2; j ++)
			in >> A[i][j];
	}

	in.close();
	return true;
	}

	double expected_value(double **&A, int rows)
	{

		double expValue;
		int i;
		expValue=0;

		for( i=0; i<rows; i++)
			expValue += A[i][0]* A[i][1];
		return expValue;
	}

	void cdf(double **&A, int rows, double **&cdfVal)
	{

		cdfVal = new double* [rows];

		double cdfValue=0;

		for(int i=0; i<rows; i++)
		{
			cdfVal[i] = new double[2];
			if (i==0)
			{
				cdfVal[i][0]= A[i][0];
				cdfVal[i][1] = 0;
				cdfVal[i][1]= cdfVal[i][1] + A[i][1];
			}
			else
			{
				cdfVal[i][0]= A[i][0];
				cdfVal[i][1] = cdfVal[i-1][1] + A[i][1];
			}
		}

	}

	double quantile ( double **C, int rows)
	{
		double percentile;

		cout << "Enter a percentile : " << endl;
		cin >> percentile;

		if ( percentile >0 && percentile < C[0][1])
		{
			cerr << " Error" << endl;
		}
		else
		{
			for( int i= 1 ; i < rows; i ++)
			{
				if( percentile >= C[i-1][1] && percentile < C[i][1])
				{
					cout << C[i-1][0] << endl;
				}
			}
		}
		return 0;
	}