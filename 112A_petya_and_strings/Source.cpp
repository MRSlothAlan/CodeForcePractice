#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
char s1[120], s2[120];

void toLower(char* s) {
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		if (s[i] < 'a') {
			s[i] = (char)(s[i] + 32);
		}
	}
}

int main() {
	scanf("%s", &s1); scanf("%s", &s2);
	toLower(s1); toLower(s2);
	printf("%d", strcmp(s1, s2));
	return 0;
}