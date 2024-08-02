#include "GameController.hpp"
#include "ConfigReader.hpp"
#include "HelperFunctions.hpp"

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
	m_gameState = GameState::RUNNING;
	m_validInput = true;
};

// Uses a ConfigReader to set the settings
GameController::GameController(Player p1, Player p2, GameBoard board)
{
	// Get ConfigReader Instance
	m_reader = m_reader->getInstance();

	// Set Instances
	m_p1 = p1;
	m_p2 = p2;
	m_board = board;

	// Set other vars as needed
	m_currentPlayer = &m_p2;
	m_gameState = GameState::RUNNING;
	m_validInput = true;
}

// Main Game Loop 
/*  Game Loop Algorithm IN WHILE LOOP
	1. Switch Player (This is why m_currentPlayer gets set to m_P2 in constructor. We will switch to P1 when game starts
	2. Player selects a Square on the grid
	3. Check to see if that square can be selected IF SO, Continue, IF NOT tell them to input again
	4. Mark the square with player input
	5. Check to see the game state after every iteration
	6. IF NOT print the board
*/
void GameController::mainGameLoop()
{

	while ( m_gameState == GameState::RUNNING)
	{
		m_board.printBoard();

		m_currentPlayer = m_currentPlayer->switchPlayer(m_currentPlayer, m_p1, m_p2);
		m_currentPlayer->getPlayerInput();
		m_validInput = m_board.markBoard(m_currentPlayer);

		// Inner Loop to Check for compliant Player input
		while (!(m_validInput))
		{
			clearScreen();
			m_board.printBoard();
			std::cout << "INPUT ERROR: Please enter a valid location on the board! " << std::endl;
			m_currentPlayer->getPlayerInput();
			m_validInput = m_board.markBoard(m_currentPlayer);
		}
		
		m_gameState = checkGameState();
		clearScreen();
	}

	m_board.printBoard();
	switch( m_gameState)
	{
		case GameState::WIN:
			std::cout << m_currentPlayer->getFullName() << " has won! " << std::endl;
			break;
		case GameState::TIE:
			std::cout << "Game was a tie between " << m_p1.getFullName() << " and " << m_p2.getFullName() << std::endl;
			break;
		default:
			std::cout << "Game ended with an UNKNOWN Game State" << std::endl;
	}
}

enum GameState GameController::checkGameState()
{
	// Assume there is no win
	enum GameState state = GameState::RUNNING;

	const char* gameBoard = m_board.getBoardStructure();
	Player* p = m_currentPlayer;		// Just to make function call shorter

	u_int8_t iterator = 0;
	u_int8_t j = 0;

	// Check rows
	while (j++ < 3)
	{
		if (gameBoard[iterator] == p->getPlayerMark() && gameBoard[iterator + 1] == p->getPlayerMark() && gameBoard[iterator + 2] == p->getPlayerMark())
		{
			state = GameState::WIN;
			break;
		}
		iterator = iterator + 3;
	}

	j = 0;
	iterator = 0;
		
	// Check Columns
	if (state == GameState::RUNNING)
	{
		while (j++ < 3)
		{
			if (gameBoard[iterator] == p->getPlayerMark() && gameBoard[iterator + 3] == p->getPlayerMark() && gameBoard[iterator + 6] == p->getPlayerMark())
			{
				state = GameState::WIN;
				break;
			}

			iterator++;
		}
	}

	// Check Diagonals
	if (state == GameState::RUNNING)
	{
		if (gameBoard[0] == p->getPlayerMark() && gameBoard[4] == p->getPlayerMark() && gameBoard[8] == p->getPlayerMark())
			state = GameState::WIN;
		else if (gameBoard[2] == p->getPlayerMark() && gameBoard[4] == p->getPlayerMark() && gameBoard[6] == p->getPlayerMark())
			state = GameState::WIN;
	}

	// Check to see if its a tie game
	if(m_board.getNumberOfMoves() == MAX_TILES)
		state = GameState::TIE;

	return state;
}