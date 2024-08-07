#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include "Types.hpp"
#include "GameController.hpp"

#include <string>
namespace HelperFunctions
{
    std::string getErrorState(const StatusCode status);

    GameController initializeObjects();

    void clearScreen();
};

#endif