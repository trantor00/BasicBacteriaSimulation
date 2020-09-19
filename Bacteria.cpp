#include "Bacteria.h"


Bacteria::Bacteria(newBacteria* newBacteria) {
	bacteriaType = newBacteria->bacteriaType;
	GENETICCODE = newBacteria->GENETICCODE;
	mutuality = newBacteria->mutuality; // true as default
	growthRATE = newBacteria->growthRATE;
	lifeTIME = newBacteria->lifeTIME;
	philes = newBacteria->philes;
	phobes = newBacteria->phobes;

}
Bacteria::~Bacteria(){}

void Bacteria::calculateSurvivalPoint() {
	// calcualtion survival point 
	double survivalPoint = 0;
	for (std::vector<double>::iterator it = philes.begin(); it != philes.end(); it++) {
		survivalPoint += *it*10;

	}
	for (std::vector<double>::iterator it = phobes.begin(); it != phobes.end(); it++) {
		survivalPoint -= *it*10;

	}
	overallSurvivalPoint = survivalPoint;
}

double Bacteria::getSurvivalPoint() {
	return overallSurvivalPoint;
}
void Bacteria::setSurvivalPoint(int point) {
	overallSurvivalPoint += point;	
}

std::string Bacteria::getGeneticCode() {
	return GENETICCODE;
}
double Bacteria::getGrowthRATE() {
	return growthRATE;
}
double Bacteria::getLifeTIME() {
	return lifeTIME;
}

void Bacteria::duplicatingCODE(std::string incomingCodon) {
	this->GENETICCODE = incomingCodon;
}

std::string Bacteria::getbacteriaType() {
	return bacteriaType;
}


injectedBacteria::injectedBacteria(std::string newBacteria) {
	this->bacteria = newBacteria;
}
newBacteria* injectedBacteria::returnBacteria() {
	if (bacteria == "Coccus") return Coccus;
	else if (bacteria == "Bacillus") return Bacillus;

	return nullptr;

}
void injectedBacteria::setBacterias() {  // so many research should be done before this section
	// I know there are bunch of sub bacterias of these 5 bacteria kind but to keep simulation basic I only defined 5 of them as main bacterias. 
	//Coccus
	Coccus = new newBacteria;
	Coccus->bacteriaType = "Coccus";
	Coccus->GENETICCODE=(std::string)CODECoccus;
	Coccus->growthRATE = 10;
	Coccus->lifeTIME = 5;
	Coccus->mutuality = true;
	std::vector<double> Coccusphiles;
	std::vector<double> Coccusphobes;
	// Vectors will take 3 parameters and these parameters alter according to the bacteria's specifications. They can be changed or increased..
	// no sensibility->0
    // min sensibility->1
	// med sensibility->2
	// max sensibility->3
	//  philes : (first parameter) xenophile, (second parameter) plurality chooser, (third parameter) good environment sensiblity
	//  phobes : (first parameter) xenophobe, (second parameter) singularity chooser, (third parameter) bad environment sensiblity

	Coccusphiles.push_back(3); Coccusphiles.push_back(1); Coccusphiles.push_back(3);
	Coccusphobes.push_back(0); Coccusphobes.push_back(3); Coccusphobes.push_back(2);
	Coccus->philes = Coccusphiles;
	Coccus->phobes = Coccusphobes;

	//Bacillus
	Bacillus = new newBacteria;
	Bacillus->bacteriaType = "Bacillus";
	Bacillus->GENETICCODE = (std::string)CODEBacillus;
	Bacillus->growthRATE = 15;
	Bacillus->lifeTIME = 7;
	Bacillus->mutuality = true;
	std::vector<double> Bacillusphiles;
	std::vector<double> Bacillusphobes;
	Bacillusphiles.push_back(2); Bacillusphiles.push_back(2); Bacillusphiles.push_back(3);
	Bacillusphobes.push_back(1); Bacillusphobes.push_back(3); Bacillusphobes.push_back(1);
	Bacillus->philes = Bacillusphiles;
	Bacillus->phobes = Bacillusphobes;
	

	//Spirillum

	//Rickettsia

	//Mycoplasma
	
}

const Bacteria& Bacteria::operator=(const Bacteria& newBacteria) {
	this->bacteriaType = newBacteria.bacteriaType;
	this->GENETICCODE = newBacteria.GENETICCODE;
	this->mutuality = newBacteria.mutuality;
	this->growthRATE = newBacteria.growthRATE;
	this->lifeTIME = newBacteria.lifeTIME;
	this->philes = newBacteria.philes; // I may need an operator= overloading for vectors.
	this->phobes = newBacteria.phobes;
	this->overallSurvivalPoint = newBacteria.overallSurvivalPoint;
	return *this;	
}



std::string Bacteria::getTrueCodon(std::string incomingCodon, int error) {
	std::string trueCodon;
	if (incomingCodon == START) return START;
	if (incomingCodon == STOP) return STOP;
	switch (error) {
	case 1:
		trueCodon = UU2;
		break;
	case 2:
		trueCodon = UC1;
		break;
	case 3:
		trueCodon = UA2;
		break;
	case 4:
		trueCodon = UG1;
		break;
	case 5:
		trueCodon = CU2;
		break;
	case 6:
		trueCodon = CC1;
		break;
	case 7:
		trueCodon = CA2;
		break;
	case 8:
		trueCodon = CG1;
		break;
	case 9:
		trueCodon = AU2;
		break;
	default:
		trueCodon = incomingCodon;
		break;
	}
	return trueCodon;

}