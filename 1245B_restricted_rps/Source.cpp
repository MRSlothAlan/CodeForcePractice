#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <cmath>
#include <math.h>
#include <algorithm>
using namespace std;
const int MAX = 200;
char s[MAX];
char res[MAX];
/*
Alice, rock a times, paper b times, scissor c times.
Alice wins if beat Bob in at least n / 2 hands.
*/

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		scanf("%s", &s);
		int len = strlen(s);
		int res_round = 0;
		memset(res, '0', sizeof(res));
		for (int i = 0; i < len; i++) {
			if (s[i] == 'R' && b > 0) { 
				b--; res_round++; res[i] = 'P';
			}
			else if (s[i] == 'P' && c > 0) { 
				c--; res_round++; res[i] = 'S';
			}
			else if (s[i] == 'S' && a > 0) { 
				a--; res_round++; res[i] = 'R';
			}
		}
		for (int i = 0; i < len; i++) {
			if (res[i] == '0') {
				if (a > 0) {
					res[i] = 'R'; a--;
				}
				else if (b > 0) {
					res[i] = 'P'; b--;
				}
				else if (c > 0) {
					res[i] = 'S'; c--;
				}
			}
		}
		int min_round = (int)ceil((double)n / 2.0);
		if (res_round >= min_round) {
			printf("YES\n");
			for (int i = 0; i < len - 1; i++) {
				printf("%c", res[i]);
			}
			printf("%c\n", res[len - 1]);
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}