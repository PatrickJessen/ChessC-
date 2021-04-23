#include "BoardManager.h"
#include "Input.h"

BoardManager::BoardManager(Window* window)
{
	this->window = window;
	board = new Board(window);
}

void BoardManager::SetClickedPiece(int x, int y)
{
	for (int i = 0; i < board->pieces.size(); i++)
	{
		if (board->pieces[i]->gridPosX == x && board->pieces[i]->gridPosY == y)
		{
			clickedPiece = board->pieces[i];
		}
	}
}

Piece* BoardManager::GetClickedPiece()
{
	return clickedPiece;
}

int BoardManager::GetBoardArray(int x, int y)
{
	return board->boardArray[y][x];
}

void BoardManager::SetBoardArray(int x, int y, int value)
{
	board->boardArray[y][x] = value;
}

std::vector<Piece*> BoardManager::GetPieceList()
{
	return board->pieces;
}

bool BoardManager::IsSameColor(int x, int y)
{
	for (int i = 0; i < board->pieces.size(); i++)
	{
		if (board->pieces[i]->gridPosX == x && board->pieces[i]->gridPosY == y)
		{
			if (board->pieces[i]->isWhite && clickedPiece->isWhite || !board->pieces[i]->isWhite && !clickedPiece->isWhite)
			{			 
				return true;
			}
		}
	}
	return false;
}



void BoardManager::SetBoardRect(int x, int y)
{
	board->boardRect = { x * board->tileSize, y * board->tileSize, board->tileSize, board->tileSize };
}

int BoardManager::GetTileSize()
{
	return board->tileSize;
}

void BoardManager::GetAvailableMoves()
{
	for (int i = 0; i < clickedPiece->moves.size(); i++)
	{
		int x = clickedPiece->moves[i]->x + clickedPiece->gridPosX;
		int y = clickedPiece->moves[i]->y + clickedPiece->gridPosY;

		while (clickedPiece->CanContinueMoving() && board->boardArray[y][x] == 0)
		{
			clickedPiece->availableMoves.push_back(new Vector2D(x, y));
			x += clickedPiece->moves[i]->x;
			y += clickedPiece->moves[i]->y;
			if (!IsSameColor(x, y))
			{
				clickedPiece->availableMoves.push_back(new Vector2D(x, y));
			}

		}
		if (!clickedPiece->CanContinueMoving() && board->boardArray[y][x] == 0)
		{
			//fix
			if (!IsSameColor(x, y))
			{
				clickedPiece->availableMoves.push_back(new Vector2D(x, y));
			}
		}
		if (!IsSameColor(x, y))
		{
			clickedPiece->availableMoves.push_back(new Vector2D(x, y));
		}
	}
}

SDL_Rect& BoardManager::GetBoardRect()
{
	return board->boardRect;
}


