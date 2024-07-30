#pragma once
#include "Player.h"

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
	bool checkGameOver(Player* p);

	int getNumberOfMoves();
};