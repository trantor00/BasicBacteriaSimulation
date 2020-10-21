#pragma once

#include "Ecosystem.h"

class BeginSimulation
{
private:
	Ecosystem ecosystem;
	std::vector<Bacteria> bacterias;
	bool naturalSelection;
	bool selectiveBreeding;
	bool antibiotics;
	int givenAlimentAmount; // can be increased
	int bacteriaAmount=0;

public:
	BeginSimulation(Ecosystem ecosystem, bool naturalSelection, bool selectiveBreeding, bool antibiotics, int givenAlimentAmount);
	~BeginSimulation();
public:
	void injectNewBacteria(Bacteria newBacteria);
	void setParameters();	
	void replication();
	void startSimulation();
	std::vector<Bacteria> getBacterias();

};

