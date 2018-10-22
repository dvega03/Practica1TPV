#include "Block.h"



Block::Block(Texture*& texture, Vector2D posicion)
{
	_posicion = posicion;
	_texture = texture;
	_width = _texture->getW();
	_heigth = _texture->getH();
	_frame = 0;
	_row = _column = 0;
}

void Block::render(const SDL_Rect& destRect, SDL_RendererFlip flip) const
{
	_texture->render(destRect, flip);
}


Block::~Block()
{
}
