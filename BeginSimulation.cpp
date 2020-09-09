#include "BeginSimulation.h"

#include <math.h>

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
	int survivalPoint = 0;
	survivalPoint += ecosystem.getoverallLifeSupport();
	bacterias.at(ecosystem.currentBacteriaAmount).setSurvivalPoint(survivalPoint);
}


void BeginSimulation::setParameters() {
	//if(antibiotics)

}
// mitotic division with a slight duplicate error
void BeginSimulation::fabrication() { 
	srand((unsigned)time(0));
	int numberofDivisionedBacterias = 0;
	for (std::vector<Bacteria>::iterator it = bacterias.begin(); it != bacterias.end(); it++) {
		double errorChance = fmod(rand(), 1.1);
		std::string copyCode = it->getGeneticCode();
		for (int j = 3; j < copyCode.length(); j+=3) {
			if (errorChance < 0.09) {  // Here, we emulate error chance of dna duplication  CODECoccus START+UU1+GC2+GA1+AG2+AC1+CU2+UG2+UC2+GA2+AG1+CG1+GG2+UU2+GC1+STOP 
				std::string tempCodon = getTrueCodon(""+copyCode[j] + copyCode[j + 1] + copyCode[j + 2], errorChance);
				copyCode[j] = tempCodon[j]; copyCode[j+1] = tempCodon[j+1]; copyCode[j+2] = tempCodon[j+2]; // can be altered -_-
			}

		}
		Bacteria fabricatedBacteria;
		fabricatedBacteria.operator=(*it);
		fabricatedBacteria.duplicatingCODE(copyCode);  // mitotic divisioned bacteria is added to environment.
		bacterias.push_back(fabricatedBacteria);	
	}


}

void BeginSimulation::startSimulation() {



}
