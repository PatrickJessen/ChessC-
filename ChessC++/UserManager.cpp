#include "UserManager.h"
#include "Input.h"

UserManager::UserManager()
{
	
}

void UserManager::ClickPiece(int tileSize, BoardManager* board)
{
	clickedX = Input::MouseX() - (Input::MouseX() % tileSize);
	clickedY = Input::MouseY() - (Input::MouseY() % tileSize);
	if (Input::MousePressed(MouseButton::LEFT))
	{
		std::cout << clickedX / tileSize << " + " << clickedY / tileSize << "\n";
		board->SetClickedPiece(clickedX / board->GetTileSize(), clickedY / board->GetTileSize());
	}
}

void UserManager::MovePiece(Piece* clickedPiece, int size, BoardManager* board)
{
	if (clickedPiece != NULL && board->CheckTurn())
	{
		int x = board->GetClickedX() / size;
		int y = board->GetClickedY() / size;
		for (int i = 0; i < clickedPiece->availableMoves.size(); i++)
		{
			if (x == clickedPiece->availableMoves[i]->x && y == clickedPiece->availableMoves[i]->y)
			{
				if (Input::MousePressed(MouseButton::LEFT))
				{
					//board->boardArray[clickedPiece->gridPosY][clickedPiece->gridPosX] = 0;
					board->SetBoardArray(clickedPiece->gridPosX, clickedPiece->gridPosY, 0);
					clickedPiece->gridPosX = x;
					clickedPiece->gridPosY = y;
					clickedPiece->rect.x = board->GetClickedX();
					clickedPiece->rect.y = board->GetClickedY();
					clickedPiece->hasMoved = true;
					CapturePiece(clickedPiece, board);
					board->SetTurn();
					board->SetClickedPieceToNULL();
				}
				return;
			}
		}
	}
}

void UserManager::CapturePiece(Piece* clickedPiece, BoardManager* board)
{
	for (int i = 0; i < board->GetPieceList().size(); i++)
	{
		if (clickedPiece->gridPosX == board->GetPieceList()[i]->gridPosX && clickedPiece->gridPosY == board->GetPieceList()[i]->gridPosY)
		{
			if (clickedPiece != board->GetPieceList()[i])
			{
				board->RemovePieceAtIndex(i);
			}
			//board->GetPieceList().erase(board->GetPieceList().begin() + i);
		}
	}
}