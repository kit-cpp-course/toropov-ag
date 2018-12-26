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

template<class T>
Vector<T>::Vector()
{
	my_capacity = 0;
	my_size = 0;
	buffer = 0;
}

template<class T>
Vector<T>::Vector(const Vector<T> & v)
{
	my_size = v.my_size;
	my_capacity = v.my_capacity;
	buffer = new T[my_size];
	for (unsigned int i = 0; i < my_size; i++)
		buffer[i] = v.buffer[i];
}

template<class T>
Vector<T>::Vector(unsigned int size)
{
	my_capacity = size;
	my_size = size;
	buffer = new T[size];
}

template<class T>
Vector<T>::Vector(unsigned int size, const T & initial)
{
	my_size = size;
	my_capacity = size;
	buffer = new T[size];
	for (unsigned int i = 0; i < size; i++)
		buffer[i] = initial;
}

template<class T>
Vector<T> & Vector<T>::operator = (const Vector<T> & v)
{
	delete[] buffer;
	my_size = v.my_size;
	my_capacity = v.my_capacity;
	buffer = new T[my_size];
	for (unsigned int i = 0; i < my_size; i++)
		buffer[i] = v.buffer[i];
	return *this;
}

template<class T>
typename Vector<T>::iterator Vector<T>::begin()
{
	return buffer;
}

template<class T>
typename Vector<T>::iterator Vector<T>::end()
{
	return buffer + size();
}

template<class T>
T& Vector<T>::front()
{
	return buffer[0];
}

template<class T>
T& Vector<T>::back()
{
	return buffer[my_size - 1];
}

template<class T>
void Vector<T>::push_back(const T & v)
{
	if (my_size >= my_capacity)
		reserve(my_capacity + 5);
	buffer[my_size++] = v;
}

template<class T>
void Vector<T>::pop_back()
{
	my_size--;
}

template<class T>
void Vector<T>::reserve(unsigned int capacity)
{
	if (buffer == 0)
	{
		my_size = 0;
		my_capacity = 0;
	}
	T * Newbuffer = new T[capacity];
	unsigned int l_Size = capacity < my_size ? capacity : my_size;

	for (unsigned int i = 0; i < l_Size; i++)
		Newbuffer[i] = buffer[i];
	my_capacity = capacity;
	delete[] buffer;
	buffer = Newbuffer;
}

template<class T>
unsigned int Vector<T>::size()const
{
	return my_size;
}

template<class T>
T& Vector<T>::operator[](unsigned int index)
{
	return buffer[index];
}

template<class T>
unsigned int Vector<T>::capacity()const
{
	return my_capacity;
}

template<class T>
Vector<T>::~Vector()
{
	delete[] buffer;
}

template <class T>
void Vector<T>::clear()
{
	my_capacity = 0;
	my_size = 0;
	buffer = 0;
}
