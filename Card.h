#ifndef CARD_H_
#define CARD_H_

#include "Texture.h"
#include "Renderer.h"

class Player;

class Card {
private:
	Texture* texture;
protected:
	bool substract(Player *target);
	Renderer* renderer;
public:
	Card(Renderer* renderer, Texture* tex);
	virtual ~Card();
	virtual bool play(Player* owner, Player* opponent){return false;}
	virtual void getCost(int *health, int *energy, int *science){*health = *energy = *science = 0;}
	void render(int n, bool usable);
	void renderCenter();

	double getRenderW();
	double getRenderH();
	virtual bool isName(const char* name){return false;}
};

#endif