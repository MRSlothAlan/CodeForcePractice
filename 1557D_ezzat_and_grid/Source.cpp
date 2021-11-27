#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
typedef unsigned long int lld;
lld arr[400000];
// set bits.
void set_bit(int idx, int n) {
	arr[idx] |= 1UL << (n - 1);
}
int rec_idx[400000], idx;
int main() {
	int n, m; scanf("%d %d", &n, &m);
	while(m--) {
		int i, l, r; scanf("%d %d %d", &i, &l, &r);
		set_bit(i, l);
		if (l != r)
			set_bit(i, r);
	}
	int starting_idx = 1;
	int max_cnt = -1;
	int cur, next, cur_cnt = 0;
	for (int i = 1; i <= n; i++) {
		cur = i, next = i + 1, cur_cnt = 0;
		while (cur <= n - 1 && next <= n) {
			if ((arr[cur] & arr[next]) > 0) {
				cur = next;
				next++;
				cur_cnt++;
			}
			else {
				next++;
			}
		}
		if (cur_cnt > max_cnt) {
			starting_idx = i;
			max_cnt = cur_cnt;
		}
	}
	idx = 0;
	for (int i = 1; i < starting_idx; i++) {
		rec_idx[idx++] = i;
	}
	cur = starting_idx, next = cur + 1;
	while (cur <= n - 1 && next <= n) {
		if ((arr[cur] & arr[next]) > 0) {
			cur = next;
			next++;
		}
		else {
			rec_idx[idx++] = next;
			next++;
		}
	}
	printf("%d\n", idx);
	for (int i = 0; i < idx; i++) {
		printf("%d ", rec_idx[i]);
	}
	return 0;
}