#include "BeginSimulation.h"
#include <iostream>
#include <stdio.h>


using namespace std;

int main() {
	cout << "hello simulation test 1 is begun!" << endl;

	//Ecosystem
	string ecosystemName = "test1";
	Ecosystem newEcosystem(ecosystemName, 0, 20, 100, 50);
	//Ecosystem *newEcosystem = new Ecosystem("test1", 0, 20, 100, 50);
	newEcosystem.createEnvironment();


	//Bacterias
	injectedBacteria simpleBacteria("Coccus");
	simpleBacteria.setBacterias();
    Bacteria tempBacteria(simpleBacteria.returnBacteria());
	tempBacteria.calculateSurvivalPoint();
	tempBacteria.setSurvivalPoint(newEcosystem.getoverallLifeSupport());
	

	//Simulation
	bool naturalSelection = true;
	bool selectiveBreeding = true;
	bool antibiotics = true;
	int givenAlimentAmount = 1000;
	//BeginSimulation* simulation1 = new BeginSimulation(*newEcosystem, naturalSelection, selectiveBreeding, antibiotics, givenAlimentAmount);
	BeginSimulation simulation1(newEcosystem, naturalSelection, selectiveBreeding, antibiotics, givenAlimentAmount);
	for(int x=0;x<5;x++)
	simulation1.injectNewBacteria(tempBacteria);
	simulation1.setSurvivability(); 
	simulation1.fabrication();
	for(int i=0;i<simulation1.getBacterias().size();i++)
	cout << "Bacteria " << simulation1.getBacterias().at(i).getbacteriaType() << " - " << i << " 'sGenetic Code : " << simulation1.getBacterias().at(i).getGeneticCode() << endl;
	
	int total = 0;
	for (int i = 0; i < 10; i++) {
		if (simulation1.getBacterias().at(i).getGeneticCode().compare((string)CODECoccus) != 0) {
			cout << "Genetical variation detected! at -> " << i << endl;
			total++;
		}
	}

	cout << "Variation rate is " <<(double)total/10 << "\n\nSimulation finished." << endl;

	


	return 0;
}