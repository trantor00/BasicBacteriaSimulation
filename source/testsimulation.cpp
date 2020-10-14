#include "BeginSimulation.h"
#include <iostream>
#include <stdio.h>


using namespace std;

int main() {
	srand(time(NULL));
	cout << "Simulation test 1 has begun!" << endl;

	//Ecosystem
	string ecosystemName = "test1";
	Ecosystem newEcosystem(ecosystemName, 0, 20, 100, 50);
	//Ecosystem *newEcosystem = new Ecosystem("test1", 0, 20, 100, 50);
	newEcosystem.createEnvironment();


	//Bacteria Coccus
	injectedBacteria simpleBacteria("Coccus");
	simpleBacteria.setBacterias();
    Bacteria tempBacteria(simpleBacteria.returnBacteria());
	tempBacteria.calculateSurvivalPoint();  // Bacteria vulnerability point
	tempBacteria.setSurvivalPoint(newEcosystem.getoverallLifeSupport());  // Environment life support

    // Bacteria Bacillus
	injectedBacteria simpleBacteria2("Bacillus");
	simpleBacteria2.setBacterias();
	Bacteria tempBacteria2(simpleBacteria2.returnBacteria());
	tempBacteria2.calculateSurvivalPoint();
	tempBacteria2.setSurvivalPoint(newEcosystem.getoverallLifeSupport()); 

	// Bacteria Spirillum
	injectedBacteria simpleBacteria3("Spirillum");
	simpleBacteria3.setBacterias();
	Bacteria tempBacteria3(simpleBacteria3.returnBacteria());
	tempBacteria3.calculateSurvivalPoint();
	tempBacteria3.setSurvivalPoint(newEcosystem.getoverallLifeSupport()); 			

    // Bacteria Rickettsia
	injectedBacteria simpleBacteria4("Rickettsia");
	simpleBacteria4.setBacterias();
	Bacteria tempBacteria4(simpleBacteria4.returnBacteria());
	tempBacteria4.calculateSurvivalPoint();
	tempBacteria4.setSurvivalPoint(newEcosystem.getoverallLifeSupport()); 

    // Bacteria Mycoplasma
	injectedBacteria simpleBacteria5("Mycoplasma");
	simpleBacteria5.setBacterias();
	Bacteria tempBacteria5(simpleBacteria5.returnBacteria());
	tempBacteria5.calculateSurvivalPoint();
	tempBacteria5.setSurvivalPoint(newEcosystem.getoverallLifeSupport()); 	


	//Simulation
	bool naturalSelection = true;
	bool selectiveBreeding = true;
	bool antibiotics = true;
	int givenAlimentAmount = 1000;
	//BeginSimulation* simulation1 = new BeginSimulation(*newEcosystem, naturalSelection, selectiveBreeding, antibiotics, givenAlimentAmount);
	BeginSimulation simulation1(newEcosystem, naturalSelection, selectiveBreeding, antibiotics, givenAlimentAmount);
	
	// Injecting new bacterias to the culture
	for(int x=0;x<5;x++){
	//if(x%2==0) 
	simulation1.injectNewBacteria(tempBacteria);
	simulation1.injectNewBacteria(tempBacteria2);
	simulation1.injectNewBacteria(tempBacteria3);
	simulation1.injectNewBacteria(tempBacteria4);
	simulation1.injectNewBacteria(tempBacteria5); 
	}
    
	

	for(int a=0;a<5;a++){
	simulation1.fabrication();  // replication

	cout << "Bacterias after " << a+1 << ". breeding:" << endl;
	
  /*for(int i=0;i<simulation1.getBacterias().size();i++){
	cout << "Bacteria " << simulation1.getBacterias().at(i).getbacteriaType() << " - " << i << " 'sGenetic Code : " << simulation1.getBacterias().at(i).getGeneticCode() << endl;
    }	*/
	
	int totalBacteria = 0;
	int totalCoccus = 0;
	int totalBacillus = 0;
	int totalSpirillum = 0;
	int totalRickettsia = 0;
	int totalMycoplasma = 0;

	for (int i = 0; i < simulation1.getBacterias().size(); i++) {
        totalBacteria++;
		if(simulation1.getBacterias().at(i).getbacteriaType().compare("Coccus") == 0){
			if (simulation1.getBacterias().at(i).getGeneticCode().compare((string)CODECoccus) != 0) {
            //	cout << "Genetical variation detected! at -> Coccus " << totalBacteria << "." << endl;
			totalCoccus++; }
			}
		else if(simulation1.getBacterias().at(i).getbacteriaType().compare("Bacillus") == 0){
			if (simulation1.getBacterias().at(i).getGeneticCode().compare((string)CODEBacillus) != 0) {
            //	cout << "Genetical variation detected! at -> Bacillus " << totalBacteria << "." << endl;
			totalBacillus++; }
			} 
		else if(simulation1.getBacterias().at(i).getbacteriaType().compare("Spirillum") == 0){
			if (simulation1.getBacterias().at(i).getGeneticCode().compare((string)CODESpirillum) != 0) {
            //	cout << "Genetical variation detected! at -> Spirillum " << totalBacteria << "." << endl;
			totalSpirillum++; }
			}
		else if(simulation1.getBacterias().at(i).getbacteriaType().compare("Rickettsia") == 0){
			if (simulation1.getBacterias().at(i).getGeneticCode().compare((string)CODERickettsia) != 0) {
             //	cout << "Genetical variation detected! at -> Rickettsia " << totalBacteria << "." << endl;
			totalRickettsia++; }
			}
		else if(simulation1.getBacterias().at(i).getbacteriaType().compare("Mycoplasma") == 0){
			if (simulation1.getBacterias().at(i).getGeneticCode().compare((string)CODEMycoplasma) != 0) {
            //	cout << "Genetical variation detected! at -> Mycoplasma " << totalBacteria << "." << endl;
			totalMycoplasma++; }
			}
		else{
			cout << "Error! at " << simulation1.getBacterias().at(i).getbacteriaType() << endl;		
			}							
	}  

	cout << "\nVariation rate is " <<(double)(totalBacillus+totalCoccus) / totalBacteria << " in " << simulation1.getBacterias().size()/2 << " mitotic division." << endl;
	cout << "Variation rate of Coccus is " << (double)totalCoccus /simulation1.getBacterias().size() << " out of " << totalCoccus << endl;
	cout << "Variation rate of Bacillus is " << (double)totalBacillus /simulation1.getBacterias().size() << " out of " << totalBacillus << endl;
	cout << "Variation rate of Spirillum is " << (double)totalSpirillum /simulation1.getBacterias().size() << " out of " << totalSpirillum << endl;
	cout << "Variation rate of Rickettsia is " << (double)totalRickettsia /simulation1.getBacterias().size() << " out of " << totalRickettsia << endl;
	cout << "Variation rate of Mycoplasma is " << (double)totalMycoplasma /simulation1.getBacterias().size() << " out of " << totalMycoplasma << endl;


	cout << "\nSimulation finished."<< endl;

	}
	cout << "Total bacterias in the culture: " << simulation1.getBacterias().size() << endl;

	return 0;
}
