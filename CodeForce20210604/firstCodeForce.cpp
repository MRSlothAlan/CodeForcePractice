#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include "firstCodeForce.h"
using namespace std;

int FirstCodeForce::main(int argc, char * argv[]) {
	// strange if abs diff between any pair of elements
// is greater than or equal to max element
// i <= j.
/*
fact #1: any pair, no matter what ordering, same abs()
fact #2: the max. value shall be the minimum difference (my commented code does that... somehow)
fact #3: after you sort the array, everytime checking next element, that element is current max.
	=> if cur min difference < cur max, break.
		(your original code missed that)
*/
	int t;
	cin >> t;
	while (t--) {
		int n, tmp;	// length of array a
		cin >> n;
		vector<int> in_seq;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			in_seq.push_back(tmp);
		}
		sort(in_seq.begin(), in_seq.end());
		int curmindiff = -1, res_c = 1;
		for (int i = 1; i < in_seq.size(); i++) {
			tmp = abs(in_seq[i] - in_seq[i - 1]);
			if (curmindiff == -1 || curmindiff > tmp) {
				curmindiff = tmp;
			}
			if (curmindiff < in_seq[i]) {
				break;
			}
			res_c++;
		}
		cout << res_c << endl;
	}
	return 0;
}

/*
		int prev = 0, min_diff = -1;
		// first number.
		int cur_num; cin >> cur_num;
		in_seq.push_back(cur_num); prev = cur_num;
		for (int i = 1; i < n; i++) {
			cin >> cur_num;
			if (cur_num != prev || (cur_num == prev && cur_num == 0)) {
				int tmp_diff = abs(prev - cur_num);
				if (min_diff == -1 || min_diff > tmp_diff)
					min_diff = abs(prev - cur_num);
				in_seq.push_back(cur_num);
				prev = cur_num;
			}
		}
		int cnt = 0;
		for (int i = 0; i < in_seq.size(); i++) {
			if (in_seq[i] < min_diff || (min_diff == 0 && in_seq[i] <= 0)) {
				cnt++;
			}
		}
		cout << cnt << endl;
		*/