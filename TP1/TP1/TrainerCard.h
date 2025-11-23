#ifndef TrainerCard_h
#define TrainerCard_h

#include <iostream>
#include<string>
#include<vector>
#include<tuple>
#include "Card.h"
#include "PokemonCard.h"
using namespace std;


class TrainerCard : public Card {
private:
	string m_trainerEffect;

public:
	
	TrainerCard(const string&, const string&);
	virtual ~TrainerCard() = default;

	void displayInfo() const override;
	string getTrainerEffect() const;
	// si je mets pas pokemon il met une erreur car vector<Pokemon*>   sans préciser  => paramêtre de méthode fait par copie 
	//  dans & c'est par reférence ( c'est pointeur vers Objet passé mais existe alias 
	void heal(vector<PokemonCard*>& Pokemons);

};

#endif