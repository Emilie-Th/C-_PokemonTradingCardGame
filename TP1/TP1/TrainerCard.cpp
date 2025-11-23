#include "TrainerCard.h"
#include "PokemonCard.h"


TrainerCard::TrainerCard(const string& trainer, const string& trainerEffect) :
	Card(trainer),
	m_trainerEffect(trainerEffect)
{

}

void TrainerCard::displayInfo() const
{
	cout << "Card Name :" << getCardName() << endl << "Trainer Effect : " << m_trainerEffect << endl;
}

string TrainerCard::getTrainerEffect() const 
{
	
	return m_trainerEffect;
}

void TrainerCard::heal(vector<PokemonCard*>& Pokemons)
{
	for (int i = 0; i < Pokemons.size(); i++) 
	{
		Pokemons[i]->setHP(Pokemons[i]->getMaxHP());
	}
}
