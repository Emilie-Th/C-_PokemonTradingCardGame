#include "stdafx.h"

#include "Player.h"
#include "Card.h"


Player::Player(const string& name, const vector<Card*> benchCards, const vector<PokemonCard*> _actionsCard):
	playerName(name),
	m_benchCards(benchCards),
	actionsCards(_actionsCard)
{
	
}


Player::Player(const string& name) :
											playerName(name),
											m_benchCards(),
											actionsCards()
{

}

Player::~Player(void)
{
}



string Player::getPlayerName() const {
	return playerName;
}

vector<Card*> Player::getBenchCards() const{
	return m_benchCards;
}

vector<PokemonCard*> Player::getActionsCards() const {
	return actionsCards;
}

void Player::addCardToBench(Card* pObjCard)
{
	m_benchCards.push_back(pObjCard);
}
