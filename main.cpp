#include "Client.h"
#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char* argv[])
{
    std::cout<<"KEY 	- Function"<<std::endl;
    std::cout<<"S 		- set a starting point"<<std::endl;
    std::cout<<"G 		- set a goal"<<std::endl;
    std::cout<<"W 		- set an obstacle"<<std::endl;
    std::cout<<"T 		- remove obstacle"<<std::endl;
    std::cout<<"C 		- clear all"<<std::endl;
    std::cout<<"ENTER 	- shows realtime searching"<<std::endl;

    if (SDL_Init(SDL_INIT_VIDEO) == 0)
	{
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;
		
		Client c;
		Astar a(33, 26);
		
        if (SDL_CreateWindowAndRenderer(660, 520, 0, &window, &renderer) == 0) 
		{
            SDL_bool done = SDL_FALSE;

            while (!done)
			{
                SDL_Event event;
				
				
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);
				
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
				
				a.search(nullptr);
				c.draw(renderer,a);
				
				
                SDL_RenderPresent(renderer);
				
				
				
                while (SDL_PollEvent(&event)) 
				{
                    if (event.type == SDL_QUIT)
                        done = SDL_TRUE;
					c.set(event,renderer,a);
                }
            }
        }

        if (renderer) 
            SDL_DestroyRenderer(renderer);
    
        if (window)
            SDL_DestroyWindow(window);
    
    }
    SDL_Quit();
    return 0;
}
