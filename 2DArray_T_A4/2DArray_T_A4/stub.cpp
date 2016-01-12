#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;

#include "Array2D.h"
#include "Exception.h"

#include <crtdbg.h> 
#define _CRTDBG_MAP_ALLOC

template <typename T>
void DisplayContents(Array2D<T> ar);

template <typename T>
void TestConst(const Array2D<T> & ar);

template <typename T>
void TestExceptions(Array2D<T> ar);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	cout << "-----------Creating 2D Array of ints-----------" << endl;
	Array2D<int> myArray(4, 4);

	int i = 1;
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			myArray[row][col] = i++;
		}
	}
	TestConst(myArray);

	cout << "-----------Creating 2D Array of strings-----------" << endl;
	Array2D<string> myStrArray(4, 4);

	char c[3] = "a";
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			c[0];
			string str = c;
			myStrArray[row][col] = str;
			++c[0];
		}
	}

	cout << "-----------Contents of 2D Array of ints-----------" << endl;
	DisplayContents(myArray);
	cout << endl;
	cout << "-----------Contents of 2D Array of strings-----------" << endl;
	DisplayContents(myStrArray);

	cout << "-----------Testing Op Equals-----------" << endl;

	Array2D<int> myArray2 = myArray;
	DisplayContents(myArray2);
	cout << endl;
	Array2D<string> strArray2 = myStrArray;
	DisplayContents(strArray2);


	cout << "-----------Testing Copy cTor----------" << endl;

	Array2D<int> myArray3(myArray);
	DisplayContents(myArray3);

	cout << "****************Exceptions******************" << endl;
	TestExceptions(myArray);

	return 0;
}

template <typename T>
void DisplayContents(Array2D<T> ar)
{
	for (int row = 0; row < ar.getRow(); row++)
	{
		for (int col = 0; col < ar.getColumn(); col++)
		{
			cout << "[" << row << "]" << "[" << col << "]: " << ar[row][col] << endl;
		}
	}
}

template <typename T>
void TestConst(const Array2D<T> & ar)
{
	cout << "-------------Tesing const ref object-----------" << endl;
	DisplayContents(ar);
}

template <typename T>
void TestExceptions(Array2D<T> ar)
{
	cout << "-----------Testing positive out of bounds index-----------" << endl;
	try
	{
		cout << ar[5][4] << endl;
	}
	catch (Exception a)
	{
		cout << a << endl;
	}

	cout << endl << "-----------Testing negative out of bounds index-----------" << endl;
	try
	{
		cout << ar[-1][-2] << endl;
	}
	catch (Exception a)
	{
		cout << a << endl;
	}

	cout << endl << "-----------Testing negative row-----------" << endl;
	try
	{
		ar.setRow(-1);
	}
	catch (Exception a)
	{
		cout << a << endl;
	}

	cout << endl << "-----------Testing negative column-----------" << endl;
	try
	{
		ar.setColumn(-1);
	}
	catch (Exception a)
	{
		cout << a << endl;
	}
}
	//Array2D<int> myArray(4, 4);
	//int i = 0;
	//for (int row = 0; row < 4; row++) 
	//{
	//	for (int col = 0; col < 4; col++)
	//	{
	//		(myArray)[row][col] = i;
	//		i++;
	//	}
	//}

	//for (int row = 0; row < myArray.getRow(); row++) 
	//{
	//	for (int col = 0; col < myArray.getColumn(); col++)
	//	{
	//		cout << "[" << row << "]" << "[" << col << "]: " << myArray[row][col] << endl;
	//	}
	//}

	//Array2D<int> Array2(myArray); 
	//

	//for (int row = 0; row < Array2.getRow(); row++)
	//{
	//	for (int col = 0; col < Array2.getColumn(); col++)
	//	{
	//		cout << "[" << row << "]" << "[" << col << "]: " << Array2[row][col] << endl;
	//	}
	//}


	//Array2D<string> myStrArray(4, 4);

	//char c[3] = "a";
	//for (int row = 0; row < 4; row++)
	//{
	//	for (int col = 0; col < 4; col++)
	//	{
	//		c[0];
	//		string str = c;
	//		myStrArray[row][col] = str;
	//		++c[0];
	//	}
	//}

	//for (int row = 0; row < myStrArray.getRow(); row++)
	//{
	//	for (int col = 0; col < myStrArray.getColumn(); col++)
	//	{
	//		cout << "[" << row << "]" << "[" << col << "]: " << myStrArray[row][col] << endl;
	//	}
	//}

	//int select = Array2.Select(2,2);

	//cout << endl << select << endl;

