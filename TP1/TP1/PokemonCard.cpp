#include "PokemonCard.h"
#include<tuple>

PokemonCard::PokemonCard(std::string const& name) :Card(name)
{
	m_maxHP = 0;
	hp = m_maxHP;
	evolutionLevel = 1; //1 suffit pour le Pokémon de départ le plus bas 

	//m_energyAllocatedCurrent = 0; // pas energie
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

PokemonCard::PokemonCard(
	std::string const& name,
	std::string const& type,
	std::string const& family,
	int evalutionLevel,
	int maxHP,             // comme construction découle hp(maxHP) on juste précisé maxHP

	int atk1cost,
	std::string const& atk1Name,
	int atk1Damage,

	int atk2cost,
	std::string const& atk2Name,
	int atk2Damage

) :Card(name)
{
	pokemonType.assign(type);
	familyName.assign(family);
	evolutionLevel = evalutionLevel;
	m_maxHP = maxHP;
	hp = m_maxHP;  // quand crée il autant vie actuel qui le MAX fixé de vie 

	// il faut que l'on rempli le tuple d'attaque
		//atkCost atkCostCurrent atkDescriptionName atkDamage
	//vector<tuple<int, int, string, int>> attacks;

	std::tuple<int, int, std::string, int> attack1;
	std::get<0>(attack1) = atk1cost;
	std::get<1>(attack1) = 0;
	std::get<2>(attack1) = atk1Name;
	std::get<3>(attack1) = atk1Damage;

	std::tuple<int, int, std::string, int> attack2;
	std::get<0>(attack2) = atk2cost;
	std::get<1>(attack2) = 0;
	std::get<2>(attack2) = atk2Name;
	std::get<3>(attack2) = atk2Damage;

	attacks.push_back(attack1);
	attacks.push_back(attack2);

}

tuple<int, int, string, int> PokemonCard::GetAttackNo(int idx)
{
	return attacks.at(idx); // copie du tuple
}

void PokemonCard::displayInfo() const
{
	cout << "Pokemon Card - Name : "
		 << getCardName()
		<< "," 
		<< " Type: " 
		<< pokemonType 
		<<","
		<< "Evolution Level : " 
		<< evolutionLevel 
		<< " of the family \"" 
		<< getfamilyName()
		<< ","
		<<"HP: "
		<< hp 
		<< "\""
		<< endl;
	cout<<  "Attacks :" << endl;
	int i = 0;
	for (const auto& tuple : attacks)
	{

		cout << "Attack #" << i <<":" << endl;
		// Access tuple elements using get<index>(tuple)
		cout << "Attack cost: " << get<0>(tuple) << endl;
		cout << "Attack current energy storage: " << get<1>(tuple) << endl;
		cout << "Attack description: " << get<2>(tuple) << endl;
		cout << "Attack damage: " << get<3>(tuple) << endl;

		i++;
	}
}

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
	return m_maxHP;
}

int PokemonCard::getHP() const {
	return hp;
}

void PokemonCard::setHP(int _hp) {
	hp = _hp;
}
/*
vector<tuple<int, int, string, int>> PokemonCard::getAttacks() const {
	return attacks;
}
*/


void PokemonCard::allocateEnergyOfEnergyCard(EnergyCard& energy)
{
	m_energyAllocatedCurrent += energy.getEnergyValue();

	for (size_t i = 0; i < attacks.size(); ++i) {
		std::get<1>(attacks[i]) = m_energyAllocatedCurrent;
	}
}