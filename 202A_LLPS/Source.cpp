#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
typedef long long int lld;
// "Lexicographically Largest Palindromic Subsequence"
char s[20], buf[20], res[20];

// check buf is palindrome
bool isPalindrome() {
	int len = strlen(buf);
	int lst = len - 1;
	if (len == 1) { return true; }
	else if (len == 0) { return false; }
	else {
		if ((len & 1)) { // odd
			int cen = len / 2;
			for (int i = 0; i < cen; i++) {
				if (buf[i] != buf[lst - i]) {
					return false;
				}
			}
			return true;
		}
		else {
			int left = len / 2 - 1, right = len / 2;
			if (buf[left] != buf[right]) { return false; }
			else {
				for (int i = 0; i < left; i++) {
					if (buf[i] != buf[lst - i]) {
						return false;
					}
				}
			}
			return true;
		}
	}
}
int main() {	
	memset(res, '\0', sizeof(res));
	scanf("%s", &s);
	int len = strlen(s);
	lld mask = (1 << len) - 1, tmp;
	while (mask > 0) {
		uint16_t tmp = mask;	// this type make sure the unassigned bits are 0.
		// or should I say, no overflow?
		memset(buf, '\0', sizeof(buf)); 
		int idx = 0;
		// well, the exact opposite is needed.
		int lst_ptr = len - 1;
		for (int b = 0; b < len; b++) {
			if (((tmp >> b) & 1)) {
				buf[idx++] = s[lst_ptr - b];
			}
		}
		strrev(buf);
		// edit: I have the compare the length as well? 
		if (isPalindrome() && strcmp(buf, res) > 0) {
			strcpy(res, buf);
		}
		mask--;
	}
	printf("%s", res);
	return 0;
}
// mississipp

/*
		while (tmp > 0) {
			if ((tmp & 1)) {
				buf[idx] += s[idx++];
			}
			tmp >>= 1;
		}
*/