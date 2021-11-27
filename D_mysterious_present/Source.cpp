#pragma warning(disable : 4996)
#include <cstdio>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

// nope
struct env {
	int w, h, idx;
	env(int w_, int h_, int idx_) {
		w = w_;
		h = h_;
		idx = idx_;
	}
};
// vector<env> all_env;
const int MAX = 5001;
int cnt[MAX], path[MAX], w_e[MAX], h_e[MAX], idx_e[MAX];

bool com(const env &l, const env &r) {
	return (l.w < r.w || l.w == r.w && l.h < r.h);
}

bool com_(const int a, const int b) {
	if (w_e[a] == w_e[b]) return h_e[a] > h_e[b];
	return w_e[a] > w_e[b];
}

int main() {
	int n, w, h, i;
	// amt of envelopes, card width, height
	scanf("%d %d %d", &n, &w, &h);
	// all_env.empty();
	for (i = 0; i < MAX; i++) cnt[i] = 1;
	memset(path, -1, sizeof(path));
	for (i = 0; i < n; i++) {
		scanf("%d %d", &w_e[i], &h_e[i]);
		idx_e[i] = i;
		// all_env.push_back(env(wi, hi, i + 1));
	}
	sort(idx_e, idx_e + n, com_);
	int prev_w = w, prev_h = h;
	/*
	for (i = 0; i < n; i++) {
		env cur = all_env.at(i);
		if (cur.w > w && cur.h > h)
			break;
	}
	*/
	// naive problem: sometimes,
	/*
	If you pick 6 9 first, then so on
	May be you will get a better result if 7 7 is the starting one
	What if next one is 8 8?
	Ah, you should have think about it boy.
	dp thinking = your bottleneck.
	REMEMBER this. dp = level 2. Your level: level 1 to 2
	*/
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (h_e[idx_e[i]] < h_e[idx_e[j]] && w_e[idx_e[i]] < w_e[idx_e[j]]) {
				if (cnt[j] + 1 > cnt[i]) {
					cnt[i] = cnt[j] + 1;
					path[i] = j;
				}
			}
		}
	}
	int ans = 0, starting = -1;
	for (int i = 0; i < n; i++) {
		if (h_e[idx_e[i]] > h && w_e[idx_e[i]] > w) {
			// check the length of that path.
			if (cnt[i] > ans) {
				starting = i;
				ans = cnt[i];
			}
		}
	}
	printf("%d\n", ans);
	if (starting != -1) {
		int tmp = starting;
		while (tmp != -1) {
			// idx shift by 1
			printf("%d ", idx_e[tmp] + 1);
			tmp = path[tmp];
		}
	}
	/*
	vector<int> res_idx;
	for (; i < n; i++) {
		env cur = all_env.at(i);
		if (cur.w > prev_w && cur.h > prev_h) {
			res_idx.push_back(cur.idx);
			prev_w = cur.w;
			prev_h = cur.h;
		}
	}
	int s = res_idx.size();
	if (s == 0) {
		printf("0\n");
	}
	else {
		printf("%d\n", s);
		for (int i = 0; i < s; i++) {
			printf("%d ", res_idx.at(i));
		}
	}
	*/
	return 0;
}