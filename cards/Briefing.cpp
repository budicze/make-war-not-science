#include "Briefing.h"
#include "../Player.h"

Briefing::Briefing(Renderer* renderer, Texture* tex) : Card(renderer, tex){
}

bool Briefing::play(Player* owner, Player* opponent){
	if(!substract(owner)){
		return false;
	}
	owner->drawCards(2);
	return true;
}


void Briefing::getCost(int *health, int *energy, int *science){
	*health = 0;
	*energy = 2;
	*science = 2;
}

bool Briefing::isName(const char* name){
	return strcmp(name, "Briefing") == 0;
}