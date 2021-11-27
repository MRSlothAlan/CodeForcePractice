#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 120;
int arr[2][MAX];
vector<int> act_seq;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		act_seq.clear();
		int k, n, m; scanf("%d %d %d", &k, &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[0][i]);
		}
		for (int i = 0; i < m; i++) {
			scanf("%d", &arr[1][i]);
		}
		int a_ptr = 0, b_ptr = 0, prev_a = 0, prev_b = 0;
		bool valid = true;
		while (a_ptr < n && b_ptr < m && valid) {
			prev_a = a_ptr;
			prev_b = b_ptr;
			// wait, add all the lines first
			while (arr[0][a_ptr] == 0 && a_ptr < n) {
				k++;
				act_seq.push_back(arr[0][a_ptr]);
				a_ptr++;
			}
			while (arr[1][b_ptr] == 0 && b_ptr < m) {
				k++;
				act_seq.push_back(arr[1][b_ptr]);
				b_ptr++;
			}
			// check the line edited.
			while (arr[0][a_ptr] > 0 && a_ptr < n) {
				if (arr[0][a_ptr] > k) {
					break;
				}
				else {
					act_seq.push_back(arr[0][a_ptr]);
					a_ptr++;
				}
			}
			while (arr[1][b_ptr] > 0 && b_ptr < m) {
				if (arr[1][b_ptr] > k) {
					break;
				}
				else {
					act_seq.push_back(arr[1][b_ptr]);
					b_ptr++;
				}
			}
			if (prev_a == a_ptr && prev_b == b_ptr) {
				valid = false;
				a_ptr = n;
				b_ptr = m;
			}
		}
		while (a_ptr < n) {
			if (arr[0][a_ptr] == 0) {
				act_seq.push_back(arr[0][a_ptr]);
				k++; a_ptr++;
			}
			else if (arr[0][a_ptr] > k) {
				valid = false; 
				a_ptr = n;
				break;
			}
			else {
				act_seq.push_back(arr[0][a_ptr]);
				a_ptr++;
			}
		}
		while (b_ptr < m) {
			if (arr[1][b_ptr] == 0) {
				act_seq.push_back(arr[1][b_ptr]);
				k++; b_ptr++;
			}
			else if (arr[1][b_ptr] > k) {
				valid = false;
				b_ptr = m;
				break;
			}
			else {
				act_seq.push_back(arr[1][b_ptr]);
				b_ptr++;
			}
		}
		if (!valid) {
			printf("-1\n");
		}
		else {
			for (int val : act_seq) {
				printf("%d ", val);
			}
			printf("\n");
		}
	}
	return 0;
}

/*
same file for n + m minutes.
before started, k lines written
every minutes -> add a new line / change one line.
if a = 0, add new line
if a > 0, change line a
print the correct sequence?
*/