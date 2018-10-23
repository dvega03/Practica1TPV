#include "BlocksMap.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
typedef unsigned int uint;

BlocksMap::BlocksMap(SDL_Renderer*& r,string filenameTxt, string filenameBlocks, int pxWidth, int pxHeigth)
{
	_pxWidth = pxWidth;
	_pxHeigth = pxHeigth;

	ifstream inputMap;

	inputMap.open(filenameTxt);

	if (!inputMap.is_open()) throw("No se ha encontrado el fichero " + filenameTxt);
	else
	{
		inputMap >> _heigth;
		inputMap >> _width;
	}

	inputMap.close();

	map = new Block**[_heigth];

	for (int i = 0; i < _heigth; i++)
	{
		map[i] = new Block*[_heigth];

		for (int j = 0; j < _width; j++)
		{
			Block* b;
			map[i][j] = b;
		}
	}
	
	
}

void BlocksMap::setCell(int numCols, int numRows)
{
	_pxCellHeigth = _pxHeigth / numRows;
	_pxCellHeigth = _pxWidth / numCols;
}


void BlocksMap::LoadMap(SDL_Renderer*& r ,ifstream& inputmap, string& filenameBlocks)
{
	string line;

	for (int i = 0; i < _heigth; i++)
	{

		getline(inputmap, line);

		for (int j = 0; j < _width; j++)
		{
			int color = line[j];

			Texture* t = new Texture(r,filenameBlocks, 2,3);
			Vector2D v = Vector2D((double)i * _pxCellHeigth,(double) j * _pxCellWidth);

			map[i][j] = &Block(t, v);
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
