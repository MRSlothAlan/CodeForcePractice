#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
// n is even, 2 <= n <= 50
const int MAX = 70;
char s[MAX], tmp[MAX];
int s_ptr;

void set_val(int idx, int flag) {
	if (flag) {
		tmp[idx] = ')';
	}
	else {
		tmp[idx] = '(';
	}
}

bool isValid(int len) {
	s_ptr = 0;
	for (int i = 0; i < len; i++) {
		if (tmp[i] == '(') {
			s_ptr++;
		}
		else if (tmp[i] == ')') {
			if (s_ptr <= 0) {
				return false;
			}
			s_ptr--;
		}
	}
	return s_ptr == 0 ? true : false;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%s", &s);
		int len = strlen(s);
		bool valid = false;
		for (int a = 0; a <= 1 && !valid; a++) {
			for (int b = 0; b <= 1 && !valid; b++) {
				for (int c = 0; c <= 1 && !valid; c++) {
					memset(tmp, '\0', sizeof(tmp));
					for (int i = 0; i < len; i++) {
						if (s[i] == 'A') { set_val(i, a); }
						else if (s[i] == 'B') { set_val(i, b); }
						else if (s[i] == 'C') { set_val(i, c); }
					}
					if (isValid(len)) {
						valid = true;
						break;
					}
				}
			}
		}
		if (valid) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}