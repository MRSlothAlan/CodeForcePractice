#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#define MIN(a, b) a > b ? b : a;
char S[1005], M[1005];
int S_i[10], M_i[10], S_i_[10], M_i_[10];

int main() {
	int n; scanf("%d", &n);	// number of digits
	scanf("%s", &S); int len = strlen(S);
	for (int i = 0; i < len; i++) {
		S_i[S[i] - '0']++;
		S_i_[S[i] - '0'] = S_i[S[i] - '0'];
	}
	scanf("%s", &M); len = strlen(M);
	for (int i = 0; i < len; i++) {
		M_i[M[i] - '0']++;
		M_i_[M[i] - '0'] = M_i[M[i] - '0'];
	}
	int S_f_cnt = 0;
	int M_f_cnt = 0;
	for (int digit = 0; digit < 10; digit++) {
		// back track digits.
		if (M_i_[digit] > 0) {
			for (int p_digit = digit - 1; p_digit >= 0 && M_i_[digit] > 0; p_digit--) {
				while (M_i_[digit] > 0 && S_i_[p_digit] > 0) {
					M_i_[digit]--; S_i_[p_digit]--;
					S_f_cnt++;
				}
			}
		}
	}
	// damn, separated queries.
	// find min M.
	M_f_cnt = n;
	for (int digit = 0; digit < 10; digit++) {
		if (M_i[digit] > 0) {
			for (int p_digit = digit; p_digit >= 0 && M_i[digit] > 0; p_digit--) {
				while (M_i[digit] > 0 && S_i[p_digit] > 0) {
					M_i[digit]--; S_i[p_digit]--;
					M_f_cnt--;
				}
			}
		}
	}
	printf("%d\n", M_f_cnt);
	printf("%d", S_f_cnt);
	return 0;
}

/*
int S_digit = 0;
for (; S_digit < 10 && S_i[S_digit] == 0; S_digit++) {}
for (int digit = 0; digit < 10 && S_digit < 10; digit++) {
	if (digit >= S_digit && M_i[digit] > 0 && S_i[S_digit] > 0) {
		while (M_i[digit] > 0 && S_i[S_digit] > 0) {
			M_i[digit]--; S_i[S_digit]--;
		}
		if (S_i[S_digit] == 0) {
			for (; S_digit < 10 && S_i[S_digit] == 0; S_digit++) {}
		}
	}
}
*/

/*
		if (S_i[digit - 1] > 0 && M_i[digit] > 0) {
			int qty = MIN(S_i[digit - 1], M_i[digit]);
			// S_i[digit - 1] -= qty;
			// M_i[digit] -= qty;
			S_f_cnt += qty;
		}
*/
/*
5
72471
72471
*/