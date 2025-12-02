//Les normes classiques C++ ( c'est MAJUSCULE et espace _ ) 
//cela sert pour La première fois que le compilateur rencontre ce fichier qui soit defini , si retrouve autre header sera pris déja defini
#ifndef POKEMONCARD_H
#define POKEMONCARD_H

//#include <iostream>
//#include<string>
//#include<vector>
//#include <tuple>
#include "Card.h"
using namespace std;

class Tuple {
public:
    int energyCost;
    int currentEnergy;
    std::string name;
    int damage;

    Tuple(int cost, int current, std::string const & n, int dmg): energyCost(cost), currentEnergy(current), name(n), damage(dmg) {}
};


class PokemonCard : public Card 
{

	/*
int atk1Cost,// Coût en énergie ( entier )
 int atk1CostCurrent,// Coût en énergie actuel ( entier )
 std::string const & atk1Name, // Description de l'attaque ( chaîne de caracttères)
int atk1Damage // Dégâts de l'attaque ( entier)

 int atk2Cost,// Coût en énergie ( entier )
 int atk2CostCurrent,// Coût en énergie actuel ( entier )
 std::string const & atk2Name, // Description de l'attaque ( chaîne de caracttères)
int atk2Damage // Dégâts de l'attaque ( entier)
*/
/*
Dans exemple du constructeur donnée cela resemble dire atkCostCurrent est valeur interne de l affichage 
player1.addCardToBench(new PokemonCard("Pikachu","Electric","Pikachu", 2 ,   100,      2,"thunder bolt",20   ,3 "thunder bolt",30));

Le nom de Pokemon String
le pokemoType     String
familyName        String
evalutionLevel    int
maxHP             int

int atk1Cost,// Coût en énergie ( entier )
			>>  INTERNE int atk1CostCurrent,// Coût en énergie actuel ( entier )
 std::string const & atk1Name, // Description de l'attaque ( chaîne de caracttères)
int atk1Damage // Dégâts de l'attaque ( entier)
*/


public:
	//void displayInfo();// override;
	void displayInfo(void) const;

	PokemonCard(std::string const & name);
	PokemonCard(
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
				);

	virtual ~PokemonCard();
/*
	string getPokemonType() const;
	string getfamilyName() const;
	int GetEvolutionLevel() const;
	int GetMaxHP() const;
	int GetHP() const;
	void SetHP(int);
	///vector<tuple<int, int, string, int>> getAttacks() const;
*/

private:
	std::string m_pokemonType;
	std::string m_familyName;
	int m_evolutionLevel;
	int m_maxHP;
	int m_hp;
	//vector<tuple<int, int, string, int>> attacks;

};

#endif