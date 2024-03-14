#include "GameController.h"
#include <iostream>

// Constructor does NOT use the new ConfigReader.... Set names here before compiling. Using the other constructor is recommended 
// to prevent unnecessary builds
GameController::GameController()
{
	// Initialize GameBoard
	m_board.initializeBoard();

	// Initialize Players
	m_p1 = Player("Tom", PlayerType::X);
	m_p2 = Player("John", PlayerType::O);

	// Set other vars as needed
	m_currentPlayer = &m_p2;
	m_gameOver = false;
	m_validInput = true;
};

// Uses a ConfigReader to set the settings
GameController::GameController(std::string iniFile)
{
	// Get ConfigReader Instance
	m_reader = m_reader->getInstance();

	// Initialize ConfigReader
	m_reader->initialize(iniFile);

	if (!m_reader->isInitialized())
	{
		std::cout << "[ERROR] ConfigReader could not be initialized. Exiting Program. " << std::endl;
		exit(0);
	}

	// Initialize Players
	std::string* players = m_reader->getPlayers();
	m_p1 = Player(players[0], PlayerType::X);
	m_p2 = Player(players[1], PlayerType::O);

	// Initialize GameBoard
	m_board.initializeBoard();

	// Set other vars as needed
	m_currentPlayer = &m_p2;
	m_gameOver = false;
	m_validInput = true;
}

// Main Game Loop 
/*  Game Loop Algorithm IN WHILE LOOP
	1. Switch Player (This is why m_currentPlayer gets set to m_P2 in constructor. We will switch to P1 when game starts
	2. Player selects a Square on the grid
	3. Check to see if that square can be selected IF SO, Continue, IF NOT tell them to input again
	4. Mark the square with player input
	5. Check to see if the game was won by that specific player
	6. IF NOT print the board
*/
void GameController::mainGameLoop()
{
	m_board.printBoard();

	while (!(m_gameOver))
	{
		m_currentPlayer = m_currentPlayer->switchPlayer(m_currentPlayer, m_p1, m_p2);
		m_currentPlayer->setPlayerMoveSelection();
		m_validInput = m_board.markBoard(m_currentPlayer);

		// Inner Loop to Check for compliant Player input
		while (!(m_validInput))
		{
			system("Clear");
			m_board.printBoard();
			std::cout << "INPUT ERROR: Please enter a valid location on the board! " << std::endl;
			m_currentPlayer->setPlayerMoveSelection();
			m_validInput = m_board.markBoard(m_currentPlayer);
		}

		// Only check for a winner after 4 moves
		if(m_board.getNumberOfMoves() > 4)
			m_gameOver = m_board.checkGameOver(m_currentPlayer);

		m_board.printBoard();
	}
}