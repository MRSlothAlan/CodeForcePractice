#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

/*
Binary Exponentiation
Euclidean algorithm for computing the greatest common divisor
Extended Euclidean Algorithm
Linear Diophantine Equations
Fibonacci Numbers
*/

// tie will form a tuple based on the values provided.
// https://en.cppreference.com/w/cpp/utility/tuple/tie
// https://en.cppreference.com/w/cpp/utility/tuple/make_tuple
// new knowledge
int gcd_xy_iter(int a, int b, int& x, int& y) {
	x = 1, y = 0;
	int x1 = 0, y1 = 1, a1 = a, b1 = b;
	while (b1) {
		int q = a1 / b1;
		tie(x, x1) = make_tuple(x1, x - q * x1);
		tie(y, y1) = make_tuple(y1, y - q * y1);
		tie(a1, b1) = make_tuple(b1, a1 - q * b1);
	}
	return a1;
}

int gcd_xy(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int d = gcd_xy(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

long long binpow_iter(long long a, long long b) {
	long long res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

long long binpow(long long a, long long b) {
	if (b == 0)
		return 1;
	long long res = binpow(a, b / 2);
	if (b % 2)
		return res * res * a;
	else
		return res * res;
}

int gcd_iter(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

// linear diophantine equation
// general form : ax + by = c
/*
	apply extended euclidean algorithm
	find xg, yg, g = gcd(), such that
	a * xg + b * yg = g

	if c is divisible by g, the equation has a solution.
	e.g. x0 = xg * c / g

	**	ax + by  + (kab / g) - (kab / g) = c
		a(x + kb / g) + b(y - ka / g) = c
		all possible solutions for a equation.

	how about in a given interval? [minx, maxx, miny, maxy]
	get a sol, then shift.
	if a || b = 0, one solution.

*/
bool find_any_solution(int a, int b, int c,
	int &x0, int &y0, int &g) {
	g = gcd_xy_iter(abs(a), abs(b), x0, y0);
	if (c % g) {
		return false;
	}
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0) x0 = -x0;
	if (b < 0) y0 = -y0;
	return true;
}

void shift_solution(int & x, int & y, int a, int b, int cnt) {
	x += cnt * b;
	y -= cnt * a;
}

int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
	int x, y, g;
	if (!find_any_solution(a, b, c, x, y, g))
		return 0;
	a /= g;
	b /= g;

	int sign_a = a > 0 ? +1 : -1;
	int sign_b = b > 0 ? +1 : -1;

	shift_solution(x, y, a, b, (minx - x) / b);
	if (x < minx)
		shift_solution(x, y, a, b, sign_b);
	if (x > maxx)
		return 0;
	int lx1 = x;

	shift_solution(x, y, a, b, (maxx - x) / b);
	if (x > maxx)
		shift_solution(x, y, a, b, -sign_b);
	int rx1 = x;

	shift_solution(x, y, a, b, -(miny - y) / a);
	if (y < miny)
		shift_solution(x, y, a, b, -sign_a);
	if (y > maxy)
		return 0;
	int lx2 = x;

	shift_solution(x, y, a, b, -(maxy - y) / a);
	if (y > maxy)
		shift_solution(x, y, a, b, sign_a);
	int rx2 = x;

	if (lx2 > rx2)
		swap(lx2, rx2);
	int lx = max(lx1, lx2);
	int rx = min(rx1, rx2);

	if (lx > rx)
		return 0;
	return (rx - lx) / abs(b) + 1;
}

/*
Fibonacci numbers: F(n) = F(n-1) + F(n-2) with F(0) = 0 and F(1) = 1.
http://oeis.org/A000045
Binet's formula
	Fn = (((1 + sqrt(5)) / 2) ^ n - ((1 - sqrt(5)) / 2) ^ n) / sqrt(5)
*/
pair<int, int> fib(int n) {
	if (n == 0)
		return { 0, 1 };

	auto p = fib(n >> 1);
	int c = p.first * (2 * p.second - p.first);
	int d = p.first * p.first + p.second * p.second;
	if (n & 1)
		return { d, c + d };
	else
		return { c, d };
}


int main() {
	return 0;
}