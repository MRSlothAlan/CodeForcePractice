#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
// good graph
// undirected graph.
const int MAX_E = 1200000;
const int MAX_N = 300500;
struct state {
	int one_cnt, cur_node;
	state() {}
	state(int in_one_cnt, int in_cur_n) {
		this->cur_node = in_cur_n;
		this->one_cnt = in_one_cnt;
	}
};

struct e {
	int to, w;	// w either 0 or 1.
	e() { to = 0, w = -1; }
	e(int in_to, int in_w) {
		this->to = in_to;
		this->w = in_w;
	}
};
e edges[MAX_E];
int id;
vector<int> G[MAX_N];

void insert(int u, int v, int w) {
	edges[id] = e(v, w);
	G[u].push_back(id);
	id++;
	edges[id] = e(u, w);
	G[v].push_back(id);
	id++;
}

void remove_latest(int u, int v, int w) {
	id--;
	G[v].pop_back();
	edges[id] = e();
	id--;
	G[u].pop_back();
	edges[id] = e();
}

bool valid_G(int start_pt) {
	queue<state> Q;
	Q.push(state(-1, start_pt));
	while (!Q.empty()) {
		state cur_s = Q.front(); Q.pop();
		if (cur_s.one_cnt >= 0 && cur_s.cur_node == start_pt) {

		}
		else {
			int tmp_one_cnt = cur_s.one_cnt == -1 ? 0 : cur_s.one_cnt;
			for (int edge_id : G[cur_s.cur_node]) {
				e cur_e = edges[edge_id];
				tmp_one_cnt += cur_e.w;

			}
		}
	}
	return false;
}

int main() {
	// from 1 to n;
	int n, q; scanf("%d %d", &n, &q);
	while (q--) {
		id = 0;
		for (int i = 0; i <= n; i++) { G[i].clear(); }
		e tmp = e();
		memset(edges, 0, sizeof(edges));
		int u, v, x; scanf("%d %d %d", &u, &v, &x);
		insert(u, v, x);

	}
	return 0;
}

/*
simple cycle -> cycle of the graph
without repeated vertices.

weight of cycle = XOR of weights of edges.
graph = good, if all simple cycles have weight 1.
*/

/*
Firstly, let's prove that a good graph has one important property: any two of its simple cycles intersect by at most one vertex, i. e. there is no edge that belongs to more than one simple cycle (cactus definition, yeah).

Let's prove it by showing that if two simple cycles of weight k>0 intersects (by edges) then they will induce a simple cycle of weight ≠k. There are two cases:

if cycles intersect by a single path, then we can create a new cycle by merging parts of cycles excluding the intersecting path — it will be simple and will have weight k⊕k=0≠k;
if cycles intersect by more than one path, we can do the next transformation: suppose the common paths are u1−v1, u2−v2, …, and they are ordered in the way how they lie on the first cycle. Let's create a third cycle using two paths from v1 to u2: from the first cycle and from the second cycle. It's easy to see that the third cycle is simple, and more over it has only one common path with the second cycle. So, it's either the third cycle has weight not equal to k or the case 1.
Okay, let's analyze the edges we try to add. Let's divide all edges in two types: tree edges and all other edges (we will name them cycle edges). Let's name an edge as a tree edge if it connects two different components at a moment when we are trying to add it in the graph.

It's obvious that we will add all tree edges in the graph, since they can't make it bad (since they don't induce new cycles). But there is a more interesting observation: when we try to add a cycle edge (u,v), it should induce an only one simple cycle where all other edges are tree edges and these tree edges can't be used in any other cycle.

It induces at least one "all-tree-edge" cycle, since u and v are already connected. It can't induce more than one "all-tree-edge" cycle, since it contradicts with tree edge definition, and if it induces a cycle with some other cycle edge, then we can replace that cycle edge with its own tree-edge path: our cycle will become "all-tree-edge" cycle, but it will use already used tree edges. In other words, it's enough to consider only one "all-tree-edge" cycle induced by any cycle edge.

The final trick is to calculate the answer in two steps: at the first step, we will find only tree edges (using DSU) that will form a spanning forest in our graph.

The second step is for each cycle edge (u,v) to calculate the XOR X on a path between u and v in our spanning forest, check that X⊕edge_weight=1 and check that none of edges on the path from u to v are used in other cycle.

Calculating X is easy: if we precalculate for each vertex v the XOR on path from v to root xr[v] then X=xr[u]⊕xr[v].

Checking that none of the edges are used on the path from u to v is a bit tricky: if we mark an edge by adding 1 to it, then we should be able to take a sum on path and add on path. There are structures that are capable of it (like HLD and other), but let's look closely.

Note that we mark each tree edge at most once, so we can manually add 1 to each edge, and only asking sum on path should be fast. In other words, we need a data structure (DS) that can add value at edge and take the sum on path — and such DS is a Fenwick tree (BIT) built on Euler tour of tree: it can add value at edge and ask a sum on path from v to root. So we need to find LCA as well, since sum of path (u,v) is equal to sum(u)+sum(v)−2⋅sum(LCA(u,v)).

As a result, complexity is O((n+m)log(n)) with quite a low constant from LCA and BIT.

*/