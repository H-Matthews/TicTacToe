#include "HelperFunctions.hpp"
#include "ConfigReader.hpp"
#include "Player.hpp"
#include "GameBoard.hpp"

#include <iostream>

std::string getErrorState(const StatusCode status)
{
	std::string st = "";

	switch(status)
	{
		case StatusCode::GO:
			st = "GO";
			break;
		case StatusCode::ALREADY_INITIALIZED:
			st = "ALREADY_INITIALIZED";
			break;
		case StatusCode::INVALID_FILE_NAME:
			st = "INVALID_FILE_NAME";
			break;
		default:
			st = "UNKNOWN_ERROR";
			break;
	}
	return st;
}

GameController initializeObjects()
{
    ConfigReader* reader = nullptr;
    reader = reader->getInstance();
    if (reader == nullptr)
    {
        std::cout << "[ERROR] - HelperFunctions::initializeObejcts() - ConfigReader"
        " object could not be created ... Exiting program " << std::endl;
        exit(0);
    }
		
    enum StatusCode status;
    reader->initialize("config.ini", status);

    if (status != StatusCode::GO)
	{
		std::cout << "[ERROR] - HelperFunctions::initializeObjects() - ConfigReader"
        " could not be initialized.  [Error Code] - [" << getErrorState(status)
		  << "] Exiting Program. " << std::endl;
		exit(0);
	}
    
    const std::string* players = nullptr;
    players = reader->getPlayers();

    if (players == nullptr)
    {
        std::cout << "[ERROR] - HelperFunctions::initializeObjects() "
        "Players did NOT populate correctly. Exiting Program. " << std::endl;
		exit(0);
    }

    Player p1 = Player(players[0], PlayerType::X);
    Player p2 = Player(players[1], PlayerType::O);

    GameBoard board;
    board.initializeBoard();

    GameController controller = GameController(p1, p2, board);

    return controller;
}

void clearScreen()
{
    system("clear");
}