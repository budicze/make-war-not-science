#ifndef MAKE_WAR_H_
#define MAKE_WAR_H_

#include "../Card.h"

class MakeWar : public Card {
public:
	MakeWar(Renderer* renderer, Texture* tex);
	bool play(Player* owner, Player* opponent);
	void getCost(int *health, int *energy, int *science);
	bool isName(const char* name);
};

#endif