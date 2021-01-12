#ifndef _ASTAR_H_
#define _ASTAR_H_

#include <climits>
#include "Node.h"
#include "Grid.h"
#include <vector>
#include "Draw.h"
#define MUL 20

class Astar
{
	public:
		//default constructor
		Astar();
		
		//non default constructor
		Astar(int,int);
		
		//destructor
		~Astar();
		
		//clears the entire grid
		void clear();
		
		//sets obstacle at a spcified location
		void obstacle(int ,int);
		
		//remove obstacle and makes it a traversable node
		void removeObstacle(int,int);
		
		//sets start node at a spcified location
		void start(int, int);
		
		//sets goal node at a spcified location
		void goal(int, int);
		
		//find the lowest f cost form open list
		Node * lowestF();
		
		//gets the indecx of a node in _open vector
		int openIndex(Node * node);
		
		//checks is node is in closed lis
		bool isClosed(Node * node);
		
		//checks if node is in open list
		bool isOpen(Node * node);
		
		//checks if new new paath creates a lower f cost
		bool isShorter(Node * curr, Node * node);
		
		//prints grid
		void print();
		
		//Astart search algoritm
		bool search(SDL_Renderer * renderer);
		
		//draws algorithm
		void draw(SDL_Renderer * renderer);
	
		//list of open nodes
		std::vector<Node *> _open;
		
		//list of closed nodes
		std::vector<Node *> _close;
		
		//list of obstacle
		std::vector<Node *> _obstacle;
		
		//list of path
		std::vector<Node *> _path;
		
		//start  node
		Node * _start;
		
		//goal  node
		Node * _goal;
		
		//Draw 
		Draw _draw;
		
		//grid
		Grid *_grid;
};

#endif
