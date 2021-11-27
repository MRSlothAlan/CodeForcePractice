#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
const int MAX = 600000;
char s[MAX];
int val[MAX], idx[MAX];
long int valptr;
bool h[4];
#define MIN(a, b) a < b ? a : b;
/*
either 1, 2, 3.
*/
void insert(char in_c, int in_idx) {
	if (valptr == 0 || 
			val[valptr - 1] != (in_c - '0')) {
		val[valptr] = in_c - '0';
		idx[valptr] = in_idx;
		valptr++;
	}
	else if (val[valptr - 1] == (in_c - '0')) {
		idx[valptr - 1] = in_idx - idx[valptr - 1] + 1;
	}
	/*
	this is for the magnitude...
	// for the first value.
	idx[0]++;
	// for the last value.
	idx[valptr - 1] = len - idx[valptr - 1];
	*/
}

void insert_idx(char in_c, int in_idx) {
	val[valptr] = in_c - '0';
	idx[valptr] = in_idx;
	h[(in_c - '0')] = true;
	valptr++;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%s", &s);
		int len = strlen(s);
		if (len < 3) {
			printf("0\n");
		}
		else {
			memset(h, false, sizeof(h));
			valptr = 0;
			for (int i = 0; i < len - 1; i++) {
				if (s[i] != s[i + 1]) {
					insert_idx(s[i], i);
					insert_idx(s[i + 1], i + 1);
				}
			}
			if (h[1] && h[2] && h[3]) {
				int res_mag = MAX;
				for (int i = 3; i < valptr; i++) {
					if (val[i - 2] == val[i - 1]) {
						if (val[i - 3] + val[i - 1] + val[i] == 6) {
							res_mag = MIN(res_mag, idx[i] - idx[i - 3]);
						}
					}
				}
				printf("%d\n", res_mag + 1);
			}
			else {
				printf("0\n");
			}
		}

	}
	return 0;
}