#include "Window.h"
#include "GameManager.h"

int main()
{
	Window* window = new Window("Chess", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 750, 750, false);
	GameManager* manager = new GameManager(window);

	while (window->Running())
	{
		manager->UpdateLogic();
		manager->UpdateGUI();
		//manager->Update();
		window->Update();
		window->Clear();
		SDL_Delay(1);
	}

	window->Clean();
	return 0;
}