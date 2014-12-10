#include <iostream>
#include <SDL2/SDL_image.h>

#include "Texture.h"

Texture::Texture(SDL_Surface* from, const Renderer& renderer_){
	using namespace std;

	ok = false;
	renderer = &renderer_;

	texture = SDL_CreateTextureFromSurface(*renderer, from);
	if(texture == NULL){
		return;
	}
	if(SDL_QueryTexture(texture, NULL, NULL, &w, &h) != 0){
		SDL_DestroyTexture(texture);
		return;
	}

	ok = true;
}

void Texture::render(int x, int y){
	static SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	dest.w = w;
	dest.h = h;

	SDL_RenderCopy(*renderer, texture, NULL, &dest);
}
void Texture::render(int x, int y, int w_, int h_){
	static SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	dest.w = w_;
	dest.h = h_;

	SDL_RenderCopy(*renderer, texture, NULL, &dest);
}

void Texture::renderShaded(int x, int y, int w_, int h_, int r, int g, int b){
	SDL_SetTextureColorMod(texture, r, g, b);
	render(x, y, w_, h_);
	SDL_SetTextureColorMod(texture, 255, 255, 255);
}


Texture::~Texture(){
	SDL_DestroyTexture(texture);
}

Texture* Texture::createFromFile(const char* filename, const Renderer & renderer_){
	using namespace std;

	SDL_Surface* surface = IMG_Load(filename);

	if(surface == NULL){
		cerr << "Image cannot be loaded: " << IMG_GetError() << endl;
		return NULL;
	}

	Texture* tex = new Texture(surface, renderer_);

	SDL_FreeSurface(surface);

	if(!tex->isOk()){
		cerr << "Cannot create texture from " << filename << " SDL_Error: " << SDL_GetError() << endl;
		return NULL;
	}
	return tex;
}
Texture* Texture::createFromText(const char* text, SDL_Color color, TTF_Font* font, const Renderer & renderer_){
	using namespace std;

	SDL_Surface* surface = TTF_RenderText_Blended(font, text, color);

	if(surface == NULL){
		cerr << "Image cannot be loaded: " << IMG_GetError() << endl;
		return NULL;
	}

	Texture* tex = new Texture(surface, renderer_);

	SDL_FreeSurface(surface);

	if(!tex->isOk()){
		cerr << "Cannot create texture from text \"" << text << "\" SDL_Error: " << SDL_GetError() << endl;
		return NULL;
	}
	return tex;
}