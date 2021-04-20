#include "Window.h"
#include "BoardManager.h"
#include "UserManager.h"

int main()
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;
	Window* window = new Window("Chess", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 750, 750, false);
	//Board* board = new Board(window);
	BoardManager* manager = new BoardManager(window);
	UserManager* userManager = new UserManager(manager->board);

	while (window->Running())
	{
		manager->Update();
		userManager->Update(window);
		window->Update();
		window->Clear();
	}

	window->Clean();
	return 0;
}