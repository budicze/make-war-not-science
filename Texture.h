#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "Renderer.h"

class Texture {
private:
	Texture(SDL_Surface* from, const Renderer& renderer_);
	bool ok;
	SDL_Texture* texture;
	int w, h;
	const Renderer* renderer;
public:
	~Texture();
	void render(int x, int y);
	void render(int x, int y, int w, int h);
	void renderShaded(int x, int y, int w_, int h_, int r, int g, int b);

	static Texture* createFromFile(const char* name, const Renderer & renderer_);
	static Texture* createFromText(const char* name, SDL_Color color, TTF_Font* font, const Renderer & renderer_);

	bool isOk(){return ok;}
	operator SDL_Texture*() {return texture;}
	int getWidth(){return w;}
	int getHeight(){return h;}
};

#endif