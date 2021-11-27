#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
typedef long long int lld;
// canine poetry
int len = 0;
const int MAX = 300000;
char s[MAX];
bool marked[MAX];
lld res_cnt;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%s", &s); len = strlen(s);
		memset(marked, false, sizeof(marked));
		res_cnt = 0;
		// check the starting point.
		if (len == 1) {
			printf("0\n");
		}
		else {
			if (s[0] == s[1]) {
				res_cnt++; marked[1] = true;
			}
			for (int i = 2; i < len; i++) {
				if (s[i] == s[i - 1] && !marked[i] && !marked[i - 1]) {
					marked[i] = true;
					res_cnt++;
				}
				// should I greedly pick the letter later, since more substring will be affected.
				// my old code almost did that but people said it is still wrong so your are stupid???
				if (s[i] == s[i - 2] && !marked[i] && !marked[i - 2]) {
					marked[i] = true;
					res_cnt++;
				}
			}
			printf("%lld\n", res_cnt);
		}
	}
	return 0;
}

/*
reads the same backwards and forwards haha
min number of modifications, such that the string
do not contain any palindromes of length greater than 1.
*/
// test case : mmmmmmmtmsammmmmmfm, damn, the substring there is 4, not 5.
//			   ftttttfftfftfttftff

/*
tutorial:

The main observation is that if there exists a palindrome of length larger than 3, 
then there exists a palindrome of length 2 or 3. 
This observation allows us to simplify the task to erasing all palindromes of length 2 or 3. 
We can also notice that each character will be replaced at most once.

From now on, there are a few possible solutions. 
The easiest one is to iterate over a word from left to right. 
When we encounter a palindrome (of length 2 or 3) ending on the current position, 
consisting of unmarked elements, we greedily mark this character as the one we want to replace. 
The number of marked characters is the answer, 
as it turns out that we can obtain a valid palindrome-less sequence 
by replacing only the letters on the marked positions. The complexity is O(n).

The sketch of proof is as follows: 

it is sufficient to ensure that each marked character does not coincide with 4 neighboring characters, 
so we are still left with 22 remaining possibilities.

We can try different approaches too. One of these is a dp-based solution, 
where the state dp[i][ca][cb] denotes the minimal result after analyzing first i elements, where characters si and si−1 are equal to ca and cb respectively. This dp can be implemented in O(n⋅262), which should pass, but is pretty messy to implement, so we want to improve it.

We can notice that we are not interested in the last 2 characters' exact values, but only if these were changed or not (the same observation as in the greedy solution). Thanks to this, our state changes to dp[i][ci][ci−1], where ci encodes whether i-th character was changed. This dp can be cleanly implemented in linear time.

*/

/*
int l_b, r_b;
if ((len & 1) == 0) {
	l_b = len / 2 - 1;
	r_b = len / 2 + 1;
}
else {
	l_b = len / 2 - 1;
	r_b = len / 2;
}
			if (s[0] == s[1]) { marked[1] = true; res_cnt++; }
if (s[len - 1] == s[len - 2]) { marked[len - 2] = true; res_cnt++; }
// go in two directions.
// so, the sol said just loop once. check out their proof.
for (int i = 1; i <= l_b; i++) {
	if (s[i] == s[i + 1] && !marked[i] && !marked[i + 1]) {
		marked[i] = true;
		res_cnt++;
	}
	// should I greedly pick the letter later, since more substring will be affected.
	if (s[i + 1] == s[i - 1] && !marked[i + 1] && !marked[i - 1]) {
		marked[i + 1] = true;
		res_cnt++;
	}
}
for (int i = len - 2; i >= r_b; i--) {
	if (s[i] == s[i - 1] && !marked[i] && !marked[i - 1]) {
		marked[i - 1] = true;
		res_cnt++;
	}
	// should I greedly pick the letter later, since more substring will be affected.
	if (s[i + 1] == s[i - 1] && !marked[i + 1] && !marked[i - 1]) {
		marked[i - 1] = true;
		res_cnt++;
	}
}
// well.
*/