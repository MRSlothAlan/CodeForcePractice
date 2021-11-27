#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

int main() {
	// warm-ups.
	int t; scanf("%d", &t);
	char in_str[200];
	while (t--) {
		scanf("%s", in_str);
		int len = strlen(in_str);
		if (len > 10) {
			printf("%c%d%c\n", in_str[0], len - 2, in_str[len - 1]);
		}
		else {
			printf("%s\n", in_str);
		}
	}
	return 0;
}