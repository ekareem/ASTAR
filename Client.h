#ifndef _CLIENT_H_
#define _CLIENT_H_

#include "Astar.h"

class Client
{
	public:
		//client
		Client();
		
		//event handeler
		void set(SDL_Event &event,SDL_Renderer * renderer,Astar & a);
		
		//draws A Star table
		void draw(SDL_Renderer * renderer,Astar & a);
		
		int _x;
		int _y;
};

#endif