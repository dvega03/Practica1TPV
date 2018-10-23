#pragma once
#include "Block.h"
#include <string>
#include <fstream>

using namespace std;


class BlocksMap
{
private:
	Block*** map;
	int _width;
	int _heigth;

	int _pxWidth;
	int _pxHeigth;

	int _pxCellWidth;
	int _pxCellHeigth;

	void setCell(int numCols, int numRows);

	void setColor(int color , int& x, int& y);

public:

	BlocksMap(SDL_Renderer*& r, string filenameTxt, string filenameBlocks, int pxWidth, int pxHeigth);
	void LoadMap(SDL_Renderer*& r, string& filenameBlocks, string filenameTxt);
	void renderMap();
	~BlocksMap();
};

