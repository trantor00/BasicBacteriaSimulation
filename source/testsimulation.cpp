#include "BeginSimulation.h"
#include <iostream>
#include <stdio.h>


using namespace std;

int main() {
	cout << "Simulation test 1 has begun!" << endl;

	//Ecosystem
	string ecosystemName = "test1";
	Ecosystem newEcosystem(ecosystemName, 0, 20, 100, 50);
	//Ecosystem *newEcosystem = new Ecosystem("test1", 0, 20, 100, 50);
	newEcosystem.createEnvironment();


	//Bacteria 1
	injectedBacteria simpleBacteria("Coccus");
	simpleBacteria.setBacterias();
    Bacteria tempBacteria(simpleBacteria.returnBacteria());
	tempBacteria.calculateSurvivalPoint();  // Bacteria vulnerability point
	tempBacteria.setSurvivalPoint(newEcosystem.getoverallLifeSupport());  // Environment life support

    // Bacteria 2
	injectedBacteria simpleBacteria2("Bacillus");
	simpleBacteria2.setBacterias();
	Bacteria tempBacteria2(simpleBacteria2.returnBacteria());
	tempBacteria2.calculateSurvivalPoint();
	tempBacteria2.setSurvivalPoint(newEcosystem.getoverallLifeSupport()); 
	

	//Simulation
	bool naturalSelection = true;
	bool selectiveBreeding = true;
	bool antibiotics = true;
	int givenAlimentAmount = 1000;
	//BeginSimulation* simulation1 = new BeginSimulation(*newEcosystem, naturalSelection, selectiveBreeding, antibiotics, givenAlimentAmount);
	BeginSimulation simulation1(newEcosystem, naturalSelection, selectiveBreeding, antibiotics, givenAlimentAmount);
	for(int x=0;x<10;x++){
	if(x%2==0) simulation1.injectNewBacteria(tempBacteria);
	simulation1.injectNewBacteria(tempBacteria2);
	}

	for(int a=0;a<6;a++){
	simulation1.fabrication();
	
	

	cout << "Bacterias after " << a+1 << ". breeding:" << endl;
	
	for(int i=0;i<simulation1.getBacterias().size();i++){
//	cout << "Bacteria " << simulation1.getBacterias().at(i).getbacteriaType() << " - " << i << " 'sGenetic Code : " << simulation1.getBacterias().at(i).getGeneticCode() << endl;
    }	
	int totalCoccus = 0;
	int totalBacillus = 0;
	for (int i = 0; i < simulation1.getBacterias().size(); i++) {
		if(simulation1.getBacterias().at(i).getbacteriaType().compare("Coccus")==0){
		if (simulation1.getBacterias().at(i).getGeneticCode().compare((string)CODECoccus) != 0) {
		//	cout << "Genetical variation detected! at -> Coccus " << i << "." << endl;
			totalCoccus++;
		}
		}
		else if(simulation1.getBacterias().at(i).getbacteriaType().compare("Bacillus")==0){
              if (simulation1.getBacterias().at(i).getGeneticCode().compare((string)CODEBacillus) != 0) {
		//	cout << "Genetical variation detected! at -> Bacillus " << i << "." << endl;
			totalBacillus ++;
		}
		}
	}

	cout << "\nVariation rate is " <<(double)(totalBacillus+totalCoccus) /simulation1.getBacterias().size()<< " in " << simulation1.getBacterias().size()/2 << " mitotic division." << endl;
	cout << "Variation rate of Coccus is " << (double)totalCoccus /simulation1.getBacterias().size() << " out of " << totalCoccus << endl;
	cout << "Variation rate of Bacillus is " << (double)totalBacillus /simulation1.getBacterias().size() << " out of " << totalBacillus << endl;



	cout << "\nSimulation finished."<< endl;

	}

	return 0;
}
