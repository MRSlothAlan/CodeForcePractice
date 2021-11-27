#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

/*
choose k, find a, len k
	1 <= a1 <= a2 <= len
*/
/*
I am almost there!
*/
/*
There are several different ways to solve this problem. 
In my opinion, the two easiest solutions are:
	notice that, in the sorted string, there is a prefix of zeroes 
	and a suffix of ones. It means that we can iterate on the prefix (from which we remove all ones), and remove all zeroes from the suffix we obtain. If we try to remove two adjacent characters, then we cannot use this prefix;

	if there is a substring 11 before the substring 00 in our string, then from both of the substrings, 
	at least one character remains, so if the first occurrence of 11 is earlier than the last occurrence of 00, 
	there is no answer. Otherwise, the answer always exists.
*/
char s[200];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%s", &s);
		int n = strlen(s);
		if (n < 4)
			printf("YES\n");
		else {
			bool valid = true;
			int find_11_idx = -1;
			int find_00_idx = n;
			for (int i = 0; i + 1 < n && find_11_idx == -1; i++) {
				if (s[i] == '1' && s[i + 1] == '1') {
					find_11_idx = i;
					break;
				}
			}
			for (int i = n - 1; i >= 1 && find_00_idx == n; i--) {
				if (s[i - 1] == '0' && s[i] == '0') {
					find_00_idx = i - 1;
					break;
				}
			}
			if (find_11_idx != -1 && find_00_idx != n && find_11_idx < find_00_idx) {
				printf("NO\n");
			}
			else {
				printf("YES\n");
			}
			/*
			for (int i = 0; i + 3 < n && valid; i++) {
				if (s[i] == '1' && s[i + 1] == '1' &&
					s[i + 2] == '0' && s[i + 3] == '0') {
					valid = false;
				}
			}
			if (valid) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
			*/
		}
	}
	return 0;
}