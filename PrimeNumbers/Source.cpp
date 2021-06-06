#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Sieve of Eratosthenes
// you know it. 
void primeNumberSieve(int n) {
	vector<char> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	// concept: 0, 1 are not prime
	// for stuff onwards, if true, then their multiples are
	// NOT prime, of course.
	// I know the problem : when n > 100000... ya very slow.
	for (int i = 2; i <= n; i++) {
		if (is_prime[i] && (long long)i * i <= n) {
			for (int j = i * i; j <= n; j += i)
				is_prime[j] = false;
		}
	}
}
/*
optimize:
	sieving till root (i * i <= n)
	sieving by the odd numbers ONLY
	using bits instead of boolean array (trade-off!)
	just keep bool array : [1 ... sqrt(n)]
*/
int SegmentedSieve(int n) {
	const int S = 10000;	// work best when 10^4 or 10^5
	vector<int> primes;
	int nsqrt = sqrt(n);
	vector<char> is_prime(nsqrt + 1, true);
	// simple sieve
	for (int i = 2; i <= nsqrt; i++) {
		if (is_prime[i]) {
			primes.push_back(i);
			for (int j = i * i; j <= nsqrt; j += i) {
				is_prime[j] = false;
			}
		}
	}
	int result = 0;
	vector<char> block(S);
	// let n = 1000? < S;
	for (int k = 0; k * S <= n; k++) {
		fill(block.begin(), block.end(), true);
		int start = k * S;
		for (int p : primes) {	// loop primes.
			int start_idx = (start + p - 1) / p;
			int j = max(start_idx, p) * p - start;
			for (; j < S; j += p)
				block[j] = false;
		}
		if (k == 0)
			block[0] = block[1] = false;
		for (int i = 0; i < S && start + i <= n; i++) {
			if (block[i]) {
				// calculate the prime numbers using blocks of values.
				// CAN YOU INVENT THIS YOURSELF
				// if yes = great mind.
				cout << i + k * S << endl;
				result++;
			}
		}
	}
	return result;
}

// find prime in a range
vector<bool> segmentedSieve(long long L, long long R) {
	// generate all primes up to sqrt(R)
	long long lim = sqrt(R);
	vector<bool> mark(lim + 1, false);
	vector<long long> primes;
	for (long long i = 2; i <= lim; ++i) {
		if (!mark[i]) {
			primes.emplace_back(i);
			for (long long j = i * i; j <= lim; j += i)
				mark[j] = true;
		}
	}

	vector<bool> isPrime(R - L + 1, true);
	for (long long i : primes)
		for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
			isPrime[j - L] = false;
	if (L == 1)
		isPrime[0] = false;
	return isPrime;
}

// find prime numbers in a range without pre-generation
vector<bool> segmentedSieveNoPreGen(long long L, long long R) {
	vector<bool> isPrime(R - L + 1, true);
	long long lim = sqrt(R);
	for (long long i = 2; i <= lim; ++i)
		for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
			isPrime[j - L] = false;
	if (L == 1)
		isPrime[0] = false;
	return isPrime;
}
// https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html

/*
Sieve of Eratosthenes --- LINEAR time complexity?
	n <= 10^7 
*/
//minimum prime factor lp[i]lp[i] for every number ii in the segment [2;n][2;n].
void LinearSieve() {
	const int N = 10000000;
	int lp[N + 1];		// minimum prime factors
	vector<int> pr;		// stores prime numbers

	for (int i = 2; i <= N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; 
			j < (int)pr.size() &&
			pr[j] <= lp[i] &&	// prime numbers <= current prime factor of number i
			i * pr[j] <= N; ++j) {
			lp[i * pr[j]] = pr[j]; // this number * prime number j has a minimum prime factor of j
			// avoid division when looking for factorization.
		}
	}
}
// primality test : if number is a prime or not?
// fermat's little theorem
// a ^ (p - 1) - 1 is an integer multiple of p.
// a ^ p == a % p (corollary)
using ll = long long;
using u64 = ll;
using u128 = ll;

u64 binpower(u64 base, u64 e, u64 mod) {
	u64 result = 1;
	base %= mod;
	while (e) {
		if (e & 1)
			result = (u128)result * base % mod;
		base = (u128)base * base % mod;
		e >>= 1;
	}
	return result;
}
bool check_composite(u64 n, u64 a, u64 d, int s) {
	u64 x = binpower(a, d, n);
	if (x == 1 || x == n - 1)
		return false;
	for (int r = 1; r < s; r++) {
		x = (u128)x * x % n;
		if (x == n - 1)
			return false;
	}
	return true;
};

bool MillerRabin(u64 n, int iter = 5) { // returns true if n is probably prime, else returns false.
	if (n < 4)
		return n == 2 || n == 3;

	int s = 0;
	u64 d = n - 1;
	while ((d & 1) == 0) {
		d >>= 1;
		s++;
	}

	for (int i = 0; i < iter; i++) {
		int a = 2 + rand() % (n - 3);
		if (check_composite(n, a, d, s))
			return false;
	}
	return true;
}
// deterministic version
bool MillerRabinDet(u64 n) { // returns true if n is prime, else returns false.
	if (n < 2)
		return false;

	int r = 0;
	u64 d = n - 1;
	while ((d & 1) == 0) {
		d >>= 1;
		r++;
	}

	for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
		if (n == a)
			return true;
		if (check_composite(n, a, d, r))
			return false;
	}
	return true;
}

/*
Integer factorization
*/
// find a prime factorization
// we can simply precompute all the primes using sieves.
vector<long long> trial_division2(long long n) {
	vector<long long> factorization;
	while (n % 2 == 0) {
		factorization.push_back(2);
		n /= 2;
	}
	for (long long d = 3; d * d <= n; d += 2) {
		while (n % d == 0) {
			factorization.push_back(d);
			n /= d;
		}
	}
	if (n > 1)
		factorization.push_back(n);
	return factorization;
}
/*
fermat's factorization method
n = ((p + q) / 2) ^ 2 - ((p - q) / 2) ^ 2
*/
int fermat(int n) {
	int a = ceil(sqrt(n));
	int b2 = a * a - n;
	int b = round(sqrt(b2));
	while (b * b != b2) {
		a = a + 1;
		b2 = a * a - n;
		b = round(sqrt(b2));
	}
	return a - b;
}
/*
Pollard's p - 1 method
please check that out
https://cp-algorithms.com/algebra/factorization.html

There are many more methods.
*/
vector<int> primes;
ll gcd(ll a, ll n) {
	// this is a stub.
	return 1;
}

ll power(ll a, ll p_power, ll n) {
	return 1;
}

long long pollards_p_minus_1(long long n) {
	int B = 10;
	long long g = 1;
	while (B <= 1000000 && g < n) {
		long long a = 2 + rand() % (n - 3);
		g = gcd(a, n);
		if (g > 1)
			return g;

		// compute a^M
		for (int p : primes) {
			if (p >= B)
				continue;
			long long p_power = 1;
			while (p_power * p <= B)
				p_power *= p;
			a = power(a, p_power, n);

			g = gcd(a - 1, n);
			if (g > 1 && g < n)
				return g;
		}
		B *= 2;
	}
	return 1;
}


// composite number : non-prime
// coprime numbers : common factor = 1
int main() {
	SegmentedSieve(100000);
	return 0;
}