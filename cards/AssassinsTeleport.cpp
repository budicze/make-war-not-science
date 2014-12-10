#include "AssassinsTeleport.h"
#include "../Player.h"

AssassinsTeleport::AssassinsTeleport(Renderer* renderer, Texture* tex) : Card(renderer, tex){
}

bool AssassinsTeleport::play(Player* owner, Player* opponent){
	if(!substract(owner)){
		return false;
	}
	opponent->setHealth(opponent->getHealth() - 5);
	return true;
}


void AssassinsTeleport::getCost(int *health, int *energy, int *science){
	*health = 0;
	*energy = 2;
	*science = 4;
}

bool AssassinsTeleport::isName(const char* name){
	return strcmp(name, "AssassinsTeleport") == 0;
}