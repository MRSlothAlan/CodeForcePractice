#include <iostream>
#include <vector>
using namespace std;

// euler's totient function
// phi function
/*
number from 1 to n, coprime to n.
gcd() = 1
*/
// O(sqrt(N)) time, don't have to repeatedly check other factors, which is a multiple of current one.
int phi(int n) {
	int result = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0) { 
				n /= i;
			}
			result -= result / i;
		}
	}
	if (n > 1)
		result -= result / n;
	return result;
}

void phi_1_to_n(int n) {
	vector<int> phi(n + 1);
	phi[0] = 0;
	phi[1] = 1;
	for (int i = 2; i <= n; i++)
		phi[i] = i;

	for (int i = 2; i <= n; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= n; j += i)
				phi[j] -= phi[j] / i;
		}
	}
}

/*
Divisor sum property
Gauss
divisors of 10 : 1, 2, 5, 10
let &(n) : function to find number of prime divisors of a number
e.g. 5 : 1, 2, 5.
10: 1, 2, 5
https://cp-algorithms.com/algebra/phi-function.html
*/


// number of divisors / sums of divisors.
// https://cp-algorithms.com/algebra/divisors.html

int main() {
	cout << phi(8) << endl;
	return 0;
}