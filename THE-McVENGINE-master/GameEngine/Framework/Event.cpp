#include "Event.h"
#include <vector>
#include <array>

// THIS IS AN ARRAY OF MY EVENT CALLBACKS (Callbacks are all of the functions that are meant to be executed when an event occurs)

// This array is the same size as the amount of events
// Each index maps to a game event
// Each element of the array contains a vector of GameEventsCallbacks

static std::array<std::vector<GameEventsCallback>, (int)Event::GameEvents::TOTAL_GAME_EVENTS> eventCallbacks;


void Event::Broadcast(GameEvents gameEvents)
{
	std::vector<GameEventsCallback>* callbacks = &eventCallbacks[(int)gameEvents];

	// For each element of the array (each Game Eve), we want to access the func
	for (int i = 0; i < callbacks->size(); i++)
	{
		GameEventsCallback callback = callbacks->at(i);
		callback();
	}
}

void Event::Register(GameEvents gameEvents, GameEventsCallback callback)
{
	std::vector<GameEventsCallback> * callbacks = &eventCallbacks[(int)gameEvents];
	callbacks->push_back(callback);
}

void Event::Unregister(GameEvents gameEvents, GameEventsCallback callback)
{
	std::vector<GameEventsCallback>* callbacks = &eventCallbacks[(int)gameEvents];
	std::vector<GameEventsCallback>::iterator iterator = std::find(callbacks->begin(), callbacks->end(), callback);
	ptrdiff_t index = std::distance(callbacks->begin(), iterator);
	callbacks->erase(callbacks->begin() + index);
}