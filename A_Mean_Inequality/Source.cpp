#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n; 
		cin >> n;
		vector<int> val(2 * n);
		for (int i = 0; i < 2 * n; i++) {
			cin >> val[i];
		}
		sort(val.begin(), val.end());
		int idx_right = val.size() - 1, idx_left = 0;
		while (idx_right > idx_left) {
			cout << val[idx_right] << " ";
			idx_right--;
			if (idx_right == idx_left) {
				cout << val[idx_left] << endl;
			}
			else {
				cout << val[idx_left] << " ";
			}
			idx_left++;
		}
	}
	return 0;
}