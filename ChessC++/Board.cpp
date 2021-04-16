#include "Board.h"
#include <map>
#include <string>

Board::Board(Window* window)
{
	int temp = 0;
	this->window = window;
	for (int i = 0; i < 8; i++)
	{
		pieces.push_back(new Piece(window, i * tileSize, 0 * tileSize, true, piece->whitePieces[i]));
		pieces.push_back(new Piece(window, i * tileSize, 1 * tileSize, true, piece->whitePieces[8]));
	}

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
				SDL_SetRenderDrawColor(window->GetRender(), 255, 255, 255, 50);
			}
			else
			{
				SDL_SetRenderDrawColor(window->GetRender(), 150, 105, 63, 255);
			}
			SDL_RenderFillRect(window->GetRender(), &boardRect);
			
		}
	}
	RenderPiecesToBoard();
}

void Board::RenderPiecesToBoard()
{ 
	for (int i = 0; i < pieces.size(); i++)
	{
		SDL_RenderCopy(window->GetRender(), pieces[i]->tex, NULL, &pieces[i]->rect);
	}
}


