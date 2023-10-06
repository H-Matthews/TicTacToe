#include "ConfigReader.h"
#include <iostream>


// Define Singleton Instance as NULL
ConfigReader* ConfigReader::m_configReaderInstance = NULL;

ConfigReader* ConfigReader::getInstance()
{
	if (m_configReaderInstance == NULL)
		m_configReaderInstance = new ConfigReader();
		

	return m_configReaderInstance;
}

ConfigReader::ConfigReader()
{
	m_buffer = "";
	m_fileName = "";
	m_errorCode = "";

	m_isInitialized = false;

	playerCounter = 1;
}

std::string ConfigReader::initialize(std::string fileName)
{
	m_errorCode = "ERROR_CODE:NO_ERROR";

	// Set member incase we need to reference file name again throughout program
	m_fileName = fileName;

	m_fileHandle.open(m_fileName, std::ios::in);

	// Check to see if file opens
	if (!m_fileHandle.is_open())
		m_errorCode = "ERROR_CODE:INVALID_FILE_NAME";

	if (m_errorCode == "ERROR_CODE:NO_ERROR")
	{
		parseFile();
		m_isInitialized = true;
	}

	return m_errorCode;
}

void ConfigReader::parseFile()
{

	while (m_fileHandle)
	{
		std::getline(m_fileHandle, m_buffer);

		// Only executes when we are looking at sectionHeaders
		if (m_buffer[0] == '[')
		{
			m_sectionHeader = "";

			// Grabs the Section Header between the [] in ini file
			for (int i = 1; i < m_buffer.length() - 1; i++)
			{
				m_sectionHeader = m_sectionHeader + m_buffer[i];
			}
		}
		// Right now we only have one section, later we will have more sections
		else if (m_sectionHeader == "Players")
		{
			if (playerCounter == 1)
			{
				m_players[0] = m_buffer;
				playerCounter++;
			}
			else
				m_players[1] = m_buffer;
		}
	}
}

bool ConfigReader::isInitialized()
{
	return m_isInitialized;
}

std::string* ConfigReader::getPlayers()
{
	return m_players;
}
