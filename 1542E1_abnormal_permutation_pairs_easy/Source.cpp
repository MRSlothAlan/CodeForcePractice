#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
typedef unsigned long int lu;

/*
permutation for 1 to n is a seq. of n integers,
each appears only once.

let p, q = 2 permutations of 1 ~ n.
permutation pairs : (p, q)
-> p < q
-> number of inversion in p > q.
*/
int main() {
	int n; lu mod_val; scanf("%d %lu", &n, &mod_val);
	printf("%ull", mod_val);
	return 0;
}