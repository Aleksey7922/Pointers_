#include<iostream>
using namespace std;

void FillRand(int arr[], int n);
void Print(int arr[], int n);


void main()

{
	setlocale(LC_ALL, "RUS");

	const int n = 10;
	int arr[n];
	FillRand(arr, n);
	Print(arr, n);

	// 1) Вычисляем размер массивов:
	int even_counter = 0;
	int odd_counter = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)even_counter++;
		else odd_counter++;
	}

	// 2) Выделяем память под массивы:(для этого создаем динамические массивы)
	int* even_arr = new int[even_counter];
	int* odd_arr = new int[odd_counter];

	// 3) Копируем значения в соответствущие массивы:
	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)even_arr[j++] = arr[i];
		else odd_arr[k++] = arr[i];
		//(arr[i] % 2 == 0 ? even_arr[j++] : odd_arr[k++]) = arr[i];
	}

	Print(even_arr, even_counter);
	Print(odd_arr, even_counter);

	delete[]odd_arr;
	delete[]even_arr;
}
void FillRand(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
	cout << endl;
}
void Print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

