#ifndef PLAYER_H
#define	PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
#include "PokemonCard.h"

using namespace std;

class Player 
{

public:

	Player(const string&, const vector<Card*>, const vector<PokemonCard*>);
	Player(const string&);

	virtual ~Player();// = default;

	void addCardToBench(Card* pObjCard);



	string getPlayerName() const;
	vector<Card*> getBenchCards() const;
	vector<PokemonCard*> getActionsCards() const;
	
private: 
	
	string playerName;
	vector<Card*> m_benchCards;
	vector<PokemonCard*> actionsCards;

};

#endif 
