
#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");

	int n ;
	cout << "Введите зазмер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "введите добавляемое значение: "; cin >> value;
	//создаем буфферный масив нужного размера на 1 злемент больше
	int* buffer = new int[n + 1];
	//копируем все значения из исходного омассива в буферный
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//удаляем  исходный массив
	delete[]arr;
	//подменяем адрес исходного массива адресом нового массива 
	arr = buffer;
	buffer = nullptr; // NULL-pointer (указатель на нолль)
	//и только после этого в массив arr можно добавить значение 
	
	arr[n] = value;
	//посде добавления элемента количество увеличивается на 1
	
	n++;
	//Мission complete -элемент добавлен 
	Print(arr, n);

	delete[] arr;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
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