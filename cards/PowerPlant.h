#ifndef POWER_PLANT_H_
#define POWER_PLANT_H_

#include "../Card.h"

class PowerPlant : public Card {
public:
	PowerPlant(Renderer* renderer, Texture* tex);
	bool play(Player* owner, Player* opponent);
	void getCost(int *health, int *energy, int *science);
	bool isName(const char* name);
};

#endif