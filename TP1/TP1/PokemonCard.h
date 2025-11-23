//Les normes classiques C++ ( c'est MAJUSCULE et espace par _ ) 
//cela sert pour La première fois que le compilateur rencontre ce fichier qui soit defini , si retrouve autre header sera pris déja defini
#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include <iostream>
#include<string>
#include<vector>
#include<tuple>
#include "Card.h"
#include "EnergyCard.h"
using namespace std;


class PokemonCard : public Card {
private:
	string pokemonType;
	string familyName;
	int evolutionLevel;
	int m_maxHP;
	int hp;
	            //atkCost atkCostCurrent atkDescriptionName atkDamage
	vector<tuple<int, int, string, int>> attacks;



public:
	PokemonCard(std::string const& name);
//	PokemonCard(const string&,const string&,const string&, int, int, int, vector<tuple<int, int, string, int>>&);

	// Dans le main du TP  je vois un exemple 
	/* du constructeur de pokemon donnée cela resemble dire atkCostCurrent est valeur interne de l affichage
		player1.addCardToBench(
		  =>> new PokemonCard("Pikachu", "Electric", "Pikachu", 2, 100, 2, "thunder bolt", 20, 3 "thunder bolt", 30));

	Le nom de Pokemon String
		le pokemoType     String
		familyName        String
		evalutionLevel    int
		maxHP             int
		*/


	PokemonCard(
		std::string const& name,
		std::string const& type,
		std::string const& famiy,
		int evalutionLevel,
		int maxHP,             // comme construction découle hp(maxHP) on juste précisé maxHP 
	
		int atk1cost,
		std::string const& atk1Name,
		int atk1Damage,
		
		int atk2cost,
		std::string const& atk2Name,
		int atk2Damage
	);

	virtual ~PokemonCard() = default;

	void displayInfo(void) const override;

	void allocateEnergyOfEnergyCard(EnergyCard& energy);

	int getNumberAttack() const { return 2; }

	tuple<int, int, string, int> GetAttackNo(int idx);


	string getPokemonType() const;
	string getfamilyName() const;
	int getEvolutionLevel() const;
	int getMaxHP() const;
	int getHP() const;
	void setHP(int);
/*
	int atkCost,// Coût en énergie ( entier )
		>> INTERNE int atkCostCurrent,// Coût en énergie actuel ( entier )
		std::string& atkDescriptionName, // Description de l'attaque ( chaîne de caracttères)
		int atk1Damage // Dégâts de l'attaque ( entier)
		*/
	           

	int m_energyAllocatedCurrent; //Energie actuellement alloue disponible
	// Pour pouvoir voir la liasion entre les carte attaché d'énergie et le pokemon
	// Idée >avoir std::vector<EnergyCard*> m_PokemonAttachedEnergyCard; // pour modeliser les carte énergies attachées à mon pokemom 

	//vector<tuple<int, int, string, int>> attacks;

};

#endif