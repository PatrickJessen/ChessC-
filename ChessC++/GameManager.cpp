#include "GameManager.h"

GameManager::GameManager(Window* window)
{
	board = new BoardManager(window);
	user = new UserManager();
	draw = new Draw(window);
}

void GameManager::UpdateLogic()
{
	Clear();
	user->ClickPiece(board->GetTileSize());
	UpdateClickedPiece();
}

void GameManager::UpdateGUI()
{
	CreateBoard();
	CreateAvailableMoves();
	user->MovePiece(board->GetClickedPiece(), board->GetTileSize(), board->board);
	CreatePieces();
	draw->DrawSquare(board->GetTileSize());
}

void GameManager::CreateBoard()
{
	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
		{
			board->SetBoardRect(r, c);
			draw->DrawBoard(board->GetBoardRect(), r, c);
		}
	}
}

void GameManager::CreatePieces()
{
	for (int i = 0; i < board->GetPieceList().size(); i++)
	{
		board->SetBoardArray(board->GetPieceList()[i]->rect.x / board->GetTileSize(), board->GetPieceList()[i]->rect.y / board->GetTileSize(), board->GetPieceList()[i]->type);
		if (board->GetBoardArray(board->GetPieceList()[i]->rect.x / board->GetTileSize(), board->GetPieceList()[i]->rect.y / board->GetTileSize()) != 0)
		{
			draw->DrawPiece(*board->GetPieceList()[i]->tex, board->GetPieceList()[i]->rect);
		}
	}
}

void GameManager::CreateAvailableMoves()
{
	if (board->GetClickedPiece() != NULL)
	{
		board->GetAvailableMoves();
		draw->DrawAvailableMoves(board->GetClickedPiece(), board->GetTileSize());
	}
}

void GameManager::UpdateClickedPiece()
{
	if (user->isClicked)
	{
		board->SetClickedPiece(user->clickedX / board->GetTileSize(), user->clickedY / board->GetTileSize());
	}
}

void GameManager::Clear()
{
	if (board->GetClickedPiece() != NULL)
	{
		for (int i = 0; i < board->GetClickedPiece()->availableMoves.size(); i++)
		{
			delete board->GetClickedPiece()->availableMoves[i];
		}
		board->GetClickedPiece()->availableMoves.clear();
	}
}

bool GameManager::IsPieceSameColor(int x, int y)
{
	for (int i = 0; i < board->GetPieceList().size(); i++)
	{		
		if (board->GetClickedPiece()->isWhite && board->GetPieceList()[i]->isWhite || !board->GetClickedPiece()->isWhite && !board->GetPieceList()[i]->isWhite)
		{
			return true;
		}
	}
	return false;
}
