#pragma warning(disable : 4996)
#include <cstdio>

// one differs from the others in evenness
// 1 even or 1 odd.
int in_num[120];
int even_c, odd_c;
int main() {
	int n; scanf("%d", &n);
	even_c = 0; odd_c = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &in_num[i]);
		if ((in_num[i] & 1) == 0) {
			even_c++;
		}
		else {
			odd_c++;
		}
	}
	if (odd_c == 1) {
		for (int i = 0; i < n; i++) {
			if ((in_num[i] & 1) != 0) {
				printf("%d\n", (i + 1));
			}
		}
	}
	else if (even_c == 1){
		for (int i = 0; i < n; i++) {
			if ((in_num[i] & 1) == 0) {
				printf("%d\n", (i + 1));
			}
		}
	}
	return 0;
}