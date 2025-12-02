// TP1.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"

#include "Player.h"
#include "EnergyCard.h"
#include "TrainerCard.h"
#include "PokemonCard.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Player player1("Habi");

	player1.addCardToBench(new EnergyCard("Electric"));
	player1.addCardToBench(new EnergyCard("Electric"));
	player1.addCardToBench(new TrainerCard("Ash","heal all your action pokemon"));
    player1.addCardToBench(new PokemonCard("Pikachu","Electric","Pikachu",2, 100,2,"thunder bolt",20,3,"thunder bolt",30));


	

	return 0;
}

