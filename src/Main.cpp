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

	GameController Controller = GameController("config.ini");

	// Program Begin
	Controller.mainGameLoop();

	return 0;
}