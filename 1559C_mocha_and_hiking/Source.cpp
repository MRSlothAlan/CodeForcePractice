#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 20000;
vector<int> G[MAX];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		for (int v = 1; v <= n + 1; v++) {
			G[v].clear();
		}
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			if (a == 0) {
				G[i].push_back();
			}
			else {

			}
		}
	}
	return 0;
}