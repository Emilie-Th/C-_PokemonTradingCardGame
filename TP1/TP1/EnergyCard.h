#ifndef EnergyCard_h
#define EnergyCard_h

#include <iostream>
#include<string>
#include<vector>
#include<tuple>
#include "Card.h"
using namespace std;


class EnergyCard : public Card {
private:
	string energyType;
	static const int UnitEnergy = 1;

public:
	void displayInfo() const override;
	EnergyCard(const string&);
	virtual ~EnergyCard() = default;
	string getEnergyType() const;

	//En C++, les accesseurs ses Getter et Setter servent pour => lire ou modifier la valeur d’un attribut privé ou protégé.
// dans le jeu chaque carte d'énergie attachée à un Pokémon compte pour 1 ( UNITE )
	int getEnergyValue() const { return UnitEnergy; }


};

#endif