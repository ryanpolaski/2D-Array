#include <iostream>
using std::cout;
using std::endl;

#include "Array2D.h"

int main() 
{
	cout << "-----------Creating 2D Array size 4 by 4-----------" << endl;
	Array2D<int> myArray(4, 4);
	int i = 1;


	for (int row = 0; row < 4; row++) 
	{
		for (int col = 0; col< 4; col++)
		{
			myArray[row][col] = i++;
		}
	}

	cout << "-----------Contents of 2D Array-----------" << endl;
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			cout << myArray[row][col] << endl;
		}
	}

	cout << "-----------Testing Op Equals-----------" << endl;

	Array2D<int> myArray2 = myArray;

	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			cout << myArray2[row][col] << endl;
		}
	}

	cout << "-----------Testing Copy cTor----------" << endl;

	Array2D<int> myArray3(myArray);

	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			cout << myArray3[row][col] << endl;
		}
	}


	//**********************Exceptions*****************************
	cout << "-----------Testing positive out of bounds index-----------" << endl;
	try
	{
		cout << myArray[5][4] << endl;
	}
	catch (Exception a)
	{
		cout << a << endl;
	}

	cout << endl << "-----------Testing negative out of bounds index-----------" << endl;
	try
	{
		cout << myArray[-1][-2] << endl;
	}
	catch (Exception a)
	{
		cout << a << endl;
	}

	return 0;
}