#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
public:
	Matrix();
	Matrix(int ,int);
	~Matrix();

	//Member Functions
	bool readMatrix(string fname);
	void printMatrix();
	bool multiplyBy(Matrix & B);

private:
	double **A;
	int rows;
	int cols;
	string fname;


};

#endif MATRIX_H