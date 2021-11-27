#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
/* pancakes. */
const int MAX = 300000;
int dp[MAX];
int arr[MAX];

/*
1
17
0 0 0 0 0 0 0 5 2 0 0 0 0 0 4 6 2
20
0 0 0 5 1 0 0 0 0 0 0 0 0 1 0 0 0 0 4 2
*/
// time limit exceeded.
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) { 
			scanf("%d", &arr[i]);
			dp[i] = 0;
		}
		/*
		The i-th layer is drenched in cream if there is such j≥i that j−aj<i.

		Then we can calculate answers for all layers i in reverse order
		(from n to 1) and maintain minimum over all values j−aj as some variable mn.

		As a result, when we move from i+1 to i, we update mn=min(mn,i−ai) and then check that mn<i.
		similar to my idea, but I get TLE.
		My logic: keep reducing current cream cnt until an array value is larger. continue from there to keep pour cream
		PROBLEM : a lot of EXTRA check && minus.
		*/
		int mn = MAX;
		for (int i = n; i >= 1; i--) {
			mn = min(mn, i - arr[i]);
			if (mn < i) {
				dp[i] = 1;
			}
		}
		for (int i = 1; i < n; i++) {
			printf("%d ", dp[i]);
		}
		printf("%d\n", dp[n]);
		/*
		int cur = n;
		while( cur > 0 ) {
			int cream = arr[cur];
			if (cream > 0) {
				dp[cur--] = 1;
				cream--;
				while (cream > 0 && arr[cur] < cream) {
					dp[cur--] = 1;
					cream--;
				}
			}
			else if (cream == 0) {
				cur--;
			}
		}
		*/
	}
	return 0;
}
