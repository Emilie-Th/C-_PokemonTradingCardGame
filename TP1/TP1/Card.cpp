#include "Card.h"

Card::Card(const string& _cardName) :
	cardName(_cardName)
{

}

string Card::getCardName() const 
{
	return cardName;
}
