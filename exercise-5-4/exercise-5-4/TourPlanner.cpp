#include "stdafx.h"
#include "TourPlanner.h"
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

TourPlanner::TourPlanner()
{
	n = 0;
	d = NULL;
	t = NULL;
}


bool TourPlanner::readMatrix(string fname)
{
	//initialize tour
	t = new int[n];
	for(int m=0; m<n-1; m++)
	{
	 t[m]=m=1;
	}
	t[n-1]=0;



	ifstream in;
	in.open(fname);
	if(in.fail())
		return false;

	in >> n;

	d = new double *[n];
	for (int i=0;i<n;i++)
	{
		d[i]= new double[n];
		d[i][i] = 0;
		for(int j=i+1; j<n; j ++)	
		{		
			in >> d[i][j];			
		}	
	}

	for(int k=0; k<n; k++)
	{
		for(int l=0; l<k; l++)
			d[k][l]=d[l][k];
	}

	in.close();
	return true;
}

void TourPlanner::printMatrix()
{
	for (int i=0;i<n;i++)
	{   cout << "[";
	for(int j=0; j<n;j ++){
		cout << d[i][j] << " "; }
	cout << "]" << endl;
	}
	cout << endl;
}


double TourPlanner::length()
{   
		double length = 0;
	
		for(int i=0; i<n-1; i++)
		{
			length += d[t[i]][t[i+1]];
		}
		length += d[t[n-1]][t[0]];
	
return length;
}

void TourPlanner::opt()
{
	int improve = 0;
	TourPlanner tour,newTour;
	do
	{
		double optDist = tour.length(); 
		for(int i=0; i<n-1; i++)
		{
			for(int j=i+1; j<n; j++ )
			{
				//swap entries
				for(int c=0; c<=i-1; c++) 
					int a = t[c];
					t[c] = t[c+1];
					t[c+1] = a;
				}	


				double newDist = newTour.length();
				if(newDist < optDist)
				{ 	//reset if improvement was found
					improve = 0;
					tour = newTour;
					optDist= newDist;
				}
			}

		

		improve++;
	}

	while(improve < n);

}

TourPlanner::~TourPlanner(void)

{
	if(n>0)
	{
		if(d !=NULL)
		{
			for(int k=0; k<n;k++)
				delete[]d[k];
		}
		delete[]d;
		if(t !=NULL)
		{
			delete [] t;
		}
	}
}
