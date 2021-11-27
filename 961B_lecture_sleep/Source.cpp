#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
// secret to keep p awake in k periods
const int MAX = 300000;
long int theorems[MAX], cache[MAX], 
	awake_cache[MAX], awake_rev[MAX], f[MAX];

int main() {
	long int n, k; scanf("%ld %ld", &n, &k);
	for (int i = 0; i < n; i++) scanf("%ld", &theorems[i]);
	long int tmp_sum = 0;
	for (int i = 0; i < k; i++) tmp_sum += theorems[i];
	cache[k - 1] = tmp_sum;	// so if pick 0 min, check 0 + k - 1 cache.
	for (int i = k; i < n; i++) {
		tmp_sum -= theorems[i - k];
		tmp_sum += theorems[i];
		cache[i] = tmp_sum;
	}
	tmp_sum = 0;
	for (int i = 0; i < n; i++) {
		int flag; scanf("%d", &flag);
		if (flag) { tmp_sum += theorems[i]; }
		awake_cache[i] = tmp_sum;
		f[i] = flag;
	}
	tmp_sum = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (f[i]) {
			tmp_sum += theorems[i];
		}
		awake_rev[i] = tmp_sum;
	}
	long int res_sum = 0;
	// init, start = -1;
	res_sum = cache[k - 1] + awake_rev[k];
	for (int start = 0; start + k - 1 < n; start++) {
		tmp_sum = awake_cache[start];
		tmp_sum += cache[start + k];
		tmp_sum += awake_rev[start + k + 1];
		res_sum = tmp_sum > res_sum ? tmp_sum : res_sum;
	}
	printf("%ld", res_sum);
	return 0;
}