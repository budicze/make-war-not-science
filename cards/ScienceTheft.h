#ifndef SCIENCE_THEFT_H_
#define SCIENCE_THEFT_H_

#include "../Card.h"

class ScienceTheft : public Card {
public:
	ScienceTheft(Renderer* renderer, Texture* tex);
	bool play(Player* owner, Player* opponent);
	void getCost(int *health, int *energy, int *science);
	bool isName(const char* name);
};

#endif