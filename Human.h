#ifndef HUMAN_H_
#define HUMAN_H_

#include "Player.h"

class Human : public Player {
public:
	Human(Renderer* renderer, int pNumber);
	bool turn(Renderer &renderer);
};

#endif