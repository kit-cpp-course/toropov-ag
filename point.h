#pragma once

/**
* Класс, описывающий точку
*/
class point
{
public:
	point();
	point(double x, double y);
	~point();
	/**
	* Возвращает длину между точками
	*
	* @param point a, point b две точки
	* @returns длина  отрезка между точками
	*/
	double distanceTo(point a, point b);
private:
	/**
	* Кординаты x, y
	*/
	double x, y;
};


