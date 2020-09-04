#pragma once
#include <iostream>
#include <vector>

#define DEFAULT "AAAAAA"  // will be changed later

//Standard genetic table:  
// To keep DNA codes basic I decreased the table.
#define UU1 "UUU"
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
#define GG2 "GGC"

#define START "AUG"
#define STOP "UAG"

//Bacteria Types: Coccus, Bacillus, Spirillum, Rickettsia, Mycoplasma

// GENETIC CODES (They are completely random at this moment, can be altered in the future..): 
//Initial code values are const but after injecting the bacteria, their codes can be changed due to selection.
// Codes consist 16 codons for now. Also codes can be generated randomly for more complicated genetic codes(like a code with 512 codons)
#define CODECoccus START+UU1+GC2+GA1+AG2+AC1+CU2+UG2+UC2+GA2+AG1+CG1+GG2+UU2+GC1+STOP  
#define CODEBacillus START+AG1+CG1+GU2+GG2+GC2+CA1+AG2+CG1+UU1+AG1+AA2+UA2+GG1+GC2+STOP
#define CODESpirillum START+STOP
#define CODERickettsia START+STOP
#define CODEMycoplasma START+STOP

struct newBacteria {
	std::string bacteriaType;
	std::string GENETICCODE;
	bool mutuality;
	double growthRATE;
	double lifeTIME;
	std::vector<double> philes;
	std::vector<double> phobes;
}typedef newBacteria;


std::string getTrueCodon(std::string incomingCodon, int error);

class Bacteria{
private:
	std::string bacteriaType;
	std::string GENETICCODE;
	bool mutuality;
	double growthRATE;
	double lifeTIME;    // minutes
	std::vector<double> philes;
	std::vector<double> phobes;
	double overallSurvivalPoint;

public:
	Bacteria(newBacteria* newBacteria);
	Bacteria();
	~Bacteria();

public:
	void calculateSurvivalPoint();
	void setSurvivalPoint(int point);
	void duplicatingCODE(); //setting
	double getSurvivalPoint();
	double getGrowthRATE();
	double getLifeTIME();

	std::string getGeneticCode();


};

class injectedBacteria{
private:
	std::string bacteria;
	newBacteria* Coccus = nullptr;
	newBacteria* Bacillus = nullptr;
	newBacteria* Spirillum = nullptr;
	newBacteria* Rickettsia = nullptr;
	newBacteria* Mycoplasma = nullptr;
public:
	injectedBacteria(std::string newBacteria);
	~injectedBacteria();
public:
	void setBacterias();
	newBacteria* returnBacteria();
};


