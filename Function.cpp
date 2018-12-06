#include "Function.h"
#include <iostream>

using namespace std;

int put_array(size_t ** array, const size_t height, const size_t width, const size_t number)
{
	size_t k=number;
	int i = 0, j = 1;
	int i_0 = 0, j_0 = -1, j_1 = 1;
	size_t nn = 1;
	
	array[0][0] = k;
	if ((height == 1) || (width == 1))
	{
		if (height == 1)
		{
			i = 0;
			for (size_t j = 0; j < width; j++)
			{
				array[i][j] = k;
				k++;
			}
		}
	else
		{
			j = 0;
			for (size_t i = 0; i < height; i++)
			{
				array[i][j] = k;
				k++;
			}
		}
	}
	else {
		while (nn < (height*width))
		{
			while (j > j_0)
			{
				k++;
				array[i][j] = k;
				nn++;
				j--;
				i++;
			}
			if (j_1 == (width - 1))
				i_0++;
			else
				j_1++;
			if (i == height)
				j_0++;
			i = i_0;
			j = j_1;
		}
	}
	return k;
}

void print_array (size_t ** array, const size_t height, const size_t width, const size_t k)
{
	size_t j, num = 0;
	j = k + (width*height) - 1;
	while (j > 0)
	{
		j = j / 10;
		num++;
	}
	cout << "\nЗаполненный массив: \n";
	for (size_t i = 0; i < height; i++)
	{
		for (size_t j = 0; j < width; j++)
		{
			cout.width(num);
			cout << array[i][j] << " ";
		}
		cout << "\n";
	}
}

bool equals (const size_t* array1, const size_t array1_size, size_t ** array2, const size_t height, const size_t width)
{

		int i_1 = 0, j_1 = 0;
		if (array1_size != (height* width)) return false;
		for (size_t i = 0; i < array1_size; i++) 
		{
			if (array1[i] != array2[i_1][j_1])
				return false;
			j_1++;
			if (j_1 == width)
			{
				j_1 = 0;
				i_1++;
			}
		}
		return true;
}
