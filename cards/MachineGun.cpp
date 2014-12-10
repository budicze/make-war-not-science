#include "MachineGun.h"
#include "../Player.h"

MachineGun::MachineGun(Renderer* renderer, Texture* tex) : Card(renderer, tex){
}

bool MachineGun::play(Player* owner, Player* opponent){
	if(!substract(owner)){
		return false;
	}
	opponent->dealDamage(1);
	return false;
}


void MachineGun::getCost(int *health, int *energy, int *science){
	*health = 0;
	*energy = 0;
	*science = 1;
}

bool MachineGun::isName(const char* name){
	return strcmp(name, "MachineGun") == 0;
}