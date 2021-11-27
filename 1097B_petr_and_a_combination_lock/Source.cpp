#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <math.h>
using namespace std;
/*
rotate 360 = 0 again.
*/
int arr[30];
int sum_a;

// pretty useful stuff
bool isSet(int in_num, int bit) {
	return 1 == ((in_num >> bit) & 1);
}

int main() {
	int n; scanf("%d", &n);	// num of rotations.
	sum_a = 0;
	for (int i = 0; i < n; i++) {
		int angle_i; scanf("%d", &angle_i);
		sum_a += angle_i; arr[i] = angle_i;
	}
	if (sum_a % 360 == 0) {
		printf("YES\n");
	}
	else {
		bool found = false;
		long int limit = pow(2, n) + 1;
		for (int i = 0; i <= limit && !found; i++) {
			int tmp_angle = 0;
			for (int b = 0; b < n; b++) {
				if (isSet(i, b)) {
					tmp_angle += arr[b];
				}
				else {
					tmp_angle -= arr[b];
				}
			}
			if (tmp_angle == 0 || tmp_angle % 360 == 0) {
				found = true;
				break;
			}
		}
		if (found) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}

/*
nope here

		for (int len = 1; len < n && !found; len++) {
			tmpF = 0, tmpS = 0;
			for (int i = 0; i < len; i++) {
				tmpF += arr[i];
			}
			for (int j = len; j < n; j++) {
				tmpS += arr[j];
			}
			if (tmpF == tmpS) {
				found = true;
				break;
			}
		}
*/
