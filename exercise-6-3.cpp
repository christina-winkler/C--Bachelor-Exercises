// week.6.3.cpp : Defines the entry point for the console application.
//Marla Simons i6067387  Alice Thesling i6076906
// vector size 10000 :  quick_sort   5.648  s; memory_efficient_quicksort  0.07 s
// vector size 100000:  quick_sort   217.11  s; memory_efficient_quicksort  0.961 s

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "stdlib.h"
#include "time.h"

using namespace std;

void quick_sort( vector<int> & V);
void memory_efficient_quicksort( vector<int> &V, int left, int right);
void random_fill(vector<int> &v, int lb, int ub, int size);

int _tmain(int argc, _TCHAR* argv[])
{

	srand(time(0));
	//Enter boundaries and the size of the vector
	int lb,ub, size;
	cout << "Enter a lower bound for the vector: " << endl;
	cin >> lb;
	cout << "Enter an upper bound for the vector: " << endl;
	cin >> ub;
	cout << "Enter a size: " << endl;
	cin >> size;

	vector<int> V;
	random_fill(V,lb,ub,size);		//vector filled with random values between the boundaries
	cout << "The Vector is: " << endl;
	vector <int> :: iterator it;
	for(it = V.begin(); it != V.end(); it ++)
	{
		cout << *it << endl;
	}
	cout << endl;
	
	cout << "The sorted vector is: " << endl;
	quick_sort(V);
	for(int i = 0; i < size; i ++)
	{
		cout << V[i] << "  " ;
	}

	cout << endl << endl;

	clock_t start, finish;//measuring time
	start = clock ();
	quick_sort(V);
	finish = clock ();
	cout << "Time for quick_sort is: " << ((double) (finish - start)) / CLOCKS_PER_SEC << endl; 
	cout << endl;
	system("pause");

	int right = V.size()-1;
	int left = 0;
	cout << "The sorted vector for the efficient function is: " << endl;
	memory_efficient_quicksort(V,left,right);
	for(int j=0; j < size; j ++)
	{
		cout << V[j] << "  ";
	}
	cout<<endl<< endl;
	
	clock_t start1, finish1;//Measuring time
	start1 = clock ();
	memory_efficient_quicksort(V,left, right);		
	finish1 = clock ();
	cout << "Time for memory_efficient_quicksort is: " << ((double) (finish1 - start1)) / CLOCKS_PER_SEC << endl; 
	

	

	system("pause");
	return 0;
}

void quick_sort(vector <int> & V) //Sorting the vector by splitting it into vectors of size 1
{
	vector<int> left;
	vector<int> right;
	
	int x;
	if(V.size() >1 )
	{
		x= V[0];
		for(int i=1; i < V.size(); i ++)
		{
			if( V[i] <= x)
			{
				left.push_back(V[i]);
				
			}
			else 
			{
				right.push_back(V[i]);
			}
		}
		quick_sort(left);
		quick_sort(right);
	for (int k=0; k < left.size(); k++)	
		{
			V[k]= left[k];
		}

	V[left.size()]=x;
		
	for (int s=left.size()+1; s<V.size(); s++)
		{
			V[s] = right[s-left.size()-1];
		}	
	}
	
	
}

void memory_efficient_quicksort(vector<int> & V, int left,int right) //more efficient way to sort the vector
{
	int l= left;
	int r= right;
	int tmp;
	int x = V[(left+right)/2];
	while(l<=r)
	{
		while(l <=right && V[l] < x)
		{
			l++;
		}
		while(r >= left && V[r]> x )
		{
			r--;
		}
		if(l<= r)
		{
			tmp = V[l];
			V[l]=V[r];
			V[r] = tmp;
			l++;
			r--;
		}
	}
	if(left <= r)
	{
		memory_efficient_quicksort(V,left,r);
	}
	if(l<= right)	
	{
		memory_efficient_quicksort(V,l,right);
	}
}


void random_fill(vector<int> & v, int lb, int ub, int size)		//function to fill the vector with random values
{
	int r;
	v.resize(size);
	for(int i=0; i < size; i++)
	{
		r= rand();
		r= r % (ub-lb +1);
		r= r + lb;
		v[i]=r;
	}
}

