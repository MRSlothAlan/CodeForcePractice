#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
/*
Partner's dancing skill, differ by at most one.
*/

int main() {
	int n; scanf("%d", &n);
	vector<int> m_arr, w_arr;
	for (int i = 0; i < n; i++) {
		int guy; scanf("%d", &guy);
		m_arr.push_back(guy);
	}
	int m; scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int woman; scanf("%d", &woman);
		w_arr.push_back(woman);
	}
	sort(m_arr.begin(), m_arr.end());
	sort(w_arr.begin(), w_arr.end());
	int m_ptr = n - 1, w_ptr = m - 1;
	int cnt = 0;
	while (m_ptr >= 0 && w_ptr >= 0) {
		int diff = abs(m_arr[m_ptr] - w_arr[w_ptr]);
		if (diff == 1 || diff == 0) { cnt++; m_ptr--; w_ptr--; }
		else if (m_arr[m_ptr] < w_arr[w_ptr]){
			w_ptr--;
		}
		else if (m_arr[m_ptr] > w_arr[w_ptr]){
			m_ptr--;
		}
	}
	printf("%d\n", cnt);
	return 0;
}