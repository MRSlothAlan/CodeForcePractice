#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

/*
Oh, the language used is called io!

a:=0
b:=1
for (i,1,File standardInput readLine asNumber,b=a+b
a=b-a)
b println

use it later
*/

// number of men = nth Fibonacci number.
/*
const int MAX = 30;
int F[MAX];

void initF() {
	F[0] = 1;
	F[1] = 1;
	for (int i = 2; i < MAX; i++) {
		F[i] = F[i - 1] + F[i - 2];
	}
}
*/
void solve(int n) {
	int cur = 1;
	int prev = 1;
	if (n <= 1) {
		printf("%d\n", 1);
	}
	else {
		int res = 0;
		for (int i = 2; i <= n; i++) {
			res = prev + cur;
			prev = cur;
			cur = res;
		}
		printf("%d\n", res);
	}
}

int main() {
	// initF();
	// int n; scanf("%d", &n);
	int n; cin >> n;
	solve(n);
	// cout << F[n];
	// printf("%d", F[n]);
	return 0;
}