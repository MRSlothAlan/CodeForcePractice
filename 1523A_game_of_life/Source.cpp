#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

/*
game of life:
	> =1 alive neighbor, dead, -> alive.
	> no element, dead.
	> all alive elements stay alive.	diu simple.
*/
const int MAX = 1005;
char in_str[MAX];

bool opt(int n) {
	bool changed = false;
	char next_state[MAX];
	memset(next_state, '0', sizeof(next_state));
	if (in_str[0] == '0') {
		if (in_str[1] == '1') {
			next_state[0] = '1';
			changed = true;
		}
	}
	else {
		next_state[0] = '1';
	}
	if (in_str[n - 1] == '0') {
		if (in_str[n - 2] == '1') {
			next_state[n - 1] = '1';
			changed = true;
		}
	}
	else {
		next_state[n - 1] = '1';
	}
	for (int i = 1; i < n; i++) {
		if (in_str[i] == '0') {
			int cnt = 0;
			int left = i - 1, right = i + 1;
			cnt += in_str[left] == '1' ? 1 : 0;
			cnt += in_str[right] == '1' ? 1 : 0;
			if (cnt == 1) {
				next_state[i] = '1';
				changed = true;
			}
		}
		else {
			next_state[i] = '1';
		}
	}
	for (int i = 0; i < n; i++) {
		in_str[i] = next_state[i];
	}
	return changed;
}

int main() {
	int t; 
	scanf("%d", &t);
	while (t--) {
		long long int n, m;
		scanf("%lld %lld", &n, &m);
		scanf("%s", in_str);
		bool allZeros = true;
		for (int i = 0; i < n; i++) {
			if (in_str[i] == '1') {
				allZeros = false;
				break;
			}
		}
		if (allZeros) {
			printf("%s\n", in_str);
		}
		else {
			for (int i = 0; i < m && opt(n); i++) {}
			printf("%s\n", in_str);
		}
	}
	return 0;
}