#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 200000;
int hasCat[MAX];

vector<int> G[MAX];

struct state {
	int node, parent, cat;
	state(int n, int p, int c) {
		node = n; parent = p, cat = c;
	}
};
queue<state> Q;
// bool visited[MAX];

/*
Problem: 
	-> My understanding: along the path, accumulate the number of cats, ignore the cats in the leaf.
	-> REAL meaning: consecutive number of cats, if no cats in the middle: reset count to 0.
	Pay attention.
*/


int main() {
	int n, m, i, x, y;
	// number of vertices, max. num of con. v, still have cats. 
	// memset(visited, false, sizeof(visited));
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) { scanf("%d", &hasCat[i]); }
	for (i = 1; i <= n; i++) { G[i].clear(); }
	for (i = 0; i < n - 1; i++) {
		scanf("%d %d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
		/*
		Note: isn't it a FUCKING TREE?
		Why it is now a GRAPH thing...
		normally, in a tree, no need bi-directional edges.
		*/
	}
	// starts from 1.
	while (!Q.empty()) {
		Q.pop();
	}
	int res_cnt = 0;
	// idx, cur cat count.
	// Q.push(pair<int, int>(1, hasCat[1]));
	Q.push(state(1, 0, hasCat[1]));
	// visited[1] = true;
	while (!Q.empty()) {
		state cur = Q.front(); Q.pop();
		int size_ = G[cur.node].size();
		if (size_ == 1 && G[cur.node][0] == cur.parent && cur.cat <= m) {
			res_cnt++;
		}
		else {
			for (int idx = 0; idx < size_; idx++) {
				int next_idx = G[cur.node][idx];
				if (next_idx != cur.parent) {
					if (cur.cat > m) {}
					else {
						state next = state(next_idx, cur.node, hasCat[next_idx] ? cur.cat + 1 : 0);
						Q.push(next);
					}
				}

				/*
				if (hasCat[next_idx] && cat_cnt + 1 > m) {}
				else if (cat_cnt <= m){
					if (hasCat[next_idx] && cat_cnt + 1 <= m) {
						//res_cnt++;
						Q.push(pair<int, int>(next_idx, (cat_cnt + 1)));
					}
					else if (!hasCat[next_idx]){
						//res_cnt++;
						Q.push(pair<int, int>(next_idx, cat_cnt));
					}
				}
				*/
			}
		}
	}
	printf("%d\n", res_cnt);
	return 0;
}