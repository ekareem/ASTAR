#ifndef _GRID_H_
#define _GRID_H_

#include <vector>
#include <algorithm>
#include "Node.h"

class Grid
{
	public:
		//default constuctor
		Grid();
		
		//non default constuctor
		Grid(int,int);
		
		//destructor
		~Grid();
		
		//initilize grids
		void init();
		
		//reset the parents of all node to nullptrs
		void resetParent();
		
		//setGoald of all node
		void setGoal(Node * goal);
		
		//checks if point is in grid
		bool inGrid(int,int);
		
		//gets the naighbouring node for a spcific Node
		std::vector<Node *> neighbour(Node *);
		
		//prints grid
		void print();
		
		//dimention
		int _l;
		int _h;
	
		//2d array of grid
		Node *** _grid;
};

#endif
