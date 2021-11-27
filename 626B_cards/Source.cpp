#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <queue>
#define ROUND_RGB(a) a > 2 ? 2 : a
using namespace std;
const int MAX = 300;
char s[MAX];
bool valid[3];

bool all_valid() {
	for (bool val : valid) {
		if (!val) return false;
	}
	return true;
}

// make a state like structure?
struct state {
	int r, g, b;
	state() {}
	state(int in_b, int in_g, int in_r) {
		this->r = in_r;
		this->g = in_g;
		this->b = in_b;
	}
	int sum_rgb() {
		return this->b + this->g + this->r;
	}
};

int main() {
	int n; scanf("%d", &n);
	scanf("%s", &s);
	int len = strlen(s);
	int R = 0, G = 0, B = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == 'R') R++;
		else if (s[i] == 'G') G++;
		else if (s[i] == 'B') B++;
	}
	R = ROUND_RGB(R);
	G = ROUND_RGB(G);
	B = ROUND_RGB(B);
	/*
	round up the values? Yes for sure.
	*/

	state init_s = state(B, G, R);
	queue<state> Q;
	Q.push(init_s);

	while (!Q.empty() && !all_valid()) {
		state cur = Q.front(); Q.pop();
		if (cur.sum_rgb() == 1) {
			if (cur.b == 1) { valid[0] = true; }
			else if (cur.g == 1) { valid[1] = true; }
			else if (cur.r == 1) { valid[2] = true; }
		}
		else {
			state new_s;
			if (cur.b >= 2) { new_s = state(cur.b - 1, cur.g, cur.r); Q.push(new_s); }
			if (cur.g >= 2) { new_s = state(cur.b, cur.g - 1, cur.r); Q.push(new_s); }
			if (cur.r >= 2) { new_s = state(cur.b, cur.g, cur.r - 1); Q.push(new_s); }
			if (cur.b > 0 && cur.g > 0) { new_s = state(cur.b - 1, cur.g - 1, cur.r + 1); Q.push(new_s); }
			if (cur.g > 0 && cur.r > 0) { new_s = state(cur.b + 1, cur.g - 1, cur.r - 1); Q.push(new_s); }
			if (cur.r > 0 && cur.b > 0) { new_s = state(cur.b - 1, cur.g + 1, cur.r - 1); Q.push(new_s); }
		}
	}
	if (valid[0]) printf("B");
	if (valid[1]) printf("G");
	if (valid[2]) printf("R");
	return 0;
}

/*
take any two (not necessarily adjacent) cards with different colors and 
exchange them for a new card of the third color;

take any two (not necessarily adjacent) cards with the same color 
and exchange them for a new card with that color.

repeat until one card left

=> GRG.

*/