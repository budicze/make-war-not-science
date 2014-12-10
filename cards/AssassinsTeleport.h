#ifndef ASSASSINS_TELEPORT_H_
#define ASSASSINS_TELEPORT_H_

#include "../Card.h"

class AssassinsTeleport : public Card {
public:
	AssassinsTeleport(Renderer* renderer, Texture* tex);
	bool play(Player* owner, Player* opponent);
	void getCost(int *health, int *energy, int *science);
	bool isName(const char* name);
};

#endif