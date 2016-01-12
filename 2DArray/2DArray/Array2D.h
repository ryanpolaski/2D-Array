#ifndef ARRAY2D_H
#define ARRAY2D_H

#include "Row.h"

template <typename T>
class Array2D
{
public:
	friend class Row<T>;
	Array2D();
	Array2D(int row, int col);
	Array2D(const Array2D & copy);
	~Array2D();
	Array2D & operator=(const Array2D & rhs);
	Row<T> operator[](int index);
	const Row<T> operator[](int index) const; // const method

	const int getRow() const;
	const int getColumn() const;
	void setRow(int rows);
	void setColumn(int columns);
	T & Select(int row, int column);
private:
	Array<T> m_array;
	int m_row;
	int m_col;
};

template <typename T>
Array2D<T>::Array2D() : m_row(0), m_col(0)
{
	m_array.setLength(0);
}

template <typename T>
Array2D<T>::Array2D(int row, int col) : m_row(row), m_col(col)
{
	m_array.setLength(row*col);
}

template <typename T>
Array2D<T>::Array2D(const Array2D & copy) : m_array(copy.m_array), m_row(copy.m_row), m_col(copy.m_col)
{}

template <typename T>
Array2D<T> & Array2D<T>::operator=(const Array2D & rhs)
{
	if (this != &rhs)
	{
		m_row = rhs.m_row;
		m_col = rhs.m_col;
		m_array = rhs.m_array;
	}
	return *this
}

template <typename T>
Row<T> Array2D<T>::operator[](int index)
{
	Row<T> row(*this, index);
	return row;
}

template <typename T>
const Row<T> Array2D<T>::operator[](int index) const
{
	return Row<T>(*this, index);
}

template <typename T>
Array2D<T>::~Array2D()
{
	//m_array2D = nullptr;
	m_col = 0;
	m_row = 0;
}

template <typename T>
const int Array2D<T>::getRow() const
{
	return m_row;
}

template <typename T>
const int Array2D<T>::getColumn() const 
{
	return m_col;
}

template <typename T>
void Array2D<T>::setRow(int rows)
{
	if (rows > m_row)
	{
		m_row = rows;
	}
	else
		throw Exception("Error: invalid row number");
}

template <typename T>
void Array2D<T>::setColumn(int columns)
{
	if (columns > m_col)
	{
		m_col = columns;
	}
	else
		throw Exception("Error: invalid column number");
}

template <typename T>
T & Array2D<T>::Select(int row, int column)
{
	return m_array[row*m_col + column];
}

#endif