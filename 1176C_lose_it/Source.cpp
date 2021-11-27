#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
const int MAX = 700000;
int seq[6] = { 4, 8, 15, 16, 23, 42 };
map<int, int> M;
int rec[7];
int arr[MAX];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < 6; i++) { rec[i] = 0; }
	for (int i = 1; i <= 6; i++) {
		M.insert(pair<int, int>(seq[i - 1], i));
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	if (n == 0) {
		printf("0");
	}
	else if (n <= 5) {
		printf("%d", n);

	}
	else {
		rec[0] = n;	// init, all 4s.
		for (int i = 0; i < n; i++) {
			if (M.find(arr[i]) != M.end()) {
				int idx = M.at(arr[i]);
				if (rec[idx - 1]) {
					rec[idx - 1]--;	// init state --
					rec[idx]++;	// move on.
				}
			}
		}
		printf("%d", n - (rec[6] * 6));
	}
	return 0;
}


/*
100
4 42 23 23 8 42 16 23 42 16 42 8 4 23 4 4 23 42 16 42 23 23 23 42 4 42 8 8 16 23 15 23 16 4 42 15 15 23 16 15 16 4 4 15 23 42 42 15 8 23 8 23 4 15 16 15 42 8 23 16 15 42 23 8 4 16 15 16 23 16 16 4 23 16 8 23 16 15 23 4 4 8 15 4 4 15 8 23 23 4 4 8 8 4 42 15 4 4 42 16

*/


/*
else {
	bool valid = true;
	for (int i = 0; i < n && valid; i++) {
		if (arr[i] == 4 && !checked[i]) {
			checked[i] = true;
			int tmp_ptr = 1, idx = i + 1;
			for (; idx < n && tmp_ptr < 6; idx++) {
				if (arr[idx] == seq[tmp_ptr]) {
					checked[idx] = true;
					tmp_ptr++;
				}
			}
			if (tmp_ptr < 6) {
				valid = false;
			}
			else {
				for (int i = 0; i < 6; i++) {
					rec[i]--;
				}
			}
		}
	}
	long int res = 0;
	for (int i = 0; i < 6; i++) {
		res += rec[i];
	}
	printf("%ld", res);
}
*/

/*
Let cnt1 be the number of subsequences [4], cnt2 be the number of subsequences [4,8], cnt3 — the number of subsequences [4,8,15] and so on, 
and cnt6 is the number of completed subsequences [4,8,15,16,23,42].

Let's iterate over all elements of a in order from left to right. 
If the current element is 4 then let's increase cnt1 by one (we staring the new subsequence). 
Otherwise it is always better to continue some existing subsequence (just because why not?). 
If the current element is 8 then we can continue some subsequence [4], 
if it is 16 then we can continue some subsequence [4,8,15] and the same for remaining numbers. 
Let pos be the 1-indexed position of the current element of a in list [4,8,15,16,23,42]. 
Then the case pos=1 is described above, and in other case (pos>1) if cntpos−1>0 then let's set cntpos−1:=cntpos−1−1 and cntpos:=cntpos+1 
(we continue some of existing subsequences). The answer can be calculated as n−6cnt6 after all n iterations.
*/