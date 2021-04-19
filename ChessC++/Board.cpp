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
			boardArray[r][c] = 0;
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
	fill = { Input::MouseX() - (Input::MouseX() % tileSize), Input::MouseY() - (Input::MouseY() % tileSize), tileSize, tileSize };
	SDL_SetRenderDrawColor(window->GetRender(), 255, 0, 0, 255);
	SDL_RenderDrawRect(window->GetRender(), &fill);
	RenderPiecesToBoard();
	DragAndDrop();
	//SelectPiece();
}

void Board::RenderPiecesToBoard()
{ 
	for (int i = 0; i < pieces.size(); i++)
	{
		boardArray[pieces[i]->rect.y / tileSize][pieces[i]->rect.x / tileSize] = pieces[i]->type;
		if (boardArray[pieces[i]->rect.y / tileSize][pieces[i]->rect.x / tileSize] != 0)
		{
			SDL_RenderCopy(window->GetRender(), pieces[i]->tex, NULL, &pieces[i]->rect);
		}
		if (pieces[i]->isSelected)
		{
			pieces[i]->rect.x = Input::MouseX() - tileSize / 2;
			pieces[i]->rect.y = Input::MouseY() - tileSize / 2;
			SDL_RenderCopy(window->GetRender(), pieces[i]->tex, NULL, &pieces[i]->rect);
		}
	}
}

void Board::DragAndDrop()
{
	
	if (Input::MousePressed(MouseButton::LEFT))
	{
		if (!hasClicked)
		{
			for (int i = 0; i < pieces.size(); i++)
			{
				if (pieces[i]->rect.x == Input::MouseX() - (Input::MouseX() % tileSize) && pieces[i]->rect.y == Input::MouseY() - (Input::MouseY() % tileSize))
				{
					pieces[i]->initialXPos = pieces[i]->rect.x;
					pieces[i]->initialYPos = pieces[i]->rect.y;
					pieces[i]->isSelected = true;
					tempPieceNr = i;
					hasClicked = true;
				}
			}
		}
		else
		{
			for (int i = 0; i < pieces.size(); i++)
			{
				if (pieces[i]->isSelected)
				{
					pieces[i]->rect.x = Input::MouseX() - (Input::MouseX() % tileSize);
					pieces[i]->rect.y = Input::MouseY() - (Input::MouseY() % tileSize);
					boardArray[Input::MouseY() - (Input::MouseY() % tileSize)][Input::MouseX() - (Input::MouseX() % tileSize)] = pieces[i]->type;
				}
				if (CheckForCapture())
				{
					if (pieces[i]->CapturePiece(pieces, Input::MouseX() - (Input::MouseX() % tileSize), Input::MouseY() - (Input::MouseY() % tileSize), i) && !IsSameColor(i))
					{
						pieces.erase(pieces.begin() + i);
					}
					CheckForSuicide(i);
				}
				pieces[i]->isSelected = false;
				hasClicked = false;
			}
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

void Board::CheckForSuicide(int i)
{
	bool test = pieces[tempPieceNr]->CapturePiece(pieces, Input::MouseX() - (Input::MouseX() % tileSize), Input::MouseY() - (Input::MouseY() % tileSize), tempPieceNr);
	bool test2 = IsSameColor(i);
	bool test3 = pieces[tempPieceNr]->isWhite && pieces[i]->isWhite;
	if (pieces[i]->CapturePiece(pieces, Input::MouseX() - (Input::MouseX() % tileSize), Input::MouseY() - (Input::MouseY() % tileSize), i) && IsSameColor(i))
	{
		pieces[tempPieceNr]->rect.x = pieces[tempPieceNr]->initialXPos;
		pieces[tempPieceNr]->rect.y = pieces[tempPieceNr]->initialYPos;
	}
	std::cout << test << "\n" << test2;
}

bool Board::CheckForCapture()
{
	if (boardArray[Input::MouseY() - (Input::MouseY() % tileSize)][Input::MouseX() - (Input::MouseX() % tileSize)] != 0)
	{
		return true;
	}
	return false;
}

bool Board::IsSameColor(int i)
{
	if (pieces[tempPieceNr]->isWhite && !pieces[i]->isWhite || !pieces[tempPieceNr]->isWhite && pieces[i]->isWhite)
	{
		return false;
	}
	return true;
}


