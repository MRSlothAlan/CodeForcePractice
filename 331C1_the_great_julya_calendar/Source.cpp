#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

/*	magic number, -d, new mn, 
	substract by max digit.		*/
int main() {
	unsigned long long int n; 
	scanf("%llu", &n);

	return 0;
}

/*
In order to solve subproblem C1 we could either calculate dynamics 
or subtract the largest number using greedy algorithm. 
It is easy to prove that it is always better to subtract the 
largest number. 

In subproblem C2 it is sufficient to calculate dynamics for the 
first million, divide (in head) the number into two groups of digits — 
low orders and high orders — and make not one subtraction, 
but a series of subtractions in order to instantly minimize low orders. 

In order to solve subproblem C3 it is necessary to store in dynamics 
parameters not the number itself, but only the number of digits.
*/

/*
Let me try. First of all, in C2 we can do what's written in the editorial: split the number in two parts(6 digits each), now while the first part is fixed, all we need to know about it is the biggest digit. So we calculate two arrays: cnt[dig][n] — how many operations we need to get to negative number if we can subtract maximum of dig and biggest digit of n, and decr[dig][n] — what is the first negative number we reach this way(here 0 ≤ dig < 10, 0 ≤ n < 106). After that, we can decrease first part by one in O(1) time and that's it.

C3's solution is almost the same, we calculate arrays cnt and decr again using memoization, but we split the number into the first digit and remainder.
*/