#ifndef AI_H_
#define AI_H_

#include "Player.h"

class AI : public Player {
public:
	AI(Renderer* renderer, int pNumber);
	bool turn(Renderer &renderer);
	Card* findCardInHand(const char* name);
	bool canPlayCard(const char* name);
	void playCardAI(const char* name);
};

#endif