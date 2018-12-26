#include <iostream>
#include "point.h"
#include "vector.h"
#include "triangulate.h"

int main()
{
	setlocale(LC_ALL, "rus");

	/**
	* Инициализируем многоугольник
	*/
	point A(0,0);	//example
	point B(4,0);
	point C(2,3);
	point D(-1,0);
	point E(-2,3);
	point F(-2,-3);

	Vector <point> p;
	p.push_back(A);
	p.push_back(B);
	p.push_back(C);
	p.push_back(D);
	p.push_back(E);
	p.push_back(F);

	const int count = 10;
	point T[count][3];

	/**
	* Выполняем триангуляцию
	*/
	triangulate res;
	res.triangulator(p, T);

	/**
	* Вывод решения триангуляции
	*/
	std::cout << "Количество треугольников в триангуляции: " << count_triang << std::endl;
	for (int i = 0; i < count_triang; i++)
	{
		std::cout << "Трегольник " << i + 1 << std::endl;
		for (int j = 0; j < 3; j++)
		{
			std::cout << T[i][j].x << " " << T[i][j].y << std::endl;
		}
	}

	system("pause");

}