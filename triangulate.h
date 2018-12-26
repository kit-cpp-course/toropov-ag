#pragma once
#include "point.h"
#include "vector.h"
#include <cmath>

/**
* Класс, реализующий триангуляцию
*/
class triangulate : private point
{
public:
	triangulate();
	~triangulate();
	/**
	* Наиболее низкая из двух точек
	*/
	point min_py(point a, point b);

	/**
	* Наиболее высокая из двух точек
	*/
	point max_py(point a, point b);

	/**
	* Наименьшее значение
	*/
	double min(double a, double b);

	/**
	* Наибольшее значение
	*/
	double max(double a, double b);

	/**
	* Ориентированная площадь треугольника - лежит ли вершина b справа от вектора a->c
	*/
	double SAT(point a, point b, point c);

	/**
	* Знак ориентированной площади треугольника
	*/
	int sSAT(point a, point b, point c);

	/**
	* Пересечение двух отрезков, не лежащих на одной прямой
	*/
	bool is_crossing(point S0, point S1, point S2, point S3);

	/**
	* Принадлежит ли точка в многоугольнику?
	*/
	bool point_in_polygon(point t, Vector <point> p);

	/**
	* Является ли отрезок внутренней диагональю многоугольника
	*/
	bool is_diagonal(Vector < point > & v, int i1, int i2);

	/**
	* Лежит ли точка справа от отрезка в обходе против часовой стрелки?
	*/
	bool ccw(point a, point b, point c);

	/**
	* Ориентированная площадь треугольника
	*/
	double area_triangle(point a, point b, point c);

	/**
	* Разрезание многоугольника по диагонали
	*/
	void cutPolygon(Vector <point> p, int i1, int i2, Vector <point> &p1, Vector <point> &p2);

	/**
	* Деление отрезка в заданном отношении
	*/
	point part_segment(point p1, point p2, double m, double n);

	/**
	* Многоугольник в порядке обхода против часовой стрелки и количество точек
	* T - массив результат - размер матрицы count x 3, содержит вершины триангуляции
	*/
	void triangulator(Vector <point> &p, point T[][3]);
private:
};

int count_triang = 0;
const double eps = 1e-7;
#define eq(a, b) (abs ((a) - (b)) <= eps) 
#define ls(a, b) (! eq ((a), (b)) && (a) < (b)) 
#define gr(a, b) (! eq ((a), (b)) && (a) > (b)) 

triangulate::triangulate()
{

}

triangulate::~triangulate()
{

}

point triangulate::min_py(point a, point b)
{
	return a.y < b.y || (abs(a.y - b.y) <= eps && a.x < b.x) ? a : b;
}

point triangulate::max_py(point a, point b)
{
	return a.y > b.y || (abs(a.y - b.y) <= eps && a.x > b.x) ? a : b;
}

double triangulate::min(double a, double b)
{
	if (a < b) return a;
	else return b;
}
double triangulate::max(double a, double b)
{
	if (a > b) return a;
	else return b;
}
double triangulate::SAT(point a, point b, point c)
{
	return 0.5 * (a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x);
}

int triangulate::sSAT(point a, point b, point c)
{
	double s = SAT(a, b, c);
	if (gr(s, 0)) return 1;
	if (ls(s, 0)) return -1;
	return 0;
}

bool triangulate::is_crossing(point S0, point S1, point S2, point S3)
{
	return sSAT(S0, S2, S1) != sSAT(S0, S3, S2) && sSAT(S2, S0, S3) != sSAT(S2, S1, S3);
}

bool triangulate::ccw(point a, point b, point c)
{
	return area_triangle(a, b, c) > eps;
}

double triangulate::area_triangle(point a, point b, point c)
{
	return 0.5 * (a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x);
}

bool triangulate::point_in_polygon(point t, Vector <point> p)
{
	int i, j;
	int count = 0;
	for (i = 0; i < p.size(); ++i)
	{
		j = (i + 1) % p.size();
		if (min(p[i].y, p[j].y) < t.y && t.y <= max(p[i].y, p[j].y) &&
			ccw(min_py(p[i], p[j]), max_py(p[i], p[j]), t))
		{
			++count;
		}
	}
	return count % 2;
}

point triangulate::part_segment(point p1, point p2, double m, double n)
{
	point t;
	t.x = (p1.x * n + p2.x * m) / (m + n);
	t.y = (p1.y * n + p2.y * m) / (m + n);
	return t;
}

bool triangulate::is_diagonal(Vector < point > & v, int i1, int i2)
{
	int i, j;
	int n = v.size();

	if (i1 == (i2 + 1) % n || i2 == (i1 + 1) % n || i1 == i2) return 0;

	for (int i = 0; i < int(n); i++)
		if (i != i1 && i != i2 && i1 != (i + 1) % n && i2 != (i + 1) % n)
		{
			j = (i + 1) % n;

			if (is_crossing(v[i], v[j], v[i1], v[i2])) return 0;
		}

	return point_in_polygon(part_segment(v[i1], v[i2], 1, 1), v);
}

void triangulate::cutPolygon(Vector <point> p, int i1, int i2, Vector <point> &p1, Vector <point> &p2)
{
	int i;
	int n = p.size();

	for (i = i1; i != (i2 + 1) % n; i = (i + 1) % n)
		p1.push_back(p[i]);

	for (i = i2; i != (i1 + 1) % n; i = (i + 1) % n)
		p2.push_back(p[i]);
}

void triangulate::triangulator(Vector <point> &p, point T[][3])
{
	if (p.size() <= 3)
	{
		for (int i = 0; i < p.size(); ++i)
			T[count_triang][i] = p[i];
		++count_triang;
		return;
	}
	int i, j;
	bool end = 0;
	for (i = 0; i < p.size() && !end; ++i)
		for (j = 0; j < p.size() && !end; ++j)
			if (is_diagonal(p, i, j))
			{
				end = 1;
				i = i - 1;
				break;
			}
	Vector <point> p1;
	Vector <point> p2;
	cutPolygon(p, i, j, p1, p2);
	triangulator(p1, T);
	triangulator(p2, T);
}