#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include "time.h"
#include "ServerSimulation.h"
using namespace std;
ServerSimulation::ServerSimulation(void)
{
}


ServerSimulation::~ServerSimulation(void)
{
}


void ServerSimulation::systemSimulation()
{
	task t;
	t.arrival = randomize(0,T);
	t.duration = randomize(0,D);
	int k = randomize(0,K);







}


int randomize(int lb, int ub)
{
	int r;
	r = rand();
	r = r % (ub-lb);
	r = r + lb;
	return r;

}