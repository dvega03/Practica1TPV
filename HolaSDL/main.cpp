
#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include "BlocksMap.h"
#include <iostream>

using namespace std;

using uint = unsigned int;



int main(int argc, char* argv[]) {



	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	const uint winWidth = 800;
	const uint winHeight = 600;
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("First test with SDL", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, winWidth, winHeight, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr)
		cout << "Error cargando SDL" << endl;
	else
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		string filenameTxt = "mapas/level01.txt";
		string filenameBlocks = "images/bricks.png";

		while (SDL_GetTicks() >= 10000)
		{
			BlocksMap map = BlocksMap(renderer, filenameTxt, filenameBlocks, winWidth, winHeight);
			map.renderMap();
		}
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
	

	return 0;
}