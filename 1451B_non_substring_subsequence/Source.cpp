#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
/*
binary string.
good substring?
	logic: it is guaranteed that the substring can be found within the string.

people don't support you, they DISCOURAGE you? for NO reason at all.
For the entire year was like why? You should have something to do right? 

FOCUS.
*/

const int MAX = 120;
char s[MAX];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, q; scanf("%d %d", &n, &q);
		scanf("%s", &s);
		for (int i = 0; i < q; i++) {
			int l, r; scanf("%d %d", &l, &r); l--; r--;
			char first = s[l]; char last = s[r]; l--; r++;
			for (; l >= 0; l--) { if (s[l] == first) { break; } } l++;
			for (; r < n; r++) { if (s[r] == last) { break; } } r--;
			if (l == 0 && r == n - 1) {
				printf("NO\n");
			}
			else {
				printf("YES\n");
			}
		}
	}
	return 0;
}
/*
In each query, the answer is YES iff the first character of the given substring is not the first 
occurence of that character 
	or 
the last character of the given substring is not the last occurrence of that character in the string.
*/