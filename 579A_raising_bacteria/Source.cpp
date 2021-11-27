#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <string>
typedef long long int lld;
/*
each morning, put any number of bacteria into the box
each night, b -> 2b
see exactly x bacteria in the box at some moment.
min number of bacteria you need to put into the box.
*/
// up to 10 ^ 9
const int MAX = 100;
const lld MAX_VAL = 1e9;
lld arr[MAX];

int main() {
	lld tmp = 1;
	int arr_idx = 0;
	while (tmp <= MAX_VAL) {
		arr[arr_idx++] = tmp;
		tmp *= 2;
	}
	arr[arr_idx++] = tmp;
	lld x; scanf("%lld", &x);
	uint64_t cur = x;	// not within limit on their judge, because my bad
	lld cnt = 0;
	int len = 0; for (; len < MAX && arr[len] <= x; len++) {}
	for (int l = 0; l < len; l++) {
		if ((cur >> l) & 1) {
			cnt++;
		}
	}
	printf("%lld", cnt);
	return 0;
}