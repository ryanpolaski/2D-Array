#ifndef ARRAY_H
#define ARRAY_H

#include "Exception.h"

template <typename T>
class Array
{
public:
	Array();
	Array(int length, int start_index = 0);
	Array(const Array & copy);
	~Array();
	Array& operator=(const Array & rhs);
	T & operator[](int index);
	int getStartIndex();
	void setStartIndex(int start_index);
	int getLength();
	void setLength(int length);

private:
	T * m_array;
	int m_length;
	int m_start_index;
};

template <typename T>
Array<T>::Array() : m_array(new T[0]), m_length(0), m_start_index(0)
{

}

template <typename T>
Array<T>::Array(int length, int start_index) : m_array(new T[length]), m_length(length), m_start_index(start_index)
{
	cout << "in two arg cTor" << endl;
}

template <typename T>
Array<T>::Array(const Array<T> & copy) : m_array(new T[copy.m_length]), m_length(copy.m_length), m_start_index(copy.m_start_index)
{
	for (int i = 0; i < m_length; i++)
	{
		m_array[i] = copy.m_array[i];
	}
}

template <typename T>
Array<T> & Array<T>::operator = (const Array<T> & rhs)
{
	if (this != &rhs)
	{
		m_start_index = rhs.m_start_index;
		m_length = rhs.m_length;

		delete[]m_array;
		m_array = new T[rhs.m_length];

		for (int i = 0; i < m_length; ++i)
			m_array[i] = rhs.m_array[i];
	}
	return *this;
}

template <typename T>
T & Array<T>::operator[](int index)
{
	if (index < m_start_index || index >= (m_length + m_start_index))
		throw Exception("Error: That is an out of bounds index");
	else
		return m_array[index - m_start_index];
}

template <typename T>
int Array<T>::getStartIndex()
{
	return m_start_index;
}

template <typename T>
int Array<T>::getLength()
{
	return m_length;
}

template <typename T>
void Array<T>::setStartIndex(int start_index)
{
	m_start_index = start_index;
}

template <typename T>
void Array<T>::setLength(int length)
{
	if (length < 0)
		throw Exception("Error: A negative length was entered");

	T * newData = new T[length];

	if (length < m_length)
	{
		for (int i = 0; i < length; ++i)
		{
			newData[i] = m_array[i];
		}
	}

	else if (length > m_length)
	{
		for (int i = 0; i < m_length; ++i)
		{
			newData[i] = m_array[i];
		}
	}

	delete[] m_array;
	m_array = newData;
	m_length = length;
}

template <typename T>
Array<T>::~Array()
{
	delete[]m_array;
}

#endif

