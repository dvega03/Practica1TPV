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

public:

	BlocksMap(SDL_Renderer*& r ,string filename, string filenameBlocks, int pcWidth, int pxHeigth);
	void LoadMap(SDL_Renderer*& r ,ifstream& inputmap, string& filenameBlocks);
	~BlocksMap();
};

