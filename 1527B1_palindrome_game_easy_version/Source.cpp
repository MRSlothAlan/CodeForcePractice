#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

const int MAX = 1001;
char in_str[MAX];
// this is the EASY version
// harder version cannot hard-code.
/*
each turn:
	choose any i, s[i] = 0, change to 1. pay $1
	reverse the whole str, pay $0
		only allowed if cur_str not a palin
		last opt != reverse.
	e.g. 01001 -> 10010
	game ends if every char == 1.
	min dollar = win.

ALICE goes first.
*/
int str_len = 0;

int count_zeros() {
	int res_z = 0;
	for (int i = 0; i < str_len; i++) {
		if (in_str[i] == '0') {
			res_z++;
		}
	}
	return res_z;
}

bool isPalindrome() {
	int start = 0;
	int end = str_len - 1;
	while (start <= end) {
		if (in_str[start] != in_str[end]) { return false; }
		start++; end--;
	}
	return true;
}

bool pickFromBack[2];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		memset(in_str, '\0', sizeof(in_str));
		scanf("%s", in_str);
		str_len = strlen(in_str);
		// ok my idea.
		if (str_len == 1 && in_str[0] == '0') {
			printf("BOB\n");
		}
		else {
			int zeros = count_zeros();
			if (zeros % 2) {
				printf("ALICE\n");
			}
			else {
				printf("BOB\n");
			}
		}
	}
	return 0;
}