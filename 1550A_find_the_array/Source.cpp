#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <cmath>
using namespace std;
// find the array.
int main() {
	// warm-ups.
	int t; scanf("%d", &t);
	while (t--) {
		int sum_ele; scanf("%d", &sum_ele);
		printf("%d\n", static_cast<int>(ceil(sqrt(sum_ele))));
	}
	return 0;
}

/*
beautiful array?
num 1. = 1, or, 2. num - 1 / num - 2 exist.

5 3 1 = beautiful.
5 - 2 = 3, yes
3 - 2 = 1, yes
last num = 1, 
*/