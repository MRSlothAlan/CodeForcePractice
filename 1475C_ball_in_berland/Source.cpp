#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
const int MAX = 300000;
int boys[MAX], girls[MAX];
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int a, b, k; scanf("%d %d %d", &a, &b, &k);
		for (int i = 0; i < k; i++) {
			// boys.
			scanf("%d", &boys[i]);
		}
		int res_cnt = 0;
		for (int i = 1; i < k; i++) {
			// girls.
			scanf("%d", &girls[i]);
			for (int j = i - 1; j >= 0; j--) {
				if (boys[i] == boys[j] || girls[i] == girls[j]) {}
				else {
					res_cnt++;
				}
			}
		}
		// I think this will get TLE
		// number of data can be 2 * 10 ^ 5.
		// but just try it out anyway.
		/*
		for (int i = 0; i < k; i++) {
			for (int j = i + 1; j < k; j++) {
				if (boys[i] == boys[j] || girls[i] == girls[j]) {}
				else {
					res_cnt++;
				}
			}
		}*/
		printf("%d\n", res_cnt);
	}
	return 0;
}
/*
possible algo, really think by me.
count cycles in graphs.
count out degrees of node.
*/

/* 
1475C - Ball in Berland
We can think that it is given a bipartite graph. Boys and girls are the vertices of the graph. 
If a boy and a girl are ready to dance together, then an edge is drawn between them. 
In this graph, you need to select two edges that do not intersect at the vertices.

Let deg(x) — the number of edges included in the vertex x.
Iterate over the first edge — (a,b). 
It will block deg(a)+deg(b)−1 of other edges 
(all adjacent to vertex a, to vertex b, but the edge (a,b) will be blocked twice. 
All non-blocked edges do not intersect with (a,b) at the vertices. So you can add k−deg(a)−deg(b)+1 to the answer.
*/
