#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "Player.hpp"
#include "GameBoard.hpp"

class ConfigReader;

class GameController
{
private:
	ConfigReader* m_reader;
	GameBoard m_board;
	Player m_p1;
	Player m_p2;
	Player* m_currentPlayer;

	enum GameState m_gameState;
	bool m_validInput;

	enum GameState checkGameState();
public:
	GameController();
	GameController(Player p1, Player p2, GameBoard board);

	void mainGameLoop();

};
#endif