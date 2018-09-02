// ConsoleApplication27.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>

using namespace std;

//Поиск простых чисел
int* pr(int* a, int& n)
{
	int m = 0;
	bool *c = new bool[n];
	for (int i = 0; i < n; i++)
	{
		bool prost = true;
		for (int j = 2; j <= (int)sqrt(a[i]); j++) {
			if (a[i] % j == 0) {
				prost = false;
				break;
			}
		}
		if (prost && a[i] != 1) {
			m++;
			c[i] = true;
		}
		else
			c[i] = false;
	}
	int *b = new int[m];
	int j = 0;
	for (int i = 0; i < n; i++)
		if (c[i])
			b[j++] = a[i];
	n = m;
	delete[] c;
	return b;
}

//Поиск чисел кратные трем
int* krat(int* a, int& n)
{
	int m = 0;
	for (int i = 0; i < n; i++)
		if (a[i] % 3 == 0) m++;
	int *b = new int[m];
	int j = 0;
	for (int i = 0; i < n; i++)
		if (a[i] % 3 == 0)
			b[j++] = a[i];
	n = m;
	return b;
}

//Поиск четных чисел
int* chet(int* a, int& n)
{
	int m = 0;
	for (int i = 0; i < n; i++)
		if (a[i] % 2 == 0) m++;
	int *b = new int[m];
	int j = 0;
	for (int i = 0; i < n; i++)
		if (a[i] % 2 == 0)
			b[j++] = a[i];
	n = m;
	return b;
}


void function(int* a, int n, int* (*f)(int*, int&))
{
	a = f(a, n);
	for (int i = 0; i < n; i++)
		cout << setw(3) << a[i];
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	//Реализовать 3 функции каждая из которых принимает указатель на массив и количество элементов и возвращает указатель на новый массив. Первая функция ищет простые числа и заносит их в новый массив, вторая – все числа кратные трем, третья – все четные числа. Затем напишите функцию, которая принимает указатель на одну из этих функций, а указатель на массив и количество элементов. Добавьте меню, в котором пользователь может выбрать желаемую операцию.

	cout << "Размер массива: ";
	int n;
	cin >> n;
	cout << "Введите элементы массива: ";
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << "Выберите операцию:\n1. Поиск простых чисел\n2. Поиск чисел кратные трем.\n3. Поиск четных чисел.\n0. Выход из меню" << endl;
	int c;

	do {
		cin >> c;
		int* (*f)(int*, int&);
		switch (c) {
		case 1: f = pr;
			break;
		case 2: f = krat;
			break;
		case 3: f = chet;
			break;
		}
		function(a, n, f);
		
	} while (c>0);

	system("pause");
	return 0;
}
