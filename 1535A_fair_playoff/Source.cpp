#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX(a, b) a > b ? a : b
int s[4];
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < 4; i++) {
			scanf("%d", &s[i]);
		}
		int first_p = MAX(s[0], s[1]);
		int second_p = MAX(s[2], s[3]);
		sort(s, s + 4);
		if ((first_p == s[2] && second_p == s[3]) ||
			(first_p == s[3] && second_p == s[2])) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}