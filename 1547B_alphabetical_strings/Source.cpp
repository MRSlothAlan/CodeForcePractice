#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
const int MAX = 30;
char s[MAX];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%s", &s);
		int cur_ptr = 0, len = strlen(s);
		for (; cur_ptr < len &&
			s[cur_ptr] != 'a'; cur_ptr++) {}
		if (cur_ptr >= len) {
			printf("NO\n");
		}
		else {
			bool valid = true;
			char next_char = 'a' + 1;
			int left = cur_ptr - 1, right = cur_ptr + 1;
			while (left >= 0 && right < len) {
				bool moved = false;
				if (s[left] == next_char) {
					left--;
					moved = true;
					next_char++;
				}
				if (!moved && s[right] == next_char) {
					right++;
					moved = true;
					next_char++;
				}
				if (!moved)
					break;
			}
			char next_char_cpy = next_char;
			while (left >= 0) {
				if (s[left] == next_char_cpy) {
					left--;
					next_char_cpy++;
				}
				else {
					break;
				}
			}
			next_char_cpy = next_char;
			while (right < len) {
				if (s[right] == next_char_cpy) {
					right++;
					next_char_cpy++;
				}
				else {
					break;
				}
			}
			if (left < 0 && right >= len) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}
	return 0;
}

/*
	s = ""
	perform the next step n times.
	ith step, take ith lowercase letter.
		write it to the left / right of the string.
*/