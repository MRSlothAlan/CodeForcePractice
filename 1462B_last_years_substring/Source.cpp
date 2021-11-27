#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

/*
operations: two num i j, remove substring i j.
turn s into 2020, <= 1 operations?
*/
const int MAX = 201;
char s[MAX];
/*
struct patterns {
	int st1, st2, len1, len2;
	patterns(int s1, int s2, int l1, int l2) {
		this->st1 = s1; this->st2 = s2;
		this->len1 = l1; this->len2 = l2;
	}
};
patterns arr[5];
*/
char target[4] = {'2', '0', '2', '0'};
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		bool notfound = true;
		int n; scanf("%d", &n);
		scanf("%s", &s);
		int len = 4;
		for (int i = 0; i < 5 && notfound; i++) {
			int st = 0;
			int st2 = n - i;
			for (; st < len; st++) {
				if (s[st] != target[st])
					break;
			}
			st--;
			if (st == len - 1) {
				st++;
				for (; st2 < n; st2++) {
					if (s[st2] != target[st])
						break;
					st++;
				}
				st2--;
				if (st2 == n - 1) {
					notfound = false;
				}
			}
			len--;
		}
		if (notfound) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}
	return 0;
}

/*
		arr[0] = patterns(0, n-4, 0, 4);
		arr[1] = patterns(0, n-3, 1, 3);
		arr[2] = patterns(0, n-2, 2, 2);
		arr[3] = patterns(0, n-1, 3, 1);
		arr[4] = patterns(0, n, 4, 0);
*/