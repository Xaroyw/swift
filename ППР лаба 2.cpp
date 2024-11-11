#include <iostream>
#include <cmath>
#include <iomanip>
#include <Windows.h>

using namespace std;

// Функция f(x) = ln(x) + (x + 1)^3
long double func(double x) {
	return log(x) + pow((x + 1), 3);  // Функция f(x) = ln(x) + (x + 1)^3
}

// Производная функции f(x) = ln(x) + (x + 1)^3
long double func2(double x) {
	return (1 / x) + (3 * pow((x + 1), 2));
}

// Функция реализации метода Ньютона
void method(double x0, double xn, long double esp, int nmax) {
	int n = 1; // Обьявления счетчика итераций
	double x2;
	long double fx, fx2, Pfx, Pfx2;

	fx = func(xn);
	Pfx = func2(xn);

	// Заголовок таблицы с форматированием
	cout << setw(5) << "n"
		<< setw(20) << "x0"
		<< setw(20) << "xn"
		<< setw(25) << "f(x)"
		<< setw(25) << "f'(x)"
		<< setw(20) << "Esp" << endl;

	// Первая итерация
	cout << setw(5) << n
		<< setw(20) << fixed << setprecision(10) << x0
		<< setw(20) << fixed << setprecision(10) << xn
		<< setw(25) << fixed << setprecision(10) << fx
		<< setw(25) << fixed << setprecision(10) << Pfx
		<< setw(20) << fixed << setprecision(10) << abs(xn - x0) << endl;

	n++; // Увеличение счетчика итераций

	while (n<=nmax){
		x2 = xn - (fx / Pfx);
		fx2 = func(x2);
		Pfx2 = func2(x2);

		cout << setw(5) << n
			<< setw(20) << fixed << setprecision(10) << x0
			<< setw(20) << fixed << setprecision(10) << xn
			<< setw(25) << fixed << setprecision(10) << fx2
			<< setw(25) << fixed << setprecision(10) << Pfx2
			<< setw(20) << fixed << setprecision(10) << abs(x2 - xn) << endl;

		// Проверка на достижение заданной точности
		if (abs(x2 - xn) < esp) {
			cout << "\nРешение найдено: x = " << x2 << " с точностью " << abs(x2 - xn)
				<< " на " << n << " итерации." << endl;
			return;
		}
		xn = x2;
		fx = fx2;
		Pfx = Pfx2;
		n++;
	}
	cout << "Количества итераций не хватило для нахждения заданной точности" << endl;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	double x0, xn;
	long double esp;
	int nmax;

	cout << "Введите x0: ";
	cin >> x0;

	cout << "Введите xn: ";
	cin >> xn;

	cout << "Введите esp: ";
	cin >> esp;

	cout << "Введите количество итерация: ";
	cin >> nmax;

	method(x0, xn, esp, nmax);

	return 0;
}