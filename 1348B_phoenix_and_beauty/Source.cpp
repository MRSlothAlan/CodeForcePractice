#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
using namespace std;
typedef long long int lld;
/*
arr, len?
*/
const int MAX = 10500;
lld arr[MAX];
set<int> S;

// beautiful array problem
int main() {
	int t; scanf("%d", &t);
	S.clear();
	while (t--) {
		S.clear();
		int n, k; scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++) {
			scanf("%lld", &arr[i]);
			S.insert(arr[i]);
		}
		if (S.size() > k) {
			printf("-1\n");
		}
		else {
			// generate a pattern that must do it?
			if (n == k && S.size() == k) {
				printf("%d\n", n);
				for (int i = 0; i < n - 1; i++) {
					printf("%d ", arr[i]);
				}
				printf("%d\n", arr[n - 1]);
			}
			else if (n > k && S.size() == k) {
				// print multiple times
				int res_size = S.size() * n;
				auto itr = S.begin();
				printf("%d\n", res_size);
				for (int i = 0; i < n; i++) {
					for (itr = S.begin(); itr != S.end(); itr++) {
						printf("%d ", *itr);
					}
				}
				printf("\n");
			}
			else if (S.size() < k) {
				// append some one.
				vector<int> tmp;
				for (auto itr = S.begin(); itr != S.end(); itr++) {
					tmp.push_back(*itr);
				}
				while (tmp.size() < k) {
					tmp.push_back(1);
				}
				printf("%d\n", k * n);
				for (int i = 0; i < n; i++) {
					for (int val : tmp) {
						printf("%d ", val);
					}
				}
				printf("\n");
			}
		}
	}
	return 0;
}
/*
beautiful array?
-> sub arr, len k, have same sum?
-> sub = conseq.
a, n
insert?

example ?
1 2 2 1
k = 2?
1 2 1 2 1
don't have to min.
4 3 4 2
k = 4?
4 3 2 1 4 3 2?
k = 3?
4 3 2 4 3 2
cannot?
k = 2
1 2 3? nope?
*/