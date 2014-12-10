#ifndef PLAGUE_H_
#define PLAGUE_H_

#include "../Card.h"

class Plague : public Card {
public:
	Plague(Renderer* renderer, Texture* tex);
	bool play(Player* owner, Player* opponent);
	void getCost(int *health, int *energy, int *science);
	bool isName(const char* name);
};

#endif