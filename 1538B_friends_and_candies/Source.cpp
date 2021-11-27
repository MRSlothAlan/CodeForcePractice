#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
typedef long long int lld;
const int MAX_ = 400000;
int arr[MAX_];
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		lld sum_ = 0;
		for (int i = 0; i < n; i++) { scanf("%d", &arr[i]); sum_ += arr[i]; }
		if ((sum_ % n) != 0) {
			printf("-1\n");
		}
		else {
			int cnt = 0;
			lld tmp = sum_ / n;
			for (int i = 0; i < n; i++) {
				if (arr[i] > tmp) {
					cnt++;
				}
			}
			printf("%d\n", cnt);
		}
	}
	return 0;
}
/*
Let's denote for s the number of candies all friends have: 
s=∑i=1nai. Note that at the end, each friend must have s / n of candy. 
If s is not completely divisible by n, then there is no answer.

How to get the answer if it exists? 
If the i-th friend has more candies than s / n, 
then he must be chosen by Polycarp 
(otherwise this friend will have more candies than the others). 
If the i-th friend has no more than s / n, then Polycarp may not choose it.

Then, if the answer exists, it is equal to the number of ai> s / n.
*/