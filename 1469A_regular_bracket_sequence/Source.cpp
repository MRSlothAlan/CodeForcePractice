#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int MAX = 200;
char s[MAX];
struct dat {
	char b;
	int idx;
	dat() {}
	dat(char in_b, int in_idx) {
		this->b = in_b;
		this->idx = in_idx;
	}
};
stack<dat> S;
stack<int> Q_idx;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		S = stack<dat>();
		Q_idx = stack<int>();
		scanf("%s", &s);
		int q_cnt = 0, len = strlen(s);
		for (int i = 0; i < len && q_cnt >= 0; i++) {
			if (s[i] == '(')
				S.push(dat(s[i], i));
			else if (s[i] == ')') {
				if (!S.empty()) {
					S.pop();
				}
				else {
					if (Q_idx.empty()) {
						q_cnt--;
						break;
					}
					else {
						q_cnt--;
						Q_idx.pop();
					}
				}
			}
			else if (s[i] == '?') {
				q_cnt++;
				Q_idx.push(i);
			}
		}
		if (q_cnt < 0) {
			printf("NO\n");
		}
		else {
			bool valid = true;
			// then
			while (!S.empty() && !Q_idx.empty()) {
				dat cur_s = S.top();
				int cur_q_idx = Q_idx.top();
				if (cur_s.idx < cur_q_idx) {
					Q_idx.pop(); q_cnt--;
					S.pop();
				}
				else {
					valid = false;
					break;
				}
			}
			if ((q_cnt & 1) != 0) {
				valid = false;
			}
			if (valid && S.empty()) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}
	return 0;
}