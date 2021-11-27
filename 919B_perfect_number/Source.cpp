#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
using namespace std;
/*
fucking b force.
*/
int main() {
	int k; scanf("%d", &k);
	int kth = 0;
	int num = 19;
	while (kth < k) {
		int tmp = num;
		int d_sum = 0;
		while (tmp > 0) {
			d_sum += tmp % 10;
			tmp /= 10;
		}
		if (d_sum == 10) {
			kth++;
		}
		if (kth == k)
			break;
		num++;
	}
	printf("%d\n", num);
	return 0;
}