// User Defined Includes
#include "GameController.hpp"
#include "GameBoard.hpp"
#include "Player.hpp"
#include "ConfigReader.hpp"

// Standard Includes
#include <iostream>

int main()
{

	ConfigReader* reader = reader->getInstance();
	reader->initialize("config.ini");

	if (!reader->isInitialized())
	{
		std::cout << "[ERROR] ConfigReader could not be initialized. Exiting Program. " << std::endl;
		exit(0);
	}

	std::string* players = nullptr;
	players = reader->getPlayers();

	if(players == nullptr)
	{
		std::cout << "[ERROR] Players did not populate correctly. Exiting Program. " << std::endl;
		exit(0);
	}

	Player p1 = Player(players[0], PlayerType::X);
	Player p2 = Player(players[1], PlayerType::O);

	GameBoard board;
	board.initializeBoard();

	GameController controller = GameController(p1, p2, board);

	// Program Begin
	controller.mainGameLoop();

	return 0;
}