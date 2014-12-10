#include "ShieldBlast.h"
#include "../Player.h"

ShieldBlast::ShieldBlast(Renderer* renderer, Texture* tex) : Card(renderer, tex){
}

bool ShieldBlast::play(Player* owner, Player* opponent){
	if(!substract(owner)){
		return false;
	}

	opponent->dealDamage(owner->getEnergy());
	owner->setEnergy(0);
	
	return true;
}


void ShieldBlast::getCost(int *health, int *energy, int *science){
	*health = 0;
	*energy = 0;
	*science = 4;
}

bool ShieldBlast::isName(const char* name){
	return strcmp(name, "ShieldBlast") == 0;
}