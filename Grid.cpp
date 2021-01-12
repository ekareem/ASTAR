#include "Grid.h"

Grid::Grid()
	:_l(10),
	_h(10),
	_grid(new Node ** [_h])
{
	init();
}

Grid::Grid(int l , int h)
	:_l(l),
	_h(h),
	_grid(new Node ** [_l])
{
	init();
}

Grid::~Grid()
{
	for(int i = 0 ; i < _l ; i ++)
		for( int j = 0 ; j < _h ; j ++)
			delete _grid[i][j];
}

void Grid::init()
{
	for(int i = 0 ; i < _l ; i++)
	{
		_grid[i] = new Node * [_h];
		for(int j = 0 ; j < _h ; j++)
			_grid[i][j] = new Node(i,j);
	}
}

void Grid::resetParent()
{
	for(int i = 0 ; i < _l ; i++)
	{
		for(int j = 0 ; j < _h ; j++)
			_grid[i][j]->_parent = nullptr;
	}
}

void Grid::setGoal(Node * goal)
{
	for(int i = 0 ; i < _l ; i++)
		for(int j = 0; j < _h ; j++)
			_grid[i][j]->goal(goal);
}

bool Grid::inGrid(int x, int y)
{
	return (x >= 0 && y >=0 && x < _l && y <_h );	
}

std::vector<Node *> Grid::neighbour(Node * node)
{
	std::vector<Node*> neighbour;
	for(int i = std::max(0,node->_x-1) ; i <= std::min(node->_x + 1, _l) ; i++)
		for( int j = std::max(0, node->_y-1) ; j <= std::min(node->_y + 1, _h) ; j++)
			if( (i != node->_x || j != node->_y) && inGrid(i,j) )
				neighbour.push_back(_grid[i][j]);
	return neighbour;
}

void Grid::print()
{
	for(int i = 0 ; i < _l ; i++)
		for(int j = 0; j < _h ; j ++)
			_grid[i][j]->print();
}
