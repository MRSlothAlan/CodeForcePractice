#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
/*
The side is fixed here.
*/
int main() {
	int n; scanf("%d", &n);
	if (n % 2 != 0) {
		printf("0\n");
	}
	else {
		printf("%.0f\n", pow(2, (n / 2)));
	}
	return 0;
}