#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SDL2/SDL.h>

#include "Renderer.h"
#include "Texture.h"
#include "Human.h"
#include "InputHandler.h"
#include "AI.h"

bool game(Renderer &renderer){

	Human h1(&renderer, 0);
	AI h2(&renderer, 1);
	Player *p1 = &h1, *p2 = &h2;
	Player* onTurn = p1;

	p1->setOpponent(p2);
	p2->setOpponent(p1);

	bool running = true;
	while(running && p1->isAlive() && p2->isAlive()){
		InputHandler::getInstance()->update();
		renderer.clear();
		p1->render(onTurn == p1);
		p2->render(onTurn == p2);
		if(onTurn->turn(renderer)){
			onTurn = (onTurn == p1) ? p2 : p1;
			onTurn->startTurn();
		}

		SDL_Event e;
		while(SDL_PollEvent(&e)){
			if(e.type == SDL_QUIT){
				return true;
			}
			if(e.type == SDL_WINDOWEVENT && e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED){
				renderer.changeSize(e.window.data1, e.window.data2);
			}
		}
		renderer.update();
		SDL_Delay(1);
	}

	while(true){
		SDL_Color c = renderer.cBlack;
		renderer.clear();
		if(!p1->isAlive() && !p2->isAlive()){
			renderer.renderText("It's a... draw? That's an achievement for you! Congratulation!", renderer.getFont(20), c, 20, 20, renderer.LEFT);
		} else if(p1->isAlive()){
			renderer.renderText("You have won! Congratulation!", renderer.getFont(20), c, 20, 20, renderer.LEFT);
		} else {
			renderer.renderText("You have lost! I wish you more luck next time!", renderer.getFont(20), c, 20, 20, renderer.LEFT);
		}

		renderer.renderText("And don't forget: Make science, NOT war!", renderer.getFont(20), c, 20, 40, renderer.LEFT);
		renderer.renderText("Press any key to end the game.", renderer.getFont(20), c, 20, 100, renderer.LEFT);
		renderer.update();

		SDL_Event e;
		while(SDL_PollEvent(&e)){
			if(e.type == SDL_WINDOWEVENT && e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED){
					renderer.changeSize(e.window.data1, e.window.data2);
				}
			if(e.type == SDL_KEYDOWN){
				return true;
			}
		}
	}

	return true;
}

void help(Renderer& renderer){
	while(true){
		TTF_Font* f = renderer.getFont(16);
		SDL_Color c = renderer.cBlack;
		renderer.clear();
		renderer.renderText("Make war, not science!", renderer.getFont(20), c, 20, 20, renderer.LEFT);
		renderer.renderText("Made for Ludum Dare 31 compo by Budi <budi@budai.cz>", f, c, 20, 40, renderer.LEFT);
		renderer.renderText("Rules:", renderer.getFont(20), c, 20, 100, renderer.LEFT);
		renderer.renderText("Your goal is to kill your enemy - get his HP down to zero.", f, c, 20, 120, renderer.LEFT);
		renderer.renderText("To accomplish this, you can play as many cards as you wish in one turn.", f, c, 20, 136, renderer.LEFT);
		renderer.renderText("If you want to end the turn, press the button, now your opponent is on turn.", f, c, 20, 152, renderer.LEFT);
		renderer.renderText("The cost of each card is written on its top side.", f, c, 20, 168, renderer.LEFT);
		renderer.renderText("At start of each turn you get:", f, c, 20, 220, renderer.LEFT);
		renderer.renderText("- 1 card (max 9)", f, c, 40, 236, renderer.LEFT);
		renderer.renderText("- science equal to the number of scientists + 1", f, c, 40, 252, renderer.LEFT);
		renderer.renderText("- energy equal to the number of generators + 1", f, c, 40, 268, renderer.LEFT);
		renderer.renderText("Energy acts also as your shield, damage done to your health is reduced by amount of your energy.", f, c, 20, 300, renderer.LEFT);
		renderer.renderText("However you will lose this energy.", f, c, 20, 316, renderer.LEFT);

		renderer.renderText("Press any key to continue!", renderer.getFont(20), c, 300, 500, renderer.LEFT);

		renderer.update();

		SDL_Event e;
		while(SDL_PollEvent(&e)){
			if(e.type == SDL_WINDOWEVENT && e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED){
					renderer.changeSize(e.window.data1, e.window.data2);
				}
			if(e.type == SDL_KEYDOWN){
				return;
			}
		}
	}
}

int main(int argc, char* argv[]){
	using namespace std;
	
	Renderer renderer(900, 600, "Make war, not science!");
	if(!renderer.isOk()){
		cout << "Ending program" << endl;
		return EXIT_FAILURE;
	}

	srand(time(NULL));

	help(renderer);

	return game(renderer) ? EXIT_SUCCESS : EXIT_FAILURE;

}