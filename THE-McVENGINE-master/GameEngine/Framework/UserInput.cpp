#include "UserInput.h"
#include "Event.h"

void UserInput::Update()
{
	//Broadcasts all the events on the event queue

	if (SDL_PollEvent(&EventHandler) != 0)
	{
		//Checks which type SDL event and attaches our equivalent event to it

		switch(EventHandler.type)
		{
			case SDL_QUIT:
				Event::Broadcast(Event::GameEvents::QUIT_GAME);
			break;


		}

	}
}
