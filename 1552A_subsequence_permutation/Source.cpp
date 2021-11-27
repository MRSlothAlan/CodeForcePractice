#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 60; 
char s[MAX], ori_s[MAX];
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n); 
		scanf("%s", &s); int len = strlen(s);
		strcpy(ori_s, s);
		sort(s, s + len);
		int res = len;
		for (int i = 0; i < len; i++) {
			if (ori_s[i] == s[i]) {
				res--;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}

/* choose number k in between 0 and n, 
select k characters of s and permute them however you want.
minimum k, so that it is possible to sort string?
*/