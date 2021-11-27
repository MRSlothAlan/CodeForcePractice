#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		// int sum_val = 0;
		int cnt_odd = 0;
		for (int i = 0; i < 2 * n; i++) {
			int val; scanf("%d", &val); if ((val & 1)) cnt_odd++;
		}
		if (cnt_odd == n) {
			printf("YES\n");
		}
		else { printf("NO\n"); }
	}
	return 0;
}

/*
	Well, math and physics guys...
	those people need to think hard about problems, 
	proof that they are right, and always accepts new ideas.
	Therefore, people who are good at math are usually successful.

	o + o => e
	o + e => o
	e + e => e
*/