#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
typedef long long int lld;
using namespace std;
const int MAX = 200000;
char s[2][MAX], tmp_min[MAX], min_str[MAX];
uint64_t val[2];	// value of two strings.

void get_val() {
	for (int i = 0; i < 2; i++) {
		val[i] = 0;
		int len = strlen(s[i]);
		int pow_val = len - 1;
		for (int j = 0; j < len; j++) {
			if (s[i][j] == '1') {
				val[i] += pow(2, pow_val - j);
			}
		}
	}
}

void generate_tmp_min(lld in_k) {
	uint64_t tmp_val = val[0] + val[1] * pow(2, in_k);
	// try this out.
	uint64_t tmp = tmp_val;
	unsigned b = 0;
	while (tmp >>= 1) { b++; }
	memset(tmp_min, '\0', sizeof(tmp_min));
	for (int p = 0; p <= b; p++) {
		if ((tmp_val >> p) & 1) {
			tmp_min[b - p] = '1';
		}
		else {
			tmp_min[b - p] = '0';
		}
	}
	strrev(tmp_min);
	printf("%s\n", tmp_min);
}

unsigned getSize(uint64_t tmp) {
	unsigned b = 0;
	while (tmp >>= 1) { b++; }
	return b;
}


int main() {
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%s", &s[0]); 
		scanf("%s", &s[1]);
		// get_val();
		strrev(s[0]); lld len_x = strlen(s[0]);
		strrev(s[1]); lld len_y = strlen(s[1]);
		// reversed y?
		lld y_pos = 0;
		for (; y_pos < len_y; y_pos++) {
			if (s[1][y_pos] == '1') {
				break;
			}
		}
		// the start idx is y_pos.
		lld x_pos = y_pos;
		for (; x_pos < len_x; x_pos++) {
			if (s[0][x_pos] == '1') {
				break;
			}
		}
		printf("%lld\n", x_pos - y_pos);
	}
	return 0;
}
/* 
1
1010101010101
11110000
test cases?
well, 
x	1010101010101
y	00001111
*/

/*
old, naive way to generate stuff:
// lld k = 0, res_cnt = 0;
		// generate_tmp_min(k++);
		// strcpy(min_str, tmp_min);
		// how to pick the right k value?
		for (;; k++) {
			// generate_tmp_min(k);
			// if (strcmp(tmp_min, min_str) >= 0) {
			strcpy(min_str, tmp_min);
			res_cnt++;
		}
		printf("%lld\n", res_cnt);
*/

/*
4
1010
11
10001
110
1
1
1010101010101
11110000
*/

/*
fun main(args: Array<String>) {
	val T = readLine()!!.toInt()
	for (tc in 1..T) {
		val x = readLine()!!.reversed()
		val y = readLine()!!.reversed()

		val posY = y.indexOf('1')
		val posX = x.indexOf('1', posY)
		println(posX - posY)
		// pos.
	}
}
*/

/*
***** Multiplying by power of 2 is "shift left" binary operation (you, probably, should know it). 

Reverse x and y for the simplicity and look at leftmost 1 in y (let's denote its position as posy).

If you move it to 0 in x then you make the revk lexicographically bigger than the reverse of x. 
So you should move it to 1 in x too. You can choose any 1 with position ≥posy.

Let posx be the minimum position of 1 in x, such that posx≥posy. 
You must move posy to posx, otherwise the 1 in posx still be present in revk and it will be not optimal.

So, the solution is next: 
reverse x and y, find posy, find posx≥posy, 
print posx−posy.

*/