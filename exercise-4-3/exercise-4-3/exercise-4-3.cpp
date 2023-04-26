// exercise-4-3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

bool read_array (double **& A, int& m, int& k, string filename);

int _tmain(int argc, _TCHAR* argv[])
{
	string filename;
	int m,n; //m rows, n columns
	double** B, **C;

	do
	{
		cout <<"Name of file : " << endl;
		cin >> filename;
	}

	while(!(read_array(B, m, n, filename)));

	for (int i = 0; i < m; i++)
	{

	double **C;

		C[i] = new double[m];
		for(int j=1; j<m;j++)
		{
			C[i][j]=0;
			for(int k=0; k<n ;k++)
				C[i][j] += B[i][k]*B[j][k];
		}
	}

	system("pause");
	return 0;
}


bool read_array (double **&A, int& rows, int& cols, string filename)
{
	ifstream in;	
	int j;
	in.open(filename);

	if(in.fail())
	{
		cout << "could not open file "<< endl;
		return false;
	}

	in >> rows;
	in >> cols;
	A = new double*[rows];
	for (int i=0; i<rows; i++)
	{
		A[i]= new double[cols];
		for(j=0; j<rows; j++)
			in >> A[i][j];
	}	



	in.close();

	return true;
}
