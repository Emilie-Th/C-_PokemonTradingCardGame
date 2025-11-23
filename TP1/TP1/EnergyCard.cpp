#include "EnergyCard.h"


EnergyCard::EnergyCard(const string& _energyType) :
	Card("Energy"),
	energyType(_energyType)
{

}

void EnergyCard::displayInfo() const
{
	cout << "Card Name :" << getCardName() << endl << "Energy Type : " << energyType << endl;
}

string EnergyCard::getEnergyType() const {
	return energyType;
}


