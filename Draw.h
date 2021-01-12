#ifndef _DRAW_H_
#define _DRAW_H_

#include <SDL2/SDL.h>
#include "Rect.h"
#include "Grid.h"

class Draw
{
	public:
		//default constructor
		Draw();
		
		//non default constructor
		Draw(Grid *,int);
		
		//destructor
		~Draw();
		
		//sets color of node depending on status
		void setColor(Node * start,Node * goal,std::vector<Node *> open,std::vector<Node *> close, std::vector<Node *> obstacle, std::vector<Node *> path);
		
		//sets size multiplier
		void setSize();
		
		//draw draws grid with color
		void drawGrid(SDL_Renderer * renderer,Node * start,Node * goal,std::vector<Node *> open,std::vector<Node *> close, std::vector<Node *> obstacle,std::vector<Node *> path);
		
		//draw grid without color
		void draw(SDL_Renderer * renderer);
		
		//size multiplier
		int _size;
		
		//_grid
		Grid * _grid;
		
		//array of rect
		Rect ** _rect;
};

#endif