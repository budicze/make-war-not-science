#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <list>

#include "Renderer.h"
#include "Texture.h"

using std::list;

class Card;

class Player {
private:
	void createDeck();
	void renderCard(Card *c, int n);
protected:
	int health, science, energy;
	int scientists, generators;
	list<Card*> cards;
	list<Card*> deck;
	Player *opponent;
	static const int MAX_CARDS = 9;
	Texture* texButton;
	Renderer *renderer;
	int pNumber;
	Texture* texName;
public:
	Player(Renderer *renderer_, int pNumber_);
	~Player();
	void playCard(Card *card);
	list<Card*> *getCards(){
		return &cards;
	}
	void setOpponent(Player *opponent);
	void drawCards(int n);
	bool isAlive(){
		return health > 0;
	}
	virtual bool turn(Renderer &renderer){return true;}
	void render(bool onTurn);
	void startTurn();

	void dealDamage(int a);
	void addCard(Card *c);

	int getHealth(){return health;}
	int getScience(){return science;}
	int getEnergy(){return energy;}
	int getScientists(){return scientists;}
	int getGenerators(){return generators;}

	void setHealth(int a){health = a;}
	void setScience(int a){science = a;}
	void setEnergy(int a){energy = a;}
	void setScientists(int a){scientists = a;}
	void setGenerators(int a){generators = a;}
};

#endif
