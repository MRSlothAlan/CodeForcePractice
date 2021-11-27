#pragma warning(disable : 4996)
#include <cstdio>

int main() {
	int w;
	// a warm-up, definitely
	scanf("%d", &w);
	// 1 <= w <= 100
	if (w == 1) {
		printf("NO\n");
	}
	else {
		int left = 1, right = w - 1;
		while (right >= left) {
			if ((right & 1) == 0 && (left & 1) == 0) {
				printf("YES\n");
				return 0;
			}
			right--; left++;
		}
		printf("NO\n");
	}
	return 0;
}