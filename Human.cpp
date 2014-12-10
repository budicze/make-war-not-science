#include <iostream>

#include "Human.h"
#include "InputHandler.h"
#include "Card.h"

Human::Human(Renderer* renderer, int pNumber) : Player(renderer, pNumber){
	
}

bool Human::turn(Renderer& renderer){
	InputHandler *i = InputHandler::getInstance();
	int x = i->getMouseX();
	int y = i->getMouseY();

	int tw = int(renderer.getWidth() * 0.15);
	int th = int(double(tw) / texButton->getWidth() * texButton->getHeight());
	int tx = renderer.getWidth() / 2 - tw / 2;
	int ty = 100;

	if(i->isMouseDown() && x > tx && y > ty && x < tx + tw && y < ty + th){
		return true;
	}

	if(cards.size() > 0 && i->isMouseDown()){

		if(y > renderer.getHeight() - 20){
			return false;
		}

		int w = cards.front()->getRenderW();
		int h = cards.front()->getRenderH();

		x -= renderer.getWidth() * 0.01;
		int n = x / int(renderer.getWidth() * 0.11);
		int r = x % int(renderer.getWidth() * 0.11);
		if(r > w){
			return false;
		}
		if(y < renderer.getHeight() - h - 20){
			return false;
		}

		if(n >= (int)cards.size()){
			return false;
		}

		auto i = cards.begin();
		std::advance(i, n);

		playCard(*i);

	}
	return false;
}