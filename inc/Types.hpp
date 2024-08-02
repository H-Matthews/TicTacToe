#ifndef TYPES_H
#define TYPES_H

enum class PlayerType
{
	O = 0,
	X,
	DEFAULT
};

enum class StatusCode
{
	GO = 0,
	ALREADY_INITIALIZED,
	INVALID_FILE_NAME,
};

enum class GameState
{
	RUNNING = 0,
	WIN,
	TIE
};

#endif