#pragma once

/**
* Класс, реализующий вектор
*/
template <class T>
class Vector
{
public:
	typedef T * iterator;

	Vector();
	Vector(unsigned int size);
	Vector(unsigned int size, const T & initial);
	Vector(const Vector<T> & v);
	~Vector();
	/**
	* Ёмкость
	*/
	unsigned int capacity() const;

	/**
	* Размер
	*/
	unsigned int size() const;

	/**
	* Итераторы начала и конца
	*/
	iterator begin();
	iterator end();

	T & front();
	T & back();

	/**
	* Добавление элемента в конец вектора
	*/
	void push_back(const T & value);

	/**
	* Удаление элемента
	*/
	void pop_back();

	/**
	* Изменение емкости
	*/
	void reserve(unsigned int capacity);

	/**
	* Необходимые операторы
	*/
	T & operator[](unsigned int index);
	Vector<T> & operator=(const Vector<T> &);

	/**
	* Очистить вектор
	*/
	void clear();
private:
	unsigned int my_size; 
	unsigned int my_capacity; 
	T * buffer; 
};