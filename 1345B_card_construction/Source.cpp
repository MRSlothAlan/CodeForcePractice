#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int card_needed(int nth) {
	return (nth * (nth + 1) + nth * (nth - 1) / 2);
}

int cal_possible_n(long long int t) {
	double delta = 1 + 4 * 3 * 2 * (double)t;
	double x1 = (-1 + sqrt(delta)) / 6;
	double x2 = (-1 - sqrt(delta)) / 6;
	if (x1 > x2) {
		return (int)floor(x1);
	}
	else {
		return (int)floor(x2);
	}
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		long long int n; scanf("%lld", &n);
		if (n <= 1) { printf("0\n"); }
		else {
			int res_cnt = 0;
			while (n > 1) {
				int nth = cal_possible_n(n);
				n -= card_needed(nth);
				res_cnt++;
			}	
			printf("%d\n", res_cnt);
		}
	}
	return 0;
}