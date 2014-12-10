#ifndef PROJECT_OMEGA_H_
#define PROJECT_OMEGA_H_

#include "../Card.h"

class ProjectOmega : public Card {
public:
	ProjectOmega(Renderer* renderer, Texture* tex);
	bool play(Player* owner, Player* opponent);
	void getCost(int *health, int *energy, int *science);
	bool isName(const char* name);
};

#endif