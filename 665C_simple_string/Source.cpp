#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
const int MAX = 2 * 1e5;
char s[MAX];
int dp[MAX], idx_to_do[MAX], mag[MAX],
idx_ptr;
// simple, if every pair of adjacent characters
// are distinct.

char genChar(char in_char, char next_char) {
	if (next_char != '_') {
		char tmp = 'a';
		while (tmp == in_char || tmp == next_char) {
			tmp = (char) (tmp + 1);
			if (tmp > 'z') {
				tmp = 'a';
			}
		}
		return tmp;
	}
	else {
		if ((char)(in_char + 1) > 'z')
			return 'a';
		else
			return (char)(in_char + 1);
	}
}

int main() {
	scanf("%s", &s);
	int len = strlen(s);
	// string s after minimal number of changes.
	idx_ptr = 0; int cnt = 1; dp[0] = 1;
	int prev = 0;
	for (int i = 1; i < len; i++) {
		if (s[i - 1] != s[i]) {
			if (cnt > 1) {
				mag[idx_ptr] = cnt;
				idx_to_do[idx_ptr++] = prev;
			}
			prev = i;
			cnt = 1;
		}
		else {
			cnt++;
		}
	}
	if (cnt > 1) {
		mag[idx_ptr] = cnt;
		idx_to_do[idx_ptr++] = prev;
	}
	for (int i = 0; i < idx_ptr; i++) {
		if ((mag[i] & 1) == 0) {	// even
			int upper_b = mag[i] + idx_to_do[i];
			for (int j = idx_to_do[i]; j < upper_b; j+=2) {
				if (j >= idx_ptr - 1) {
					s[j] = genChar(s[j], s[j - 1]);
				}
				else if (j <= 0) {
					s[j] = genChar(s[j], s[j + 1]);
				}
				else {
					s[j] = genChar(s[j - 1], s[j + 1]);
				}
			}
		}
		else {	// odd
			int upper_b = mag[i] + idx_to_do[i];
			for (int j = idx_to_do[i] + 1; j < upper_b; j += 2) {
				if (j >= idx_ptr - 1) {
					s[j] = genChar(s[j], s[j - 1]);
				}
				else if (j <= 0) {
					s[j] = genChar(s[j], s[j + 1]);
				}
				else {
					s[j] = genChar(s[j - 1], s[j + 1]);
				}
			}
		}
	}
	printf("%s", s);
	return 0;
}

/*
minimal number of changes:
e.g. abbbscsad
	bbbbsdadbsdscc
	 x x
	e.g. : asbbbbbbsadsdm
	aa	-> change 1
	aaa -> change 1
	aaaa -> change 2
	aaaaa -> change 2 (5 / 2)
	aaaaaa -> change 3 (6 / 2)
*/