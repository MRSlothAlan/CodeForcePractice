// find bugabooset
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef long long ll;
#pragma warning(disable:4996)

int main() {
	// easy version, health must be no-negative.
	// it is wrong, if the starting value is negative.

	int n;	
	cin >> n;
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	ll sum = 0, potions = 0;
	
	for (int i = 0; i < n; i++) {
		ll a;
		cin >> a;
		sum += a;
		pq.push(a);
		potions++;
		// skips all the negatives at the start
		// keep adding values to sum, when sum < 0,
		// then you should remove some greatest negative values picked before.
		while (sum < 0) {
			sum -= pq.top();
			pq.pop(); potions--;
		}
	}
	cout << potions << endl;
	/*
	// your original code will NOT work, unless order
	does not matter.
	vector<int> in_seq(n);
	for (int i = 0; i < n; i++) {
		cin >> in_seq[i];
	}
	sort(in_seq.begin(), in_seq.end());
	int cnt = 0, tmp = 0;
	for (int i = n - 1; i >= 0 && tmp > 0; i--) {
		tmp += in_seq[i];
		cnt++;
	}
	cout << cnt << endl;
	*/
	return 0;
}