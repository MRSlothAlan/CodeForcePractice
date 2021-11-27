#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#define MIN(a, b) a < b ? a : b;
// a city with n buildings
const int MAX = 300000;
char s[MAX];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int a, b; // the cost to activate / place one mine
		scanf("%d %d", &a, &b);
		scanf("%s", &s);
		int len = strlen(s); 
		long int p0 = 0, p1 = a;
		for (int i = 0; i < len; i++) {
			if (s[i] == '0') {
				p1 = MIN(a + p0, b + p1);	// that's actually for the NEXT p1.
			}
			else {
				// equalize the values since only need to activate ONCE for each segment.
				long int val = MIN(a + p0, p1);
				p0 = val; p1 = val;
			}
		}
		printf("%ld\n", p0);
	}
	return 0;
}

/*
Since the activation of any mine explodes the 
entire segment of mines, which it is, 
you can immediately replace the input string with an array 
of mine segments. 
We now have two operations. 

We can delete any segment by a coins, 
or turn two adjacent segments [l1,r1], [l2,r2] (r1<l2) 
into one segment for b⋅(l2−r1). 
That is, two segments can be deleted for a cost of 2⋅a 
or a+b⋅(l2−r1). This means that you need to merge 
two segments while b⋅(l2−r1)≤a. 
You need to go through all adjacent segments and 
check this condition.
*/

/*
activate / place.
e.g.
01101110
12345678
place a mine on 4, activate it.
01201230
02103210
*/



/*
tmp = 0;
for (i = 0; i < len; i++) {
	if (s[i] == '1') tmp++;
	else tmp = 0;
	rec[i] = tmp;
}
tmp = 0;
for (i = len - 1; i >= 0; i--) {
	if (s[i] == '1') tmp++;
	else tmp = 0;
	rec_rev[i] = tmp;
}
long int cost = 0;
if (len == 1) {
	printf("%d\n", a);
}
else {
	// len at least > 2.
	i = 1, j = len - 1;
	if (rec_rev[1] > 0 && s[0] == '0') {
		cost += MIN(a * rec_rev[1], a + b);
		i = rec_rev[1] + 1;
	}
	else if (s[0] == '1' && rec_rev[0] > 1) {
		cost += MIN(a * rec_rev[0], a + b);
		i = rec_rev[0];
	}
	if (s[0] == '1' && s[1] == '0') {
		cost += a;
	}
	while (i <= j) {
		if (i == j) {
			if (s[i] == '1') {
				cost += a;
			}
			i++;
		}
		else if (s[i] == '1'
			&& rec[i - 1] == 0
			&& rec_rev[i + 1] == 0) {
			cost += a;
			i++;
		}
		else if (s[i] == '0'
			&& rec[i - 1] > 0
			&& rec_rev[i + 1] > 0) {
			cost += MIN(a + b, a * (rec[i - 1] + rec_rev[i + 1]));
			i += rec_rev[i + 1] + 1;
		}
		else {
			i++;
		}
	}
	printf("%ld\n", cost);
}
*/



/*
int rec[MAX],
	rec_rev[MAX],

seg_left[MAX], seg_right[MAX], seg_ptr;
bool checked[MAX];

int i, j, l, r;
l = -1;
seg_ptr = 0;
for (i = 0; i < len; i++) {
	if (s[i] == '1' && l == -1) {
		l = i;
	}
	else if (s[i] == '0') {
		if (l != -1) {
			checked[seg_ptr] = false;
			seg_left[seg_ptr] = l;
			seg_right[seg_ptr] = i - 1;
			seg_ptr++;
			l = -1;
		}
	}
}
if (i == len && l != -1) {
	seg_left[seg_ptr] = l;
	seg_right[seg_ptr] = len - 1;
	seg_ptr++;
}
long int cost = 0;
if (seg_ptr == 0) {
	printf("0\n");
}
else if (seg_ptr == 1) {
	printf("%d\n", a);
}
else {
	for (i = 1; i < seg_ptr; i++) {
		if (!checked[i] && !checked[i - 1]) {
			long int b_cost = (seg_left[i] - seg_right[i - 1] - 1) * b;
			if (b_cost <= a) {
				cost += a + b_cost;
			}
			else {
				cost += a * 2;
			}
			checked[i] = true;
			checked[i - 1] = true;
		}
	}
	if (!checked[seg_ptr - 1]) {
		cost += a;
	}
	printf("%ld\n", cost);
}
*/