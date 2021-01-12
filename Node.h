#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
#include <Math.h>

class  Node
{
	public:
		//constructor
		Node();
	
		//non default constructor
		Node(int x,int y);
		
		//non default constuctor
		Node(int x,int y,Node * goal);
		
		//destructor
		~Node();
		
		//parents and goal
		Node * _parent;
		Node * _goal;
	
		//distance from node to start
		int g();
		
		//distance from node to goal
		int h();
		
		//g cost +  h cost
		int f();
		
		//set goal
		void goal(Node *);
		
		//sets parent
		void parent(Node *);
		
		//set walkable value
		void walkable(bool);
		
		//print node attribuites
		void print();
		
		//position
		int _x, _y;
		
		//walkable
		bool _walkable;
};

#endif
