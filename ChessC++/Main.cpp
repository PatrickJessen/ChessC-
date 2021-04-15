#include "Window.h"
#include "Board.h"

int main()
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	Window* window = new Window("GameEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 768, 600, false);
	Board* board = new Board(window);

	while (window->Running())
	{
		board->DrawBoard();
		window->Update();
		window->Clear();
	}

	window->Clean();
	return 0;
}