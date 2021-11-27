#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
const int MAX = 200;
int arr[MAX];
int main() {
	// warm-ups.
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			arr[i] = a;
		}
		int tmp = arr[0];
		for (int i = 1; i < n; i++) {
			tmp = (tmp & arr[i]);
		}
		printf("%d\n", tmp);
	}
	return 0;
}