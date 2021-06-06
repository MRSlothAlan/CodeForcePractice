#include "SuffixArray.h"
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1 << 21;
char * S;
int N, gap;
int sa[MAXN],	// suffix array.
	pos[MAXN],	// stores the int value of characters
	tmp[MAXN];

bool SuffixArray::sufCmp(int i, int j) {
	if (pos[i] != pos[j])
		return pos[i] < pos[j];
	i += gap;
	j += gap;
	return (i < N && j < N) ? pos[i] < pos[j] : i > j;
}

void SuffixArray::buildSA() {
	N = strlen(S);
	// initialize the suffix array and prepare the
	// character array, which will be sorted.
	REP(i, N)
		sa[i] = i, pos[i] = S[i];
	for (gap = 1;; gap *= 2) {
		sort(sa, sa + N, sufCmp);
		REP(i, N - 1)
			tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
		REP(i, N)
			pos[sa[i]] = tmp[i];
		if (tmp[N - 1] == N - 1)
			break;
	}
}

int UseSuffixArray::main(int argc, char* argv[]) {
	string str = "";
	cin >> str;
	S = new char[str.length()];
	strcpy(S, str.c_str());
	SuffixArray::buildSA();
	return 0;
}

/*

submission:



#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
// #include "firstCodeForce.h"
// #include "SuffixArray.h"
using namespace std;
#pragma warning(disable:4996)
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int MAXN = 1 << 21;
char * S;
int N, gap;
int sa[MAXN],	// suffix array.
pos[MAXN],	// stores the int value of characters
tmp[MAXN];

bool sufCmp(int i, int j) {
	if (pos[i] != pos[j])
		return pos[i] < pos[j];
	i += gap;
	j += gap;
	return (i < N && j < N) ? pos[i] < pos[j] : i > j;
}

void buildSA() {
	N = strlen(S);
	// initialize the suffix array and prepare the
	// character array, which will be sorted.
	REP(i, N)
		sa[i] = i, pos[i] = S[i];
	for (gap = 1;; gap *= 2) {
		sort(sa, sa + N, sufCmp);
		REP(i, N - 1)
			tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
		REP(i, N)
			pos[sa[i]] = tmp[i];
		if (tmp[N - 1] == N - 1)
			break;
	}
}

int main(int argc, char* argv[]) {
	string str_in = "";
	cin >> str_in;
	S = new char[str_in.length()];
	strcpy(S, str_in.c_str());
	buildSA();
	cout << str_in.length() << " ";
	for (int i = 0; i < N - 1; i++) {
		cout << sa[i] << " ";
	}
	cout << sa[N - 1] << endl;
}


*/