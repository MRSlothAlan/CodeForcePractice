#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
// A, B
/*
map<long long int, int> M_cnt;
vector<long long int> odd, even;
*/

/*
	FUCKING GAME? USUALLY GAMES, THE SO-CALLED OPTIMAL WAY IS AMBIGUOUS.
	my logic is the same as the author's one, but a smatter way is needed here.
*/

long long int tmp;
bool com(long long int l, long long int r) {
	return l > r;
}
vector<long long int> vec;
long long int global_val = 0;	// use gloabl val instead.

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		global_val = 0;
		// long long int A = 0, B = 0;
		vec.clear();
		int n; scanf("%d", &n);
		while (n--) {
			scanf("%lld", &tmp);
			vec.push_back(tmp);
		}
		sort(vec.begin(), vec.end(), com);
		bool A_turn = true;
		for (long long int val : vec) {
			if (A_turn) {
				if ((val & 1) == 0) {
					global_val += val;
					// A += val;
				}
			}
			else {
				if ((val & 1) != 0) {
					global_val -= val;
					// B += val;
				}
			}
			A_turn = !A_turn;
		}
		if (global_val > 0) {
			printf("Alice\n");
		}
		else if (global_val < 0) {
			printf("Bob\n");
		}
		else {
			printf("Tie\n");
		}
	}
	return 0;
}

/*
M_cnt.clear();
odd.clear(); even.clear();
int n; scanf("%d", &n);
while (n--) {
	long long int val; scanf("%lld", &val);
	if (M_cnt.find(val) == M_cnt.end()) {
		M_cnt.insert(pair<long long int, int>(val, 1));
		if ((val & 1) == 0) { even.push_back(val); }
		else { odd.push_back(val); }
	}
	else {
		M_cnt[val]++;
	}
}
int odd_len = odd.size(), even_len = even.size(),
	optr = 0, eptr = 0;
sort(odd.begin(), odd.end(), com);
sort(even.begin(), even.end(), com);
// Alice first.

int turn = 1;
while (optr < odd_len && eptr < even_len) {
	A += even[eptr]; eptr++; turn++;
	if (eptr >= even_len) break;
	B += odd[optr]; optr++; turn++;
	if (optr >= odd_len) break;
}
if ((turn & 1) == 0) {	// Bob's turn
	for (int i = optr; i < odd_len; i += 2) {
		B += odd[i];
	}
}
else {	// Alice's turn
	for (int i = eptr; i < even_len; i += 2) {
		A += even[i];
	}
}*/