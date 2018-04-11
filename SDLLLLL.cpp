#include <stdio.h>
#include <SDL.h>

#undef main
int main(int a, char* b[])
{

	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Surface* tempSurface = NULL;
	SDL_Texture* texture = NULL;
	SDL_Event mainEvent;
	SDL_Rect sourceRect;
	SDL_Rect desRect;
	bool isRunning = true;

	//initializes  the subsystems
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("Unable to initialize SDL %s\n", SDL_GetError());
		return -1;
	}

	//Create window
	window = SDL_CreateWindow("Gameetbfffft", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Could not create window %s", SDL_GetError());
		return -1;
	}


	//create a renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		printf("Could not create render %s", SDL_GetError());
		return -1;
	}

	//create a tempSurface
	tempSurface = SDL_LoadBMP("images.bmp");
	//create a texutre from surface
	texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	//free surface
	SDL_FreeSurface(tempSurface);


	SDL_QueryTexture(texture, NULL, NULL, &sourceRect.w, &sourceRect.h);

	sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = sourceRect.w / 2;
	sourceRect.h = sourceRect.h / 2;

	desRect.x = 200;
	desRect.y = 200;
	desRect.w = sourceRect.w;
	desRect.h = sourceRect.h;

	//set background color
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	//main loop
	while (isRunning)
	{
		// clear the window to black
		SDL_RenderClear(renderer);
		//main event
		while (SDL_PollEvent(&mainEvent))
		{
			switch (mainEvent.type)
			{
				//User - requested quit
				case SDL_QUIT:
				{
					isRunning = false;
					break;
				}
				default:
				{
					break;
				}
			}
		}

		// copy a portion of the texture to the current rendering target.
		SDL_RenderCopy(renderer, texture, &sourceRect, NULL);
		//draw to the screen
		SDL_RenderPresent(renderer);
	}

	//Destroy a window.
	SDL_DestroyWindow(window);

	//Destroy a renderer
	SDL_DestroyRenderer(renderer);

	//cleans up all initialized subsystems
	SDL_Quit();
	return 0;
}
