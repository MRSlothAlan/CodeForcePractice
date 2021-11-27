#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

const int MAX = 600000;
char s[MAX];
set<int> S;

int main() {
	int n, k; scanf("%d %d", &n, &k);
	scanf("%s", &s);
	// k : available on keyboard
	// how many substring of string s he can still type.
	for (int i = 0; i < k; i++) {
		char tmp; scanf(" %c", &tmp); S.insert(tmp);
	}
	long long int cnt = 0, res = 0;
	for (int i = 0; i < n; i++) {
		if (S.find(s[i]) != S.end()) { cnt++; }
		else cnt = 0;
		res += cnt;
	}
	printf("%lld", res);
	return 0;
}