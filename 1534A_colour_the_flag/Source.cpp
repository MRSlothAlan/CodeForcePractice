#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

const int MAX = 60;
char M[MAX][MAX];
// R W .
// every red cell, w neighbors, vice versa
int n, m;	// row * column

char val(char c) {
	if (c == 'W') return 'R';
	else if (c == 'R') return 'W';
}

bool fill_row(int i, int j) {
	int tmp_left = j - 1,
		tmp_right = j + 1;
	while (tmp_left >= 0) {
		if (M[i][tmp_left] == '.')
			M[i][tmp_left] = val(M[i][tmp_left + 1]);
		tmp_left--;
	}
	while (tmp_right <= m) {
		if (M[i][tmp_right] == '.')
			M[i][tmp_right] = val(M[i][tmp_right - 1]);
		tmp_right++;
	}
	char cur = M[i][0];
	for (int idx = 1; idx < m; idx++) {
		if (cur == M[i][idx]) {
			return false;
		}
		cur = M[i][idx];
	}
	return true;
}

bool fill_col(int i, int j) {
	int tmp_up = i - 1,
		tmp_down = i + 1;
	while (tmp_up >= 0) {
		if (M[tmp_up][j] == '.')
			M[tmp_up][j] = val(M[tmp_up + 1][j]);
		tmp_up--;
	}
	while (tmp_down <= n) {
		if (M[tmp_down][j] == '.')
			M[tmp_down][j] = val(M[tmp_down - 1][j]);
		tmp_down++;
	}
	char cur = M[0][j];
	for (int idx = 1; idx < n; idx++) {
		if (cur == M[idx][j]) {
			return false;
		}
		cur = M[idx][j];
	}
	return true;
}


bool check_fill_col(int i, int j) {
	for (int idx = i; idx < n; idx++) {
		if (M[idx][j] != '.') {
			return fill_col(idx, j);
		}
	}
	return false;	// this won't happen actually.
}

void display() {
	for (int i = 0; i < n; i++) {
		printf("%s\n", M[i]);
	}
}

void generateFullGraph() {
	char start = 'W';
	for (int i = 0; i < n; i++) {
		M[i][0] = start;
		for (int j = 1; j < m; j++) {
			M[i][j] = val(M[i][j - 1]);
		}
		start = val(start);
	}
}

int main() {
	int t, i, j; scanf("%d", &t);
	while (t--) {
		bool valid = true;
		n, m; scanf("%d %d", &n, &m);
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				M[i][j] = ' ';
			}
		}
		bool all_empty = true;
		for (i = 0; i < n; i++) {
			scanf("%s", &M[i]);
			for (j = 0; j < m; j++) {
				if (M[i][j] != '.') {
					valid = valid && fill_row(i, j);
					all_empty = false;
					break;
				}
			}
		}
		if (valid) {
			// now, some rows might be empty and some are not. 
			// time to check all columns.
			if (all_empty) {
				// just generate a full graph.
				generateFullGraph();
				printf("YES\n");
				display();
			}
			else {
				for (int j = 0; j < m; j++) {
					valid = valid && check_fill_col(0, j);
				}
				if (valid) {
					printf("YES\n");
					display();
				}
				else {
					printf("NO\n");
				}
			}
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}