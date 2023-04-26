// exercise-4-4.cpp : Defines the entry point for the console application.
//
 //Test for n = 100000 we get ; 300000; and 1000000

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <time.h>
using namespace std;

bool write_array (int a[], int size , string fname);
bool is_prime (int n);
void computeprimes(int n, int *&prime);

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	int * prime;
	string fname;

	cout << "Type in a natural number n : ";
	cin >> n;
	cout <<"Name of Output file : ";
	cin >> fname;

	


	//Measuring CPU time of function computeprimes
	
	clock_t start = clock() ;
	computeprimes( n,prime);
	clock_t end=clock();
	cout << 1000 * (end-start)/CLOCKS_PER_SEC << " ms " << endl;
	
	 write_array ( prime,  n , fname);



	system("pause");
	return 0;
}


void computeprimes(int n, int *&prime)
{
	prime = new int[n]; 
	int count=0;
	
	for(int i=1; count <=n ; i++)
	{
		if(is_prime(i)==true)
		{
		prime[count]=i;
		count++;
		}
	}
}

bool is_prime (int n)
{

	if (n == 1) return false;
	int q = 2;   
	bool prime = true;   	

	while (prime && (q*q <= n))
	{
		if (n % q == 0)
		{
			prime = false;
		}
		else	
		{
			q = q + 1;
		}
		
	}
	return prime;
}
bool write_array (int a[], int size , string fname)
{
	ofstream out;
	out.open(fname);
	if(out.fail())
	{
		cout << "could not open file "<< endl;
		return false;
	}

	out << size << endl;

	for( int j=0; j<size; j++)
	{
		out << a[j] << " ";
	}

	out.close();
	return true;
}

