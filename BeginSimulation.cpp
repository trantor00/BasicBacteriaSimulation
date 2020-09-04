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
		std::string copyCode = it->getGeneticCode;
		for (int j = 0; j < copyCode.length(); j++) {
			if (errorChance < 0.02) {  // Here, we emulate error chance of dna duplication


			}
		}
	}


}

void BeginSimulation::startSimulation() {



}