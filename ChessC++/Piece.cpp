#include "Piece.h"
#include <string>

Piece::Piece(Window* window)
{
	this->window = window;
}

void Piece::DrawPiece()
{

}

const std::string Piece::GetPiece()
{
	return "Assets/" + std::string((isWhite ? "white" : "black")) + std::to_string(type) + ".png";
}