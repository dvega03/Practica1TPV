#include "BlocksMap.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
typedef unsigned int uint;

BlocksMap::BlocksMap(SDL_Renderer*& r,string filenameTxt , string filenameBlocks, int pxWidth, int pxHeigth)
{
	_pxWidth = pxWidth;
	_pxHeigth = pxHeigth;

	map = nullptr;

	LoadMap(r,filenameBlocks, filenameTxt);
	

}

void BlocksMap::setCell(int numCols, int numRows)
{
	_pxCellHeigth = _pxHeigth / numRows;
	_pxCellHeigth = _pxWidth / numCols;
}

void BlocksMap::setColor(int color, int& x, int& y)
{

	switch (color)
	{
	default:
		break;

	case 1:
		x = 0;
		y = 0;
		break;
	case 2:
		x = 1;
		y = 0;
		break;
	case 3:
		x = 2;
		y = 0;
		break;
	case 4: 
		x = 0;
		y = 1;
		break;
	case 5:
		x = 1;
		y = 1;
		break;
	case 6:
		x = 2;
		y = 2;
		break;
	}
}

void BlocksMap::LoadMap(SDL_Renderer*& r ,string& filenameBlocks, string filenameTxt)
{

	ifstream inputMap;

	inputMap.open(filenameTxt);

	if (!inputMap.is_open()) throw("No se ha encontrado el fichero " + filenameTxt);
	else
	{
		inputMap >> _heigth;
		inputMap >> _width;
	}

	setCell(_width, _heigth);

	string line;

	map = new Block**[_heigth];

	for (int i = 0; i < _heigth; i++)
	{
		getline(inputMap, line);
		map[i] = new Block*[_heigth];

		for (int j = 0; j < _width; j++)
		{

			Texture* t = new Texture(r, filenameBlocks, 2, 3);
			Vector2D v = Vector2D((double)i * _pxCellHeigth, (double)j * _pxCellWidth); 

			map[i][j] = &Block(t, v);
			map[i][j]->color = line[j*2];
			
		}

	}

	inputMap.close();
}

void BlocksMap::renderMap()
{
	for (int i = 0; i < _heigth; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			if (map[i][j]->color != 0)
			{
				int x = 0, y = 0;

				setColor(map[i][j]->color,x,y);

				SDL_Rect destRect;
				destRect.h = _pxCellHeigth;
				destRect.w = _pxCellWidth;
				destRect.x = j * _pxCellWidth;
				destRect.y = i * _pxCellHeigth;
				map[i][j]->renderFrame(destRect,y,x,0,SDL_FLIP_NONE);
			}
		}
	}
}

BlocksMap::~BlocksMap()
{
	for (int i = 0; i < _heigth; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			delete map[i][j];
		}

		delete map[i];
	}

	delete map;
}
