#pragma once
#include <string>
#include <fstream>

constexpr int PLAYER_MAX = 2;

class ConfigReader
{
private:
	
	std::string m_buffer;
	std::string m_sectionHeader;

	std::fstream m_fileHandle;
	std::string m_fileName;

	std::string m_errorCode;

	std::string m_players[PLAYER_MAX];
	int playerCounter;

	bool m_isInitialized;

public:

	ConfigReader();

	std::string initialize(std::string fileName);

	void parseFile();

	bool isInitialized();

	std::string* getPlayers();

};