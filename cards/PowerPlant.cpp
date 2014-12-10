#include "PowerPlant.h"
#include "../Player.h"

PowerPlant::PowerPlant(Renderer* renderer, Texture* tex) : Card(renderer, tex){
}

bool PowerPlant::play(Player* owner, Player* opponent){
	if(!substract(owner)){
		return false;
	}
	owner->setGenerators(owner->getGenerators() + 1);
	return true;
}


void PowerPlant::getCost(int *health, int *energy, int *science){
	*health = 1;
	*energy = 1;
	*science = 2;
}

bool PowerPlant::isName(const char* name){
	return strcmp(name, "PowerPlant") == 0;
}