#include "DamageCard.h"
#include "../Player.h"

DamageCard::DamageCard(Renderer* renderer, Texture* tex, int science_, int damage_) : Card(renderer, tex){
	science = science_;
	damage = damage_;
}

bool DamageCard::play(Player* owner, Player* opponent){
	if(!substract(owner)){
		return false;
	}
	opponent->dealDamage(damage);
	return true;
}

void DamageCard::getCost(int *health, int *energy, int *science_){
	*health = 0;
	*energy = 0;
	*science_ = science;
}

bool DamageCard::isName(const char* name){
	using namespace std;
	string str;
	str = "DamageCard" + to_string(damage);
	return strcmp(name, str.c_str()) == 0;
}