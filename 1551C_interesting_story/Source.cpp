#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
// my code, great!
typedef pair<char, int> d;
string tmp; 
const int MAX = 300000;
d rec[MAX][5];
int tmp_cnt[5]; 
map<char, int> c_r;
char c_allowed[5] = { 'a', 'b', 'c', 'd', 'e' };
vector<d> R;

bool com(d l, d r) {
	return l.second > r.second;
}

int main() {
	c_r['a'] = 0;
	c_r['b'] = 1;
	c_r['c'] = 2;
	c_r['d'] = 3;
	c_r['e'] = 4;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			memset(tmp_cnt, 0, sizeof(tmp_cnt));
			cin >> tmp; int tot = 0;
			for (char c : tmp) { tmp_cnt[c_r[c]]++; }
			for (int cur = 0; cur < 5; cur++) {
				tot = 0;
				// cal. sum of all other letters in total.
				for (int o = 0; o < 5; o++) { if (o != cur) { tot += tmp_cnt[o]; } }
				rec[i][cur] = d(c_allowed[cur], tmp_cnt[cur] - tot);
			}
		}
		int res = 0;
		for (int cur = 0; cur < 5; cur++) {
			R.clear();
			for (int i = 0; i < n; i++) {
				R.push_back(rec[i][cur]);
			}
			sort(R.begin(), R.end(), com);
			int sum = R[0].second;
			int picked = 0;
			if (sum <= 0)
				picked = 0;
			else {
				picked = 1;
				for (int idx = 1; idx < n && sum > 0; idx++) {
					sum += R[idx].second;
					if (sum <= 0) { break; }
					picked++;
				}
			}
			res = max(res, picked);
		}
		printf("%d\n", res);
	}
	return 0;
}

// abcde involved.

/*
Let f(s,c) be the number of the occurrences of the 
letter c in the word s minus the number of the occurrences of all other letters in total. 
Since for each two words s1 and s2 the number of the occurrences of a letter in the word s1+s2 is 
the sum of the numbers of its occurrences in s1 and s2, 
the equality f(s1+s2,c)=f(s1,c)+f(s2,c) is true (s1+s2 means the concatenation of s1 and s2).

Consider a sequence of words s1,s2,…,sn. 
A story consisting of words si1,si2,…,sim is interesting 
if and only if there's a letter c such that f(si1+si2+…+sim,c)>0 — 
it exactly means that there's a letter which occurs more times than all other in total. 
So we are interested in searching for a letter c such that exists a 
positive integer m — a maximal number of words si1,si2,…,sim 
such that ∑j=1mf(sij,c)=f(si1+si2+…+sim,c)>0.

Suppose we have a set of words that form an interesting story and 
where c is the letter having more occurrences than all other letters in total. 
Suppose we can add to it one of few words. 
We had better add a word s such that f(s,c) is maximal to be able to add more words in the future.

So the problem has the following solution: 
for each letter c of the Latin alphabet and 
	for each word si 
		let's calculate f(s,c). 
		Then let's iterate over all letters c, 
		take a sequence f(s1,c),f(s2,c),…,f(sn,c) and sort it in descending order. 
		
	Let's initialize an interesting story by a set of a single word corresponding to the first element of the sequence. 
	If there's no word s such that f(s,c)≤0, then there's no non-empty interesting story containing some words of the given set. 
	Otherwise, let's take the next elements of the sequence sequentially until the sum of f(s,c) over all taken words s 
	is greater than zero. Let's select a letter such that the corresponding taken set is maximal over all letters.
	Finally, we should print the set's size.

The solution consists of two phases: the calculation of all f(s,c) (works in O(L×∑i=1n|si|) where L is the alphabet's size, |s| is the lengths of a string s) and building a maximal interesting story for each letter c (sorting and a greedy algorithm — O(L×n×logn)).
*/