// User Defined Includes
#include "GameController.h"
#include "GameBoard.h"
#include "Player.h"
#include "ConfigReader.h"

// Standard Includes
#include <iostream>

int main()
{
	// TODO: GameController should be created with a config reader param to increase flexibility
	//		 We will have a config.ini that will contain the names of the players playing the game.
	//       We could also provide different settings for the game. This is useful because it doesnt 
	//       need the code to be recompiled if we change player names.
	GameController Controller = GameController("config.ini");

	// Program Begin
	Controller.mainGameLoop();

	return 0;
}