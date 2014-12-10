#include "HireScientist.h"
#include "../Player.h"

HireScientist::HireScientist(Renderer* renderer, Texture* tex) : Card(renderer, tex){
}

bool HireScientist::play(Player* owner, Player* opponent){
	if(!substract(owner)){
		return false;
	}
	owner->setScientists(owner->getScientists() + 1);
	return true;
}


void HireScientist::getCost(int *health, int *energy, int *science){
	*health = 1;
	*energy = 1;
	*science = 2;
}

bool HireScientist::isName(const char* name){
	return strcmp(name, "HireScientist") == 0;
}