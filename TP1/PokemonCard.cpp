#include "stdafx.h"
#include "PokemonCard.h"

#include <iostream> // Use cout

PokemonCard::PokemonCard(std::string const & name):Card(name)
{
}

PokemonCard::PokemonCard(
							std::string const & name,
							std::string const & type,
							std::string const & famiy,
							int evalutionLevel,    
							int maxHP,
							int atk1Current,
							std::string const & atk1Name,
							int atk1Damage,
							int atk2Current,
							std::string const & atk2Name,    
							int atk2Damage                    
						):Card(name)
{
	m_pokemonType.assign(type);
	m_familyName.assign(famiy);
	m_evolutionLevel=evalutionLevel;
	m_maxHP = maxHP;
}


/*

PokemonCard::PokemonCard(const string& _cardName,const string& _pokemonType,const string& _familyName,
	int _evolutionLevel, int _maxHP, int _hp, vector<tuple<int, int, string, int>>& _attacks) :
	Card(_cardName),
	pokemonType(_pokemonType),
	familyName(_familyName),
	evolutionLevel(_evolutionLevel),
	maxHP(_maxHP),
	hp(_hp),
	attacks(_attacks)
{

}
*/

PokemonCard::~PokemonCard(void)
{
}


void PokemonCard::displayInfo(void) const
{
	cout << "Card Name :" << m_cardName<< endl << "Pokemon Type : " << m_pokemonType << endl
		 << "Family Name : " << m_familyName << endl << "Evolution Level : " << m_evolutionLevel << endl
		 << "max HP : " <<m_maxHP<<endl<<"hp : "<< m_hp<< endl;
	cout << "Attacks :" << endl;
	/*for (const auto& tuple : attacks) {
		// Access tuple elements using get<index>(tuple)
		cout << "energy " << ": " << get<0>(tuple) << ", " << get<1>(tuple) << ", " << get<2>(tuple) << ", " << get<3>(tuple) << endl;
	}*/
}
/*
string PokemonCard::getPokemonType() const {
	return pokemonType;
}

string PokemonCard::getfamilyName() const {
	return familyName;
}

int PokemonCard::getEvolutionLevel() const {
	return evolutionLevel;
}

int PokemonCard::getMaxHP() const {
	return maxHP;
}

int PokemonCard::getHP() const {
	return hp;
}

void PokemonCard::setHP(int _hp) {
	hp = _hp;
}

vector<tuple<int, int, string, int>> PokemonCard::getAttacks() const {
	return attacks;
}

*/