#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()

{
	setlocale(LC_ALL, "");

	int n;
	cout << "Введите размер массива: "; cin >> n;

	// создаем динамический масив:
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n); 

	int value;
	cout << "введите добавляемое значение :"; cin >> value;
	// 1) Сщздаем буферный иассив нужного размера()
	int* buffer = new int[n + 1];
	// 2) Копируем все значения из исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	// 3) удаляем исходный массив:
	delete[]arr;
	// 4) подменяем адрес исходного массива адресом нового массива:
	arr = buffer;
	buffer = nullptr;
	// 5) и только после этого в массив 'arr' можно добавить значение:

	arr[n] = value; //NULL -pointer(указатель на 0)
	// 6) После добавления элемента в массив количество его элементов увеличивается на 1:
	n++;
	// 7) Mission complete - элемент добавлен

	Print(arr, n);

	delete[]arr;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr+ i) = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

