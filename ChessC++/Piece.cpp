#include "Piece.h"
#include <string>

Piece::Piece(Window* window, int xPos, int yPos, bool isWhite, const char* path)
{
	this->window = window;
	this->isWhite = isWhite;
	whitePieces[15] = path;
	surface = IMG_Load(path);
	tex = SDL_CreateTextureFromSurface(window->GetRender(), surface);
	rect = { xPos, yPos, 74, 74 };
}

Piece::~Piece()
{
	SDL_DestroyTexture(tex);
	SDL_FreeSurface(surface);
}

void Piece::LoadPieces(int tileSize)
{
	SDL_Rect position = { type * tileSize, type * tileSize, tileSize, tileSize };
	SDL_RenderCopy(window->GetRender(), tex, NULL, &position);
}

const char* Piece::GetPiece()
{
	//return std::string("Assets/" + std::string((isWhite ? "White" : "Black")) + "Tower" + ".png").c_str();
	return "Assets/WhiteTower.png";
}