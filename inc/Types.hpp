#ifndef TYPES_H
#define TYPES_H

enum class PlayerType
{
	O,
	X,
	DEFAULT
};

enum class ErrorCode
{
	NO_ERROR,
	ALREADY_INITIALIZED,
	INVALID_FILE_NAME,
};

#endif