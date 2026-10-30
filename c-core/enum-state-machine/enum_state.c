typedef enum e_state
{
	IDLE,
	RUNNING,
	PAUSED,
	DONE,
	FAILED
}	state;

typedef enum e_event
{
	START,
	PAUSE,
	RESUME,
	FINISH,
	ERROR
}	event;

// next_state returns the state reached from current when e fires, and current
// itself when that pair is absent from the transition table.
state	next_state(state current, event e)
{
	if ((current == IDLE && e == START) || (current == PAUSED && e == RESUME))
		return RUNNING;
	else if (current == RUNNING && e == PAUSE)
		return PAUSED;
	else if (current == RUNNING && e == FINISH)
		return DONE;
	else if ((current == RUNNING || current == PAUSED) && e == ERROR)
		return FAILED;
	else
		return current;
}
