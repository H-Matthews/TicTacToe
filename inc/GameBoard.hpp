#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include "Player.hpp"

#define MAX_TILES 9

class GameBoard
{
private:
	static const int m_boardLength = 9;
	char m_boardStructure[m_boardLength];
	int numberOfMoves;

public:
	GameBoard();
	void initializeBoard();
	void printBoard();
	bool markBoard(Player* p);

	const int getNumberOfMoves() const;
	const char* getBoardStructure() const;
};
#endif
