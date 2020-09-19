#include "BeginSimulation.h"

#include <math.h>


std::vector<Bacteria> BeginSimulation::getBacterias() {
	return bacterias;
}
BeginSimulation::BeginSimulation(Ecosystem ecosystem, bool naturalSelection, bool selectiveBreeding, bool antibiotics, int givenAlimentAmount){
	this->ecosystem = ecosystem;
	this->naturalSelection = naturalSelection;
	this->selectiveBreeding = selectiveBreeding;
	this->antibiotics = antibiotics;
	this->givenAlimentAmount = givenAlimentAmount;

}
BeginSimulation::~BeginSimulation(){}

void BeginSimulation::injectNewBacteria(Bacteria newBacteria) {
	bacterias.push_back(newBacteria);
	setSurvivability();
	ecosystem.currentBacteriaAmount++;
}


void BeginSimulation::setSurvivability() {
	int survivalPoint = ecosystem.getoverallLifeSupport();

/*	for (std::vector<Bacteria>::iterator it = bacterias.begin(); it != bacterias.end(); it++) {
		it->setSurvivalPoint(survivalPoint);
	}*/
}


void BeginSimulation::setParameters() {
	//if(antibiotics)

}
// mitotic division with a slight duplicate error
void BeginSimulation::fabrication() { 
	srand((unsigned)time(0));
	int numberofDivisionedBacterias = 0;
	std::vector<Bacteria> tempBacterias;
	for (std::vector<Bacteria>::iterator it = bacterias.begin(); it != bacterias.end(); it++) {
		double errorChance = fmod(rand(), 1.1);
		std::string copyCode = it->getGeneticCode();
		for (int j = 3; j < copyCode.length()-3; j+=3) {
			if (errorChance < 0.5) {  // Here, we emulate error chance of dna duplication  CODECoccus START+UU1+GC2+GA1+AG2+AC1+CU2+UG2+UC2+GA2+AG1+CG1+GG2+UU2+GC1+STOP 
				errorChance *= 10;
				std::string currentCodon;
				currentCodon.push_back(copyCode[j]); currentCodon.push_back(copyCode[j + 1]); currentCodon.push_back(copyCode[j + 2]);
				std::string tempCodon = it->getTrueCodon(currentCodon, errorChance);
				copyCode[j] = tempCodon[0];
				copyCode[j+1] = tempCodon[1];
				copyCode[j+2] = tempCodon[2]; // can be altered -_-
			}
		}
		Bacteria fabricatedBacteria=*it; 
		fabricatedBacteria.duplicatingCODE(copyCode);  // mitotic divisioned bacteria is added to environment.
		tempBacterias.push_back(fabricatedBacteria);	
	}
	for (std::vector<Bacteria>::iterator it = tempBacterias.begin(); it != tempBacterias.end(); it++) {
		bacterias.push_back(*it);
	}

}

void BeginSimulation::startSimulation() {



}
