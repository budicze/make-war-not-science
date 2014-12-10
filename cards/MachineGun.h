#ifndef MACHINE_GUN_H_
#define MACHINE_GUN_H_

#include "../Card.h"

class MachineGun : public Card {
public:
	MachineGun(Renderer* renderer, Texture* tex);
	bool play(Player* owner, Player* opponent);
	void getCost(int *health, int *energy, int *science);
	bool isName(const char* name);
};

#endif