#include "Plague.h"
#include "../Player.h"

Plague::Plague(Renderer* renderer, Texture* tex) : Card(renderer, tex){
}

bool Plague::play(Player* owner, Player* opponent){
	if(!substract(owner)){
		return false;
	}
	owner->dealDamage(5);
	opponent->dealDamage(5);
	return true;
}


void Plague::getCost(int *health, int *energy, int *science){
	*health = 0;
	*energy = 0;
	*science = 2;
}

bool Plague::isName(const char* name){
	return strcmp(name, "Plague") == 0;
}