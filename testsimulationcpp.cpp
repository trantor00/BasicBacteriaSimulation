#include "BeginSimulation.h"
#include <iostream>
#include <stdio.h>
#include <memory>

using namespace std;

int main() {
	cout << "hello simulation test 1 is begun!" << endl;

	//Ecosystem
	string ecosystemName = "test1";
	unique_ptr<Ecosystem> newEcosystem(new Ecosystem(ecosystemName, 0, 20, 100, 50));
	//Ecosystem *newEcosystem = new Ecosystem("test1", 0, 20, 100, 50);
	newEcosystem->createEnvironment();


	//Bacterias
	unique_ptr<injectedBacteria> simpleBacteria(new injectedBacteria(("Coccus")));	
	simpleBacteria->setBacterias();
	unique_ptr<Bacteria> tempBacteria(new Bacteria(simpleBacteria->returnBacteria()));
	tempBacteria->calculateSurvivalPoint();
	tempBacteria->setSurvivalPoint(newEcosystem->getoverallLifeSupport());

	//Simulation
	bool naturalSelection = true;
	bool selectiveBreeding = true;
	bool antibiotics = true;
	int givenAlimentAmount = 1000;
	//BeginSimulation* simulation1 = new BeginSimulation(*newEcosystem, naturalSelection, selectiveBreeding, antibiotics, givenAlimentAmount);
	unique_ptr<BeginSimulation> simulation1(new BeginSimulation(*newEcosystem, naturalSelection, selectiveBreeding, antibiotics, givenAlimentAmount));
	simulation1->injectNewBacteria(*tempBacteria);
	simulation1->setSurvivability();
	simulation1->fabrication();



	cout << "Simulation finished" << endl;

	


	return 0;
}