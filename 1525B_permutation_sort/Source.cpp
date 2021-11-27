#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

/*
What I know && written at notebook so far:
=> most likely 2 operations are enough to rearrange them (written)
=> if sorted, 0
What I don't know?
=> if a[1] = 1 / a[n] = n, just do 1 operation.
=> if a[1] = n && a[n] = 1, 3 operations.
*/
const int MAX = 51;
int arr[MAX];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		bool inOrder = true;
		for (int i = 1; i <= n; i++) { 
			scanf("%d", &arr[i]); 
			if (arr[i] != i) {
				inOrder = false;
			}
		}
		if (inOrder) {
			printf("0\n");
		}
		else {
			if (arr[1] == 1 || arr[n] == n) {
				printf("1\n");
			}
			else if (arr[1] == n && arr[n] == 1) {
				printf("3\n");
			}
			else {
				printf("2\n");
			}
		}
	}
	return 0;
}