#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
double r, x, y, x_r, y_r;
int main() {
	scanf("%lf %lf %lf %lf %lf", &r, &x, &y, &x_r, &y_r);
	if (x == x_r && y == y_r) { printf("0"); }
	else {
		double x_val = (double)(x - x_r);
		double y_val = (double)(y - y_r);
		double dist = sqrt(x_val * x_val + y_val * y_val);
		int steps = ceil(dist / (2 * r));
		printf("%d", steps);
	}
	return 0;
}

// there are 8 possible destinations.
// either 2r, one side or r, both side
// My thought process : direct line, round up value.
// what I can't think of at the moment : ceil(d / (2 * R))