#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1000;
char s[MAX], res[MAX];
char dp_rec[10][MAX];
/* some math to proof and study. */

bool com(char l, char r) {
	return l > r;
}

int main() {
	strcpy(dp_rec[0], "");
	strcpy(dp_rec[1], "");
	strcpy(dp_rec[2], "2");
	strcpy(dp_rec[3], "3");
	strcpy(dp_rec[4], "322");
	strcpy(dp_rec[5], "5");
	strcpy(dp_rec[6], "53");
	strcpy(dp_rec[7], "7");
	strcpy(dp_rec[8], "7222");
	strcpy(dp_rec[9], "7332");

	int n; scanf("%d", &n);
	scanf("%s", &s);
	int len = strlen(s);
	// no zeros and ones.
	memset(res, '\0', sizeof(res));
	int str_ptr = 0;
	for (int i = 0; i < len; i++) {
		int digit = s[i] - '0';
		if (digit > 1) {
			int len_tmp = strlen(dp_rec[digit]);
			for (int j = 0; j < len_tmp; j++) {
				res[str_ptr++] = dp_rec[digit][j];
			}
		}
	}
	sort(res, res + str_ptr, com);
	printf("%s", res);
	return 0;
}
/*
BTW, business, trading hm... it is all about people...

a, n digits, >= 1 digit > 1, can start with leading 0.
max pos number x:
	=> no 0 or 1.
	=> F(x) = F(a)
Well, F(1234) = F(33222)


Conclusion first:

First, we transform each digit of the original number as follows:
0, 1 -> empty
2 -> 2
3 -> 3
4 -> 322
5 -> 5
6 -> 53
7 -> 7
8 -> 7222
9 -> 7332

Then, sort all digits in decreasing order as a new number, then it will be the answer.

Proof:

We can observe that our answer won't contain digits 4,6,8,9, 
because we can always transform digits 4,6,8,9 to more digits as in the conclusion, 
and it makes the number larger.

Then, how can we make sure that the result is the largest after this transformation?

We can prove the following lemma:

For any positive integer x, if it can be written as the form (2!)c2 * (3!)c3 * (5!)c5 * (7!)c7, 
there will be only one unique way.

Suppose that there exists two ways to write down x in this form, 
we can assume that the two ways are (2!)a2 * (3!)a3 * (5!)a5 * (7!)a7 
and (2!)b2 * (3!)b3 * (5!)b5 * (7!)b7.

We find the largest i such that ai ≠ bi, Then we know there exists at least one prime number 
whose factor is different in the two ways.

But according to the Fundamental Theorem of Arithmetic, there is only one prime factorization of each integer. 
So we get a contradiction.

After getting the result, we don't need to worry about other numbers being larger than ours.

Time Complexity: O(n).
*/