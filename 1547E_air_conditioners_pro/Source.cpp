#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#define cn getchar
#define pt putchar
#define ll long long
using namespace std;
pair<int, int> a[300010];
int n, m, T, t, l[300010], r[300010];
int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++) scanf("%d", &a[i].first);
		for (int i = 1; i <= m; i++) scanf("%d", &a[i].second);
		sort(a + 1, a + m + 1);
		t = a[1].second + a[1].first;

		for (int i = 1, j = 1; i <= n; i++) {
			t++;
			if (i == a[j].first) {
				t = min(a[j].second, t);
				if (j < m) j++;
			}
			l[i] = t;
		}
		t = a[m].second + n - a[m].first + 1;
		for (int i = n, j = m; i; i--) {
			t++;
			if (i == a[j].first) {
				t = min(a[j].second, t);
				if (j > 1) j--;
			}
			r[i] = t;
		}
		for (int i = 1; i <= n; i++) printf("%d ", min(l[i], r[i]));
		printf("\n");
	}
	return 0;
}
