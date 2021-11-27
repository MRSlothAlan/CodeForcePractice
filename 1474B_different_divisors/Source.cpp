#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 20000000;
bool isPrime[MAX];
vector<int> primes;

void opt() {
	memset(isPrime, true, sizeof(isPrime));
	isPrime[1] = false;
	isPrime[2] = true;
	isPrime[3] = true;
	int cnt = 2;
	primes.push_back(2);
	primes.push_back(3);
	for (int i = 3; i <= MAX && cnt < 10000; i += 2) {
		if (isPrime[i]) {
			for (int j = i * 2; j < MAX; j += i) {
				isPrime[j] = false;
			}
			cnt++;
			primes.push_back(i);
		}
	}
}

int main() {
	opt();
	int t; scanf("%d", &t);
	while (t--) {
		int d; scanf("%d", &d);
		long long int a = 1, b = 1;
		a *= *std::lower_bound(primes.begin(), primes.end(), d + 1);
		b *= *std::lower_bound(primes.begin(), primes.end(), a + d);	// difference, at least d, come on. Maybe you need a break.
		printf("%lld\n", min(a * a * a, a * b));
	}
	return 0;
}
/* 
find the smallest 
*/

/*
#include <bits/stdc++.h>

using namespace std ;

const int MAX = 1e5 + 10 ;

bool prime[MAX] ;
int d ;

vector<int>primes ;

void sieve()
{
	for(int i = 2 ; i < MAX ; ++i)
		prime[i] = 1 ;
	for(int i = 2 ; i < MAX ; ++i)
	{
		if(prime[i])
		{
			primes.push_back(i) ;
			for(int j = i+i ; j < MAX ; j += i)
				prime[j] = 0 ;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	sieve() ;
	int t ;
	cin>>t ;
	while(t--)
	{
		cin>>d ;
		int a = lower_bound(primes.begin() , primes.end() , 1+d) - primes.begin() ;
		a = primes[a] ;
		int b = lower_bound(primes.begin() , primes.end() , a+d) - primes.begin() ;
		b = primes[b] ;
		cout<<min(a * 1ll * a * 1ll * a , a * 1ll * b)<<"\n" ;
	}
	return 0 ;
}
*/