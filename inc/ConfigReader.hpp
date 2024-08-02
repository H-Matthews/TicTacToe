#ifndef CONFIG_READER_H
#define CONFIG_READER_H

#include <string>
#include <fstream>
#include "Types.hpp"

constexpr int PLAYER_MAX = 2;

// Singleton Class Design
class ConfigReader
{
public:

	static ConfigReader* getInstance();

	void initialize(const std::string fileName, StatusCode& status);

	bool isInitialized() const;

	const std::string* getPlayers() const;

private:
	static ConfigReader* m_configReaderInstance;
	
	std::string m_buffer;
	std::string m_sectionHeader;

	std::fstream m_fileHandle;
	std::string m_fileName;

	std::string m_players[PLAYER_MAX];
	int playerCounter;

	bool m_isInitialized;

	void read();
	ConfigReader();
	~ConfigReader();

};

#endif