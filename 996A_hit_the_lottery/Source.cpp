#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <inttypes.h>
/*
minimum number of bills
*/
/*
lli pow(lli in_val, lli cnt) {
	lli res = in_val;
	cnt--;
	while (cnt--) {
		res *= in_val;
	}
	return res;
}
*/
int arr[5] = { 1,5,10,20,100 };
int main() {
	int n; scanf("%d", &n);
	// poop
	// fuckin pooping.
	// greedy.
	int res_val = 0;
	for (int i = 4; i >= 0; i--) {
		while (n - arr[i] >= 0) {
			n -= arr[i];
			res_val++;
		}
	}
	printf("%d\n", res_val);
	return 0;
}