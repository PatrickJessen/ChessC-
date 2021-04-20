#include "Piece.h"
#include <string>

Piece::Piece(Window* window, int xPos, int yPos, pieceType type, bool isWhite, std::vector<Vector2D*> possiblePositions, const char* path)
{
	this->window = window;
	this->isWhite = isWhite;
	this->type = type;
	this->possibleMoves = possiblePositions;
	isSelected = false;
	piecePath[11] = path;
	surface = IMG_Load(path);
	tex = SDL_CreateTextureFromSurface(window->GetRender(), surface);
	rect = { xPos, yPos, 90, 90 };
	gridPosX = xPos / 90;
	gridPosY = yPos / 90;
}

Piece::~Piece()
{
	SDL_DestroyTexture(tex);
	SDL_FreeSurface(surface);
}

Piece* Piece::GetPiece(std::vector<Piece*> pieces, int x, int y)
{
	for (int i = 0; i < pieces.size(); i++)
	{
		if (pieces[i]->gridPosX == x && pieces[i]->gridPosY == y)
		{
			return pieces[i];
		}
	}
	return 0;
}

bool Piece::CapturePiece(std::vector<Piece*> pieces, int xPos, int yPos, int index)
{
	if (pieces[index]->rect.x == xPos && pieces[index]->rect.y == yPos)
	{
		return true;
	}
	return false;
}

void Piece::ShowAvailableMoves(Piece* clickedPiece, int board, SDL_Rect &rect)
{
	
}

