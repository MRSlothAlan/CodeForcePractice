#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
// for the original code I submitted, see the platform
// In the meantime, learn how to observe and proof ideas, stop doing new ones.
#include <vector>
#include <string>
#include <iostream>
using namespace std;

bool solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> t, m;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'T')
			t.push_back(i);
		else
			m.push_back(i);
	}
	if (t.size() != 2 * m.size())
		return false;
	for (int i = 0; i < m.size(); i++) {
		if (m[i] < t[i] || m[i] > t[i + m.size()])
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cout << (solve() ? "YES" : "NO") << '\n';
	}
}

/*
1
21
TMTMMMMTTTTTTTMMTTTTT




			for (int i = 0; i < len; i++) {
				if (s[i] == 'T') {
					t_cnt++;
					com++;
				}
				else {
					m_cnt++;
					com--;
				}
				if (com < 0)
					break;
			}
			if (m_cnt * 2 == t_cnt && com >= 0) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
*/