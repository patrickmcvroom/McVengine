#pragma once

#include <stdio.h>
#include <SDL.h>

class UserInput
{
public:

	void Update();

	// Creating our event manager with SDL's default event handler

	SDL_Event EventHandler;
};

