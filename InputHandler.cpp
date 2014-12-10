#include <SDL2/SDL.h>

#include "InputHandler.h"

InputHandler* InputHandler::instance = NULL;


InputHandler::InputHandler(){
	mouseClicked = false;
	mouseDown = false;
}

InputHandler* InputHandler::getInstance(){
	if(instance == NULL){
		instance = new InputHandler();
	}
	return instance;
}

void InputHandler::update(){
	mouseClicked = false;
	bool oldState = mouseDown;
	mouseDown = SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT);
	if(oldState == true && mouseDown == false){
		mouseClicked = true;
	}
}