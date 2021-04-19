#include "Board.h"
#include "Input.h"


Board::Board(Window* window)
{
	this->window = window;
	pieces.push_back(new Piece(window, 0 * tileSize, 7 * tileSize, pieceType::Rook, true, piecePath[0]));
	pieces.push_back(new Piece(window, 1 * tileSize, 7 * tileSize, pieceType::Knight, true, piecePath[1]));
	pieces.push_back(new Piece(window, 2 * tileSize, 7 * tileSize, pieceType::Bishop, true, piecePath[2]));
	pieces.push_back(new Piece(window, 3 * tileSize, 7 * tileSize, pieceType::Queen, true, piecePath[4]));
	pieces.push_back(new Piece(window, 4 * tileSize, 7 * tileSize, pieceType::King, true, piecePath[3]));
	pieces.push_back(new Piece(window, 5 * tileSize, 7 * tileSize, pieceType::Bishop, true, piecePath[2]));
	pieces.push_back(new Piece(window, 6 * tileSize, 7 * tileSize, pieceType::Knight, true, piecePath[1]));
	pieces.push_back(new Piece(window, 7 * tileSize, 7 * tileSize, pieceType::Rook, true, piecePath[0]));

	pieces.push_back(new Piece(window, 0 * tileSize, 0 * tileSize, pieceType::Rook, false, piecePath[6]));
	pieces.push_back(new Piece(window, 1 * tileSize, 0 * tileSize, pieceType::Knight, false, piecePath[7]));
	pieces.push_back(new Piece(window, 2 * tileSize, 0 * tileSize, pieceType::Bishop, false, piecePath[8]));
	pieces.push_back(new Piece(window, 3 * tileSize, 0 * tileSize, pieceType::Queen, false, piecePath[10]));
	pieces.push_back(new Piece(window, 4 * tileSize, 0 * tileSize, pieceType::King, false, piecePath[9]));
	pieces.push_back(new Piece(window, 5 * tileSize, 0 * tileSize, pieceType::Bishop, false, piecePath[8]));
	pieces.push_back(new Piece(window, 6 * tileSize, 0 * tileSize, pieceType::Knight, false, piecePath[7]));
	pieces.push_back(new Piece(window, 7 * tileSize, 0 * tileSize, pieceType::Rook, false, piecePath[6]));
	for (int i = 0; i < 8; i++)
	{
		pieces.push_back(new Piece(window, i * tileSize, 6 * tileSize, pieceType::Pawn, true, piecePath[5]));
		pieces.push_back(new Piece(window, i * tileSize, 1 * tileSize, pieceType::Pawn, false, piecePath[11]));
	}
}

Board::~Board()
{

}

void Board::DrawBoard()
{
	int test = boardArray[Input::MouseY() - (Input::MouseY() % tileSize)][Input::MouseX() - (Input::MouseX() % tileSize)];
	std::cout << test << "\n";
	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
		{
			//boardArray[r][c] = 0;
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
	//boardRect = { clickRectX, clickRectY, tileSize, tileSize };
	if (boardArray[Input::MouseY() - (Input::MouseY() % tileSize)][Input::MouseX() - (Input::MouseX() % tileSize)] != 0)
	{
		boardRect = { Input::MouseX() - (Input::MouseX() % tileSize), Input::MouseY() - (Input::MouseY() % tileSize), tileSize, tileSize };
		SDL_SetRenderDrawColor(window->GetRender(), 255, 0, 0, 255);
		SDL_RenderFillRect(window->GetRender(), &boardRect);
	}
}

void Board::DrawPieces()
{
	for (int i = 0; i < pieces.size(); i++)
	{
		//boardArray[pieces[i]->rect.y / tileSize][pieces[i]->rect.x / tileSize] = static_cast<int>(pieces[i]->type);
		SDL_RenderCopy(window->GetRender(), pieces[i]->tex, NULL, &pieces[i]->rect);
	}
}

void Board::DrawHighlighter()
{
	/*if (isClicked)
	{
		boardRect = { clickRectX, clickRectY, tileSize, tileSize };
		SDL_SetRenderDrawColor(window->GetRender(), 255, 0, 0, 255);
		SDL_RenderFillRect(window->GetRender(), &boardRect);
	}*/
}
