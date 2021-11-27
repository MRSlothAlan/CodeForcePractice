#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <cmath>
#include <math.h>
#include <algorithm>
using namespace std;
double pi = 3.14159265359;
int main() {
	double k, x, y;
	scanf("%lf %lf %lf", &k, &x, &y);
	double angle_val = k * pi / 180.0;
	double res_x = x * cos(angle_val) - y * sin(angle_val);
	double res_y = x * sin(angle_val) + y * cos(angle_val);
	printf("%.8lf %.8lf", res_x, res_y);
	return 0;
}