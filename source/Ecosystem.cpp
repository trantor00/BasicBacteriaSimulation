#include "Ecosystem.h"

Ecosystem::Ecosystem(std::string ecosystemName, int environmentType, double degree, double area, int maxAmountofBacterias) {
	this->ecosystemName = ecosystemName;
	this->environmentType = environmentType;
	this->degree=degree;
	this->area = area;
	this->maxAmountofBacterias = maxAmountofBacterias;
	overallLifeSupport = 0;
}
Ecosystem::Ecosystem() {}
Ecosystem::~Ecosystem(){}

int Ecosystem::createEcosystem() {
	int environmentLifeSupport = 0;
	switch (environmentType) {
	case environments{ Forest }:
		environmentLifeSupport += 30;
		break;
	case environments{ Grassland }:
		environmentLifeSupport += 12;
		break;
	case environments{ Tundra }:
		environmentLifeSupport += 7;
		break;
	case environments{ Desert }:
		environmentLifeSupport += 3;
		break;
	case environments{ Freshwater }:
		environmentLifeSupport += 10;
		break;
	case environments{ Marine }:
		environmentLifeSupport += 35;
		break;
	}

	return environmentLifeSupport;
}

int Ecosystem::calculateLifesupport() {
	int environmentLifeSupport = 0;
	if (degree > 0 && degree < 30)
		environmentLifeSupport += degree;
	else if (degree > 30 && degree < 50)
		environmentLifeSupport += degree / 4;
	else if (degree > 50)
		environmentLifeSupport -= degree;
	else if (degree<0 && degree>-30)
		environmentLifeSupport -= degree;
	else if (degree > -273 && degree < -200)
		environmentLifeSupport -= -1000;
	
	double areaBacteriaRatio = area / maxAmountofBacterias;
	if (area > maxAmountofBacterias)
		environmentLifeSupport += areaBacteriaRatio * 10;
	else
		environmentLifeSupport -= areaBacteriaRatio * 10;
	return environmentLifeSupport;
 }


void Ecosystem::createEnvironment() {
	overallLifeSupport = createEcosystem() + calculateLifesupport();
	std::cout << "Ecosystem life support is" << overallLifeSupport << std::endl;
}

int Ecosystem::getoverallLifeSupport() {
	return overallLifeSupport;
}
const Ecosystem& Ecosystem::operator=(const Ecosystem& newEcosystem) {
	this->ecosystemName = newEcosystem.ecosystemName;
	this->degree = newEcosystem.degree;
	this->area = newEcosystem.area;
	this->maxAmountofBacterias = newEcosystem.maxAmountofBacterias;
	this->overallLifeSupport = newEcosystem.overallLifeSupport;
	this->environmentType = newEcosystem.environmentType;
	return *this;
}
