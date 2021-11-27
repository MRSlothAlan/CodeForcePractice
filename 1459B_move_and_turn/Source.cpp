#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
typedef long long int l;
/*
if first step : n / s, w / e
vice versa.
*/
int main() {
	int n; scanf("%d", &n);
	// number of different possible locations.
	/*
	hints : please observe all the details and come up with a general form.
	*/
	l sum;
	if ((n & 1) == 0) {
		sum = (n / 2 + 1) * (n / 2 + 1);
	}
	else {
		l k = (n - 1) / 2;
		sum = 2 * (k + 1) * (k + 2);
	}
	printf("%lld", sum);
	return 0;
}

/*
bool state[4000][4000];
// cur can be 1 or 2.
l naive(int step, int cur_r, int cur_c, int cur) {
	if (step == 0) {
		if (!state[cur_r][cur_c]) {
			state[cur_r][cur_c] = true;
			return 1;
		}
		return 0;
	}
	else {
		l sum = 0;
		if (cur == 1) {
			sum += naive(step - 1, cur_r, cur_c + 1, 2);
			sum += naive(step - 1, cur_r, cur_c - 1, 2);
		}
		else if (cur == 2) {
			sum += naive(step - 1, cur_r + 1, cur_c, 1);
			sum += naive(step - 1, cur_r - 1, cur_c, 1);
		}
		return sum;
	}
}
*/

/* 
We will describe an O(1) formula solution. Some slower solutions were also allowed.

First, consider the case when n is even. Regardless of the initial direction, 
we will make n/2 horizontal (west-east) steps and n/2 vertical (north-south) steps. 
Further, directions of horizontal and vertical steps may be decided independently.

If we have to make, say, k horizontal steps choosing left/right direction every time, 
there are k+1 possible horizontal positions x we can end up in. Indeed, all possible ways can be grouped as follows:

k steps left, 0 steps right: x=−k;
k−1 steps left, 1 step right: x−−k+2;
...
0 steps left, k steps right: x=k.
Back in the case of even n, since the directions for vertical and horizontal steps can be chosen independently, 
there are (n/2+1)2 possible combinations of final x and y.

Let's now say that n=2k+1 is odd. If we start with a horizontal step, 
then in total we will be making k+1 horizontal steps and k vertical steps, thus the number of combinations here is (k+1)×(k+2). 
A similar argument applies for when we start with a vertical step. 

Finally, observe that it is impossible to reach the same position starting with both vertical and horizontal step. 
This is because the parity of, say, the final horizontal position x is the same as the number of horizontal steps, 
thus it can not be the same after k and k+1 horizontal steps. Thus, in the odd case the answer is 2(k+1)(k+2), where k=n/2 rounded down.

*/