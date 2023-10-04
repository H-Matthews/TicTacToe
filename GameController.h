#pragma once
#include "Player.h"
#include "GameBoard.h"

class GameController
{
private:
	GameBoard m_board;
	Player m_p1;
	Player m_p2;
	Player* m_currentPlayer;

	bool m_gameOver;
	bool m_validInput;

public:
	GameController();

	void mainGameLoop();

};