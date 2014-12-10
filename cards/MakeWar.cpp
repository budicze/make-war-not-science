#include "MakeWar.h"
#include "../Player.h"

MakeWar::MakeWar(Renderer* renderer, Texture* tex) : Card(renderer, tex){
}

bool MakeWar::play(Player* owner, Player* opponent){
	if(!substract(owner)){
		return false;
	}

	opponent->dealDamage(owner->getScientists());
	
	return true;
}


void MakeWar::getCost(int *health, int *energy, int *science){
	*health = 1;
	*energy = 0;
	*science = 1;
}

bool MakeWar::isName(const char* name){
	return strcmp(name, "MakeWar") == 0;
}