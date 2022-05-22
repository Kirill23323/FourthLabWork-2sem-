#include <iostream>
#include "Matrix.h"
#include"Vector.h"
#include<clocale>
 void line()
{
	std::cout << "\n=============================================================\n" << std::endl;
}
int main() 
{
	setlocale(LC_ALL, "Rus");
	// Векторы

	TVector<int> a(10);
	TVector<int> a1(10);
	TVector<int> a2(a1);
	TVector<int> a3;
	TVector<int> a4;
	TVector<int> a5;
	TVector<int> a6;
	TVector<int> a7;
	TVector<int> a8(5,2);
	TVector<int> a9;
	int n = 10;
	for (int i = 0; i < 10; i++) 
	{
		a1[i] = rand() % 50;
	}
	for (int i = 0; i < 10; i++)
	{
		a[i] = rand() % 50;
	}
	a2 = a1;
	a3 = a1 - a;
	a4 = a1 + a;
	a5 = a1 * a;
	a6 = a1 / a;
	std::cin >> a7;
	if (a1 == a2)
		std::cout << "a1 = a2" << std::endl;
	line();
	if (a1 != a3)
		std::cout << "a1 != a3" << std::endl;
	line();
	std::cout << a << std::endl;
	std::cout << "Вектор a" << std::endl;
	line();
	std::cout << a1 << std::endl;
	std::cout << "Вектор a1" << std::endl;
	line();
	std::cout << a2 << std::endl;
	std::cout << "Вектор a2" << std::endl;
	line();
	std::cout << a3 << std::endl;
	std::cout << "a1 - a" << std::endl;
	line();
	std::cout << a4 << std::endl;
	std::cout << "a1 + a" << std::endl;
	line();
	std::cout << a5 << std::endl;
	std::cout << "a1 * a" << std::endl;
	line();
	std::cout << a6 << std::endl;
	std::cout << "a1 / a" << std::endl;
	line();
	std::cout << a7 << std::endl;
	std::cout << "Введенный вектор" << std::endl;
	line();
	std::cout << a[0] << std::endl;
	std::cout << "a[0]"<< std::endl;
	line();
	a1.Resize(5);
	std::cout << a1 << std::endl;
	std::cout << "a1 после изменения размера" << std::endl;
	line();

	// Матрицы
	TMatrix<int> b(5,5);
	TMatrix<int> b1(5,5);
	TMatrix<int> b2(b1);
	TMatrix<int> b3;
	TMatrix<int> b4;
	TMatrix<int> b5;
	TMatrix<int> b6;
	TMatrix<int> b7;
	TMatrix<int> b8(4, 5);
	TMatrix<int> b9(a8.GetLen(), b8.GetLen());
	TMatrix<int> b10(10000, 1000);
	TMatrix<int> b11(10000, 1000);
	TMatrix<int> b12;
	for (int i = 0; i < b1.GetWidth(); i++)
	{
		for (int j = 0; j < b1.GetLen(); j++)
		{
			b1[i][j] = rand() % 50;
		}
	}
	for (int i = 0; i < b.GetWidth(); i++)
	{
		for (int j = 0; j < b.GetLen(); j++)
		{
			b[i][j] = rand() % 50;
		}
	}
	for (int i = 0; i < a8.GetLen(); i++)
		a8[i] = rand() % 50;
	for (int i = 0; i < b8.GetWidth(); i++)
	{
		for (int j = 0; j < b8.GetLen(); j++)
			b8[i][j] = rand() % 50;
	}
	b2 = b1;
	b3 = b1 - b;
	b4 = b1 + b;
	if (b1 == b2)
		std::cout << "b1 = b2" << std::endl;
	line();
	if (b1 != b3)
		std::cout << "b1 != b3" << std::endl;
	line();
	std::cin >> b7;
	std::cout << b << std::endl;
	std::cout << "Матрица b" << std::endl;
	line();
	std::cout << b1 << std::endl;
	std::cout << "Матрица b1" << std::endl;
	line();
	std::cout << b2 << std::endl;
	std::cout << "Матрица b2" << std::endl;
	line();
	std::cout << b3 << std::endl;
	std::cout << "b1 - b" << std::endl;
	line();
	std::cout << b4 << std::endl;
	std::cout << "b1 + b" << std::endl;
	line();
	std::cout << b7 << std::endl;
	std::cout << "Введенная  матрица" << std::endl;
	line();
	std::cout << b[4][1] << std::endl;
	std::cout << "b[4][1]" << std::endl;
	line();
	b1.Resize(4,5);
	std::cout << b1 << std::endl;
	std::cout << "b1 после изменения размера" << std::endl;
	line();

	//Умножение матрицы на вектор и вектора на матрицу

	a9 = b8 * a8;
	std::cout << a9 << std::endl;
	std::cout << "b8 * a8" << std::endl;
	line();
	b8.Resize(1, b8.GetLen());
	b9 = a8 * b8;
	std::cout << b9 << std::endl;
	std::cout << "a8 * b8" << std::endl;
	return 0;
}