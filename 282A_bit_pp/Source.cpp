#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

char s[3];
int main() {
	int n; scanf("%d", &n);
	int x = 0;
	for (int i = 1; i < n; i++) {
		scanf("%s", &s);
		if (s[0] == '+' && s[1] == '+') { ++x; }
		else if (s[1] == '+' && s[2] == '+') { x++; }
		else if (s[0] == '-' && s[1] == '-') { --x; }
		else if (s[1] == '-' && s[2] == '-') { x--; }
	}
	// last one.
	scanf("%s", &s);
	if (s[0] == '+' && s[1] == '+') { ++x; }
	else if (s[1] == '+' && s[2] == '+') { x++; }
	else if (s[0] == '-' && s[1] == '-') { --x; }
	else if (s[1] == '-' && s[2] == '-') { x--; }
	printf("%d", x);
	return 0;
}