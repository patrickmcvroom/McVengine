#include "Renderer.h"
#include "ResourceLoader.h"
#include <iostream>

SDL_Surface* imageOne = nullptr;

Renderer::Renderer()
{

}

Renderer::~Renderer()
{
	//Deallocate surface
	SDL_FreeSurface(screenSurface);
	SDL_FreeSurface(imageOne);
	imageOne = NULL;
}

void Renderer::Initialise(SDL_Window* window)
{
	printf("Initialising Renderer\n");
	imageOne = ResourceLoader::LoadBitmap("Images/Race_Kart_bmp.bmp");

	//Creates a window surface
	screenSurface = SDL_GetWindowSurface(window);

}

void Renderer::Update(SDL_Window* window)
{
	//Fill the surface white
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
	
	SDL_BlitSurface(imageOne, NULL, screenSurface, NULL);
	
	//Update the surface
	SDL_UpdateWindowSurface(window);

}
