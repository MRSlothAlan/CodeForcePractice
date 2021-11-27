#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <math.h>
using namespace std;
/*
click :
even if two negative numbers are in differnet locations 
you can just propagate to the next negative numbers
*/
int main() {
	int t, n, sum, m, min, a, naim;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		sum = 0;
		naim = 100000000;
		min = 0;
		for (int i = 0; i < n*m; i++)
		{
			scanf("%d", &a);
			sum += abs(a);
			if (a < 0) min++;
			if (abs(a) < naim)naim = abs(a);
		}
		if (min % 2 == 0) printf("%d\n", sum);
		else printf("%d\n", sum - 2 * naim);
	}
	return 0;
}
/*
2
2 2
-1 1
1 1
3 4
0 -1 2 3
1 2 3 4
2 3 4 -5

*/

/*

#include<iostream>
using namespace std;

int main() {
	int t,n,sum,m,min,a,naim;
	cin >> t;
	while (t--) {
		cin >> n>>m;
		sum = 0;
		naim = 100000000;
		min = 0;
		for (int i = 0; i < n*m; i++)
		{
			cin >> a;
			sum += abs(a);
			if (a < 0) min++;
			if (abs(a) < naim)naim = abs(a);
		}
		if (min % 2 == 0) cout << sum;
		else cout << sum - 2*naim;
		cout << '\n';
	}
	return 0;
}

n rows, m columns
choose, adj cells, mul. the values in them by -1

	if (arr[i1][j1] > 0 && arr[i2][j2] > 0) {
		return;
	}
	else if (arr[i1][j1] <= 0 && arr[i2][j2] <= 0) {
		arr[i1][j1] *= -1;
		arr[j1][j2] *= -1;
		return;
	}
	else {
		int val1 = abs(arr[i1][j1]);
		int val2 = abs(arr[i2][j2]);
		if (arr[i1][j1] > 0 && val1 < val2) {
			arr[i1][j1] *= -1;
			arr[j1][j2] *= -1;
			return;
		}
		else if (arr[i2][j2] > 0 && val1 > val2){
			arr[i1][j1] *= -1;
			arr[j1][j2] *= -1;
			return;
		}
	}
*/