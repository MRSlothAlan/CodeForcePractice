#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
const int MAX = 200;
char s[MAX];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		scanf("%s", &s);
		int len = strlen(s);
		if (len == 1) {			
			if (s[0] == '?') {
				s[0] = 'B';
			}
			printf("%s\n", s);
		}
		else {
			for (int i = 0; i < len; i++) {
				if (s[i] == '?') {
					if (i == 0) {
						int tmp = 0;
						for (; tmp < len && s[tmp] == '?'; tmp++) {}
						if (tmp >= len) {
							i = tmp;
							// well.
						}
						else {
							i = tmp;
							if (s[tmp] == 'R') {
								char w = 'B';
								for (int j = 0; j < tmp; j++) {
									s[j] = w;
									w = w == 'B' ? 'R' : 'B';
								}
							}
							else if (s[tmp] == 'B') {
								char w = 'R';
								for (int j = 0; j < tmp; j++) {
									s[j] = w;
									w = w == 'B' ? 'R' : 'B';
								}
							}
						}
						if (s[1] == 'R') {
							s[0] = 'B';
						}
						else if (s[i] == 'B') {
							s[0] = 'R';
						}
					}
					else {
						// depends on prev ones.
						if (s[i - 1] == 'R') {
							s[i] = 'B';
						}
						else if (s[i - 1] == 'B') {
							s[i] = 'R';
						}
					}
				}
			}
			printf("%s\n", s);
		}
	}
	return 0;
}