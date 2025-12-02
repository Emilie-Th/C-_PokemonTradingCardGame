#include "stdafx.h"
#include "EnergyCard.h"

#include <iostream> // Use cout

EnergyCard::EnergyCard(const string& energyType) :Card("Energy"),m_energyType(energyType)
{

}

EnergyCard::~EnergyCard()
{

}

void EnergyCard::displayInfo(void) const
{
	std::cout << "Card Name :" << m_cardName << endl << "Energy Type : " << m_energyType << endl;
}

string EnergyCard::getEnergyType() const 
{
	return m_energyType;
}


