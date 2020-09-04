#pragma once

#include <iostream>
#include <stdlib.h>    
#include <time.h> 
#include <string>
#include <vector>

#include "Bacteria.h"

enum environments {  //0-5
	//Terrestrial ecosystems
	Forest,
	Grassland,
	Tundra,
	Desert,
	//Aquatic ecosystems
	Freshwater,
	Marine
};


// Source: https://examples.yourdictionary.com/examples-of-bacteria.html
/*struct bacterias {
	enum Coccus { Staphaureus, Sepidermidis};
	enum Bacillus { Cdiptheriae, Bacillusanthracis};
	enum Spirillum {   };
	enum Rickettsia {   };
	enum Mycoplasma {   };

}typedef bacterias;*/



class Ecosystem
{
private:
	std::string ecosystemName;
	double degree; // celcius
	double area; // m^2
	int maxAmountofBacterias;
	int overallLifeSupport;  // which will be calculated from calculateLifesupport();
	int environmentType=0;
	

public:
	 Ecosystem(std::string ecosystemName, int environmentType, double degree, double area, int maxAmountofBacterias);
	 Ecosystem();
	~Ecosystem();

public:
	int createEcosystem();
	int calculateLifesupport();
	void environment();
	int currentBacteriaAmount = 0;
	int getoverallLifeSupport();
};

