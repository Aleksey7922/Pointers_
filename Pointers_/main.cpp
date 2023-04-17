#include<iostream>
using namespace std;

//#define POINTERS_BASICS

void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTERS_BASICS
	int a = 2;
	int* pa = &a;
	cout << a << endl;	//вывод переменной 'a' на экран.
	cout << &a << endl;	//взятие адреса переменной 'a' прямо привыводе.
	cout << pa << endl;	//вывод адреса переменной 'a', хранящегося в указателе 'pa'.
	cout << *pa << endl;//Разыменование указателя 'pa', и вывод на экран значения по адресу.  
#endif // POINTERS_BASICS

	const int n = 5;
	int arr[n] = { 3, 5, 8, 13, 21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr + i << "\t";
	}
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;
}
