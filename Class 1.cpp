#include <iostream>
#include <stdlib.h>
#include <time.h>  
#include <math.h>
#include <algorithm>

using namespace std;

void showArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << "  ";
	}
	cout << endl;
}

void findMax(int* arr, int size)
{
	int maxim = *arr;
	for (int i = 1; i < size; i++)
	{
		maxim = max(*(arr + i), maxim);
	}

	cout << maxim << endl;
}

void joinAndShow(int* sortedArr1, int* sortedArr2, int size1, int size2)
{
	int pointer1 = 0;
	int pointer2 = 0;
	int* resultArr = new int[size1 + size2];
	
	while (pointer1 < size1 && pointer2 < size2)
	{
		if (*(sortedArr1 + pointer1) < *(sortedArr2 + pointer2))
		{
			*(resultArr + pointer1 + pointer2) = *(sortedArr1 + pointer1);
			pointer1++;
		}
		else
		{
			*(resultArr + pointer1 + pointer2) = *(sortedArr2 + pointer2);
			pointer2++;
		}
	}

	while (pointer1 < size1)
	{
		*(resultArr + pointer1 + pointer2) = *(sortedArr1 + pointer1);
		pointer1++;
	}

	while (pointer2 < size2)
	{
		*(resultArr + pointer1 + pointer2) = *(sortedArr2 + pointer2);
		pointer2++;
	}

	showArr(resultArr, size1 + size2);

	delete[] resultArr;

}

int* reverseArr(int* arr, int size)
{
	int temp;

	for (int i = 0; i < size / 2; i++)
	{
		temp = *(arr + i);
		*(arr + i) = *(arr + size - 1 - i);
		*(arr + size - 1 - i) = temp;
	}

	return arr;
}

void shiftBy(int* arr, int size, int shift)
{

	int temp;
	shift %= size;
	while (shift > 0)
	{
		temp = *(arr);
		for (int i = 0; i < size; i++)
		{
			*(arr + i) = *(arr + i + 1);
		}
		*(arr + size - 1) = temp;
		shift--;
	}
}

void multiplyAndShow(int* arr1, int* arr2, int size1, int size2)
{
	int* result = new int[(size1 + size2) - 1];

	for (int i = 0; i < (size1 + size2) - 1; i++)
	{
		*(result + i) = 0;
	}

	for (int i = 0; i < size1; i++)
		for (int j = 0; j < size2; j++)
		{
			*(result + i + j) += *(arr1 + i) * *(arr2 + j);
		}

	showArr(result, (size1 - 1) + (size2 - 1));

	delete[] result;
}

void drawPascalsTriangle(int n)
{
	int** arr = new int* [n];

	for (int i = 0; i < n; i++)
		*(arr + i) = new int[i + 1];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			if (j==0 || j == i)
				*(*(arr + i) + j) = 1;
			else
			{
				*(*(arr + i) + j) = *(*(arr + i-1) + j-1) + *(*(arr + i - 1) + j);
			}
			cout <<*(*(arr + i) + j) << " ";
		}
		cout << endl;
	}

	delete[] arr;
}

int main()
{
	int size;
	int size1, size2;
	cout << "Enter size: ";
	cin >> size;
	cout << "Enter size1: ";
	cin >> size1;
	cout << "Enter size2: ";
	cin >> size2;

	int* arr1 = new int[size1];
	int* arr2 = new int[size2];
	int* arr = new int[size];

	srand(time(NULL));

	for (int i = 0; i < size; i++)
	{
		*(arr + i) = rand() % 11;
	}

	for (int i = 0; i < size1; i++)
	{
		*(arr1 + i) = rand() % 11;
	}

	for (int i = 0; i < size2; i++)
	{
		*(arr2 + i) = rand() % 11;
	}

	cout << "random array: " << endl;
	showArr(arr, size);
	cout << "Max:" << endl;
	findMax(arr, size);
	cout << "Reversed:" << endl;
	arr = reverseArr(arr, size);
	showArr(arr, size);
	cout << "Shift by: ";
	int shift;
	cin >> shift;
	shiftBy(arr, size, shift);
	showArr(arr, size);

	int* sortedArr1 = new int[size1];
	int* sortedArr2 = new int[size2];

	for (int i = 0; i < size1; i++)
	{
		*(sortedArr1 + i) = i/2;
	}

	for (int i = 0; i < size2; i++)
	{
		*(sortedArr2 + i) = i/3+2;
	}

	cout << "sorted array 1: " << endl;
	showArr(sortedArr1, size1);
	
	cout << "sorted array 2: " << endl;
	showArr(sortedArr2, size2);

	cout << "joined: " << endl;
	joinAndShow(sortedArr1, sortedArr2, size1, size2);
	
	cout << "Arrays as polynomial: " << endl;
	showArr(arr1, size1);
	showArr(arr2, size2);
	cout << "Multiplied " << endl;
	multiplyAndShow(arr1, arr2, size1, size2);

	cout << endl << "enter pascal triangle size: " << endl;
	cin >> size;
	drawPascalsTriangle(size);

	delete[] arr;
	delete[] arr1;
	delete[] arr2;
	delete[] sortedArr1;
	delete[] sortedArr2;

	return 0;
}


