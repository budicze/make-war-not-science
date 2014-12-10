#include "ProjectOmega.h"
#include "../Player.h"
#include "MachineGun.h"

ProjectOmega::ProjectOmega(Renderer* renderer, Texture* tex) : Card(renderer, tex){
}

bool ProjectOmega::play(Player* owner, Player* opponent){
	if(!substract(owner)){
		return false;
	}

	owner->addCard(new MachineGun(renderer, Texture::createFromFile("images/cards/MachineGun.png", *renderer)));

	return true;
}


void ProjectOmega::getCost(int *health, int *energy, int *science){
	*health = 2;
	*energy = 0;
	*science = 15;
}

bool ProjectOmega::isName(const char* name){
	return strcmp(name, "ProjectOmega") == 0;
}