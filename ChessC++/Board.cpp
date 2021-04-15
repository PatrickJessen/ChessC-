#include "Board.h"

Board::Board(Window* window)
{
	this->window = window;
}

void Board::DrawBoard()
{
	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
		{
			boardRect = { r * tileSize, c * tileSize, tileSize, tileSize };
			if ((r + c) % 2 == 0)
			{
				SDL_SetRenderDrawColor(window->GetRender(), 255, 255, 255, 100);
			}
			else
			{
				SDL_SetRenderDrawColor(window->GetRender(), 161, 130, 76, 255);
			}
			SDL_RenderFillRect(window->GetRender(), &boardRect);
		}
	}
}
