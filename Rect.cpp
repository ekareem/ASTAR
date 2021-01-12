//-*_ c++ -*-
//$id: Rect.cpp

#include "Rect.h"

Rect::Rect()
	:_r(225),
	_g(225),
	_b(225)
{

}

Rect::Rect(float x1, float y1, float x2, float y2)
	:_x1(x1),
	_y1(y1),
	_x2(x2),
	_y2(y2),
	_r(225),
	_g(225),
	_b(225)
{
}

Rect::Rect(float x1, float y1, float x2, float y2,int r,int g, int b)
	:_x1(x1),
	_y1(y1),
	_x2(x2),
	_y2(y2),
	_r(r),
	_g(g),
	_b(b)
{
}

Rect::Rect(const Rect & rect)
	:_x1(rect._x1),
	_y1(rect._y1),
	_x2(rect._x2),
	_y2(rect._y2),
	_r(225),
	_g(225),
	_b(225)
{
}

const Rect& Rect::operator = (const Rect & rect)
{
	_x1 = rect._x1;
	_y1 = rect._y1;
	_x2 = rect._x2;
	_y2 = rect._y2;
	return *this;
}

void Rect::draw(SDL_Renderer * renderer)
{
	SDL_SetRenderDrawColor(renderer, _r,_g,_b,225);
	SDL_RenderDrawLine(renderer,_x1,_y1,_x2,_y1);
	SDL_RenderDrawLine(renderer,_x1,_y2,_x2,_y2);
	SDL_RenderDrawLine(renderer,_x1,_y1,_x1,_y2);
	SDL_RenderDrawLine(renderer,_x2,_y1,_x2,_y2);
}

void Rect::fill(SDL_Renderer * renderer, int r, int g, int b)
{
	SDL_SetRenderDrawColor(renderer, r,g,b,225);
	for(float i = 0; i <= _y2 - _y1; i++)
		SDL_RenderDrawLine(renderer,_x1,_y1 + i, _x2, _y1 + i);
}

void Rect::fill(SDL_Renderer * renderer)
{
	SDL_SetRenderDrawColor(renderer, _r,_g,_b,225);
	for(float i = 0; i <= _y2 - _y1; i++)
		SDL_RenderDrawLine(renderer,_x1,_y1 + i, _x2, _y1 + i);
}

bool Rect::overlap(Rect & r2) const
{
	if(_x1 > r2._x2 || r2._x1 > _x2)
		return false;
	if(_y1 > r2._y2 || r2._y1 > _y2)
		return false;
	return true;
}

bool Rect::overlap(Rect & r1, Rect & r2) const
{
	if(r1._x1 > r2._x2 || r2._x1 > r1._x2)
		return false;
	if(r1._y1 > r2._y2 || r2._y1 > r1._y2)
		return false;
	return true;
}

Rect Rect::unionRect(Rect & r2) const
{
	float x1 = std::max(_x1, r2._x1);
	float y1 = std::max(_y1, r2._y1);
	float x2 = std::max(_x2, r2._x2);
	float y2 = std::min(_y2, r2._y2);

	return Rect(x1,x2,x2-x1,y2-y1);
}

Rect Rect::unionRect (Rect & r1, Rect r2) const
{
	float x1 = std::max(r1._x1, r2._x1);
	float y1 = std::max(r1._y1, r2._y1);
	float x2 = std::max(r1._x2, r2._x2);
	float y2 = std::min(r1._y2, r2._y2);

	return Rect(x1,x2,x2-x1,y2-y1);
}

void Rect::setAttributes(float x1, float y1, float x2, float y2)
{
	_x1 = x1;
	_y1 = y1;
	_x2 = x2;
	_y2 = y2;
}

void Rect::setColor(int r, int g, int b)
{
	_r = r;
	_g = g;
	_b = b;
}

void Rect::x1(float x1)
{
	_x1 = x1;
}

void Rect::y1(float y1)
{
	_y1 = y1;
}

void Rect::x2(float x2)
{
	_x2 = x2;
}

void Rect::y2(float y2)
{
	_y2 = y2;
}

float Rect::x1()
{
	return _x1;
}

float Rect::y1()
{
	return _y1;
}

float Rect::x2()
{
	return _x2;
}
float Rect::y2()
{
	return _y2;
}
