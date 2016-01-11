#ifndef ROW_H
#define ROW_H

#include "Array2D.h"
#include "Array.h"

template <typename T> class Array2D;
template <typename T>
class Row
{
public:
	Row(Array2D<T> & ar, int row);
	T & operator[](int column) const;
private:
	Array2D<T> & m_array2D;
	int m_row;
};

template <typename T>
Row<T>::Row(Array2D<T> & ar, int row) : m_array2D(ar), m_row(row)
{

}

template <typename T>
T & Row<T>::operator [] (int column) const
{
	return m_array2D.m_array[m_row * m_array2D.m_col + column];
}

#endif