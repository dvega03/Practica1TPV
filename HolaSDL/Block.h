#pragma once
#include "Vector2D.h"
#include "Texture.h"
using namespace std;




class Block
{

private:
	Vector2D _posicion = Vector2D(0,0);
	int _width;
	int _heigth;
	int _color;
	int _frame;
	int _row;
	int _column;
	Texture* _texture;
	

public:
	Block(Texture*& texture, Vector2D posicion);
	void render(const SDL_Rect& destRect, SDL_RendererFlip flip) const;
	~Block();
};

