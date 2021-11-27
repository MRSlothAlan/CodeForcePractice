#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

const int MAX = 2000;
int rec[MAX][MAX][5];

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < m; c++) {
			scanf("%d", &rec[r][c][0]);
		}
	}
	// up
	for (int c = 0; c < m; c++) {
		int r_s = 0;
		for (; r_s < n && rec[r_s][c][0] == 0; r_s++) {}
		r_s++;
		for (; r_s < n; r_s++) {
			rec[r_s][c][1] = 1;
		}
	}
	// right
	for (int r = 0; r < n; r++) {
		int c_s = m - 1;
		for (; c_s >= 0 && rec[r][c_s][0] == 0; c_s--) {}
		c_s--;
		for (; c_s >= 0; c_s--) {
			rec[r][c_s][2] = 1;
		}
	}
	// down
	for (int c = 0; c < m; c++) {
		int r_s = n - 1;
		for (; r_s >= 0 && rec[r_s][c][0] == 0; r_s--) {}
		r_s--;
		for (; r_s >= 0; r_s--) {
			rec[r_s][c][3] = 1;
		}
	}
	// left
	for (int r = 0; r < n; r++) {
		int c_s = 0;
		for (; c_s < m && rec[r][c_s][0] == 0; c_s++) {}
		c_s++;
		for (; c_s < m; c_s++) {
			rec[r][c_s][4] = 1;
		}
	}
	// up right down left
	int res_cnt = 0;
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < m; c++) {
			if (rec[r][c][0] == 0) {
				res_cnt +=
					rec[r][c][1]
					+ rec[r][c][2]
					+ rec[r][c][3]
					+ rec[r][c][4];
			}
		}
	}
	printf("%d", res_cnt);
	return 0;
}
/*
position = good if
	no actor in cell spotlight
	>= 1 actor in up / down / left / right
	each direction -> good.
*/