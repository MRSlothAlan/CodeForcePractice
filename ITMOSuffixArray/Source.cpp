#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
ababba$
add 2 characters at the beginning of the string.

k = 1		k = 2
ba $a		4
bb a$		3
a$ ab		5
ab ab		0
$a ba		6
ab ba		2
ba bb		1
			(idx of CURRENT first char.)
*/

// opt 2
void count_sort(vector<int> &p, vector<int> &c) {
	int n = p.size();
	vector<int> cnt(n);
	for (auto x : c) {
		cnt[x]++;
	}
	vector<int> p_new(n);
	vector<int> pos(n);
	pos[0] = 0;	// position of bucket 0 is always 0.
	// position in bucket i ?
	for (int i = 1; i < n; i++) {
		pos[i] = pos[i - 1] + cnt[i - 1];
	}
	for (auto x : p) {
		int i = c[x];
		p_new[pos[i]] = x;
		pos[i]++;
	}
	 p = p_new;
}

// optimization : radix sort
// n log n algorithm, works in linear time.
void radix_sort(vector<pair<pair<int, int>, int>> &a) {
	int n = a.size();
	{
		// counting sort for the second element
		vector<int> cnt(n);
		for (auto x : a) {
			cnt[x.first.second]++;	// counting sort, place counters in bucket
		}
		vector<pair<pair<int, int>, int>> a_new(n);
		vector<int> pos(n);
		pos[0] = 0;	// position of bucket 0 is always 0.
		// position in bucket i ?
		for (int i = 1; i < n; i++) {
			pos[i] = pos[i - 1] + cnt[i - 1];
		}
		for (auto x : a) {
			int i = x.first.second;
			a_new[pos[i]] = x;
			pos[i]++;
		}
		a = a_new;
	}
	{
		// counting sort for the second element
		vector<int> cnt(n);
		for (auto x : a) {
			cnt[x.first.first]++;	// counting sort, place counters in bucket
		}
		vector<pair<pair<int, int>, int>> a_new(n);
		vector<int> pos(n);
		pos[0] = 0;	// position of bucket 0 is always 0.
		// position in bucket i ?
		for (int i = 1; i < n; i++) {
			pos[i] = pos[i - 1] + cnt[i - 1];
		}
		for (auto x : a) {
			int i = x.first.first;
			a_new[pos[i]] = x;
			pos[i]++;
		}
		a = a_new;
	}
}

int main() {
	string s;
	cin >> s;
	s += "$";
	int n = s.size();
	vector<int> p(n), c(n);
	{
		// k = 0;
		vector<pair<char, int>> a(n);
		for (int i = 0; i < n; i++) {
			a[i] = { s[i], i };	// put char && indice pairs
		}
		sort(a.begin(), a.end());
		for (int i = 0; i < n; i++) {
			p[i] = a[i].second;
		}
		c[p[0]] = 0;	// first class, assign classes as 0
		for (int i = 1; i < n; i++) {
			if (a[i].first == a[i - 1].first) {
				c[p[i]] = c[p[i - 1]];
			}
			else {
				c[p[i]] = c[p[i - 1]] + 1;
			}
		}
		// finished k = 0
		int k = 0;
		while ((1 << k) < n) {
			// k -> k + 1;
			// the pair of numbers with classes.
			/*
			vector<pair<pair<int, int>, int>> a(n);
			for (int i = 0; i < n; i++) {
				// find the equavilant class of left and right member
				// if k = 1, a 'gap' of 2 is included, which is
				// basically (i + (1 << 1)) % n (cylic index)
				a[i] = { { c[i], c[(i + (1 << k)) % n] }, i };
			}
			*/
			// shift string trick
			for (int i = 0; i < n; i++) {
				// shifted the starting index of the string.
				p[i] = (p[i] - (1 << k) + n) % n;
			}

			// use radix sort here.
			// radix_sort(a);
			count_sort(p, c);
			vector<int> c_new(n);
			c_new[p[0]] = 0;
			for (int i = 1; i < n; i++) {
				pair<int, int> prev = { c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n] };
				pair<int, int> now = {c[p[i]], c[(p[i] + (1 << k)) % n]};
				if (now == prev) {
					c_new[p[i]] = c_new[p[i - 1]];
				}
				else {
					c_new[p[i]] = c_new[p[i - 1]] + 1;
				}
			}
			c = c_new;
			// sort(a.begin(), a.end());

			/*
			for (int i = 0; i < n; i++) {
				p[i] = a[i].second;
			}
			c[p[0]] = 0;
			for (int i = 1; i < n; i++) {
				if (a[i].first == a[i - 1].first) {
					c[p[i]] = c[p[i - 1]];
				}
				else {
					c[p[i]] = c[p[i - 1]] + 1;
				}
			}
			*/
			k++;
		}
		/*
		for (int i = 0; i < n; i++) {
			cout << p[i] << " " << s.substr(p[i], n - p[i]) << "\n";
		} */
		for (int i = 0; i < n - 1; i++) {
			cout << p[i] << " ";
		}
		cout << p[n - 1] << endl;
	}
	return 0;
}