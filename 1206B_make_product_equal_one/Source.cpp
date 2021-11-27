#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

/*
operations: one coin:
	choose a number, + - 1
make product of numbers = 1;
tricky part : 
-525187879 0 425880698 --> -1 0 1.
one step to turn 0 to -1.
*/

int main() {
	int n; scanf("%d", &n);
	int neg_one_cnt = 0;
	int zero_cnt = 0;
	long long int res_cost = 0;
	for (int i = 0; i < n; i++) {
		int d; scanf("%d", &d);
		if (d == 0) { zero_cnt++; }	// deal with that later.
		else if (d > 0) { res_cost += d - 1; }
		else { d = -d; res_cost += d - 1;  neg_one_cnt++; }
	}
	// neg_one_cnt == 1, if just +1, is 0.
	while (zero_cnt > 0) {
		if ((neg_one_cnt & 1) != 0) { neg_one_cnt--; }
		zero_cnt--;
		res_cost++;
	}
	if ((neg_one_cnt & 1) == 0) {
		printf("%lld\n", res_cost);
	}
	else {
		printf("%lld\n", (res_cost + 2));
	}
	return 0;
}