
#include<iostream>
using namespace std;


void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int* arr, int& n, int value);
int* push_front(int* arr, int& n, int value);
int* insert(int* arr, int& n, int value, int index);

int* pop_back(int* arr, int& n);
int* pop_front(int* arr, int& n);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Ââåäèòå ðàçìåð ìàññèâà: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Ââåäèòå äîáàâëÿåìîå çíà÷åíèå: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "Ââåäèòå äîáàâëÿåìîå çíà÷åíèå: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "Ââåäèòå èíäåêñ äîáàâëÿåìîãî ýëåìåíòà: "; cin >> index;
	cout << "Ââåäèòå äîáàâëÿåìîå çíà÷åíèå: "; cin >> value;
	arr = insert(arr, n, value, index);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	delete[] arr;
#endif // DYNAMIC_MEMORY_1

	int rows, cols;
	cout << "Ââåäèòå êîëè÷åñòâî ñòðîê: "; cin >> rows;
	cout << "Ââåäèòå êîëè÷åñòâî ýëåìåíòî ñòðîêè: "; cin >> cols;

	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	//1) Óäàëÿåì ñòðîêè:
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//2) Óäàëÿåì ìàññèâ óêàçàòåëåé:
	delete[] arr;
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
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
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

int* push_back(int* arr, int& n, int value)
{
	//1) Ñîçäàåì áóôåðíûé ìàññèâ íóæíîãî ðàçìåðà (íà 1 ýëåìåíò áîëüøå):
	int* buffer = new int[n + 1];
	//2) Êîïèðóåì âñå çíà÷åíèÿ èç èñõîäíîãî ìàññèâà â áóôåðíûé:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) Óäàëåì èñõîäíûé ìàññèâ:
	delete[] arr;
	//4) Ïîäìåíÿåì àäðåñ èñõîäíîãî ìàññèâà àäðåñîì íîâîãî ìàññèâà:
	arr = buffer;
	buffer = nullptr;	//NULL-pointer (óêàçàòåëü íà 0)
	//cout << typeid(nullptr).name() << endl;
	//5) È òîëüêî ïîñëå ýòîãî â ìàññèâ 'arr' ìîæíî äîáàâèòü çíà÷åíèå:
	arr[n] = value;
	//6) Ïîñëå äîáàâëåíèÿ ýëåìåíòà â ìàññèâ êîëè÷åñòâî åãî ýëåìåíòîâ óâåëè÷èâàåòñÿ íà 1:
	n++;
	//7) Mission complete - ýëåìåíò äîáàâëåí.
	return arr;
}
int* push_front(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1];
	buffer[0] = value;
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n++;
	return arr;
}
int* insert(int* arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}

int* pop_back(int* arr, int& n)
{
	/*int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;*/

	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
int* pop_front(int* arr, int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
//
//void FillRand(int arr[], const int n);
//void Print(int arr[], const int n);
//
//
//void main()
//{
//	setlocale(LC_ALL, "");
//
//	int n ;
//	cout << "Введите зазмер массива: "; cin >> n;
//	int* arr = new int[n];
//	FillRand(arr, n);
//	Print(arr, n);
//
//	int value;
//	cout << "введите добавляемое значение: "; cin >> value;
//	//создаем буфферный масив нужного размера на 1 злемент больше
//	int* buffer = new int[n + 1];
//	//копируем все значения из исходного омассива в буферный
//	for (int i = 0; i < n; i++)
//	{
//		buffer[i] = arr[i];
//	}
//	//удаляем  исходный массив
//	delete[]arr;
//	//подменяем адрес исходного массива адресом нового массива 
//	arr = buffer;
//	buffer = nullptr; // NULL-pointer (указатель на нолль)
//	//и только после этого в массив arr можно добавить значение 
//	
//	arr[n] = value;
//	//посде добавления элемента количество увеличивается на 1
//	
//	n++;
//	//Мission complete -элемент добавлен 
//	Print(arr, n);
//
//	delete[] arr;
//}
//void FillRand(int arr[], const int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		*(arr + i) = rand() % 100;
//	}
//}
//void Print(int arr[], const int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << arr[i] << "\t";
//	}
//	cout << endl;
//}