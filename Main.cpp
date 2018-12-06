#include <iostream>
#include "Function.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	size_t height, width;
	cout << "Добрый день. Лабораторная работа №1 Скоковой Виктории гр. 7302\n";
	cout << "Введите размеры двумерного массива\n";
	cout << "Строки: ";
	cin >> height;
	cout << "Столбцы: ";
	cin >> width;
	int beginning, l;
	cout << "Введите число, начиная с которого будет заполняться массив ";
	cin >> l;

	size_t **array = new size_t*[height];
	for (size_t i = 0; i < height; i++)
		array[i] = new size_t[width];
	beginning = put_array(array, height, width, l);
	print_array(array, height, width, beginning);
	for (size_t i = 0; i < height; i++)
		delete[] array[i];
	delete[]array;
	system("pause");
	return 0;
}
