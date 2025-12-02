#ifndef TRAINERCARD_H
#define TRAINERCARD_H


#include<string>
//#include<vector>
//#include<tuple>
#include "Card.h"
//#include "PokemonCard.h"
using namespace std;

/*
class TrainerCard : public Card 
{

public:
	
	TrainerCard(const string&, const string&);
	 ~TrainerCard() ;//= default;

	//void displayInfo() ;//override;
//	void displayInfo(void) const;
	void displayInfo();// override;

	string GetTrainerEffect();
	// si je mets pas pokemon il met une erreur
//	void heal(vector<PokemonCard*> pokemon);

private:
	std::string m_trainerEffect;

};
*/



class TrainerCard : public Card 
{


public:
	
	TrainerCard(const string& trainer, const string& trainerEffect);
	~TrainerCard();// = default;

//	void displayInfo()const;// override;
	void displayInfo(void) const;
	string getTrainerEffect() const;

private:
	string m_trainerEffect;

};
#endif