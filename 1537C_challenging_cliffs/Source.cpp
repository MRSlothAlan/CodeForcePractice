#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long int lld;
const int INF = 1e11;
const int MAX = 300000;
lld arr[MAX];
// learn the proof got damn it.
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lld", &arr[i]);
		}
		sort(arr, arr + n);
		int idx_a, idx_b;
		lld min_diff = INF;
		for (int i = 0; i < n - 1; i++) {
			lld diff = abs(arr[i] - arr[i + 1]);
			if (diff < min_diff) {
				min_diff = diff;
				idx_a = i; idx_b = i + 1;
			}
		}
		printf("%lld ", arr[idx_a]);
		for (int i = idx_a + 2; i < n; i++) {
			printf("%lld ", arr[i]);
		}
		for (int i = 0; i < idx_a; i++) {
			printf("%lld ", arr[i]);
		}
		printf("%lld\n", arr[idx_b]);
	}
	return 0;
}
/*
from all arrangments that min(abs(h1 - hn))
find the most difficult one.
We claim that the maximum difficulty is at least n−2. 
Assume the array is sorted. 
We first need to find the two mountains which go on 
the ends. 
To do this, we can iterate through every mountain in 
the sorted array and check the difference between a 
mountain and its neighbours in the array. 
Let mk and mk+1 be the mountains with the smallest 
height difference. 
We can achieve at least a difficulty of n−2 by 
arranging the mountains as 
mk,mk+2,mk+3...mn,m1,m2,.....,mk+1. 
To get difficulty n−1, 
we need mk to be the shortest mountain and mk+1 to 
be the tallest mountain. 
This will only happen if n=2.
*/