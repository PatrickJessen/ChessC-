#include "Piece.h"
#include <string>

Piece::Piece(Window* window, int xPos, int yPos, pieceType type, bool isWhite, const char* path)
{
	this->window = window;
	this->isWhite = isWhite;
	this->type = type;
	isSelected = false;
	piecePath[11] = path;
	surface = IMG_Load(path);
	tex = SDL_CreateTextureFromSurface(window->GetRender(), surface);
	rect = { xPos, yPos, 74, 74 };
}

Piece::~Piece()
{
	SDL_DestroyTexture(tex);
	SDL_FreeSurface(surface);
}

bool Piece::CapturePiece(std::vector<Piece*> pieces, int xPos, int yPos, int index)
{
	if (pieces[index]->rect.x == xPos && pieces[index]->rect.y == yPos)
	{
		return true;
	}
	return false;
}
