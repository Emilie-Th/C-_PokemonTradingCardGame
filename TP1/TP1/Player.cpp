#include "Player.h"
#include "EnergyCard.h"
#include "TrainerCard.h"
#include "Card.h"
#include <vector>

Player::Player(const string& name, const vector<Card*> benchCards, const vector<PokemonCard*> actionsCard):
	m_playerName(name),
	m_benchCards(benchCards),
	m_actionsCards(actionsCard)
{
	
}

Player::Player(const string& name) :
	m_playerName(name),
	m_benchCards(),
	m_actionsCards()
{

}

string Player::getPlayerName() const 
{
	return m_playerName;
}

// Les methodes pour les parametre d'une methode prefere avoir le nom  p ( pointer ) Obj ( Obj C++ ) et nom de la Classe ( Card )
void Player::addCardToBench(Card* pObjCard)
{
	m_benchCards.push_back(pObjCard);
	// trop complique car doit gére ou on insert > m_benchCards.insert(m_benchCards.end(), pObjCard);

}



// Si on peu méthode nommé clairement les paramètres de la méthode ici int idxPokemonCardOfBench  
// Cela aide dans la lecture de la méthode sur l(+'utilisation ou pour qui la sollicitation sera impacter donc le membre "Bench" le sac de carte dispo
void Player::activatePokemonCard(int idxPokemonCardOfBench)
{
	// on voit que l'on doit afficher "Hadi is activating a Pokemon Card: Pickachu" dans la sortie console  Output dans le TP

	// m_benchCards[idxPokemonCardOfBench]
	//BAD => pour un vector [] ne fait aucune vérification SAUF si pense en Tableau donc gére soit même le contrôle des bornes
	//       Exemple avant if (idxPokemonCardOfBench < 0 || idxPokemonCardOfBench >= m_benchCards.size()) return;
	//PokemonCard* pPokemonCardSelected = dynamic_cast<PokemonCard*>(m_benchCards[idxPokemonCardOfBench]);

	// MIEUX pour éviter de faire cela à la main le controle des bornes
	// .at() fait déjà la sécurité des bornes.Si index est hors limites → exception out_of_range et NULL sera la pPokemonCardSelected
	//Card* pCardSelected =  (m_benchCards.at(idx));


	PokemonCard* pPokemonCardSelected = dynamic_cast<PokemonCard*>(m_benchCards.at(idxPokemonCardOfBench));

	/* COMPRENDRE LE FONCTIONNEMENT dynamic_cast
		dynamic_cast ne fonctionne que si la classe de base possède au moins une méthode virtuelle pour remonté réel objet accendant
		qui peut etre dans le cas cité "EnergyCard" "TrainerCard" "PockemonCard"
		sinon dynamic_cast retourne undefined(ou toujours NULL), car l’objet n’a pas d’informations RTTI ( (RunTime Type Information)
		 => ces informations ne sont générées que si la classe est polymorphe.
			DEF: Une classe est polymorphe dès qu’elle a au moins une méthode virtuelle : notre cas dans la classe Card
				car virtual void displayInfo() const = 0; // rend la classe polymorphe  si pas la => dynamic_cast ne marcherait pas
	*/

	if (pPokemonCardSelected!=NULL)
	{
		m_actionsCards.push_back(pPokemonCardSelected);

		cout << m_playerName
			 << " is activating a Pokemon Card: "
			 << pPokemonCardSelected->getCardName()
			 << endl;

		// même souci avez en  trop une ligne dans la sortie console Output
		/*

		Habi is activating a Pokemon Card: Pikachu
		Habi is attaching Energy Card of type Electric to the Pokemon Pikachu
		Habi is attaching Energy Card of type Electric to the Pokemon Pikachu

		Bench cards for Player Habi:
		Trainer Card - Name: Ash, Effect: heal all your action pokemon
		BAD >>>>>>>>>>Pokemon Card - Name: Pikachu, Type: Electric

		   donc activer la carte pokemon faut soit plus dans bench comme mon souci avec affichage l'autre
		*/

		// faut aussi la retirer cette carte du bench
		m_benchCards.erase(m_benchCards.begin() + idxPokemonCardOfBench);
	}
}



void Player::attachEnergyCard(int idxOfBench, int idxOfPokemon) 
{
	EnergyCard* pEnergyCardSelected = dynamic_cast<EnergyCard*>(m_benchCards[idxOfBench]);
	PokemonCard* pPokemonCardSelected = dynamic_cast<PokemonCard*>(m_actionsCards[idxOfPokemon]);

	if ((pEnergyCardSelected != NULL) && (pPokemonCardSelected != NULL))
	{
		// on alloue de l'energie à la carte en plus de celle qu'elle  dispose 
		pPokemonCardSelected->allocateEnergyOfEnergyCard(*pEnergyCardSelected);

		std::cout << m_playerName
			<< " is attaching Energy Card of type "
			<< pEnergyCardSelected->getEnergyType()
			<< " to the Pokemon "
			<< pPokemonCardSelected->getCardName()
			<< std::endl;

		/*
		player1.addCardToBench(new EnergyCart("Electric"));
		player1.addCardToBench(new EnergyCart("Electric"));
		player1.addCardToBench(new TrainerCard("Ash","heal all your action pokemon"));
		player1.addCardToBench(new PokemonCard("Pikachu","Electric","Pikachu", 2 , 100, 2,"thunder bolt",20 ,3 "thunder bolt",30));
		player1.activatePokemonCard(3);
		Player1.attachEnergyCard(0,0);
		Player1.attachEnergyCard(0,0);
		player1.displayBench();

		la sortie Console est
		Habi is activating a Pokemon Card: Pikachu Habi is attaching Energy Card of type Electric to the Pokemon Pikachu
		Habi is attaching Energy Card of type Electric to the Pokemon Pikachu
		Habi is attaching Energy Card of type Electric to the Pokemon Pikachu
		Bench cards for Player
		Habi: Trainer Card - Name: Ash, Effect: heal allyour action pokemon"
		   donc veut dire doit retirer des attache de energie via attachEnergyCard a chque fois que attaché appelé

		   ==> écrase l'ellement du vector de la classe corepsondant à  bench Cards

		*/

		// retirer la carte du bench
		m_benchCards.erase(m_benchCards.begin() + idxOfBench);
	}
}

vector<Card*> Player::getBenchCards() const
{
	return m_benchCards;
}

vector<PokemonCard*> Player::getActionsCards() const 
{
	return m_actionsCards;
}

void Player::displayBench(void)
{
	/*
	Bench cards for Player Habi:
	Trainer Card : Ash, Effect: heal all your action pokemon
	*/

	std::cout << "Bench cards for Player " << m_playerName << ":" << std::endl;

	// Puis liste toutes les carte disponible encore dans mon vector m_benchCards 
	// Attention que je tombe pas dans le piége ou j'ai eu souci avec Card* pour avoir le vrai objet a cause du polymorphe
	// 
	for (size_t i = 0; i < m_benchCards.size(); ++i)
	{
		Card* pObjCard = m_benchCards.at(i);

		// Je sais pas qu'elle type de de carte réel qui correspond card  cela peut etre "TrainerCard" ou "PokemonCard" ou "EnergyCard"
        // Mais j'ai utilisé dynamic_cast il va me donner NULL si pas celui attendu  => celui qui pas null sera le bon type 

		EnergyCard* pEnergyCardIs = dynamic_cast<EnergyCard*>(pObjCard);
		PokemonCard* pPokemonCardIs= dynamic_cast<PokemonCard*>(pObjCard);
		TrainerCard* pTrainerCardCardIs = dynamic_cast<TrainerCard*>(pObjCard);

		// On peut utiliser dynamic_cast fait avoir bon et donc utiliser , afficher les infos spécifiques utiliser métohde displayInfo
		if (pEnergyCardIs!=NULL)
		{
			std::cout << "Energy Card - Type: "
				<< pEnergyCardIs->getEnergyType()
				<< std::endl;
		}

		if (pPokemonCardIs != NULL)
		{
			std::cout << "Pokemon Card - Name: "
				<< pPokemonCardIs->getCardName()
				<< ", Type: " << pPokemonCardIs->getPokemonType()
				<< std::endl;
		}

		if (pTrainerCardCardIs != NULL)
		{
			std::cout << "Trainer Card - Name: "
				<< pTrainerCardCardIs->getCardName()
				<< ", Effect: " << pTrainerCardCardIs->getTrainerEffect()
				<< std::endl;
		}


	}

}

void Player::displayAction(void)
{
	/*
	Action cards for Player Hadi:
	Pokemon Card - Name: Pikachu, ....
	*/

	std::cout << "Action cards for Player " << m_playerName << ":" << std::endl;

	// Puis liste toutes les carte disponible encore dans mon vector m_ActionCards 
	 
	for (size_t i = 0; i < m_actionsCards.size(); ++i)
	{
		PokemonCard* pObjPokemonCard = m_actionsCards.at(i);
		pObjPokemonCard->displayInfo();
	}
}

PokemonCard* Player::GetPokemonOfActionsCardsForIndexNo(int idx)
{
	PokemonCard* pObjPokemonCard = NULL;

	if (idx < m_actionsCards.size()) pObjPokemonCard = m_actionsCards.at(idx);

	return pObjPokemonCard;
}

void Player::attack(int iPokemonAttaquant, int iPokemonDefence, Player& Target, int iUseAttack)
{
	/*
	Only 2 attacks exist.
	Hadi attacking Germain's Pokemon BUlbassaur with th Pokemon Pikachu with its attack: thunder bold
	Reducing 20 from Germain's Pokemon's HP
	Pokemon Bulbasaur is still alice
	*/

	PokemonCard* pObjPokemonCard = NULL;

	if(iPokemonAttaquant < m_actionsCards.size()) pObjPokemonCard = m_actionsCards.at(iPokemonAttaquant);

	if (pObjPokemonCard != NULL)
	{
		cout << "Only " << pObjPokemonCard->getNumberAttack() << " attacks exist." << endl;

		cout << m_playerName
			<< " attacking "
			<< Target.getPlayerName()
			<< "'s Pokemon ";

		PokemonCard* pObjPokemonDefence =  Target.GetPokemonOfActionsCardsForIndexNo(iPokemonDefence);

		if (pObjPokemonDefence != NULL)
		{
			cout << pObjPokemonDefence->getCardName();
		}
		else
		{
			cout << "NULL";
		}

		cout << "with the Pokemon " << pObjPokemonCard->getCardName() << " with its attack: ";
		std::tuple<int, int, std::string, int> attackSelected;
		attackSelected = pObjPokemonCard->GetAttackNo(iUseAttack);

		cout << std::get<2>(attackSelected);

		cout << endl;
		cout << "Reducing ";

		cout << std::get<3>(attackSelected);  // C'est le domage infliger

		cout << " from " << Target.getPlayerName() << "'s Pokemon's HP" << endl;
		cout << "Pokemon ";
		cout << pObjPokemonDefence->getCardName();

		// Le Pokemon Bulbizarre est toujours en vie donc cela veut dire controle lié au domage 
		// la botl attaque est 20   donc Butbizarre vie de 100  => 100 -20 = 80

		int iNewHP = pObjPokemonDefence->getHP() - std::get<3>(attackSelected);
		pObjPokemonDefence->setHP(iNewHP);
		
		if (iNewHP > 0)
		{
			cout << " is still alive";
		}
		else
		{
			cout << " is still dead";
		}

		cout << endl;

		//Target.displayAction();
		
	}

	


}

void Player::useTrainer(int idxTrainerCardOfBench)
{
	std::cout << m_playerName << " is using the Trainer Card to \""   ;

	TrainerCard* pTrainerCardCardFinding=NULL;

	int idxCurrent = 0;
	for (size_t i = 0; i < m_benchCards.size(); ++i)
	{
		Card* pObjCard = m_benchCards.at(i);
		TrainerCard*  pTrainerCardCardIs = dynamic_cast<TrainerCard*>(pObjCard);

		if (pTrainerCardCardIs != NULL)
		{
			if (idxTrainerCardOfBench == idxCurrent)
			{
				pTrainerCardCardFinding = pTrainerCardCardIs;
				break;
			}
			idxCurrent++;
		}
	}

	if (pTrainerCardCardFinding != NULL)
	{
		cout << pTrainerCardCardFinding->getTrainerEffect();

		//pTrainerCardCardFinding->heal()

		for (size_t i = 0; i < m_actionsCards.size(); ++i)
		{
			PokemonCard* pObjPokemonCard = m_actionsCards.at(i);
			//pObjPokemonCard->displayInfo();

			int iMax = pObjPokemonCard->getMaxHP();
			pObjPokemonCard->setHP(iMax);
		}

	}

	cout << "\"" << endl << endl;

	
}