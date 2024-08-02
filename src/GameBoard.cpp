#include "GameBoard.hpp"
#include <iostream>


GameBoard::GameBoard()
{
	numberOfMoves = 0;
}

void GameBoard::initializeBoard()
{
	int counter = 0;

	// ASCII Codes 49 - 57 is equal to characters 1 - 9
	for (int i = 49; i < 58; i++)
	{
		m_boardStructure[counter++] = i;
	}
}

// markBoard() will check to see if we have a valid mark. IF so, then it will mark the board
// Incorrect marks are denoted as any userInput that does not match the numbers 1 - 9 in the current board state 
// Board cells will be changed to the corresponding ASCII code for 'X' or 'O'
bool GameBoard::markBoard(Player* p)
{
	bool successfulMark = false;

	for (int i = 0; i < m_boardLength; i++)
	{
		if (m_boardStructure[i] == p->getPlayerMove())
		{
			m_boardStructure[i] = p->getPlayerMark(); // This marks the board
			successfulMark = true;
			numberOfMoves++;
		}
	}

	return successfulMark;
}

void GameBoard::printBoard()
{
	for (int i = 1; i < 10; i++)
	{
		std::cout << m_boardStructure[i - 1] << " ";

		// Create  a new line every 3 chars to look like a board
		if (i % 3 == 0)
		{
			std::cout << std::endl;
		}
	}
}

const int GameBoard::getNumberOfMoves() const
{
	return numberOfMoves;
}

const char* GameBoard::getBoardStructure() const
{
	return m_boardStructure;
}