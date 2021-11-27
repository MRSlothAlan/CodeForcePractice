#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <cmath>
const int MAX = 101;
char s[MAX];
int Qleft[MAX], Qright[MAX];
/*
naive method:
for each Q, for each A, for each Q
THIS WORKS, ONLY BECAUSE n <= 100.

better way : hints:
	iterate on the place of A, get numbers of
	Q before & after, using prefix sums.
*/

int main() {
	scanf("%s", &s);
	int n = strlen(s);
	int res_val = 0;
	// prefix sum solution
	if (s[0] == 'Q')
		Qleft[0] = 1;
	if (s[n - 1] == 'Q')
		Qright[n - 1] = 1;
	for (int i = 1; i < n; i++) {
		Qleft[i] = Qleft[i - 1];
		if (s[i] == 'Q')
			Qleft[i]++;
	}
	for (int i = n - 2; i >= 0; i--) {
		Qright[i] = Qright[i + 1];
		if (s[i] == 'Q')
			Qright[i]++;
	}
	// IAQVAQZLQBQVQFTQQQADAQJA
	for (int i = 1; i < n - 1; i++) {
		if (s[i] == 'A') {
			int q_left = Qleft[i - 1];
			int q_right = Qright[i + 1];
			// EVERY subpatterns!!
			res_val += q_left * q_right;
			/*
			if (q_left > 0 && q_right > 0) {
				int res = q_left > q_right ? q_left : q_right;
				res_val += res;
			}*/
		}
	}
	/*
	for (int i = 0; i < n; i++) {
		if (s[i] == 'Q') {
			for (int j = i + 1; j < n; j++) {
				if (s[j] == 'A') {
					for (int k = j + 1; k < n; k++) {
						if (s[k] == 'Q') {
							res_val++;
						}
					}
				}
			}
		}
	}*/

	printf("%d\n", res_val);
	return 0;
}