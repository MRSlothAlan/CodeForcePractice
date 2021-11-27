#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

/*
alternate turns removing stones.
(the pile with the minimal index, that has at least one stone).

The KEY point :
what the hell is the opt strategy?
player 1 : pick till 1 left, so that 
player 2 : pick ALL?
*/
/*
Suppose a1>1. If removing the entire first pile is winning, 
player 1 will do that. 

Otherwise, player 1 can leave exactly one stone in the first pile, forcing player 2 to remove it, leaving player 1 in the winning position. 
Otherwise, if a1=1, then it is forced to remove the first pile.

So, whichever player gets the first pile with more than one stone wins. 
That is, let k be the maximum number such that a1=⋯=ak=1. If k is even, 
the first player will win. Otherwise, the second player will win. 
The only exception is when all piles have exactly 1 stone. In that case, the first player wins when k is odd.
*/

const int MAX = 110000;
int pile[MAX];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		bool all_ones = true;
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			long long int stones;
			scanf("%lld", &stones);
			if (stones > 1) {
				pile[i] = 2;
				all_ones = false;
			}
			else {
				pile[i] = 1;
			}
		}
		if (n == 1) {
			printf("First\n");
		}
		else {
			if (all_ones) {
				if ((n & 1) == 0) {
					printf("Second\n");
				}
				else {
					printf("First\n");
				}
			}
			else {
				// second player's opt strategy: get all.
				bool isF = true;
				for (int i = 0; i < n - 1; i++) {
					if (pile[i] == 1) {
						isF = !isF;
					}
					else {
						// isF = !isF;
						break;
					}
				}
				if (isF) {
					printf("First\n");
				}
				else {
					printf("Second\n");
				}
			}
		}
	}
	return 0;
}

/*
while (pile[i] > 0) {
					if (!isF) {
						pile[i] = 0;
						isF = !isF;
					}
					else {
						isF = !isF;
						pile[i]--;
					}
				}
*/