#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int gcd_iter(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
	int t, k, fac_idx = 0;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &k);	// k%, (100 - k)% water
		int value = 100;
		int tmp_fac = gcd_iter(value, k);
		if (tmp_fac == 1) {
			printf("%d\n", value);
		}
		else {
			while (tmp_fac > 1) {
				tmp_fac = gcd_iter(value, k);
				value /= tmp_fac;
				k /= tmp_fac;
			}
			printf("%d\n", value);
		}
		/*
		int tmp_fac = value % k;
		if (tmp_fac == 1) // already 1.
			printf("%d\n", value);
		else if (tmp_fac == 0) {
			printf("%d\n", value / k);
		}
		else {
			while (tmp_fac > 1) {
				tmp_fac = gcd_iter(value, k);
				value /= tmp_fac;
				k /= tmp_fac;
			}
			printf("%d\n", value + k);
		}
		*/
	}
	return 0;
}