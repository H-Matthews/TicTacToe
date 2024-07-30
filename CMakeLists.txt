cmake_minimum_required(VERSION 3.5)
project(TicTacToe LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

set(SRC_DIR src)
set(INC_DIR inc)

# Define source / include files
set(SOURCES ${SRC_DIR}/ConfigReader.cpp 
${SRC_DIR}/GameBoard.cpp
${SRC_DIR}/GameController.cpp 
${SRC_DIR}/Player.cpp 
${SRC_DIR}/Main.cpp
${INC_DIR}/ConfigReader.h
${INC_DIR}/GameBoard.h
${INC_DIR}/GameController.h 
${INC_DIR}/Player.h 
${INC_DIR}/Types.h)

# Define executable to be built
add_executable(Debug ${SOURCES})

# Define destination for our include directory for target 
target_include_directories(Debug PUBLIC ${INC_DIR})

# Installs the executable to the install interface
install(TARGETS Debug)
install(DIRECTORY configs DESTINATION .)