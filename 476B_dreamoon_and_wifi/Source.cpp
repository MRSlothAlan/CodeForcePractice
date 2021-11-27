#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

const int MAX = 20;
char drazil[MAX], dreamoon[MAX];
int pos[MAX], neg[MAX], draLen, dreLen;

void setValidAns(int cur_loc, int step_idx) {
	if (step_idx > dreLen - 1) { 
		if (cur_loc < 0) { neg[cur_loc * -1]++; }
		else { pos[cur_loc]++; }
		return; 
	}
	else {
		if (dreamoon[step_idx] == '+') {
			setValidAns(cur_loc + 1, step_idx + 1);
		}
		else if (dreamoon[step_idx] == '-') {
			setValidAns(cur_loc - 1, step_idx + 1);
		}
		else {
			setValidAns(cur_loc + 1, step_idx + 1);
			setValidAns(cur_loc - 1, step_idx + 1);
		}
	}
}

int main() {
	scanf("%s", &drazil); draLen = strlen(drazil);
	scanf("%s", &dreamoon); dreLen = strlen(dreamoon);
	// drazil has the correct answer.
	int correct_ans = 0;
	for (int i = 0; i < draLen; i++) {
		if (drazil[i] == '+')
			correct_ans++;
		else if (drazil[i] == '-')
			correct_ans--;
	}
	setValidAns(0, 0);
	double corr = 0.0, wrong = 0.0;
	if (correct_ans == 0) { corr += pos[0]; }
	wrong += pos[0];	// denominator always add it.

	for (int num = 1; num < MAX; num++) {
		if ((double)num == correct_ans) { corr += pos[num]; }
		if ((double)num * -1 == correct_ans) { corr += neg[num]; }
		wrong += pos[num];
		wrong += neg[num];
	}
	if (wrong <= 0) {
		printf("1.000000000000");
	}
	else {
		printf("%.13f", corr / wrong);
	}
	return 0;
}