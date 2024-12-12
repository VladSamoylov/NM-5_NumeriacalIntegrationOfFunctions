#include <iostream>
#include <cmath>
#include <functional>
#include <iomanip>

#define ANSI_COLOR_BLUE "\033[34m"
#define ANSI_COLOR_RESET "\033[0m"
#define ANSI_COLOR_GREEN "\033[32m"
#define ANSI_COLOR_RED "\033[31m"
#define ANSI_COLOR_PURPLE "\033[35m"
#define ANSI_COLOR_LIGHTBLUE "\033[94m"

using namespace std;

/**
 * @brief Функція чисельного обчислення методом прямокутників і трапецій
 * @param f Функція визначеного інтегралу
 * @param a Межа а
 * @param b Межа b
 * @param n Кількість підінтервалів
 */
static void RectTrapMethod(function<double(double)> f, const double& a, const double& b, int& n) {

	double h = (b - a) / n;
	cout << "h = " << ANSI_COLOR_GREEN << h << ANSI_COLOR_RESET << endl;
	double s1 = 0, s2 = 0, i1 = 0, i2 = 0, i = 0;
	cout << "-----Rectangle Method-----" << endl;
	cout << ANSI_COLOR_LIGHTBLUE << setw(4) << left << "n" << setw(10) << "Xn" << setw(10) << "F(Xn)" << ANSI_COLOR_RESET << endl;
	double x;
	for (int i = 0; i < n; i++) {
		x = a + i * h;
		s1 += f(x);
		cout << setw(4) << i << setw(10) << x << setw(10) << f(x) << endl;
	}
	for (int i = 1; i <= n; i++) {
		x = a + i * h;
		s2 += f(x);
		if (i == n) cout << setw(4) << i << setw(10) << x << setw(10) << f(x) << endl;
	}
	i1 = h * s1;
	i2 = h * s2;
	i = (i1 + i2) / 2;
	cout << "S1 = " << s1 << endl;
	cout << "S2 = " << s2 << endl;
	cout << "I1 = " << i1 << endl;
	cout << "I2 = " << i2 << endl;
	cout << "Irect = " << ANSI_COLOR_PURPLE << i << ANSI_COLOR_RESET << endl;
	
	cout << "-----Trapezium Method-----" << endl;
	double s = 0, sFL = 0;
	n = static_cast<int>((2 - (-0.8)) / sqrt(0.01));
	h = (b - a) / n;
	cout << "h = " << ANSI_COLOR_GREEN << h << ANSI_COLOR_RESET << " n = " << ANSI_COLOR_LIGHTBLUE << n << ANSI_COLOR_RESET << endl;
	for (int i = 0; i <= n; i++) {
		x = a + i * h;
		if (i == 0 || i == n) sFL += f(x);
		else s += f(x);
	}
	i = h * (sFL / 2 + s);
	cout << "Itrap = " << ANSI_COLOR_PURPLE << i << ANSI_COLOR_RESET << endl;
}

/**
 * @brief Функція чисельного обчислення методом Сімпсона
 * @param f Функція визначеного інтегралу
 * @param a Межа а
 * @param b Межа b
 * @param n Кількість підінтервалів
 */
static void ParabolaMethod(function<double(double)> f, const double& a, const double& b, int& n) {

	cout << "-----Parabola Method (Simpson)-----" << endl;
	n *= 2;
	const double h = (b - a) / n;
	cout << "h = " << ANSI_COLOR_GREEN << h << ANSI_COLOR_RESET << endl;
	double s0 = 0, s1 = 0, s2 = 0, x, i;
	cout << ANSI_COLOR_LIGHTBLUE << setw(4) << left << "n" << setw(10) << "Xn" << setw(15) << "F(X0,Xn)" << setw(15) << "F(Xn%2!=0)" << setw(15) << "F(Xn%2==0)" << ANSI_COLOR_RESET << endl;
	for (int i = 0; i <= n; i++) {
		x = a + i * h;
		if (i == 0 || i == n) s0 += f(x);
		else if (i % 2 == 0) s2 += f(x);
		else s1 += f(x);
		cout << setw(4) << left << i << setw(10) << x;
		if (i == 0 || i == n) cout << setw(15) << f(x);
		else cout << setw(15) << " ";
		if (i % 2 != 0) cout << setw(15) << f(x);
		else cout << setw(15) << " ";
		if (i % 2 == 0 && i != 0 && i != n) cout << setw(15) << f(x) << endl;
		else cout << setw(15) << " " << endl;
	}
	cout << setw(14) << "Amount : " << ANSI_COLOR_GREEN << setw(15) << s0 << " " << setw(15) << s1 << " " << setw(15) << s2 << " " << ANSI_COLOR_RESET << endl;
	i = h / 3 * (s0 + 2 * s2 + 4 * s1);
	cout << "Isimpson = " << ANSI_COLOR_PURPLE << i << ANSI_COLOR_RESET << endl;
}

int main() {

	double epsilon = 0.01;
	int n = static_cast<int>((2 - (-0.8)) / epsilon);
	int n_test = 10;
	auto f_test = [](double x) {return pow(cos(exp(x)), 3); };
	auto f = [](double x) {return 1 / sqrt(pow(x, 3) + 1.7); };
	//RectTrapMethod(f_test, 0, 1, 10);
	RectTrapMethod(f, -0.8, 2, n);
	//ParabolaMethod(f_test, 0, 1, n_test);
	ParabolaMethod(f, -0.8, 2, n_test);

	return 0;
}
