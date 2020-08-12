#include <stdio.h>
#include "GameEngine.h"

int main(int argc, char* argv[])
{
	GameEngine gameEngine;

	gameEngine.Initialtise("Coventry Chasers!", 640, 480);

	while (gameEngine.isRunning)
	{
		gameEngine.Update();
		//gameEngine.Render();
	}

	return 0;
}
