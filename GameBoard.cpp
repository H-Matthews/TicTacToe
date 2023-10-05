#include "GameBoard.h"
#include <iostream>

void GameBoard::initializeBoard()
{
	int counter = 0;

	// ASCII Codes 49 - 57 is equal to characters 1 - 9
	for (int i = 49; i < 58; i++)
	{
		m_boardStructure[counter++] = i;
	}
}

bool GameBoard::checkGameOver(Player* p)
{
	// Assume there is no win
	bool win = false;

	// Next 3 covers Horizontal win condition
	if (m_boardStructure[0] == p->getPlayerMark() && m_boardStructure[1] == p->getPlayerMark() && m_boardStructure[2] == p->getPlayerMark())
		win = true;
	else if (m_boardStructure[3] == p->getPlayerMark() && m_boardStructure[4] == p->getPlayerMark() && m_boardStructure[5] == p->getPlayerMark())
		win = true;
	else if (m_boardStructure[6] == p->getPlayerMark() && m_boardStructure[7] == p->getPlayerMark() && m_boardStructure[8] == p->getPlayerMark())
		win = true;
	// Next 3 covers Vertical win condition
	else if (m_boardStructure[0] == p->getPlayerMark() && m_boardStructure[3] == p->getPlayerMark() && m_boardStructure[6] == p->getPlayerMark())
		win = true;
	else if (m_boardStructure[1] == p->getPlayerMark() && m_boardStructure[4] == p->getPlayerMark() && m_boardStructure[7] == p->getPlayerMark())
		win = true;
	else if (m_boardStructure[2] == p->getPlayerMark() && m_boardStructure[5] == p->getPlayerMark() && m_boardStructure[8] == p->getPlayerMark())
		win = true;
	// Next 2 covers diagonal win condition
	else if (m_boardStructure[0] == p->getPlayerMark() && m_boardStructure[4] == p->getPlayerMark() && m_boardStructure[8] == p->getPlayerMark())
		win = true;
	else if (m_boardStructure[2] == p->getPlayerMark() && m_boardStructure[4] == p->getPlayerMark() && m_boardStructure[6] == p->getPlayerMark())
		win = true;

	if (win == true)
		std::cout << p->getFullName() << " has won! " << std::endl;
	else
		system("Clear");

	return win;
}

bool GameBoard::markBoard(Player* p)
{
	bool successfulMark = false;

	for (int i = 0; i < m_boardLength; i++)
	{
		if (m_boardStructure[i] == p->getPlayerMoveSelection())
		{
			m_boardStructure[i] = p->getPlayerMark();
			successfulMark = true;
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