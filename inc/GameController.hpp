#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "Player.hpp"
#include "GameBoard.hpp"
#include "ConfigReader.hpp"

class GameController
{
private:
	ConfigReader* m_reader;
	GameBoard m_board;
	Player m_p1;
	Player m_p2;
	Player* m_currentPlayer;

	bool m_gameOver;
	bool m_validInput;


public:
	GameController();

	GameController(std::string iniFile);

	void mainGameLoop();

};
#endif