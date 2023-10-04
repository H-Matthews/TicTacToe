#pragma once
#include "Player.h"

class GameBoard
{
private:
	static const int m_boardLength = 9;
	char m_boardStructure[m_boardLength];

public:
	void initializeBoard();
	void printBoard();
	bool markBoard(Player* p);
	bool checkGameOver(Player* p);
};
