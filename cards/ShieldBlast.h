#ifndef SHIELD_BLAST_H_
#define SHIELD_BLAST_H_

#include "../Card.h"

class ShieldBlast : public Card {
public:
	ShieldBlast(Renderer* renderer, Texture* tex);
	bool play(Player* owner, Player* opponent);
	void getCost(int *health, int *energy, int *science);
	bool isName(const char* name);
};

#endif