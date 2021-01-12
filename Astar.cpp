#include  "Astar.h"

Astar::Astar()
	:_start(nullptr),
	 _goal(nullptr),
	 _grid(new Grid()),
	 _draw(Draw(_grid,MUL))
{
}

Astar::Astar(int l , int h)
	:_start(nullptr),
	_goal(nullptr),
	_grid(new Grid(l,h))
{
	_draw = Draw(_grid,MUL);
}

Astar::~Astar()
{
	delete _grid;
}

void Astar::clear()
{
	_open.clear();
	_close.clear();
	_path.clear();
	
	for( auto curr : _obstacle)
		curr->walkable(true);
	
	_obstacle.clear();
	
	_grid->resetParent();
	_start =  nullptr;
	_goal = nullptr;
}

void Astar::obstacle(int x, int y)
{
	//exit if Node already in obstacel list
	for( auto curr : _obstacle)
	{
		if(curr->_x == x && curr->_y == y){
			return;
		}
	}
	
	
	//if position is same has goal or start do not set obstacle
	if (_start != nullptr && _start->_x == x && _start->_y == y)
		return;
	
	if (_goal != nullptr && _goal->_x == x && _goal->_y == y)
		return;
	
	//push node to obstacel list
	if(_grid->inGrid(x,y))
	{
		_grid->_grid[x][y]->walkable(false);
		_obstacle.push_back(_grid->_grid[x][y]);
	}
}

void Astar::removeObstacle(int x ,int y)
{
	if(_grid->inGrid(x,y))
	{
		_grid->_grid[x][y]->walkable(true);
		
		int i = 0;
		bool obstacle= false;
		
		//if obstacle not in list
		for( auto curr : _obstacle)
		{
			if(curr->_x == x && curr->_y == y){
				obstacle = true;
				break;
			}
			i++;
		}
		if(obstacle == true)
		_obstacle.erase(_obstacle.begin() + i);
	}
}

void Astar::start(int x, int y)
{
	if(_grid->inGrid(x,y))
	{
		for( auto curr : _obstacle)
			if(curr->_x == x && curr->_y == y)
				return;
			
		_start = _grid->_grid[x][y];
	}
}

void Astar::goal(int x, int y)
{
	if(_grid->inGrid(x,y))
	{
		for( auto curr : _obstacle)
			if(curr->_x == x && curr->_y == y)
				return;
			
		_goal = _grid->_grid[x][y];
		_grid->setGoal(_goal);
	}
}

bool Astar::search(SDL_Renderer * renderer)
{
	//reset grid states
	_open.clear();
	_close.clear();
	_path.clear();
	_grid->resetParent();
	
	//if goal or start has not been set return false
	if (_start == nullptr || _goal == nullptr)
		return false;
	
	//push start to opne list
	_open.push_back(_start);
	Node * curr = nullptr;
	std::vector<Node *> neighbour;
	int i = 0;
	while(true)
	{
		//if no node in open return false
		if(_open.size() == 0)
			return false;
		
		//push lowest f cost from open to close and set it to cutt
		curr = lowestF();
		_open.erase(_open.begin() + openIndex(curr));
		_close.push_back(curr);
		
		//shows process
		if(renderer != nullptr)
		{
			draw(renderer);
			SDL_RenderPresent(renderer);
		}
		
		//if curr is gool trace path and push to path list
		if(curr == _goal){
			
			Node * temp  = curr;
			while(temp != nullptr)
			{
				_path.push_back(temp);
				temp = temp->_parent;
			}
			return true;
		}
	
		//get  neighbout nod of curr
		neighbour = _grid->neighbour(curr);
		
		for(auto c : neighbour)
		{
			if(c->_walkable && !isClosed(c))
			{
				if(isShorter(curr,c) || !isOpen(c))
				{
					c->_parent = curr;
					if(!isOpen(c))
						_open.push_back(c);
				}
			}
		
		}

	}
	
	return false;
}

void Astar::draw(SDL_Renderer * renderer)
{
	_draw.drawGrid(renderer,_start,_goal,_open,_close,_obstacle,_path);
}

Node * Astar::lowestF()
{
	Node * lowest = nullptr;
	int f = INT_MAX;
	int h = INT_MAX;
	
	for(auto & curr : _open)
		if(curr->f() <= f && curr->h() <= h)
		{
			f = curr->f();
			h = curr->h();
			lowest = curr;
		}

	return lowest;
}

int Astar::openIndex(Node * node)
{
	int i = 0;
	for( auto curr : _open)
	{
		if(curr->_x == node->_x && curr->_y == node->_y)
			return i;
		i++;
	}

	return -1;
}

bool Astar::isClosed(Node * node)
{
	for( auto curr: _close)
	{
		if(curr->_x == node ->_x && curr->_y == node->_y)
			return true;
	}
	return false;
}

bool Astar::isOpen(Node * node)
{
	for( auto curr: _open)
	{
		if(curr->_x == node ->_x && curr->_y == node->_y)
			return true;
	}
	return false;
}

bool Astar::isShorter(Node * curr, Node * node)
{
	int g = sqrt((curr->_x - node->_x) * (curr->_x -node->_x) + (curr->_y - node->_y) * (curr->_y - node->_y)) * 10 + curr->g()	;
	int h = node->h();
	int f = g + h;
	
	return f < node->f();
}

void Astar::print()
{
	if(_start == nullptr)
		std::cout<<"start: nullptr"<<std::endl;
	else
		std::cout<<"start: Node["<<_start->_x<<"]"<<"["<<_start->_y<<"]"<<std::endl;
	if(_goal == nullptr)
		std::cout<<"goal: nullptr"<<std::endl;
	else
		std::cout<<"goal : Node["<<_goal->_x<<"]"<<"["<<_goal->_y<<"]"<<std::endl;
	_grid->print();
}