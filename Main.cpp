#include <iostream>
#include "Function.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	size_t height, width;
	cout << "������ ����. ������������ ������ �1 �������� �������� ��. 7302\n";
	cout << "������� ������� ���������� �������\n";
	cout << "������: ";
	cin >> height;
	cout << "�������: ";
	cin >> width;
	int beginning, l;
	cout << "������� �����, ������� � �������� ����� ����������� ������ ";
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