#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
/*
M x N squares.
2 x 1 squares
max cover
	no overlap
	inside the board
*/
int main() {
	int m, n; 
	scanf("%d %d", &m, &n);
	printf("%.0f", floor((m * n) / 2));
	return 0;
}