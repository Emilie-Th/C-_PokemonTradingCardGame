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
	virtual ~Player() = default;

	// Les methodes pour les parametre d'une methode prefere avoir le nom  p ( pointer ) Obj ( Obj C++ ) et nom de la Classe ( Card )
	void addCardToBench(Card* pObjCard);

	void activatePokemonCard(int idxPokemonCardOfBench);
	void attachEnergyCard(int idxOfBench, int idxOfPokemon);
	void displayBench(void);
	void displayAction(void);

	// Avoir la methode 
	// vu dans le main du TP 
	//player1.attack(0,0,player2,0);
	void attack(int, int, Player& Target, int);

	PokemonCard* GetPokemonOfActionsCardsForIndexNo(int idx);

	void useTrainer(int);


	string getPlayerName() const;
	vector<Card*> getBenchCards() const;
	vector<PokemonCard*> getActionsCards() const;

/*
private:
	string playerName;
	vector<Card*> benchCards;
	vector<PokemonCard*> actionsCards;
*/
private:

	//- playerName nom du joueur  
	string m_playerName;

	//- benchcards(vector<Card*>) un vecteur de pointeurs vers des éléments Card, c'est le deck des cartes en réserve regle jeu 
	vector<Card*> m_benchCards;

	//- actionCards(vector<PokemonCard*>) un vecteur de pointeurs vers des éléments PokemonCard, c'est le deck des cartes d'action Pokémon.
	vector<PokemonCard*> m_actionsCards;  //C’est un vecteur ne contient que des Pokémon actifs.

};

#endif 
