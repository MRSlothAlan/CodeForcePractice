#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;

deque<int> DQ;
const int MAX = 120;
char s[MAX];
int dp[MAX], len_rec[MAX], ptr;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		DQ.clear();
		int n, a, b; scanf("%d %d %d", &n, &a, &b);
		scanf("%s", &s);
		int len = strlen(s);
		if (b >= 0) {
			printf("%d\n", (a + b) * len);
		}
		else if (b < 0) {
			char prev = s[0]; int cur_len = 0, i = 0, prev_start;
			ptr = 0;
			for (; i < len; i++) {
				if (prev != s[i]) {
					prev = s[i];
					// len_rec[ptr++] = cur_len;
					DQ.push_back(cur_len);
					cur_len = 0;
					prev_start = i;
				}
				cur_len++;
				dp[i] = cur_len;
			}
			// len_rec[ptr++] = cur_len;
			DQ.push_back(cur_len);
			int res_val = 0;
			while (DQ.size() > 2) {
				cur_len = DQ[1];
				res_val += a * cur_len + b;
				DQ.erase(DQ.begin() + 1);
				int next_len = DQ[1];
				DQ[0] += next_len;
				DQ.erase(DQ.begin() + 1);
			}
			for (int rem_len : DQ) {
				res_val += a * rem_len + b;
			}
			printf("%d\n", res_val);
		}
	}
	return 0;
}

/*
3
7 1 -4
1001110
*/

/* 
operation: consec. substr of equal char, 
erase them from string.
delete a substr of length l
score : a * l + b points

Let l1,l2,…,lk be the length of the substring deleted at the i-th step.	
Then the number of points will be equal to ∑i=1k(a⋅li+b) or a∑i=1kli+bk. 

The sum of all li is equal to n (because in the end we deleted the entire string), 
so the final formula has the form an+bk. Obviously, for b≥0, you should delete the characters one by one so that k=n. 

Now b<0 and you have to delete the string in the minimum number of operations. 

Let the string s consist of m blocks of zeros and ones, then ⌊m2⌋+1 is the minimum number of operations for which the entire string can be deleted. 

As long as the number of blocks is more than 2, we will delete the second block, the number of blocks will decrease by 2 after each such operation
(the block that we delete will disappear, and the first and third blocks will merge into one).
*/