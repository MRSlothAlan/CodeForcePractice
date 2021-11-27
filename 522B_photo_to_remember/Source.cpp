#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 300000;
// stands in a line.

/*
how about 10 1 4 2 3 7 11 34
sort : 1 2 3 4 7 10 11 34
*/

int W[MAX], H[MAX];
vector<int> h_val;
int main() {
	int n; scanf("%d", &n);
	h_val.clear();
	int s_w = 0;
	for (int i = 0; i < n; i++) {
		int w, h; scanf("%d %d", &w, &h);
		W[i] = w; 
		H[i] = h;
		h_val.push_back(h);
		s_w += w;
	}
	sort(h_val.begin(), h_val.end());
	int max_h = h_val[n - 1], sec_max_h = h_val[n - 2];
	// init, pick max_h.
	for (int i = 0; i < n; i++) {
		int tmp_h = H[i];
		if (tmp_h < max_h) 
			tmp_h = max_h; 
		else 
			tmp_h = sec_max_h;
		printf("%d ", ((s_w - W[i]) * tmp_h));
	}
	return 0;
}