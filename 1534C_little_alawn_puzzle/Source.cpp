#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

const int MAX = 400005;
int puzzle[2][MAX];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		for (int r = 0; r < 2; r++) {
			for (int i = 0; i < n; i++) {
				scanf("%d", &puzzle[r][i]);
			}
		}
		// initial solved configuration... ans must at least 1

	}
	return 0;
}

/*
Define the "direction" of a column as the orientation of its numbers. 
Swapping the numbers in a column will flip its direction.

Let's create a simple, undirected graph where the nodes are the n columns 
on the puzzle and we draw one edge connecting it to the 2 other columns 
that share a number with it.
Notice that the degree of every node in this graph is 2, 
so the graph must be made of some number of disjoint simple cycles.

Now consider any component in the graph. 
If we fix the direction of any of the columns in the component, 
that will fix the direction of the columns adjacent to it, 
and so on until the direction of every column in the component has been fixed 
(also note that as the component is a simple cycle, we will never get a contradiction). 
As there are 2 possible directions for any column, 
there are thus 2 ways to direct the columns in this component.

Lastly, notice that the columns in each component are independent, so the answer is simply 2k, where k is the number of components in our graph.

Time Complexity: O(n) with DFS
*/