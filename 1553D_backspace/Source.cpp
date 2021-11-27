#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
const int MAX = 1e5 + 500;
char s[MAX], t[MAX];

int main() {
	int N; scanf("%d", &N);
	while (N--) {
		scanf("%s", &s); scanf("%s", &t);
		int ptrS = strlen(s) - 1,
			ptrT = strlen(t) - 1;
		while (ptrS >= 0 && ptrT >= 0) {
			if (s[ptrS] == t[ptrT]) {
				ptrS--; ptrT--;
			}
			else {
				ptrS -= 2;
			}
		}
		if (ptrT < 0) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}

/*
The main idea of the problem is that backspace results in losing 2 characters, 
the one we intended to type (which we replace with a backspace) and the character that the backspace will remove.

In general, the idea is to compare every letter si with tj ​starting from right to left, 
if they match we will move to compare si−1 with tj−1 in the next step, 
else if they don't match we will delete si and si−1, then compare si−2 with tj in the next step and so on.

If we successfully matched all characters in t we will print YES, NO otherwise.
*/

/*
int rec[MAX], next[MAX];
next[0] = -1;
int i = 0, j = -1;
while (i < len_pat && j < len_pat) {
	if (j == -1 || t[i] == t[j]) {
		next[++i] = ++j;
	}
	else {
		j = next[j];
	}
}
int len = strlen(s);
i = 0; j = 0;
bool found = false;
while (i < len && !found) {
	if (j == -1 || s[i] == t[j]) {
		i++; j++;
	}
	else {
		if (j == len_pat) {
			found = true;
			break;
		}
		j = next[j];
	}
}
if (j == len_pat)
found = true;
if (found) {
	printf("YES\n");
}
else {
	printf("NO\n");
}
*/

/*
int len = strlen(s), ptr_pat = 0, len_pat = strlen(t);
		for (int i = 0; i < len; i++) {
			if (ptr_pat >= len_pat)
				break;
			else if (s[i] == t[ptr_pat]) {
				ptr_pat++;
			}
		}
		if (ptr_pat >= len_pat)
			printf("YES\n");
		else
			printf("NO\n");
*/