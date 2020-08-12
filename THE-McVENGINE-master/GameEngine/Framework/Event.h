#pragma once

typedef void (*GameEventsCallback)();

class Event
{
public:

	enum class GameEvents
	{
		START_GAME,
		QUIT_GAME,
		TOTAL_GAME_EVENTS
	};

	static void Broadcast(GameEvents gameEvents);
	static void Register(GameEvents gameEvents, GameEventsCallback callback);
	static void Unregister(GameEvents gameEvents, GameEventsCallback callback);

private:

};