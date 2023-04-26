// exercise-3-5.cpp : Defines the entry point for the console application.
//
//Christina Winkler, Svenja Kruessenberg
#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;

//Defining the data struct
struct PersonalData
{
	string FirstName, LastName;
	int DayOfBirth, MonthOfBirth, YearOfBirth;
};

bool first_is_older(PersonalData personOne, PersonalData personTwo);
int index_of_max(PersonalData x[] , int startIndex, int endIndex);
void exchange(PersonalData x[], int a, int b);
void sort(PersonalData a[], int size);
bool read_array (PersonalData a[], int size, string filename);

int _tmain(int argc, _TCHAR* argv[])
{
	PersonalData personOne, personTwo;

	int size=4;
	PersonalData a[4];
	string filename;


	do
	{
		cout <<"Name of file : " << endl;
		cin >> filename;
		cout << endl;
	}

	while(!(read_array(a, size, filename)));

	sort(a,size);
	cout << endl;
	for (int i=0; i< size; i++)
	{ 
		cout << a[i].FirstName << " "; 
		cout << a[i].LastName << " ";
		cout << a[i].DayOfBirth << " ";
		cout << a[i].MonthOfBirth << " ";
		cout << a[i].YearOfBirth << " " << endl << endl;
	}



	system("pause");
	return 0;
}

bool first_is_older(PersonalData personOne, PersonalData personTwo)
{
	if(personOne.YearOfBirth < personTwo.YearOfBirth)

	return true;

	else if (personOne.YearOfBirth > personTwo.YearOfBirth)

	return false;

	else if (personOne.MonthOfBirth < personTwo.MonthOfBirth)
	
	return true;

	else if (personOne.MonthOfBirth > personTwo.MonthOfBirth)

	return false;

	else if (personOne.DayOfBirth < personTwo.DayOfBirth)

	return true;

	else if (personOne.DayOfBirth > personTwo.DayOfBirth)
	
	return false;

	else if (personOne.DayOfBirth = personTwo.DayOfBirth)

	return false;




}

int index_of_max(PersonalData x[] , int startIndex, int endIndex)
{
	int maxIndex;
	int i ;

	if ((endIndex < startIndex) || (startIndex < 0))
	{
		cerr << "Error in subarray bounds " << endl;
		return -1;
	}
		maxIndex = startIndex;
		for (i = startIndex+1; i<= endIndex; i++)
			if ( first_is_older( x[maxIndex], x[i]))
				maxIndex = i;
		return maxIndex;
	
}
void exchange(PersonalData x[], int a, int b)
{  
	PersonalData w;

	w = x[a];
	x[a] = x[b];
	x[b] = w;

}

void sort(PersonalData a[], int size)
{
	int j,k;
	k=0;
	while (k<size -1)
	{
		j = index_of_max(a,k,size-1);
		exchange(a,j,k);
		k=k+1;
	}
}

bool read_array (PersonalData a[], int size, string filename)

{
	double x;
	ifstream in;
	in.open(filename);
	if (in.fail()){
		cout << "Cannot open file: " << filename << ". Provide a different name !\n";
		return false;
	}

	in >> x;

	if ( x >= size) 
	{
		for (int i=0; i < size; i++)
		{ 
			in >> a[i].FirstName; 
			in >> a[i].LastName;
			in >> a[i].DayOfBirth;
			in >> a[i].MonthOfBirth;
			in >> a[i].YearOfBirth;

		}
		cout << "Read succeeded" << endl;
		in.close();
		return true;
	}

	else 
	{ 
		in.close();
		return false; }
}
