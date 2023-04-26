// exercise-5-4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include "TourPlanner.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	TourPlanner tour;
	string fname="e.txt";
	/*string fname="m.txt";
	string fname="h.txt";*/

	int t[3]={2,4,3};

	tour.readMatrix(fname);
	tour.printMatrix();
	tour.length();
	tour.opt();



	system("pause");
	return 0;
}

