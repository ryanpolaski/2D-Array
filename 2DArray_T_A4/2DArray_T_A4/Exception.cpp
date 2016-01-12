#include "Exception.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

Exception::Exception() : m_msg(0)
{
	cout << "Default cTor Exception" << endl;
}

Exception::Exception(char * msg) : m_msg(msg)
{
	m_msg = msg;
}

Exception::Exception(const Exception & copy) : m_msg(copy.m_msg)
{
	m_msg = copy.m_msg;
}

Exception::~Exception()
{
	cout << "In exception dTor" << endl;
}

Exception & Exception::operator=(const Exception & rhs)
{
	if (this != &rhs)
	{
		m_msg = rhs.m_msg;
	}
	return *this;
}

const char * Exception::getMessage()
{
	return m_msg;
}

void Exception::setMessage(char * msg)
{
	m_msg = msg;
}

ostream & operator << (ostream & stream, const Exception & exc)
{
	stream << endl << exc.m_msg << endl;
	return stream;
}