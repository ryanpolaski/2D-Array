#ifndef ROW_H
#define ROW_H

#include "Array2D.h"

template <typename T> class Array2D;

template <typename T>
class Row
{
public:
	Row(const Array2D<T> &, const int row);
	Row(Array2D<T> & ar, int row);
	T & operator[](int column) const;
private:
	Array2D<T> & m_array2D;
	int m_row;
};

template <typename T>
Row<T>::Row(const Array2D<T> & why, const int row) : m_array2D(const_cast<Array2D<T> &>(why)), m_row(row)
{

}

template <typename T>
Row<T>::Row(Array2D<T> & ar, int row) : m_array2D(ar), m_row(row)
{

}

template <typename T>
T & Row<T>::operator [] (int column) const
{
	return m_array2D.m_array[m_row][column];
}

#endif
