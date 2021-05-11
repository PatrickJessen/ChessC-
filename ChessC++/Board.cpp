#include "Board.h"
#include "Input.h"


Board::Board(Window* window)
{
	this->window = window;
	bool hasPlaced = false;
	for (int i = 1, j = 0; j < 8; j++)
	{

		pieces.push_back(new Piece(window, tileSize, (PieceType)i, true, j, 7));
		pieces.push_back(new Piece(window, tileSize, PieceType::Pawn, true, j, 6));

		pieces.push_back(new Piece(window, tileSize, (PieceType)i, false, j, 0));
		pieces.push_back(new Piece(window, tileSize, PieceType::Pawn, false, j, 1));


		// to reuse enum pieces rook knight and bishop	
		if (!hasPlaced && i != 6)
		{
			i++;
		}
		if (i == 6)
		{
			hasPlaced = true;
			i = 4;
		}
		if (hasPlaced && i != 1)
		{
			i--;
		}
	}
}

Board::~Board()
{

}

bool Board::IsPieceWhite()
{
	for (int i = 0; i < pieces.size(); i++)
	{
		if (pieces[i]->GetRect().x == GetClickedPosX() && pieces[i]->GetRect().y == GetClickedPosY())
		{
			if (pieces[i]->IsWhite())
			{
				return true;
			}
			return false;
		}
	}
	return false;
}

int Board::GetClickedPosX()
{
	return Input::MouseX() - (Input::MouseX() % tileSize);
}

int Board::GetClickedPosY()
{
	return Input::MouseY() - (Input::MouseY() % tileSize);
}
