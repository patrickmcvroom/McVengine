#pragma once
#include <SDL.h>

#include "Renderer.h"
#include "UserInput.h"
#include "Event.h"
#include <GL/gl3w.h>

class GameEngine
{
public:

	bool isRunning;
	void Initialtise(const char* windowTitle, int screenWidth, int screenHeight);
	void Update();
	

	GameEngine();

	~GameEngine();

private:

	SDL_Window* window = nullptr;
	Renderer* renderer = nullptr;
	UserInput* input = nullptr;

};

void OnQuitGame();

