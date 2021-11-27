#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define ll long long int
void solve()
{
	ll n, m, k = 0, p = 0, q = 0, sum = 0, ans = 0, tmp = 0, count = 0;
	cin >> n >> m;
	int rslt[40][40];
	memset(rslt, -1, sizeof(rslt));
	for (int i = 5; i < n + 5; i++) {
		for (int j = 5; j < m + 5; j++) {
			if (rslt[i][j] == -1 && (i == 5 || i == n + 4 || j == 5 || j == m + 4)) {
				rslt[i][j] = 1;
				rslt[i + 1][j] = 0;
				rslt[i - 1][j] = 0;
				rslt[i][j + 1] = 0;
				rslt[i][j - 1] = 0;
				rslt[i - 1][j - 1] = 0;
				rslt[i - 1][j + 1] = 0;
				rslt[i + 1][j + 1] = 0;
				rslt[i + 1][j - 1] = 0;
			}
		}
	}
	for (int i = 5; i < n + 5; i++) {
		for (int j = 5; j < m + 5; j++) {
			if (rslt[i][j] == -1)cout << 0;
			else
				cout << rslt[i][j];
		}
		cout << endl;
	}
	cout << "\n";
}
// stupid hard-code question.
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll t, count = 1;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
/*
#include <cstdio>
#include <cstring>
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int w, h; scanf("%d %d", &h, &w);
		for (int r = 1; r <= h; r++) {
			if ((r & 1)) {
				if (r == 1 || r == h) {
					if ((w & 1)) {
						for (int c = 1; c < w; c += 2) {
							printf("10");
						}
						printf("1");
					}
					else {
						for (int c = 1; c <= w; c += 2) {
							printf("10");
						}
					}
				}
				else {
					printf("1");
					for (int c = 2; c < w; c++) {
						printf("0");
					}
					printf("1");
				}
			}
			else {
				for (int c = 1; c <= w; c++) {
					printf("0");
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
*/