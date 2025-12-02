#ifndef ENERGYCARD_H
#define ENERGYCARD_H


#include<string>
//#include<vector>
//#include<tuple>
#include "Card.h"
using namespace std;


class EnergyCard : public Card 
{


public:
	
	EnergyCard(const string&);
	~EnergyCard();// = default;

//	void displayInfo()const;// override;
	void displayInfo(void) const;
	string getEnergyType() const;

private:
	string m_energyType;

};

#endif