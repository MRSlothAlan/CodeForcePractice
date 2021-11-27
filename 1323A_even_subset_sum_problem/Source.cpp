#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

const int MAX = 103;
int arr[MAX];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		int even_idx = -1;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
			if ((arr[i] & 1) == 0) {
				even_idx = i;
			}
		}
		if (even_idx > -1) {
			printf("1\n");
			printf("%d\n", even_idx);
		}
		else {
			if (n <= 1) {
				printf("-1\n");
			}
			else {
				printf("2\n");
				printf("1 2\n");
			}
		}
	}
	return 0;
}