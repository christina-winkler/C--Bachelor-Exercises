#pragma once
#include "randomvariable.h"
#include <string>
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;



#ifndef RANDOMVARIABLE_H
#define RANDOMVARIABLE_H

class randomvariable
{
public:
	//Member functions
	//Read array
	bool read_array (string fname);
	//Expected Value
	double expectedvalue();

	randomvariable(void);
	~randomvariable(void);
private:
	int rows;
	double ** A;
	
};

#endif