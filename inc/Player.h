#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Types.h"

class Player
{
private:
	std::string m_fullName;
	PlayerType m_playerType;
	char m_playerTypeChar;
	char m_playerMoveSelection;

	// Internal function 
	void setPlayerMarkChar(PlayerType type);

public:
	
	Player(std::string fullName, PlayerType type);
	Player();

	std::string getFullName();
	char getPlayerMark();

	void setPlayerMoveSelection();
	char getPlayerMoveSelection();
	Player* switchPlayer(Player* currentPlayer, Player& p1, Player& p2);


};
#endif
