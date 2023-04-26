// exercise-5-3.cpp : Defines the entry point for the console application.
//Svenja Kruessenberg I6080302, Christina Winkler I6067928

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include "Matrix.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	Matrix m,d;
	string fname="a.txt";
	string fnameTwo="b.txt";
	m.readMatrix(fname);
	m.printMatrix();
	d.readMatrix(fnameTwo);
	d.printMatrix();
	m.multiplyBy(d);
	m.printMatrix();
 

	system("pause");
	return 0;
}

