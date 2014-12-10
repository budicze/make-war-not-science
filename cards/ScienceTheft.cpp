#include <algorithm>

#include "ScienceTheft.h"
#include "../Player.h"

ScienceTheft::ScienceTheft(Renderer* renderer, Texture* tex) : Card(renderer, tex){
}

bool ScienceTheft::play(Player* owner, Player* opponent){
	if(!substract(owner)){
		return false;
	}

	int stolenScience = std::min(opponent->getScience(), 6);
	owner->setScience(owner->getScience() + stolenScience);
	opponent->setScience(opponent->getScience() - stolenScience);

	return true;
}


void ScienceTheft::getCost(int *health, int *energy, int *science){
	*health = 0;
	*energy = 3;
	*science = 2;
}

bool ScienceTheft::isName(const char* name){
	return strcmp(name, "ScienceTheft") == 0;
}