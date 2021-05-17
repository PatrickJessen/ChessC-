#include "GameManager.h"

GameManager::GameManager(Window* window)
{
	board = new BoardManager(window);
	user = new UserManager();
	draw = new Draw(window);
}

void GameManager::UpdateLogic()
{
	CreateBoard();
	if (board->GetClickedPiece() != NULL)
	{
		board->CheckIfPawnMoved();
		board->CanPawnCapture();
		board->GetAvailableMoves();
		user->MovePiece(board->GetClickedPiece(), board->GetTileSize(), board);
	}
	user->ClickPiece(board->GetTileSize(), board);
	//UpdateClickedPiece();
}

void GameManager::UpdateGUI()
{
	CreateAvailableMoves();
	CreatePieces();
	draw->DrawSquare(board->GetTileSize());
	Clear();
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
		board->SetBoardArray(board->GetPieceList()[i]->rect.x / board->GetTileSize(), board->GetPieceList()[i]->rect.y / board->GetTileSize(), (int)board->GetPieceList()[i]->type);
		if (board->GetBoardArray(board->GetPieceList()[i]->rect.x / board->GetTileSize(), board->GetPieceList()[i]->rect.y / board->GetTileSize()) != 0)
		{
			draw->DrawPiece(*board->GetPieceList()[i]->tex, board->GetPieceList()[i]->rect);
		}
	}
}

void GameManager::CreateAvailableMoves()
{
	if (board->GetClickedPiece() != NULL && board->CheckTurn())
	{
		draw->DrawAvailableMoves(board->GetClickedPiece(), board->GetTileSize());
	}
}

void GameManager::UpdateClickedPiece()
{
	if (user->isClicked)
	{
		//board->SetClickedPiece(user->clickedX / board->GetTileSize(), user->clickedY / board->GetTileSize());
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


