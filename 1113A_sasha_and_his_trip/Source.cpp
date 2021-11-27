#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

/*
n cities, on one straight line, from 1 to n.
all roads directed.
v liters, 1 l for 1 km.
price of 1 liter = i dollars
*/
int main() {
	int n, v; scanf("%d %d", &n, &v);
	// return the min amount of money needed.
	if (n - 1 <= v) {
		printf("%d\n", n - 1);
	}
	else {
		int cost = v;
		int last = n - v;
		for (int city = 2; city <= last; city++) {
			cost += city;
		}
		printf("%d\n", cost);
	}
	return 0;
}