//Les normes classiques C++ ( c'est MAJUSCULE et espace _ ) 
//cela sert pour La première fois que le compilateur rencontre ce fichier qui soit defini , si retrouve autre header sera pris déja defini
#ifndef CARD_H
#define CARD_H

#include <iostream>
#include<string>
using namespace std;


class Card 
{
private:
	string cardName;

public :
	Card(const string&);
	virtual ~Card() = default;

	
	string getCardName() const;

	// Methode virtuelle pure C.A.D ( //= 0 pour dire méthode virtuelle pure
	// Methode sans parametre on écrit (void) , mais implictement si rien c'est comme avait mis void  ()
	
	//Methode 'const' fait que cela promet de ne rien changer dans l'objet donc les attributs de la classe Card
	virtual void displayInfo(void) const = 0;   // rend la classe polymorphe important pour les opération de Dynamic_Cast 
	//DEF: Une classe est polymorphe dès qu’elle a au moins une méthode virtuelle
};

#endif