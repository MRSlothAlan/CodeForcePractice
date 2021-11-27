#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

const int MAX = 200;
bool valid[MAX];
// damn.
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int q, d;  scanf("%d %d", &q, &d);
		int lower = 10 * d;	// the lower bound
		while (q--) {
			long long int a; scanf("%lld", &a);
			if (a >= lower) {
				printf("YES\n");
			}
			else {
				// dp solution. e.g. 7, now upper = 70 - 1 = 69
				memset(valid, false, sizeof(valid));
				int to_check = a;
				int cur_d = 0;
				while (to_check) {
					cur_d = to_check % 10;
					if (cur_d == d) {
						valid[a] = true;
						break;
					}
					to_check /= 10;
				}
				if (valid[a]) {
					printf("YES\n");
				}
				else {
					int cur_item = d;
					for (int num = d; num < MAX; num += d) {
						valid[num] = true;
					}
					cur_item += 10;
					while (cur_item < lower && cur_item < a) {
						for (int num = 1; num < MAX; num++) {
							if (valid[num]) {
								int tmp = num + cur_item;
								while (tmp < MAX) {
									valid[tmp] = true;
									tmp += cur_item;
								}
							}
						}
						cur_item += 10;
					}
					if (valid[a]) {
						printf("YES\n");
					}
					else {
						printf("NO\n");
					}
				}
			}
		}
	} 
	return 0;
}