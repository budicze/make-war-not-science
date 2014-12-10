#ifndef BRIEFING_H_
#define BRIEFING_H_

#include "../Card.h"

class Briefing : public Card {
public:
	Briefing(Renderer* renderer, Texture* tex);
	bool play(Player* owner, Player* opponent);
	void getCost(int *health, int *energy, int *science);
	bool isName(const char* name);
};

#endif