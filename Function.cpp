#include "Function.h"
#include <iostream>

using namespace std;

//Функция заполнениния массива работает следующим образом:
//заполнение происходит по диагонали путем уменьшения j номера столбца и увеличения i номера строки, пока не дойдет до элемента с индексом j=j_0 (задает крайний левый столбец, необходимый для заполнения)
//После того как заполнится крайний левый возможный элемент, переходим на новый символ, сравнивая i, j с максимумами. В случае совпадения, меняем начальные значения в цикле. Основной цикл происходит пока не будут заполнены все элементы.

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

// Функция, считающая значение для ровного вывода массива

int for_print(const size_t height, const size_t width, const size_t k)
{
	size_t j, num = 0;
	j = k + (width*height) - 1;
	while (j > 0)
	{
		j = j / 10;
		num++;
	}
	return num;
}

void print_array (size_t ** array, const size_t height, const size_t width, const size_t num)
{

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

	        cout << "\nЗаполненный массив: \n";
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
