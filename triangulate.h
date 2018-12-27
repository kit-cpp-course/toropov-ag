#pragma once

/**
* Класс, реализующий триангуляцию
*/
class triangulate : private point
{
public:
	triangulate();
	~triangulate();
	/**
	* Возвращает наиболее низкую из двух точек
	* @param point a, point b две точки
	* @return наиболее низкая точка
	*/
	point min_py(point a, point b);

	/**
	* Возвращает наиболее высокую из двух точек
	* @param point a, point b две точки
	* @return наиболее высокая точка
	*/
	point max_py(point a, point b);

	/**
	* Возвращает наименьшее значение
	* @param double a, double b два значения
	* @return наименьшее значение
	*/
	double min(double a, double b);

	/**
	* Возвращает наибольшее значение
	* @param double a, double b два значения
	* @return наибольшее значение
	*/
	double max(double a, double b);

	/**
	* Находит ориентированную площадь треугольника - лежит ли вершина b справа от вектора a->c
	* @param point a, point b, point c три точки
	* @return ориентированная площадь
	*/
	double SAT(point a, point b, point c);

	/**
	* Находит знак ориентированной площади треугольника
	* @param point a, point b, point c три точки
	* @return знак ориентированной площади
	*/
	int sSAT(point a, point b, point c);

	/**
	* Пересечение двух отрезков, не лежащих на одной прямой
	* @param point S0, point S1 - точки первого отрезка; point S2, point S3 - точки второго отрезка
	* @return пересекаются ли два отрезка
	*/
	bool is_crossing(point S0, point S1, point S2, point S3);

	/**
	* Принадлежит ли точка в многоугольнику
	* @param point t - точка; Vector <point> p - вектор, содержащий вершины многоугольника
	* @return принадлежит или нет
	*/
	bool point_in_polygon(point t, Vector <point> p);

	/**
	* Является ли отрезок внутренней диагональю многоугольника
	* @param Vector <point> v - вектор, содержащий вершины многоугольника; i1, i2 - номера вершины
	* @return является или нет
	*/
	bool is_diagonal(Vector < point > & v, int i1, int i2);

	/**
	* Лежит ли точка справа от отрезка в обходе против часовой стрелки
	* @param point a, point b, point c три точки
	* @return лежит или нет
	*/
	bool ccw(point a, point b, point c);

	/**
	* Ориентированная площадь треугольника
	* @param point a, point b, point c три точки
	* @return ориентированную площадь треугольника
	*/
	double area_triangle(point a, point b, point c);

	/**
	* Реализует разрезание многоугольника по диагонали
	* @param Vector <point> p - вектор, содержащий вершины многоугольника; i1, i2 - номера вершин;
	*		 Vector <point> &p1, Vector <point> &p2 - получают вершины новых многоугольников
	*/
	void cutPolygon(Vector <point> p, int i1, int i2, Vector <point> &p1, Vector <point> &p2);

	/**
	* Деление отрезка в заданном отношении
	* @param point p1, point p2 - точки отрезка; double m, double n - заданные значения отношения
	* @return точка на отрезке
	*/
	point part_segment(point p1, point p2, double m, double n);

	/**
	* Реализует триангуляцию многоугольника в порядке обхода против часовой стрелки
	* T - массив результат - размер матрицы count x 3, содержит вершины триангуляции
	*/
	void triangulator(Vector <point> &p, point T[][3]);
};