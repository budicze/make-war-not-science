#ifndef TECHNOCRACY_H_
#define TECHNOCRACY_H_

#include "../Card.h"

class Technocracy : public Card {
public:
	Technocracy(Renderer* renderer, Texture* tex);
	bool play(Player* owner, Player* opponent);
	void getCost(int *health, int *energy, int *science);
	bool isName(const char* name);
};

#endif