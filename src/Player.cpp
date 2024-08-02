#include "Player.hpp"
#include <string>
#include <iostream>

// Constructors

Player::Player()
{
	m_fullName = " ";
	m_playerType = PlayerType::DEFAULT;
	m_playerTypeChar = ' ';
	m_playerMoveSelection = ' ';
}

Player::Player(std::string fullName, PlayerType type)
{
	m_fullName = fullName;
	m_playerType = type;
	
	// Sets m_playerTypeChar
	setPlayerMarkChar(type);
}

Player* Player::switchPlayer(Player* currentPlayer, Player& p1, Player& p2)
{
	if (currentPlayer == &p1)
		currentPlayer = &p2;
	else
		currentPlayer = &p1;
	
	return currentPlayer;
}

char Player::getPlayerMove()
{
	return this->m_playerMoveSelection;
}

void Player::getPlayerInput()
{
	std::cout << m_fullName << "(" << m_playerTypeChar << ")" << " enter move selection: ";
	std::cin >> m_playerMoveSelection;
}

void Player::setPlayerMarkChar(PlayerType type)
{
	// ASCII Code X ---> 88
	// ASCII Code O ---> 79
	if (m_playerType == PlayerType::X)
		m_playerTypeChar = 88;
	else
		m_playerTypeChar = 79;
}

std::string Player::getFullName()
{
	return this->m_fullName;
}

char Player::getPlayerMark()
{
	return this->m_playerTypeChar;
}