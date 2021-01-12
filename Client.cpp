#include "Client.h"

Client::Client()
{

}

void Client::set(SDL_Event &event,SDL_Renderer * renderer, Astar & a)
{
	//gest mouse position with offset
	if(event.type == SDL_MOUSEMOTION)
	{
		_x = event.motion.x / MUL;
		_y = event.motion.y / MUL;
	}
	
	//on key down
	if(event.type == SDL_KEYDOWN)
	{
		switch(event.key.keysym.sym)
		{
			//places obstacle  at mouse location : W
			case SDLK_w:
			{
				a.obstacle(_x,_y);
			}
			break;
			
			//remove Obstacles at mouse location
			case SDLK_t:
			{
				a.removeObstacle(_x,_y);
			}
			break;
			
			//set start at mouse location
			case SDLK_s:
			{
				a.start(_x,_y);
			}
			break;
			
			//sets end location at mouse location
			case SDLK_g:
			{
				a.goal(_x,_y);
			}
			break;
			
			//prints out grid attributes for debuging
			case SDLK_d:
			{
				a._grid->_grid[_x][_y]->print();
			}
			break;
			
			case SDLK_c:
			{
				a.clear();
			}
			break;
			
			//runs the search algorithm
			case SDLK_RETURN:
			{
				a.search(renderer);
			}
			break;
		}
	}
}

//draw grid
void Client::draw(SDL_Renderer * renderer,Astar & a)
{
	a.draw(renderer);
}
