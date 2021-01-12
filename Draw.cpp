#include "Draw.h"

Draw::Draw()
{
	
}

Draw::Draw(Grid* g,int size)
	:_grid(g),
	_size(size)
{
	for(int i = 0 ; i < _grid->_l ; i++)
	{
		_rect[i] = new Rect [_grid->_h];
		for(int j = 0 ; j < _grid->_h ; j++)
			_rect[i][j] = Rect();
	}
	
	setSize();
	
}

Draw::~Draw()
{
	
}

void Draw::setColor(Node * start,Node * goal,std::vector<Node *> open,std::vector<Node *> close, std::vector<Node *> obstacle, std::vector<Node *> path)
{
	
	//reset to white
	for(int i = 0 ; i < _grid->_l ; i++)
		for(int j = 0 ; j < _grid->_h ; j++)
			_rect[i][j].setColor(225,225,225);
		
	//if in open make color green
	for(auto curr: open)
		_rect[curr->_x][curr->_y].setColor(0,204,0);
	
	//if  in close make color red
	for(auto curr: close)
		_rect[curr->_x][curr->_y].setColor(204,0,0);
	
	//if in path make color blue
	for(auto curr: path)
		_rect[curr->_x][curr->_y].setColor(0,128,255);
	
	//if obstacle make color black
	for(auto curr: obstacle)
		_rect[curr->_x][curr->_y].setColor(0,0,0);
	
	//if start make color yellow
	if(start != nullptr)
		_rect[start->_x][start->_y].setColor(225,225,0);
	
	//if gtoal make color purple 
	if(goal != nullptr)
		_rect[goal->_x][goal->_y].setColor(142,87,244);
}

void Draw::setSize()
{
	for(int i = 0 ; i < _grid->_l ; i++)
	{
		for(int j = 0 ; j < _grid->_h ; j++)
		{
			_rect[i][j].setAttributes(i * _size ,j * _size , (i + 1) * _size , (j + 1) * _size);
		}
	}
}

void Draw::draw(SDL_Renderer * renderer)
{
	for(int i = 0 ; i < _grid->_l ; i++)
	{
		for(int j = 0 ; j < _grid->_h ; j++)
		{
			_rect[i][j].fill(renderer);
		}
	}
}

void Draw::drawGrid(SDL_Renderer * renderer,Node * start,Node * goal,std::vector<Node *> open,std::vector<Node *> close, std::vector<Node *> obstacle,std::vector<Node *> path)
{
	setColor(start,goal,open,close,obstacle,path);
	
	for(int i = 0 ; i < _grid->_l ; i++)
	{
		for(int j = 0 ; j < _grid->_h ; j++)
		{
			_rect[i][j].fill(renderer);
		}
	}
}
