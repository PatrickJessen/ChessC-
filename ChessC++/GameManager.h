#pragma once
#include "BoardManager.h"
#include "UserManager.h"

class GameManager
{
private:
	BoardManager* boardManager;
	UserManager* userManager;
public:
	GameManager(Window* window);
};

