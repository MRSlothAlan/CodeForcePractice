#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#define MIN(a, b) a < b ? a : b
const int MAX = 13;
char s[MAX];
int Fd[MAX], Sd[MAX];
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%s", &s);
		memset(Fd, 0, sizeof(Fd)); memset(Sd, 0, sizeof(Sd));
		int len = strlen(s);
		for (int i = 0; i < len; i++) {
			if (s[i] == '?') {
				if ((i & 1)) {
					Fd[i] = 0;
					Sd[i] = 1;
				}
				else {
					Fd[i] = 1;
					Sd[i] = 0;
				}
			}
			else {
				Fd[i] = s[i] - '0'; Sd[i] = s[i] - '0';
			}
		}
		int F_round = 5, S_round = 5,
			Fs = 0, Ss = 0,
			res_val = 12;
		for (int i = 0; i < len; i++) {
			if ((i & 1)) {	
				Ss += Fd[i];
				S_round--;
				if (Ss > F_round + Fs || Ss + S_round < Fs) {
					res_val = MIN(res_val, (i + 1));
					i = len;
				}
			}
			else {
				Fs += Fd[i];
				F_round--;
				if (Fs > S_round + Ss || Fs + F_round < Ss) {
					res_val = MIN(res_val, (i + 1));
					i = len;
				}
			}
		}
		F_round = 5, S_round = 5, Fs = 0, Ss = 0;
		for (int i = 0; i < len; i++) {
			if ((i & 1)) {	// S team
				Ss += Sd[i];
				S_round--;
				if (Ss > F_round + Fs || Ss + S_round < Fs) { // second team ar.
					res_val = MIN(res_val, (i + 1));
					i = len;
				}
			}
			else {
				Fs += Sd[i];
				F_round--;
				if (Fs > S_round + Ss || Fs + F_round < Ss) {
					res_val = MIN(res_val, (i + 1));
					i = len;
				}
			}
		}
		printf("%d\n", res_val >= 10 ? 10 : res_val);
	}
	return 0;
}
// minimum possible number of kicks in the phrase.
/*
1, score
0, won't score
?, don't know.

first team, kick, second, alt.

4
1?0???1001
1111111111
??????????
0100000000

this >> ?000??0001
*/