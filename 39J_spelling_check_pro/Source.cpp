#pragma warning(disable : 4996)
#define _CRT_DISABLE_PERFCRIT_LOCKS
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <numeric>
#include <fstream>
#include <cmath>
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define rep(i,a,b) for(auto i=(a); i<(b); i++)
#define dec(i,n,a) for(auto i=(n); i>=(a); i--)
#define inp(a) for(auto& i: a) cin >> i
#define prt(a) for(auto& i: a) cout << i << ' '
#define _ auto
#define el '\n'
#define Yes cout << "Yes" << el
#define No cout << "No" << el
#define YES cout << "YES" << el
#define NO cout << "NO" << el
#define qua size_t _q_; cin>>_q_; while(_q_--)
#define all(item) item.begin(), item.end()

typedef int64_t ll;
typedef uint64_t ull;
typedef vector<bool> vb;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef pair<int32_t, int32_t> pii;
typedef pair<ll, ll> pll;
typedef vector<int32_t> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int32_t>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<string>> vvs;

#define uint unsigned int
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	string s, ans;
	cin >> s >> ans;
	uint pref = 0;
	int i = 0;
	while (s[i] == ans[i]) {
		i++;
		pref++;
		if (i == ans.length())
			break;
	}
	uint suf = 0;
	i = ans.length() - 1;
	int j = s.length() - 1;
	while (s[j] == ans[i]) {
		i--;
		j--;
		suf++;
		if (i < 0 || j < 0)
			break;
	}
	// find lcp, lcs
	if (pref + 1 < s.length() - suf) {
		cout << (0);
	}
	else {
		int l = (int)max(s.length() - suf, (unsigned int)1),
			r = (int)min(pref + 1, s.length());
		cout << (r - l + 1) << el;
		for (int w = l; w <= r; ++w) {
			cout << w << ' ';
		}
	}
	return 0;
}