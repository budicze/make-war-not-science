#include "Technocracy.h"
#include "../Player.h"

Technocracy::Technocracy(Renderer* renderer, Texture* tex) : Card(renderer, tex){
}

bool Technocracy::play(Player* owner, Player* opponent){
	if(!substract(owner)){
		return false;
	}
	owner->setScience(owner->getScience() * 2);
	return true;
}


void Technocracy::getCost(int *health, int *energy, int *science){
	*health = 8;
	*energy = 0;
	*science = 0;
}

bool Technocracy::isName(const char* name){
	return strcmp(name, "Technocracy") == 0;
}