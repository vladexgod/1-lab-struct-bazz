#include <iostream>
#include<chrono>
using namespace std;
int node_calculation(int a, int b, int& x, int& y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = node_calculation(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
int main()
{
	setlocale(LC_ALL, "rus");
	int x, y, a, b;
	cout << "Работу выполнил Ершов Владислав Олегович РПИа-о22 " << endl;
	cout << "Введите 2 числа дня нахождения наибольшего делителя через enter : " << endl;
	cin >> a >> b;
	auto start = chrono::steady_clock::now();
	cout << "Наибольший общий делитель: " << node_calculation(a, b, x, y) << endl;
	cout << "x: " << x << endl << "y: " << y;
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	cout << endl << chrono::duration <double, milli>(diff).count() << " ms" << endl;
}