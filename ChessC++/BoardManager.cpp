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

void BoardManager::SetBoardRect(int x, int y)
{
	board->boardRect = { x * board->tileSize, y * board->tileSize, board->tileSize, board->tileSize };
}

int BoardManager::GetTileSize()
{
	return board->tileSize;
}

SDL_Rect& BoardManager::GetBoardRect()
{
	return board->boardRect;
}


