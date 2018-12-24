#pragma once
#include <cmath>

/**
* �����, ����������� �����
*/
class point
{
public:
	point();
	point(double x, double y);
	~point();
	/**
	* ��������� x, y
	*/
	double x, y;
	/**
	* ���������� ����� ����� �������
	*
	* @param point a, point b ��� �����
	* @returns �����  ������� ����� �������
	*/
	double distanceTo(point a, point b);
};

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
