#include "GameManager.h"

GameManager::GameManager(Window* window)
{
	boardManager = new BoardManager(window);
	userManager = new UserManager();
}
