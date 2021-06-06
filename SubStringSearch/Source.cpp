#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;



void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template<typename T, typename V>
void __print(const pair<T, V> &x) { cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}'; }
template<typename T>
void __print(const T &x) { int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}"; }
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) { __print(t); if (sizeof...(v)) cerr << ", "; _print(v...); }
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

using namespace __gnu_pbds;
*/
#define mod 1000000007

template <typename T>
// using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

/// Some frequent usable functions
#define int                        long long
void add(int &a, int b) { a += b; if (a > mod)a -= mod; }
void sub(int &a, int b) { a -= b; if (a < 0)a += mod; }
void mul(int &a, int b) { a = 1ll * a * b % mod; }
template<typename T> T pow(T a, T b, long long m) { T ans = 1; while (b > 0) { if (b % 2 == 1) ans = (ans*a) % m; b /= 2; a = (a*a) % m; } return ans % m; }
int powmod(int a, int b)
{
	int res = 1; while (b) { if (b & 1) { res = (res * a) % mod; }b = b / 2; a = (a*a) % mod; }return res;
}
int _ceil(int, int);
int _floor(int a, int b) { return b < 0 ? _floor(-a, -b) : a < 0 ? -_ceil(-a, b) : a / b; }
int _ceil(int a, int b) { return b < 0 ? _ceil(-a, -b) : a < 0 ? -_floor(-a, b) : (a + b - 1) / b; }

// int gcd(int a, int b, int &x, int &y) {if (a == 0) {x = 0; y = 1;return b;
//     }int x1, y1;int d = gcd(b%a, a, x1, y1); x = y1 - (b / a) * x1;y = x1;return d;}
// int find(int v){return v==parent[v]?v:parent[v] = find(parent[v]);}
// void merge(int i,int j)
//     {i = find(i);j = find(j);if(i == j)return;parent[parent[i]] = parent[j];cmp--;}

/*
	/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/ *** Directions in grids *** \/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
*/
// int dy[4] = {0,0,1,-1}, dx[4] = {1,-1,0,0}; // 4 Direction
// int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1};  // 8 Direction
// int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1};  // Knight moves
// int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1};  // Hexagonal Direction
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define sp(a , x) cout << fixed << setprecision(a) << x << endl;
#define endl "\n"
#define pb push_back
#define pf push_front
#define ub upper_bound
#define lb lower_bound
#define F first
#define S second
#define mset(a, b) memset(a, b, sizeof a)
#define sz(x) ((int)(x.size()))
#define sqr(x) ((x) * (x))
#define graph vector<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int,int>
#define all(c)                      c.begin() , c.end()
#define rep(i,a) for(int i=0;i<a;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define iter(it,a) for(auto it=a.begin();it!=a.end();it++)
#define PQP priority_queue<pi, vector<pi>, greater<pi>>
#define PQI priority_queue<int, vector<int>, greater<int>>
#define dbg debug
#define inf (int)1e16
const long double EPS = 0.0000000001;
const long double PI = 3.1415926535897932384;
//vec.resize(unique(all(vec)) - vec.begin());
int dy[4] = { 0,0,1,-1 }, dx[4] = { 1,-1,0,0 };

/// define some data.......
const int N = (int)1e4 + 15;
string str;
vector<int>ans;


vector<int> construct_suffix_array(const string& s)
{
	int n = sz(s);
	vector<int>p(n, 0), c(n, 0);

	int limit = 257;
	vector<int>cnt(max(limit, n), 0);
	for (char c : s)cnt[c]++;
	for (int i = 1; i < limit; i++) cnt[i] += cnt[i - 1];
	for (int i = 0; i < n; i++)p[--cnt[s[i]]] = i;

	c[p[0]] = 0;
	int cls = 1;
	for (int i = 1; i < n; i++)
	{
		if (s[p[i]] != s[p[i - 1]]) cls++;
		c[p[i]] = cls - 1;
	}

	vector<int>pn(n, 0), cn(n, 0);

	for (int h = 0; (1LL << h) < n; h++)
	{
		for (int i = 0; i < n; i++)
		{
			pn[i] = (p[i] - (1LL << h));
			if (pn[i] < 0) pn[i] += n;
		}

		for (int i = 0; i < cls; i++) cnt[i] = 0;

		for (int i = 0; i < n; i++)
		{
			cnt[c[pn[i]]]++;
		}
		for (int i = 1; i < cls; i++) cnt[i] += cnt[i - 1];

		for (int i = n - 1; i >= 0; i--)
		{
			p[--cnt[c[pn[i]]]] = pn[i];
		}

		cn[p[0]] = 0;

		cls = 1;
		for (int i = 1; i < n; i++)
		{
			pair<int, int> cur = { c[p[i]], c[(p[i] + (1LL << h)) % n] };
			pair<int, int> pre = { c[p[i - 1]], c[(p[i - 1] + (1LL << h)) % n] };

			if (cur != pre)cls++;
			cn[p[i]] = cls - 1;
		}

		c.swap(cn);

	}

	return p;
}

bool look(string& p)
{
	int l = 0;
	int r = sz(ans) - 1;

	while (l <= r)
	{
		int mid = (l + r) / 2;

		// string suf = str.substr(ans[mid]);

		string pre = str.substr(ans[mid], sz(p));
		if (pre == p) return true;
		if (pre < p) l = mid + 1;
		else r = mid - 1;

	}

	return false;
}

void solve()
{
	cin >> str;
	str += "$";

	ans = construct_suffix_array(str);
	ans.erase(ans.begin());
	str.pop_back();

	int q;
	cin >> q;
	while (q--)
	{
		string p;
		cin >> p;

		if (look(p))
		{
			cout << "Yes\n";
		}
		else cout << "No\n";
	}


}
int32_t main()
{
	fast;
	int test = 1;
	// cin >> test;
	int tc = 1;
	while (test--)
	{
		solve();	// segment tree, find patterns.
	}

}