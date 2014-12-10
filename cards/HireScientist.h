#ifndef HIRE_SCIENTIST_H_
#define HIRE_SCIENTIST_H_

#include "../Card.h"

class HireScientist : public Card {
public:
	HireScientist(Renderer* renderer, Texture* tex);
	bool play(Player* owner, Player* opponent);
	void getCost(int *health, int *energy, int *science);
	bool isName(const char* name);
};

#endif