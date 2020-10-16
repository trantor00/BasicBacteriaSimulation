#include "BeginSimulation.h"

#include <math.h>
#include <time.h>


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
	//ecosystem.currentBacteriaAmount++;
}

void BeginSimulation::setParameters() {
	//if(antibiotics)

}
// mitotic division with a slight duplicate error
void BeginSimulation::fabrication() { 
	srand((unsigned)time(0));
	int numberofDivisionedBacterias = 0;
	std::vector<Bacteria> tempBacterias;
	double survivalpoints[5];  // since we have 5 bacteria species..
	std::string xample1 = bacterias.at(0).getbacteriaType();
	std::string xample2 = bacterias.at(1).getbacteriaType();
	std::string xample3 = bacterias.at(2).getbacteriaType();
	std::string xample4 = bacterias.at(3).getbacteriaType();
	std::string xample5 = bacterias.at(4).getbacteriaType();

               survivalpoints[0]= bacterias.at(0).getSurvivalPoint();
			   survivalpoints[1]= bacterias.at(1).getSurvivalPoint();
			   survivalpoints[2]= bacterias.at(2).getSurvivalPoint();
			   survivalpoints[3]= bacterias.at(3).getSurvivalPoint();
			   survivalpoints[4]= bacterias.at(4).getSurvivalPoint();
		
               	std::string code1 = bacterias.at(0).getGeneticCode();
	            std::string code2 = bacterias.at(1).getGeneticCode();
              	std::string code3 = bacterias.at(2).getGeneticCode();
             	std::string code4 = bacterias.at(3).getGeneticCode();
	            std::string code5 = bacterias.at(4).getGeneticCode();

		int tempV = 0xFFF0; 
		int chosen;
		for(int j = 0; j < 5; j++){
            if(survivalpoints[j] < tempV){
				tempV = survivalpoints[j];
			}
		}
		for(int y = 0; y < 5; y++){
			if(survivalpoints[y] == tempV){
           //    chosen = y ;  // if a bacteria has lower survival points than others then it will be dying slowly.
			}
		}	
	
	
	for (std::vector<Bacteria>::iterator it = bacterias.begin(); it != bacterias.end(); it++) {
	//	int fabricationAbility = it->getSurvivalPoint();
		double errorChance = fmod(rand(), 1.1);
		std::string copyCode = it->getGeneticCode();
		for (int j = 3; j < copyCode.length()-3; j+=3) {
			if (errorChance < 0.5) {  // Here, we emulate error chance of dna duplication.
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
		fabricatedBacteria.duplicatingCODE(copyCode);  // mitotic divisioned bacteria is added to the environment.

		if(it->getbacteriaType().compare(xample1) == 0){
			    if(it->getGeneticCode() != code1){
			    int divisions = survivalpoints[0]/90;
			    for(int i=0;i<divisions;i++){
                tempBacterias.push_back(fabricatedBacteria);}
			}
			else{
				tempBacterias.push_back(fabricatedBacteria);
			}
			if(chosen == 0){
				tempBacterias.pop_back();
			}
		}
		else if(it->getbacteriaType().compare(xample2) == 0){
			    if(it->getGeneticCode() != code2){
			    int divisions = survivalpoints[1]/90;
			    for(int i=0;i<divisions;i++){
                tempBacterias.push_back(fabricatedBacteria);}
			}
			else{
				tempBacterias.push_back(fabricatedBacteria);
			}
			if(chosen == 1){
				tempBacterias.pop_back();
			}			
		}
		else if(it->getbacteriaType().compare(xample3) == 0){
			    if(it->getGeneticCode() != code3){
			    int divisions = survivalpoints[2]/90;
			    for(int i=0;i<divisions;i++){
                tempBacterias.push_back(fabricatedBacteria);}
			}
			else{
				tempBacterias.push_back(fabricatedBacteria);
			}
			if(chosen == 2){
				tempBacterias.pop_back();
			}			
		}
		else if(it->getbacteriaType().compare(xample4) == 0){
			    if(it->getGeneticCode() != code4){
			    int divisions = survivalpoints[3]/90;
			    for(int i=0;i<divisions;i++){
                tempBacterias.push_back(fabricatedBacteria);}
			}
			else{
				tempBacterias.push_back(fabricatedBacteria);
			}
			if(chosen == 3){
				tempBacterias.pop_back();
			}			
		}
		else if(it->getbacteriaType().compare(xample5) == 0){
			    if(it->getGeneticCode() != code5){
			    int divisions = survivalpoints[4]/90;
			    for(int i=0;i<divisions;i++){
                tempBacterias.push_back(fabricatedBacteria);}
			}
			else{
				tempBacterias.push_back(fabricatedBacteria);
			}
			if(chosen == 4){
				tempBacterias.pop_back();
			}			
		}								
			
	}
	for (std::vector<Bacteria>::iterator it = tempBacterias.begin(); it != tempBacterias.end(); it++) {
		bacterias.push_back(*it);
	}
}

void BeginSimulation::startSimulation() {



}


