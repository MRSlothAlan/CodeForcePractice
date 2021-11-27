#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

const int N = 50000;

void player_1() {
	cout << "Ashishgup" << endl;
}

void player_2() {
	cout << "FastestFinger" << endl;
}

bool check_prime(int n) {
	for (int i = 2; i < min(N, n); i++)
		if (n % i == 0)
			return 0;
	return 1;
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		bool lose = (n == 1);
		if (n > 2 && n % 2 == 0) {
			if ((n & (n - 1)) == 0)	// check for odd divisor, damn.
				lose = 1;
			else if (n % 4 != 0 && check_prime(n / 2))
				lose = 1;
		}
		if (lose)
			player_2();
		else player_1();
	}
	return 0;
}

/*
	moves:
	divide n by any of it odd divisor ( > 1), include number itself
	subtract 1 from n if n > 1.
	A moves first. both play opt.
	e.g. if num = 1, F wins.
	
	The key idea that makes my code get wrong answer: I assume that optimal strategy means to pick the largest possible odd value.
*/
/*
const lld MAX = 100000;
lld n, prime[MAX], p_ptr, i, j;
lld isPrime[MAX];


void setPrime() {
	p_ptr = 0;
	for (i = 2; i <= MAX; ++i) {
		if (!isPrime[i]) {
			isPrime[i] = i;
			prime[p_ptr++] = i;
		}
		for (j = 0; j < (int)p_ptr &&
			prime[j] <= isPrime[i] &&
			i * prime[j] <= MAX; ++j) {
			isPrime[i * prime[j]] = prime[j];
		}

	}
}

bool check(int in_n) {
	int root = (int)sqrt(in_n);
	for (j = 0; j < p_ptr && prime[j] <= root; j++) {
		if (in_n % prime[j] == 0) {	// in_n is a multiple of something.
			return false;
		}
	}
	return true;
}

lld tmp_odd_div = 0;

bool hasOddDivisor(lld in_d) {
	lld limit = ceil(sqrt(in_d));
	if ((limit & 1) == 0) {
		limit++;
	}
	for (tmp_odd_div = limit; tmp_odd_div > 1; tmp_odd_div -= 2) {
		if (in_d % tmp_odd_div == 0) {
			return true;
		}
	}
	if (tmp_odd_div <= 1) {
		tmp_odd_div = 1;
		return false;
	}
}

int main() {
	// FastestFinger wins for n = 1, n = 2x where(x > 1) and n = 2⋅p where p is a prime ≥3 else Ashishgup wins.
	int t; scanf("%d", &t);
	setPrime();
	while (t--) {
		
		Key Idea:

		FastestFinger wins for n=1 , n=2x where (x>1)
		and n=2⋅p where p is a prime ≥3 else Ashishgup wins.

		Solution:

		Let's analyse the problem for the following 3 cases:
	
		lld n; scanf("%lld", &n);
		if (n == 1) {
			printf("FastestFinger\n");
		}
		else if (n == 2) {
			printf("Ashishgup\n");
		}
		else {
			if ((n & 1) == 0) {
				
				Case 2: n is even and has no odd divisors greater than 1
					Here n is of the form 2x. As n has no odd divisors greater than 1,
					Ashishgup is forced to subtract it by 1 making n odd. So if x>1,
					FastestFinger wins. For x=1, n−1 is equal to 1, so Ashishgup wins.
				
				bool hasOdddiv = hasOddDivisor(n);
				if (!hasOdddiv) {
					printf("FastestFinger\n");
				}
				else if (hasOdddiv){
					
					Case 3: n is even and has odd divisors
					If n is divisible by 4 then Ashishgup can divide n by
					its largest odd factor after which n becomes of the form 2x where x>1,
					so Ashishgup wins.
					
					if (n % 4 == 0) {
						printf("Ashishgup\n");
					}
					else {
						
						Otherwise n must be of the form 2⋅p, where p is odd. If p is prime,
						Ashishgup loses since he can either reduce n by 1 or divide it by p both
						of which would be losing for him.
						If p is not prime then p must be of the form p1⋅p2 where p1 is prime and
						p2 is any odd number >1.
						Ashishgup can win by dividing n by p2.
						
						lld fac = n / 2;
						if (check(fac)) {
							printf("FastestFinger\n");
						}
						else {
							printf("Ashishgup\n");
						}
					}
				}
			}
			else {
				
				Case 1: n is odd
				Here Ashishgup can divide n by itself, since it is odd and hence nn=1,
				and FastestFinger loses. Here n=1 is an exception.
				
				printf("Ashishgup\n");	// obviously wins.
			}
		}
	}
	return 0;
}
*/

/*
#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
using namespace std;

const int N = 50000;

void player_1(){
	cout << "Ashishgup" << endl;
}

void player_2(){
	cout << "FastestFinger" << endl;
}

bool check_prime(int n){
	for(int i = 2; i < min(N, n); i++)
		if(n % i == 0)
			return 0;
	return 1;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		bool lose = (n == 1);
		if(n > 2 && n % 2 == 0){
			if((n & (n — 1)) == 0)	// check for odd divisor, damn.
				lose = 1;
			else if(n % 4 != 0 && check_prime(n / 2))
				lose = 1;
		}
		if(lose)
			player_2();
		else player_1();
	}
	return 0;
}
*/