#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

/*
sum of 2020s and 2021s = n?
1000000
*/
const int MAX = 1100000;
bool valid[MAX];

int main() {
	int t; scanf("%d", &t);
	valid[2020] = true;
	valid[2021] = true;
	for (int i = 2020; i < MAX; i++) {
		if (valid[i]) {
			for (int j = i + 2020; j < MAX; j += 2020) {
				valid[j] = true;
				valid[j + 1] = true;
			}
		}
	}
	while (t--) {
		int n; scanf("%d", &n);
		printf("%s\n", valid[n] ? "YES" : "NO");
	}
	return 0;
}