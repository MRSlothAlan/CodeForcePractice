#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long int lld;
/*
sort all lucky numbers in increasing order,
1-based index of n?
*/
const lld MAX = 15;
char s[MAX];

int main() {
	scanf("%s", &s);
	int len = strlen(s);
	lld res_idx = 0;
	lld tmp = 2;
	for (int p = 1; p < len; p++) {
		res_idx += tmp;
		tmp *= 2;
	}
	int pow_val = len - 1;
	for (int i = 0; i < len; i++) {
		if (s[i] == '7') {
			res_idx += pow(2, pow_val - i);
		}
	}
	printf("%lld", res_idx + 1);
	return 0;
}