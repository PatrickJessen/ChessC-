#include "Board.h"
#include "Input.h"

Board::Board(Window* window)
{
	this->window = window;
	pieces.push_back(new Piece(window, 0 * tileSize, 7 * tileSize, piece->Rook, true, piece->piecePath[0]));
	pieces.push_back(new Piece(window, 1 * tileSize, 7 * tileSize, piece->Knight, true, piece->piecePath[1]));
	pieces.push_back(new Piece(window, 2 * tileSize, 7 * tileSize, piece->Bishop, true, piece->piecePath[2]));
	pieces.push_back(new Piece(window, 3 * tileSize, 7 * tileSize, piece->Queen, true, piece->piecePath[4]));
	pieces.push_back(new Piece(window, 4 * tileSize, 7 * tileSize, piece->King, true, piece->piecePath[3]));
	pieces.push_back(new Piece(window, 5 * tileSize, 7 * tileSize, piece->Bishop, true, piece->piecePath[2]));
	pieces.push_back(new Piece(window, 6 * tileSize, 7 * tileSize, piece->Knight, true, piece->piecePath[1]));
	pieces.push_back(new Piece(window, 7 * tileSize, 7 * tileSize, piece->Rook, true, piece->piecePath[0]));

	pieces.push_back(new Piece(window, 0 * tileSize, 0 * tileSize, piece->Rook, false, piece->piecePath[6]));
	pieces.push_back(new Piece(window, 1 * tileSize, 0 * tileSize, piece->Knight, false, piece->piecePath[7]));
	pieces.push_back(new Piece(window, 2 * tileSize, 0 * tileSize, piece->Bishop, false, piece->piecePath[8]));
	pieces.push_back(new Piece(window, 3 * tileSize, 0 * tileSize, piece->Queen, false, piece->piecePath[10]));
	pieces.push_back(new Piece(window, 4 * tileSize, 0 * tileSize, piece->King, false, piece->piecePath[9]));
	pieces.push_back(new Piece(window, 5 * tileSize, 0 * tileSize, piece->Bishop, false, piece->piecePath[8]));
	pieces.push_back(new Piece(window, 6 * tileSize, 0 * tileSize, piece->Knight, false, piece->piecePath[7]));
	pieces.push_back(new Piece(window, 7 * tileSize, 0 * tileSize, piece->Rook, false, piece->piecePath[6]));
	for (int i = 0; i < 8; i++)
	{
		pieces.push_back(new Piece(window, i * tileSize, 6 * tileSize, piece->Pawn, true, piece->piecePath[5]));
		pieces.push_back(new Piece(window, i * tileSize, 1 * tileSize, piece->Pawn, false, piece->piecePath[11]));
	}
}

void Board::DrawBoard()
{
	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
		{
			pieceArray[r][c] = NULL;
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
	DragAndDrop();
	//SelectPiece();
}

void Board::RenderPiecesToBoard()
{ 
	for (int i = 0; i < pieces.size(); i++)
	{
		pieceArray[pieces[i]->rect.y / tileSize][pieces[i]->rect.x / tileSize] = pieces[i];
		if (pieceArray[pieces[i]->rect.y / tileSize][pieces[i]->rect.x / tileSize] != NULL)
		{
			SDL_RenderCopy(window->GetRender(), pieces[i]->tex, NULL, &pieces[i]->rect);
			if (tempPiece != NULL && hasClicked)
			{
				tempPiece->rect.x = Input::MouseX() - tileSize / 2;
				tempPiece->rect.y = Input::MouseY() - tileSize / 2;
				SDL_RenderCopy(window->GetRender(), tempPiece->tex, NULL, &tempPiece->rect);
			}
		}
	}
}

void Board::DragAndDrop()
{
	if (Input::MousePressed(MouseButton::LEFT))
	{
		if (pieceArray[Input::MouseY() * tileSize][Input::MouseX() * tileSize] != NULL && !hasClicked)
		{
			std::cout << "test2";
			tempPiece = pieceArray[Input::MouseY() / tileSize][Input::MouseX() / tileSize];
			hasClicked = true;
		}
		else if (tempPiece != NULL)
		{
			std::cout << "test";
			pieceArray[Input::MouseY() / tileSize][Input::MouseX() / tileSize] = tempPiece;
			tempPiece = NULL;
			hasClicked = false;
		}
	}
}

void Board::SelectPiece()
{
	if (Input::MousePressed(MouseButton::LEFT))
	{
		fill = { Input::MouseX() * tileSize, Input::MouseY() * tileSize, tileSize, tileSize };
		hasClicked = true;
	}
}


