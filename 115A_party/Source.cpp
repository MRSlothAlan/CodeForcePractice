#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define MAX(a, b) a > b ? a : b
vector<int> tree[3000];
vector<int> roots;
int max_val = -1;
// find the height of the tree.
void dfs(int cur_height, int par) {
	if (tree[par].size() == 0) {
		max_val = MAX(cur_height, max_val);
	}
	else {
		for (int c : tree[par]) {
			dfs(cur_height + 1, c);
		}
	}
}

int main() {
	int n; scanf("%d", &n);
	for (int ith = 1; ith <= n; ith++) {
		int im_manager; scanf("%d", &im_manager);
		if (im_manager != -1) {
			tree[im_manager].push_back(ith);
		}
		else {
			roots.push_back(ith);
		}
	}
	for (int r : roots) {
		dfs(0, r);
	}
	printf("%d", max_val + 1);
	return 0;
}