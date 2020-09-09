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



injectedBacteria::injectedBacteria(std::string newBacteria) {
	this->bacteria = newBacteria;
	setBacterias();
}
void injectedBacteria::setBacterias() {  // so many research should be done before this section
	// I know there are bunch of sub bacterias of these 5 bacteria kind but to keep simulation basic I only defined 5 of them as main bacterias. 
	//Coccus
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
	Coccus->bacteriaType = "Bacillus";
	Coccus->GENETICCODE = (std::string)CODEBacillus;
	Coccus->growthRATE = 15;
	Coccus->lifeTIME = 7;
	Coccus->mutuality = true;
	std::vector<double> Bacillusphiles;
	std::vector<double> Bacillusphobes;
	Bacillusphiles.push_back(2); Bacillusphiles.push_back(2); Bacillusphiles.push_back(3);
	Bacillusphobes.push_back(1); Bacillusphobes.push_back(3); Bacillusphobes.push_back(1);
	Coccus->philes = Bacillusphiles;
	Coccus->phobes = Bacillusphobes;

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

newBacteria* injectedBacteria::returnBacteria() {
	if (bacteria == "Coccus") return Coccus;
	else if (bacteria == "Bacillus") return Bacillus;

	return nullptr;

}

std::string getTrueCodon(std::string incomingCodon, int error) {
	std::string trueCodon;
	error *= 100;
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
		/*#define UU1 "UUU"
#define UU2 "UUC"
#define UC1 "CUU"
#define UC2 "CUC"
#define UA1 "AUU"
#define UA2 "AUC"
#define UG1 "GUU"
#define UG2 "GUC"
#define CU1 "UCU"
#define CU2 "UCC"
#define CC1 "CCU"
#define CC2 "CCC"
#define CA1 "ACU"
#define CA2 "ACC"
#define CG1 "GCU"
#define CG2 "GCC"
#define AU1 "UAU"
#define AU2 "UAC"
#define AC1 "CAU"
#define AC2 "CAC"
#define AA1 "AAU"
#define AA2 "AAC"
#define AG1 "GAU"
#define AG2 "GAC"
#define GU1 "UGU"
#define GU2 "UGC"
#define GC1 "CGU"
#define GC2 "CGG"
#define GA1 "AGU"
#define GA2 "AGC" 
#define GG1 "GGU"
#define GG2 "GGC"*/





		return trueCodon;
	}

}