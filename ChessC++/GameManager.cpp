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
	user->MovePiece(board->GetClickedPiece(), board->GetTileSize());
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
	int test[col][row];
	if (board->GetClickedPiece() != NULL)
	{
		board->GetAvailableMoves();
		draw->DrawAvailableMoves(board->GetClickedPiece(), board->GetTileSize());
		/*for (int i = 0; i < board->GetClickedPiece()->moves.size(); i++)
		{
			int x = board->GetClickedPiece()->moves[i]->x + board->GetClickedPiece()->gridPosX;
			int y = board->GetClickedPiece()->moves[i]->y + board->GetClickedPiece()->gridPosY;

			while (board->GetClickedPiece()->CanContinueMoving() && board->GetBoardArray(x, y) == 0)
			{
				board->GetClickedPiece()->availableMoves.push_back(new Vector2D(x, y));
				x++;
				y++;
			}
			board->GetClickedPiece()->availableMoves.push_back(new Vector2D(x, y));
		}*/
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
