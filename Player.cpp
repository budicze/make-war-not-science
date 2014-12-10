#include <algorithm>
#include <ctime>

#include "Player.h"
#include "cards/DamageCard.h"
#include "cards/AssassinsTeleport.h"
#include "cards/Plague.h"
#include "cards/ScienceTheft.h"
#include "cards/Technocracy.h"
#include "cards/HireScientist.h"
#include "cards/PowerPlant.h"
#include "cards/Briefing.h"
#include "cards/ProjectOmega.h"
#include "cards/ShieldBlast.h"
#include "cards/MakeWar.h"

bool sortRandom(const Card* first, const Card* second){
	return (rand() % 2) == 0;
}

Player::Player(Renderer *renderer_, int pNumber_){
	using namespace std;
	health = 30;
	science = 2;
	energy = 0;

	scientists = 0;
	generators = 0 ;

	opponent = NULL;
	renderer = renderer_;
	pNumber = pNumber_;

	string name = "Player #";
	name += to_string(pNumber);
	SDL_Color black = {0, 0, 0};
	texName = Texture::createFromText(name.c_str(), black, renderer->getFont(20), *renderer);
	texButton = Texture::createFromFile("images/button.png", *renderer);
	createDeck();

	drawCards(5);
}

Player::~Player(){
	delete texName;
}

void Player::createDeck(){
	using std::vector;
	deck.push_front(new DamageCard(renderer, Texture::createFromFile("images/cards/Gunshot.png", *renderer), 1, 1));
	deck.push_front(new DamageCard(renderer, Texture::createFromFile("images/cards/Gunshot.png", *renderer), 1, 1));
	deck.push_front(new DamageCard(renderer, Texture::createFromFile("images/cards/Gunshot.png", *renderer), 1, 1));
	deck.push_front(new DamageCard(renderer, Texture::createFromFile("images/cards/Gunshot.png", *renderer), 1, 1));
	deck.push_front(new DamageCard(renderer, Texture::createFromFile("images/cards/SMGshot.png", *renderer), 2, 2));
	deck.push_front(new DamageCard(renderer, Texture::createFromFile("images/cards/SMGshot.png", *renderer), 2, 2));
	deck.push_front(new DamageCard(renderer, Texture::createFromFile("images/cards/SMGshot.png", *renderer), 2, 2));
	deck.push_front(new DamageCard(renderer, Texture::createFromFile("images/cards/SMGshot.png", *renderer), 2, 2));

	deck.push_front(new DamageCard(renderer, Texture::createFromFile("images/cards/Lasershot.png", *renderer), 3, 4));
	deck.push_front(new DamageCard(renderer, Texture::createFromFile("images/cards/Lasershot.png", *renderer), 3, 4));
	deck.push_front(new AssassinsTeleport(renderer, Texture::createFromFile("images/cards/AssassinsTeleport.png", *renderer)));
	deck.push_front(new AssassinsTeleport(renderer, Texture::createFromFile("images/cards/AssassinsTeleport.png", *renderer)));
	//deck.push_front(new Plague(renderer, Texture::createFromFile("images/cards/Plague.png", *renderer)));
	deck.push_front(new Plague(renderer, Texture::createFromFile("images/cards/Plague.png", *renderer)));
	deck.push_front(new ScienceTheft(renderer, Texture::createFromFile("images/cards/ScienceTheft.png", *renderer)));
	deck.push_front(new ScienceTheft(renderer, Texture::createFromFile("images/cards/ScienceTheft.png", *renderer)));
	deck.push_front(new Technocracy(renderer, Texture::createFromFile("images/cards/Technocracy.png", *renderer)));
	deck.push_front(new Technocracy(renderer, Texture::createFromFile("images/cards/Technocracy.png", *renderer)));
	deck.push_front(new HireScientist(renderer, Texture::createFromFile("images/cards/HireScientist.png", *renderer)));
	deck.push_front(new HireScientist(renderer, Texture::createFromFile("images/cards/HireScientist.png", *renderer)));
	deck.push_front(new HireScientist(renderer, Texture::createFromFile("images/cards/HireScientist.png", *renderer)));
	deck.push_front(new HireScientist(renderer, Texture::createFromFile("images/cards/HireScientist.png", *renderer)));
	deck.push_front(new PowerPlant(renderer, Texture::createFromFile("images/cards/PowerPlant.png", *renderer)));
	deck.push_front(new PowerPlant(renderer, Texture::createFromFile("images/cards/PowerPlant.png", *renderer)));
	deck.push_front(new PowerPlant(renderer, Texture::createFromFile("images/cards/PowerPlant.png", *renderer)));
	deck.push_front(new PowerPlant(renderer, Texture::createFromFile("images/cards/PowerPlant.png", *renderer)));
	deck.push_front(new Briefing(renderer, Texture::createFromFile("images/cards/Briefing.png", *renderer)));
	deck.push_front(new Briefing(renderer, Texture::createFromFile("images/cards/Briefing.png", *renderer)));
	deck.push_front(new Briefing(renderer, Texture::createFromFile("images/cards/Briefing.png", *renderer)));
	deck.push_front(new ProjectOmega(renderer, Texture::createFromFile("images/cards/ProjectOmega.png", *renderer)));
	deck.push_front(new ShieldBlast(renderer, Texture::createFromFile("images/cards/ShieldBlast.png", *renderer)));
	deck.push_front(new ShieldBlast(renderer, Texture::createFromFile("images/cards/ShieldBlast.png", *renderer)));
	deck.push_front(new MakeWar(renderer, Texture::createFromFile("images/cards/MakeWar.png", *renderer)));
	deck.push_front(new MakeWar(renderer, Texture::createFromFile("images/cards/MakeWar.png", *renderer)));
	deck.push_front(new MakeWar(renderer, Texture::createFromFile("images/cards/MakeWar.png", *renderer)));


	vector<Card*> myVector(deck.size());
	copy(deck.begin(), deck.end(), myVector.begin());
	random_shuffle(myVector.begin(), myVector.end());
	deck = list<Card*>(myVector.begin(), myVector.end());

}

void Player::playCard(Card *card){
	int h, e, s;
	card->getCost(&h, &e, &s);
	if(h > health || e > energy || s > science){
		return;
	}

	card->renderCenter();
	time_t start = time(NULL);
	while(difftime(time(NULL), start) < 3){
		SDL_Event e;
		while(SDL_PollEvent(&e) != 0);
	}

	if(card->play(this, opponent)){
		cards.remove(card);
		delete card;
	}
}

void Player::setOpponent(Player *opp){
	opponent = opp;
}
void Player::drawCards(int n){
	for(; n > 0 && deck.size() > 0; n--){
		if(cards.size() < MAX_CARDS){
			cards.push_back(deck.front());
		}
		deck.pop_front();
	}
}

void Player::renderCard(Card *c, int n){
	int cHealth, cEnergy, cScience;
	c->getCost(&cHealth, &cEnergy, &cScience);
	c->render(n, !(health < cHealth || energy < cEnergy || science < cScience));
}

void Player::render(bool onTurn){
	int w = renderer->getWidth();
	SDL_Color col = renderer->cBlack;
	TTF_Font *font = renderer->getFont(16);

	texName->render(pNumber ? (w - texName->getWidth() - 20) : 20, 20);

	std::string text;

	text = "HP: " + std::to_string(health);
	renderer->renderText(text.c_str(), font, col, 20, 40, pNumber ? Renderer::RIGHT : Renderer::LEFT);
	text = "Science: " + std::to_string(science);
	renderer->renderText(text.c_str(), font, col, 20, 56, pNumber ? Renderer::RIGHT : Renderer::LEFT);
	text = "Energy: " + std::to_string(energy);
	renderer->renderText(text.c_str(), font, col, 20, 72, pNumber ? Renderer::RIGHT : Renderer::LEFT);

	text = "Scientists: " + std::to_string(scientists);
	renderer->renderText(text.c_str(), font, col, 20, 100, pNumber ? Renderer::RIGHT : Renderer::LEFT);
	text = "Generators: " + std::to_string(generators);
	renderer->renderText(text.c_str(), font, col, 20, 116, pNumber ? Renderer::RIGHT : Renderer::LEFT);

	if(!onTurn  || pNumber == 1){
		return;
	}

	text = "Currently playing";
	renderer->renderText(text.c_str(), font, col, 20, 140, pNumber ? Renderer::RIGHT : Renderer::LEFT);


	int tw = int(renderer->getWidth() * 0.15);
	int th = int(double(tw) / texButton->getWidth() * texButton->getHeight());
	int tx = renderer->getWidth() / 2 - tw / 2;
	int ty = 100;

	texButton->render(tx, ty, tw, th);

	int n = 0;
	for(auto i = cards.begin(); i != cards.end(); ++i, ++n){
		renderCard(*i, n);
	}
}

void Player::startTurn(){
	energy += generators + 1;
	science += scientists + 1;
	drawCards(1);
}

void Player::dealDamage(int damage){
	int oldEnergy = energy;
	energy = std::max(0, energy - damage);
	damage -= oldEnergy - energy;

	health -= damage;
}

void Player::addCard(Card *c){
	if(cards.size() == MAX_CARDS){
		return;
	}
	cards.push_back(c);
}