#include <iostream>
#include "point.h"
#include "vector.h"
#include "triangulate.h"

int main()
{
	
	setlocale(LC_ALL, "rus");

	/**
	* Èíèöèàëèçèðóåì ìíîãîóãîëüíèê
	*/
	point A;	//example
	A.x = 0;
	A.y = 0;

	point B;
	B.x = 4;
	B.y = 0;

	point C;
	C.x = 2;
	C.y = 3;

	point D;
	D.x = -1;
	D.y = 0;

	point E;
	E.x = -2;
	E.y = 3;

	point F;
	F.x = -2;
	F.y = -3;

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
	* Âûïîëíÿåì òðèàíãóëÿöèþ
	*/
	triangulate res;
	res.triangulator(p, T);

	/**
	* Âûâîä ðåøåíèÿ òðèàíãóëÿöèè
	*/
	std::cout << "Êîëè÷åñòâî òðåóãîëüíèêîâ â òðèàíãóëÿöèè: " << count_triang << std::endl;
	//std::cout << "======" << std::endl;
	for (int i = 0; i < count_triang; i++)
	{
		std::cout << "Òðåãîëüíèê " << i + 1 << std::endl;
		for (int j = 0; j < 3; j++)
		{
			std::cout << T[i][j].x << " " << T[i][j].y << std::endl;
		}
	}

	system("pause");

}
