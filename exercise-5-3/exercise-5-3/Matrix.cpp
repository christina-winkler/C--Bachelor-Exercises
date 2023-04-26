#include "stdafx.h"
#include "Matrix.h"
#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

Matrix::Matrix()
{
	//sets number of rows and columns equal to zero
	rows = 0;
	cols = 0;

}

Matrix::Matrix(int r, int c)
{
	rows = r;
	cols = c;
	A = new double *[r];

	//Initialize entries in the matrix with 0
	A=NULL;
}

bool Matrix::readMatrix(string fname)
{

	ifstream in;
	in.open(fname);
	if(in.fail())
		return false;
	in >> rows;
	in >> cols;

	A = new double *[rows];
	for (int i=0;i<rows;i++)
	{
		A[i]= new double [cols];
		for(int j=0; j<cols; j ++)
			in >> A[i][j];

	}


	in.close();
	return true;

}

void Matrix::printMatrix()
{
	for (int i=0;i<rows;i++)
	{   cout << "[";
	for(int j=0; j<cols; j ++){
		cout << A[i][j] << " "; }
	cout << "]" << endl;
	}
	cout << endl;
}

bool Matrix::multiplyBy(Matrix  & B)
{ 
	if (cols != B.rows)
	{
		cout<<"You can't multiply these matrices - wrong dimensions!"<<endl <<endl;
		return false;
	}
	
	else
	{
		double **C = new double*[rows];
		for (int i=0; i<rows; i++)
		{
			C[i] = new double[B.cols];

			for (int j=0; j<cols; j++)
			{
				C[i][j]=0;
				for (int k=0; k<cols; k++)
					
					C[i][j] += A[i][j] * B.A[k][j];
			}
		}
		A = C;
		return true;
	}


}



Matrix::~Matrix(void)
{
	for (int i= 0; i<rows; i++)
	delete []A[i];
	delete []A;

	rows = 0;
	cols = 0;
}
