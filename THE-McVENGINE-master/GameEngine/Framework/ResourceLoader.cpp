#include "ResourceLoader.h"

#include <stdio.h>
#include <SDL.h>


SDL_Surface* ResourceLoader::LoadBitmap(const char* imageName)
{
	//Load Image

	SDL_Surface* kartImage = SDL_LoadBMP(imageName);

	if (kartImage == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", imageName, SDL_GetError());
	}

	return kartImage;

}

