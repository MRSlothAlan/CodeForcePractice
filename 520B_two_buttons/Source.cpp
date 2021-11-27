#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define MIN(a, b) a < b ? a : b
typedef long long int lld;
const int MAX = 1e7;
// your prev attempt also has checked, graph and queue 
// but... look at other's efficient approach.
vector<int> G[MAX];
bool vis[MAX];
bool vis_graph[MAX];
queue<lld> Q;
lld dist[MAX];

lld n, m;

// things learnt:
// instead of making nested for loops,
// use a great and clear recursive function instead.
void recursive_add_G(lld x) {
	if (x != m && x > 0 && !vis_graph[x]) {
		vis_graph[x] = true;
		G[x].push_back(x - 1);	// minus 1
		G[x].push_back(2 * x);  // or time 2.
		if (x < m) {
			recursive_add_G(2 * x);
		}
		recursive_add_G(x - 1);
	}
}

// you also have BFS, but what's the difference
// that set those programmer apart?
void bfs(lld x) {
	vis[x] = true;
	Q.push(x);	// only stores the cur_node,
	// no need to make a struct.
	while (!Q.empty()) {
		lld cur_node = Q.front();
		Q.pop();
		for (lld des : G[cur_node]) {
			if (!vis[des]) {
				vis[des] = true;
				// smart, use a dist arr to store the dist.
				// no relaxation needed, why?
				// because all the route are unique.
				// 4 -> 8 -> 16
				// if minus one, 3 -> 6 -> 12... different
				dist[des] = dist[cur_node] + 1;
				Q.push(des);
			}
		}
	}
}

int main() {
	// well, let's look at how others build their graphs.
	scanf("%lld %lld", &n, &m);
	if (n == m) {
		printf("0");
	}
	else {
		// oh learn that.
		recursive_add_G(n);
		bfs(n);
		printf("%lld", dist[m]);
	}
	return 0;
}

/*
red : mul num by 2.
blue: sub num by 1.
if num <= 0, break.
want to get number m.

e.g. n = 10, m = 1, press blue 9 times.
*/
/*
in a graph, there are multiple edges.
*/

/*
The simplest solution is simply doing a breadth-first search. 
Construct a graph with numbers as vertices and edges leading from one number to another 
if an operation can be made to change one number to the other. 

We may note that it is never reasonable to make the number larger than 2m, 
so under provided limitations the graph will contain at most 2·104 vertices and 4·104 edges, 
and the BFS should work real fast.

There is, however, an even faster solution. T
he problem can be reversed as follows: we should get the number n starting from m using the operations 
"add 1 to the number" and "divide the number by 2 if it is even".

Suppose that at some point we perform two operations of type 1 and then one operation of type 2; 
but in this case one operation of type 2 and one operation of type 1 would lead to the same result, 
and the sequence would contain less operations then before. 

That reasoning implies that in an optimal answer more than one consecutive operation of type 1 is possible only if no operations of type 2 follow, that is, the only situation where it makes sense is when n is smaller than m and we just need to make it large enough. Under this constraint, there is the only correct sequence of moves: if n is smaller than m, we just add 1 until they become equal; else we divide n by 2 if it is even, or add 1 and then divide by 2 if it is odd. The length of this sequence can be found in .

Challenge: suppose we have a generalized problem: we want to get n starting from m using two operations "subtract a" and "multiply by b". Generalize the solution to find the minimal number of moves to get from n to m in  time if a and b are coprime. Can you do it if a and b may have common divisors greater than 1?
*/

/*
previous submission:

// well, minus then multiply is also great.
int tmp_val = 0, steps = 0, min_steps = MAX;
for (int num = n; num >= 1; num--) {
	// if (!checked[num]) {
	bool valid = true;
	tmp_val = num; steps = n - num;
	checked[tmp_val] = true;
	while (tmp_val < m && valid) {
		tmp_val *= 2;
		steps++;
		if (checked[tmp_val]) {
			valid = false;
			break;
		}
		checked[tmp_val] = true;
	}
	if (valid) {
		steps += tmp_val - m;
		min_steps = MIN(min_steps, steps);
	}
	// }
}
printf("%d", min_steps);
*/


/*
bool checked[MAX];

struct state {
	lld step_cnt, cur_node;
	state() {}
	state(lld in_cur_node, lld in_step) {
		this->cur_node = in_cur_node;
		this->step_cnt = in_step;
	}
};
set<lld> G[MAX];
// really ? I thought there are better methods but turns out that I should really make a graph or something.
queue<state> Q;

	else if (n > m) {
		printf("%lld", n - m);
	}
	else {
		// destination : m
		for (lld num = n; num >= 2; num--) {
			for (lld des = num - 1; des >= 1; des--) {
				G[num].insert(des);
			}
			lld tmp_n = num * 2;
			while (tmp_n < m) {
				G[num].insert(tmp_n);
				for (lld des = tmp_n - 1; des >= 1; des--) {
					G[tmp_n].insert(des);
				}
				tmp_n *= 2;
			}
			// last tmp_n.
			G[num].insert(tmp_n);
			for (lld des = tmp_n - 1; des >= 1; des--) {
				G[tmp_n].insert(des);
			}
		}
		lld min_cnt = MAX;
		Q.push(state(n, 0));
		while (!Q.empty()) {
			state cur = Q.front(); Q.pop();
			if (cur.cur_node == m) {
				min_cnt = MIN(min_cnt, cur.step_cnt);
			}
			else {
				int node = cur.cur_node;
				int len = G[node].size();
				int step = cur.step_cnt;
				for (auto itr = G[node].begin(); itr != G[node].end(); itr++) {
					int des = *itr;
					if (!checked[des]) {
						Q.push(state(des, step + 1));
						checked[des] = true;
					}
				}
			}
		}
		printf("%lld", min_cnt);
	}*/