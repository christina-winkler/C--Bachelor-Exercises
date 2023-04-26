// exercise-4-2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

void prime_deco (int n, int*& primes, int& nr_of_primes);


int _tmain(int argc, _TCHAR* argv[])
{
	int nr_of_primes;
	int * primes;

	prime_deco (2614644, primes, nr_of_primes);

	for (int i=0; i< nr_of_primes; i++)
	{ 
		cout << primes[i] << endl;

	}

	system("pause");
	return 0;
}

void prime_deco (int n, int*& primes, int& nr_of_primes)

{ 
	int q=2, count, m;
	int * a;
	a = new int[n]; //create memory for array a, size unknown

	nr_of_primes=0;
	m=n;	

	while (q<=n)
	{
		count = 0;
		while(n%q == 0)
		{

			n=n/q;
			count ++;

		}

		for(int i=0; i<count; i++ )	
			a[i+nr_of_primes]=q ;


		nr_of_primes += count;

		q++;
	}


	primes = new int [nr_of_primes];

	for(int j=0; j< nr_of_primes; j++)
	primes[j]= a[j];


	
	delete a;
}

