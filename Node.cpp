#include "Node.h"

Node::Node()
	:_goal(nullptr),
	_parent(nullptr),
	_walkable(true)
{

}

Node::Node(int x , int y)
	:_x(x),
	_y(y),
	_goal(nullptr),
	_parent(nullptr),
	_walkable(true)
{
	
}

Node::Node(int x, int y, Node * goal)
	:_x(x),
	_y(y),
	_goal(goal),
	_parent(nullptr),
	_walkable(true)
{

}

void Node::walkable(bool state)
{
	_walkable = state;
}

Node::~Node()
{
	if(_parent != nullptr)
		delete _parent;
	if(_goal != nullptr)
		delete _goal;
}

void Node::parent(Node * g)
{
	if(_walkable)
		_parent = g;
}

void Node::goal(Node * g)
{
	if(_walkable)
		_goal = g;	
}

int Node::g()
{
	if(_walkable)
	{
		if(_parent == nullptr)
			return 0;
		int distance = sqrt((_parent->_x - _x) * (_parent->_x -_x) + (_parent->_y - _y) * (_parent->_y - _y)) * 10;
	return distance + _parent->g();
	}
	return -1;
}

int Node::h()
{
	if(_walkable && _goal != nullptr)
			return sqrt((_goal->_x - _x) * (_goal->_x - _x) + (_goal->_y - _y) * (_goal->_y-_y)) * 10;
	return -1;
}

int Node::f()
{
	if(_walkable)
		return g() + h();
	return -1;
}

void Node::print()
{
	
	std::cout<<"Node["<<_x<<"]"<<"["<<_y<<"] ";
	
	
	if(_parent == nullptr)
		std::cout<<"_parent: nullptr ";
	else
		std::cout<<"_parent: Node["<<_parent->_x<<"]"<<"["<<_parent->_y<<"] ";
	
	if(_goal == nullptr)
		std::cout<<"_goal: nullptr ";
	else
		std::cout<<"_goal: Node["<<_goal->_x<<"]"<<"["<<_goal->_y<<"] ";
	
	std::cout<<"g: "<< g() <<" h: "<< h() <<" f: "<< f();
	
	std::cout<<" walkable: "<<_walkable<<std::endl;
}

