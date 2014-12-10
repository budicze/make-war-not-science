#include <iostream>

#include "AI.h"
#include "InputHandler.h"
#include "Card.h"

AI::AI(Renderer* renderer, int pNumber) : Player(renderer, pNumber){
	
}

Card* AI::findCardInHand(const char* name){
	for(auto it = cards.begin(); it != cards.end(); ++it){
		if((*it)->isName(name)){
			return *it;
		}
	}

	return NULL;
}

bool AI::canPlayCard(const char* name){
	Card* c = findCardInHand(name);
	if(c == NULL){
		return false;
	}

	int h, e, s;

	c->getCost(&h, &e, &s);
	if(h > health || e > energy || s > science){
		return false;
	}

	return true;
}

void AI::playCardAI(const char* name){
	Card *c = findCardInHand(name);
	if(c == NULL){
		return;
	}
	playCard(c);
}

bool AI::turn(Renderer& renderer){
	bool cont = true;
	do{
		if(health > 11 && science > 4 && canPlayCard("Technocracy")){
			playCardAI("Technocracy");
			continue;
		}
		if(cards.size() < 5 && canPlayCard("Briefing")){
			playCardAI("Briefing");
			continue;
		}
		if(canPlayCard("ProjectOmega")){
			playCardAI("ProjectOmega");
			continue;
		}
		if(canPlayCard("HireScientist")){
			playCardAI("HireScientist");
			continue;
		}
		if(canPlayCard("PowerPlant")){
			playCardAI("PowerPlant");
			continue;
		}
		if(scientists > 2 && canPlayCard("MakeWar")){
			playCardAI("MakeWar");
			continue;
		}
		if(energy > 4 && canPlayCard("ShieldBlast")){
			playCardAI("ShieldBlast");
			continue;
		}
		if(canPlayCard("AssassinsTeleport")){
			playCardAI("AssassinsTeleport");
			continue;
		}
		if(opponent->getScience() > 4 && canPlayCard("ScienceTheft")){
			playCardAI("ScienceTheft");
			continue;
		}
		if((health > 15 || energy > 4) && canPlayCard("Plague")){
			playCardAI("Plague");
			continue;
		}
		if(canPlayCard("DamageCard1")){
			playCardAI("DamageCard1");
			continue;
		}
		if(canPlayCard("DamageCard2")){
			playCardAI("DamageCard2");
			continue;
		}
		if(canPlayCard("DamageCard4")){
			playCardAI("DamageCard4");
			continue;
		}
		if(canPlayCard("MachineGun")){
			playCardAI("MachineGun");
			continue;
		}

		cont = false;
	} while(cont);
	return true;
}