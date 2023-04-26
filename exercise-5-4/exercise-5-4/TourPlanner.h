#pragma once

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

#ifndef TOURPLANNER_H
#define TOURPLANNER_H

class TourPlanner
{
public:
	TourPlanner(void);
	~TourPlanner(void);

//Member Functions
bool readMatrix(string fname);
double length();
void opt();
void printMatrix();

private:
double **d; //distance
int n; //number of cities
int *t; //cities in tour

};





#endif TOURPLANNER_H
