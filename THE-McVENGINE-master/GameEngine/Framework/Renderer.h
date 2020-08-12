#pragma once
#include <SDL.h>


class Renderer
{
public:

	SDL_Surface* screenSurface = nullptr;

	void Initialise(SDL_Window* window);
	void Update(SDL_Window* window);

	Renderer();

	~Renderer();

};

