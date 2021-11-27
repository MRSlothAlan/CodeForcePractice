#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
typedef long long int lld;
const int MAX = 1e6 * 4;
char s[MAX], tmp[10];

bool valid_num(const char * str) {
	lld val = 0;
	while (*str) {
		val = val * 10 + (*str++ - '0');
	}
	return val % 4 == 0;
}


int main() {
	scanf("%s", &s);
	int len = strlen(s);
	lld cnt = 0;
	// boring naive way.
	for (int i = 0; i < len; i++) {
		tmp[0] = s[i];
		tmp[1] = '\0';
		if (valid_num(tmp)) {
			cnt++;
		}
	}
	for (int j = 0; j < len - 1; j++) {
		tmp[0] = s[j];
		tmp[1] = s[j + 1];
		tmp[2] = '\0';
		if (valid_num(tmp)) {
			cnt += j + 1;	// two digits divisible by 4 then ok, pick right most index.
		}
	}
	printf("%lld", cnt);
	return 0;
}
/*
substring 

5810438174

8, 0, 4, 8, 4
80, 84, 88, 84
04, 08, bababa..

*/