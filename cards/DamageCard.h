#ifndef DAMAGE_CARD_H_
#define DAMAGE_CARD_H_

#include "../Card.h"

class DamageCard : public Card {
private:
	int science, damage;
public:
	DamageCard(Renderer* renderer, Texture* tex, int science, int damage);
	bool play(Player* owner, Player* opponent);
	void getCost(int *health, int *energy, int *science_);
	bool isName(const char* name);
};

#endif