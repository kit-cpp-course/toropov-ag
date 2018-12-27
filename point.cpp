#include <cmath>
#include "point.h"

point::point()
{
	x = 0;
	y = 0;
}

point::point(double x, double y)
{
	this->x = x;
	this->y = y;
}

point::~point()
{

}

double point::distanceTo(point a, point b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}