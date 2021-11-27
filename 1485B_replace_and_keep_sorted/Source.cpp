#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
typedef long long int ll;
const int MAX = 300000;
ll arr[MAX];
ll rec[MAX];
int main() {
	ll n, q, k; // number k, [1, k]
	scanf("%lld %lld %lld", &n, &q, &k);
	scanf("%lld", &arr[0]);
	rec[0] = arr[0] - 1;
	for (int i = 1; i < n; i++) {
		scanf("%lld", &arr[i]);
		rec[i - 1] += arr[i] - arr[i - 1] - 1;
		rec[i] = arr[i] - arr[i - 1] - 1;
	}
	rec[n - 1] += k - arr[n - 1];
	for (int i = 1; i < n; i++) {
		rec[i] += rec[i - 1];
	}
	while (q--)
	{
		ll l, r; scanf("%lld %lld", &l, &r); l--; r--;
		ll sum = 0;
		if (l == r) {
			sum = k - arr[l] + arr[l] - 1;
		}
		else {
			/*
			for (int i = l + 1; i <= r - 1; i++) {
				sum += rec[i];
			}*/
			sum += rec[r - 1] - rec[l];
			sum += arr[l] - 1 + (arr[l + 1] - arr[l] - 1);
			sum += k - arr[r] + (arr[r] - arr[r - 1] - 1);
		}
		printf("%lld\n", sum);
	}
	return 0;
}

/*
How many k-similar arrays can you make if either x<al or x>ar?
*/