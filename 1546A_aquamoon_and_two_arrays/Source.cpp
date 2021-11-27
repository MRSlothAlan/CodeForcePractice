#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int, int> pr;
const int MAX = 120;
int a[MAX], b[MAX];
vector<pr> res_step;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		res_step.clear();
		int n; scanf("%d", &n);
		int sum_a = 0, sum_b = 0;
		for (int i = 0; i < n; i++) { scanf("%d", &a[i]); sum_a += a[i]; }
		for (int i = 0; i < n; i++) { scanf("%d", &b[i]); sum_b += b[i]; }
		if (sum_a != sum_b) { 
			printf("-1\n"); 
		}
		else {
			int steps_cnt = 0;
			int ptr = 0, ptr_next = 0;
			while (ptr < n) {
				if (a[ptr] > b[ptr]) {
					for (ptr_next = 0; ptr_next < n; ptr_next++) {
						if (a[ptr_next] < b[ptr_next]) { break; }
					}
					a[ptr]--; a[ptr_next]++;
					res_step.push_back(pr(ptr + 1, ptr_next + 1));
				}
				else if (a[ptr] < b[ptr]) {
					for (ptr_next = 0; ptr_next < n; ptr_next++) {
						if (a[ptr_next] > b[ptr_next]) { break; }
					}
					a[ptr]++; a[ptr_next]--;
					res_step.push_back(pr(ptr_next + 1, ptr + 1));
				}
				else if (a[ptr] == b[ptr]) {
					ptr++;
				}
			}
			steps_cnt = res_step.size();
			printf("%d\n", steps_cnt);
			for (pr val : res_step) {
				printf("%d %d\n", val.first, val.second);
			}
		}
	}
	return 0;
}

/*
She chooses two indices i and j (1 <= i, j <= n)
	decreases the ith element of array a by 1.
	increases the jth element of array a by 1.
each element must be >= 0
if i = j, doesn't change the array a.
*/