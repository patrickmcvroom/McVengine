#include <stdio.h>
#include <iostream>
#include "GameEngine.h"


GameEngine::GameEngine()
{
	isRunning = false;
	printf("Constructed\n");

	Event::Register(Event::GameEvents::QUIT_GAME, &OnQuitGame);
}

GameEngine::~GameEngine()
{
	isRunning = false;
	printf("Destructed\n");

	Event::Unregister(Event::GameEvents::QUIT_GAME, &OnQuitGame);

	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();
}

void GameEngine::Initialtise(const char* windowTitle, int screenWidth, int screenHeight)
{
	printf("Initialise\n");

	//Initialize SDL
	bool sdlError = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER);

	if (sdlError)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());

		return;
	}

	// Decide GL+GLSL versions
#if __APPLE__
	// GL 3.2 Core + GLSL 150
	const char* glsl_version = "#version 150";
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG); // Always required on Mac
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
#else
	// GL 3.0 + GLSL 130
	const char* glsl_version = "#version 130";
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#endif

	// Create window with graphics context
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
	SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);

	window = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, window_flags);

	SDL_GLContext gl_context = SDL_GL_CreateContext(window);
	SDL_GL_MakeCurrent(window, gl_context);
	SDL_GL_SetSwapInterval(1); // Enable vsync

	if (window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return;
	}

	bool err = gl3wInit() != 0;

	if (err)
	{
		fprintf(stderr, "Failed to initialize OpenGL loader!\n");
		return;
	}

	renderer = new Renderer;
	renderer->Initialise(window);

	input = new UserInput;

	isRunning = true;
}

void GameEngine::Update()
{
	input->Update();
	renderer->Update(window);
}

void OnQuitGame()
{
	printf("QUIT GAME EVENT RECIEVED!\n");
}
