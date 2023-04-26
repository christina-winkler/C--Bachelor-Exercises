#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <list>
#include "time.h"
#pragma once

#ifndef SERVERSIMULATION_H
#define SERVERSIMULATION_H

struct task
	{
	int arrival;
	int duration;
	};

class ServerSimulation
{
public:
	ServerSimulation(void);
	~ServerSimulation(void);
	void systemSimulation();
	int randomize(int lb, int ub);

private:
	int m; //number of server
	int D;	//maximal duration of execution 
	int K; //number of tasks
	int T; //arrival time
   queue<task> waiting;
};

#endif SERVERSIMULATION_H