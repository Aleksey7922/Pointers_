#include<iostream>
#include<cstdlib>
using namespace std;
//
//void FillRand(int arr[], const int n);
//void Print (int arr[], const int n);


void main()
{
	setlocale(LC_ALL, "");

	const int n = 10;
	int arr[n];
	int e = 0;
	int* even = new int[e];
	int o = 0;
	int* odd = new int[o];
	int even_count = 0;
	int odd_count = 0;
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		cout << arr[i] << "\t ";		
	}
	cout << endl;
	
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			even[e] = arr[i];
			e++;
		}
		else
		{
			odd[o] = arr[i];
			o++;
		}
	}
	cout << "четные: ";
	for (int i = 0; i < e; i++)
	{
		cout << even[i] << "\t ";
	}
	cout << endl;
	cout << "нечетные: ";
	for (int i = 0; i < o; i++)
	{
		cout << odd[i] << "\t";
	}
	delete[] even;
	delete[] odd;
	/*FillRand(arr, n);
	Print(arr, n);*/

}
//void FillRand(int arr[], const int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] = rand() % 100;
//	}
//}
//void Print(int arr[], const int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << arr[i] << " ";
//	
//	}
//	cout << endl;
//}
