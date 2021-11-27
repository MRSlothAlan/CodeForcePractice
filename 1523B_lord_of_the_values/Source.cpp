#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lld;

struct val {
	int idx;
	lld value;
	lld target;
	val() {}
	val(int in_i, lld in_v ) {
		this->idx = in_i;
		this->value = in_v;
		this->target = in_v * -1;
	}
};

struct opt {
	int type, i, j;
	opt() {}
	opt(int in_t, int in_i, int in_j) {
		this->type = in_t;
		this->i = in_i;
		this->j = in_j;
	}
};

const int MAX = 2000;
val arr[MAX];
vector<opt> operations;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		operations.clear();
		int n; scanf("%d", &n);
		for (int i = 1; i <= n ; i++) { 
			lld ai; scanf("%lld", &ai);
			arr[i] = val(i, ai);
		}
		for (int i = 1; i <= n; i += 2) {
			int j = i + 1;
			while (arr[i].value != arr[i].target ||
				arr[j].value != arr[j].target) {
				arr[i].value += arr[j].value;
				operations.push_back(opt(1, i, j));
				if (arr[i].value == arr[i].target && 
					arr[j].value == arr[j].target) { break; }
				else {
					arr[j].value -= arr[i].value;
					operations.push_back(opt(2, i, j));
				}
			}
		}
		printf("%d\n", operations.size());
		for (opt o : operations) {
			printf("%d %d %d\n", o.type, o.i, o.j);
		}

	}
	return 0;
}

/*
Notice that for transforming any pair of numbers (a,b) into a pair (−a,−b) 
a sequence of operations such as (1,2,1,2,1,2) can be performed. 
Since n is even we can apply this sequence of operations for all pairs of numbers (ai⋅2−1,ai⋅2) for all i from 1 to n2.
Final complexity: O(n).
*/

/* 
change values to neg?
number of action <= 5000
after opt, no var >= 1e18
opt allowed:
ai = ai + aj (first type)
aj = aj - ai (second type)
i < j
*/