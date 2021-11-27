#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
const int MAX = 300000;
int arr[MAX];
typedef long long int LL;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		memset(arr, 0, sizeof(arr));
		int n; scanf("%d", &n);
		int min_a = -1;
		scanf("%d", &arr[0]);
		min_a = arr[0];
		for (int i = 1; i < n; i++) {
			scanf("%d", &arr[i]);
			if (arr[i] < min_a) {
				min_a = arr[i];
			}
		}
		LL min_val_cnt = 0;
		bool valid = true;
		for (int i = 0; i < n && valid; i++) {
			if (arr[i] == min_a) {
				min_val_cnt++;
			}
			if ((min_a & arr[i]) != min_a) {
				// technique to see whether 0 exist
				valid = false;
			}
		}
		if (valid) {
			// recall combination.
			// damn, practice needed.
			LL MOD = 1e9 + 7;
			LL factorial = 1;
			for (LL i = 1; i <= n - 2; i++) {
				factorial = (factorial * i) % MOD;
			}
			LL ans = (min_val_cnt * (min_val_cnt - 1)) % MOD;
			ans = (ans * factorial) % MOD;
			printf("%lld\n", ans);
		}
		else {
			printf("0\n");
		}
	}
	return 0;
}

/*
good if a1 & a2 & ... & ai = ai+1 & ai+2 &...
supermask -> set a subset of 0 to 1
rest of string untouched.
1001110 -> 1101111
-> I get it, the so-called super-mask.
bitwise AND -> make sure that no numbers, & => get 0.
*/