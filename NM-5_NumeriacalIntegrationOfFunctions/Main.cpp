#include <iostream>
#include <cmath>
#include <functional>
#include <iomanip>

using namespace std;

void RectTrapMethod(function<double(double)> f, const int& a, const int& b, const int& n) {

	const int h = (a + b) / n;
	int iterat = 0;
	int s1, s2, i1, i2;
	

}

int main() {

	auto f_test = [](double x) {return pow(cos(exp(x)), 3); };
	RectTrapMethod(f_test, 0, 1, 10);


	return 0;
}
