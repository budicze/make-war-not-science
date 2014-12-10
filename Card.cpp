#include "Card.h"
#include "Player.h"

Card::Card(Renderer* renderer_, Texture* tex){
	renderer = renderer_;
	texture = tex;
}

Card::~Card(){
	delete texture;
}

double Card::getRenderW(){
	return renderer->getWidth() * (1.0 / 10);
}

double Card::getRenderH(){
	return getRenderW() / texture->getWidth() * texture->getHeight();
}

void Card::renderCenter(){
	texture->render(renderer->getWidth() / 2 - texture->getWidth() / 2,renderer->getHeight() / 2 - texture->getHeight() / 2);
	renderer->update();
}
void Card::render(int n, bool usable){
	double x = renderer->getWidth() * (0.11 * n + 0.01);
	double h = getRenderH();
	double y = renderer->getHeight() - 20 - h;
	double w = getRenderW();
	if(usable){
		texture->render(int(x), int(y), int(w), int(h));
	}	
	else {
		texture->renderShaded(int(x), int(y), int(w), int(h), 128, 128, 128);
	}

}
bool Card::substract(Player *target){
	int health, energy, science;
	getCost(&health, &energy, &science);
	if(target->getHealth() < health || target->getEnergy() < energy || target->getScience() < science){
		return false;
	}

	target->setHealth(target->getHealth() - health);
	target->setEnergy(target->getEnergy() - energy);
	target->setScience(target->getScience() - science);

	return true;
}