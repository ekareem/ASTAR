// -*- c++ -*-
// $id: Rect.h 12-20-2019 
// Purpose: create a Rectangle shape class of SDL

#ifndef _RECT_H_
#define _RECT_H_
#include <algorithm>
#include <iostream>
#include <SDL2/SDL.h>

class Rect
{
	public:
		//Default constructor
		Rect();

		//non Defualt constuctor
		Rect(float x1, float y1, float x2, float y2);

		Rect(float x1, float y1, float x2, float y2,int r,int g, int b);
		//Copy constructor
		Rect(const Rect & rect);
		
	    /**
		* Assignment operation
		* @param[in]	Rect
		* @param[out]	This
		*/
		const Rect& operator = (const Rect & rect);
		
		/**
		* draws triangle shape
		* @param[in]	SDL_Renderer *
		*/
		void draw (SDL_Renderer * renderer);
		/**
		* fills rect with color
		* @param[in]	int,int,int
		*/
		void fill(SDL_Renderer * renderer, int r, int g, int b);
		
		void fill(SDL_Renderer * renderer);
		/**
		* checks if rectangles overlaps with rect
		* @param[in]	Rect &
		* @param[out]	bool
		*/
		
		bool overlap (Rect & r2) const;
		bool overlap (Rect & r1, Rect & r2) const;
		
		/**
		* findes the union Rectangle between two rectangles
		* @param[in]	Rect
		* @param[out]	Rect
		*/
		Rect unionRect (Rect & r2) const;
		Rect unionRect (Rect & r1, Rect R2) const;
		
		/**
		* cheks if point is in rect
		* @param[in]	float,float
		* @param[out]	boolÎ
		*/
		bool pointInRect(float x, float y) const;
		
		//setters
		void setAttributes(float x1, float y1, float x2, float y2);
		void setColor(int r, int g , int b);
		void x1(float x1);
		void y1(float y2);
		void x2(float x2);
		void y2(float y2);
		
		//getters
		float x1();
	    float y1();
		float x2();
		float y2();
	private:
		//points
		float _x1, _y1, _x2 , _y2;
		int _r, _g ,_b;
};
#endif
