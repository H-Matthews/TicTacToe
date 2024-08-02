// User Defined Includes
#include "GameController.hpp"
#include "HelperFunctions.hpp"

// Standard Includes
#include <iostream>

int main()
{

	GameController controller = HelperFunctions::initializeObjects();

	// Program Begin
	controller.mainGameLoop();

	return 0;
}