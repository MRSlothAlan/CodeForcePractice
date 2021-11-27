#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 101;
int power[MAX];

/*
Each turn : remove l / r stone
min steps so that least & greatest power destroyed.
*/

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		memset(power, 0, sizeof(power));
		int n; scanf("%d", &n);
		int min_stone = MAX; int max_stone = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &power[i]);
			min_stone = min(power[i], min_stone);
			max_stone = max(power[i], max_stone);
		}
		int min_left = -1, 
			min_right = -1, 
			max_left = -1, 
			max_right = -1;
		for (int l = 1; l <= n && (min_left == -1 || max_left == -1); l++) {
			if (power[l] == min_stone) min_left = l;
			else if (power[l] == max_stone) max_left = l;
		}
		for (int r = n; r >= 1 && (min_right == -1 || max_right == -1); r--) {
			if (power[r] == min_stone) min_right = r;
			else if (power[r] == max_stone) max_right = r;
		}
		int min_right_mag = n - min_right + 1; 
		int max_right_mag = n - max_right + 1;
		int leftOnly = max(min_left, max_left);
		int rightOnly = max(min_right_mag, max_right_mag);
		/*
		case: 3 5 2 1 4 
		*/
		int leftRight;
		if (min_left > max_right) {
			leftRight = min_right_mag + max_left;
		}
		else {
			leftRight = min_left + max_right_mag;
		}
		printf("%d\n", min(leftOnly, min(rightOnly, leftRight)));
	}
	return 0;
}