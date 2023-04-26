// exercise-6-3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "time.h"
using namespace std;
void random_fill(vector<int> &v, int lb, int ub, int size);
void quickSort(vector<int> &v);
void memory_efficient_quicksort(vector<int>& v, int a, int b);

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(0));
	int r,ub,lb,size;
	vector<int> v, w;

	ub = 100;
	lb = 1;
	size = 10000;

	//fill the vector with random integers
	random_fill(v,lb,ub,size);
	w = v;
	//output unsorted vector v
	/*cout << "Unsorted vector :\n";
	for(int i=0; i<v.size(); i++)
	cout << v[i] << " ";
	cout << endl << endl;*/
	

	//Output sorted vector v and Measuring CPU time of function quicksort
	clock_t start = clock();
	quickSort(v);
	clock_t end=clock();
		cout << "Quick sort :\n";
		for(int j=0; j<v.size()-1;j++)
		cout << v[j] <<" ";
		cout << endl << endl;
	cout << 1000 * (end-start)/CLOCKS_PER_SEC << "ms " << endl;
	
	
	//Measuring CPU time of function memory efficient quicksort
	clock_t s = clock();
	memory_efficient_quicksort(w,0,w.size()-1);
	clock_t e=clock();
		cout << "Efficient quick sort :\n";
		for(int j=0; j<w.size();j++)
		cout << w[j] <<" ";
		cout << endl << endl;
	cout << 1000 * (e-s)/CLOCKS_PER_SEC << " ms " << endl;

	system("pause");
	return 0;
}


void quickSort(vector<int> &v)
{
	//Create left and right vector
	int x;
	vector<int> l,r;
	if(v.size() >= 2)
	{
		x = v[0];
		for(int i=1; i<v.size();i++)
		{	
			if(v[i] <=x)
			{ 		
				l.push_back(v[i]);
			}
			else 
			{
				r.push_back(v[i]);
			}
		}


		quickSort(l);
		quickSort(r);

		for(int p=0; p<l.size();p++)
			v[p]=l[p];

		v[l.size()]=x;
		for(int s = l.size()+1; s<v.size() ; s++)
			v[s]=r[s-l.size()-1];
	}
}


void memory_efficient_quicksort(vector<int>& v, int from, int to)
{
	int a,b, x;           
	x=v[(from+to)/2];
	int temp;

	a=from;
	b=to;

	while (a <= b)
	{
		while (v[a] < x && a <= b)
		a++;

		while (v[b] > x && b >= b)
		b--;
		

		if(a <= b)
		{
			temp = v[b];
			v[a] = v[b];
			v[b] = temp;
			a++;
			b--;
		}
	}

	if (a < b)
	{
		memory_efficient_quicksort(v, from, b);
	}

	if (a < b)
	{
		memory_efficient_quicksort(v, a, to);
	}
}



void random_fill(vector<int> &v, int lb, int ub, int size)
{
	int r;
	v.resize(size);
	for(int i=0;i<size; i++)
	{
		r = rand();
		r = r % (ub - lb + 1);
		r = r + lb;
		v[i]=r;
	}
}