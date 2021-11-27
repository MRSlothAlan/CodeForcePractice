#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
typedef pair<int, int> pr;
const int MAX = 60000;
vector<vector<int>> AL_REC;

// well. 
// size of vector athleteA is 5, result of matches
bool myCompareFunction(vector<int> athleteA, vector<int> athleteB) {
	int A_won = 0;
	int len = athleteA.size() - 1;
	for (int i = 0; i < len; i++) {
		if (athleteA[i] < athleteB[i]) A_won++;
		else A_won--;
	}
	return A_won > 0;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		AL_REC.clear();
		int n; scanf("%d", &n);
		for (int a = 0; a < n; a++) {
			AL_REC.push_back(vector<int>(6));
			scanf("%d %d %d %d %d", &AL_REC[a][0], &AL_REC[a][1], &AL_REC[a][2], &AL_REC[a][3], &AL_REC[a][4]);
			AL_REC[a][5] = a + 1;
		}
		if (n == 1) {
			printf("1\n");
		}
		else {
			sort(AL_REC.begin(), AL_REC.end(), myCompareFunction);
			int len = AL_REC[0].size() - 1;
			bool isSuperior = true;
			for (int i = 1; i < n && isSuperior; i++) {
				int tmp = 0;
				for (int j = 0; j < len; j++) {
					if (AL_REC[0][j] < AL_REC[i][j]) { tmp++; }
				}
				if (tmp < 3) {
					isSuperior = false;
				}
			}
			if (isSuperior) {
				printf("%d\n", AL_REC[0][5]);
			}
			else {
				printf("-1\n");
			}
		}
	}
	return 0;
}

/*
criteria:
x > y, if athlete x ranked better than athlete y
>= 3 marathons, rx < ry

gold, if superior to all other ppl
*/

/*
// int rec[MAX][6];
// vector<pr> R;

bool com(pr l, pr r) {
	return l.second < r.second;
}

old code;

			int tmp = 0; for (int i = 0; i < 5; i++) { tmp += rec[a][i]; }
			R.push_back(pr(a, tmp));

			sort(R.begin(), R.end(), com);
			int res_val = -1;
			for (pr res : R) {
				if (res_val != -1) break;
				int cur_a = res.first;
				int sup_cnt = 0;
				for (int a = 0; a < cur_a; a++) {
					int tmp_m = 0;
					for (int i = 0; i < 5; i++) {
						if (rec[cur_a][i] < rec[a][i]) {
							tmp_m++;
						}
						if (tmp_m >= 3)
							break;
					}
					if (tmp_m >= 3) {
						sup_cnt++;
					}
				}
				for (int a = cur_a + 1; a < n; a++) {
					int tmp_m = 0;
					for (int i = 0; i < 5; i++) {
						if (rec[cur_a][i] < rec[a][i]) {
							tmp_m++;
						}
						if (tmp_m >= 3)
							break;
					}
					if (tmp_m >= 3) {
						sup_cnt++;
					}
				}
				if (sup_cnt == n - 1) {
					res_val = cur_a + 1;
					break;
				}
			}
			printf("%d\n", res_val);
*/