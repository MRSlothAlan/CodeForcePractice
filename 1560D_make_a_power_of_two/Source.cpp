#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

const int MAX_VAL = 1e9;
const int MAX = 200;
int arr[MAX];

int main() {
	int tmp_val = 1;
	int len = 0;
	for (; len < MAX; len ++) {
		arr[len] = tmp_val;
		tmp_val *= 2;
		if (tmp_val > MAX_VAL) {
			break;
		}
	}
	arr[len++] = tmp_val;
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		int min_moves = -1;
		int tmp_moves = 0;
		// min number of moves to transform number into any power of 2.
		for (int i = 0; i < len; i++) {
			tmp_moves = arr[i] - n;
			if (tmp_moves < 0) {
				tmp_moves *= -1;
			}
			if (tmp_moves == 0) {
				min_moves = 0;
				break;
			}
			if (min_moves == -1 || min_moves > tmp_moves) {
				min_moves = tmp_moves;
			}
		}
		printf("%d\n", min_moves);
	}
	return 0;
}