#include "Window.h"
#include "BoardManager.h"
#include "UserManager.h"
#include "Draw.h"

int main()
{
	Window* window = new Window("Chess", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 750, 750, false);
	BoardManager* manager = new BoardManager(window);
	Draw* draw = new Draw(window, manager);

	while (window->Running())
	{
		draw->Update();
		//manager->Update();
		window->Update();
		window->Clear();
	}

	window->Clean();
	return 0;
}