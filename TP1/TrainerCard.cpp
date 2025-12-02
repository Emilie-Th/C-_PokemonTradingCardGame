#include "stdafx.h"
#include "TrainerCard.h"
//#include "PokemonCard.h"

#include <iostream>



TrainerCard::TrainerCard(const string& trainer, const string& trainerEffect) :Card(trainer),m_trainerEffect(trainerEffect)
{

}

TrainerCard::~TrainerCard()
{

}

void TrainerCard::displayInfo(void) const
{
	cout << "Card Name :" << m_cardName << endl << "Trainer Effect : " << m_trainerEffect << endl;
}

string TrainerCard::getTrainerEffect() const 
{
	return m_trainerEffect;
}

/*
void TrainerCard::heal(vector<PokemonCard*> pokemon)
{
	for (int i = 0; i < pokemon.size(); i++) {
		pokemon[i]->setHP(pokemon[i]->getMaxHP());
	}
}
*/


