// User Defined Includes
#include "GameController.hpp"
#include "GameBoard.hpp"
#include "Player.hpp"
#include "ConfigReader.hpp"

// Standard Includes
#include <iostream>

int main()
{
	// TODO: Game Controller now takes in a Filename to open using the new ConfigReader
	//		 We need to improve the configReader algorithm and make it more modular.

	ConfigReader* reader = reader->getInstance();
	reader->initialize("config.ini");

	if (!reader->isInitialized())
	{
		std::cout << "[ERROR] ConfigReader could not be initialized. Exiting Program. " << std::endl;
		exit(0);
	}

	std::string* players = reader->getPlayers();
	Player p1 = Player(players[0], PlayerType::X);
	Player p2 = Player(players[1], PlayerType::O);

	GameBoard board;
	board.initializeBoard();

	GameController controller = GameController(p1, p2, board);

	// Program Begin
	controller.mainGameLoop();

	return 0;
}