#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

// consist of n * (n - 1) games
// guess uniforms?
// if host team home u = guess.
// host => guess.
const int MAX = 40;
int uniforms[MAX][2];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &uniforms[i][0], &uniforms[i][1]);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				if (uniforms[i][0] == uniforms[j][1]) {
					cnt++;
				}
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}