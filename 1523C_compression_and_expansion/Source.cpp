#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int MAX = 1e8;
char s[MAX];
int idx_s;
stack<int> S;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		idx_s = 0;
		memset(s, '\0', sizeof(s));
		s[idx_s++] = '1';
		s[idx_s++] = '.';
		int n; scanf("%d", &n);
		S.push(1);
		while (n--) {
			int a; scanf("%d", &a);
			while (true) {
				int cur = S.top();
				S.pop();
				s[idx_s--] = '\0';
				while (idx_s >= 0 && s[idx_s] != '.') {
					s[idx_s--] = '\0';
				}
				if (cur != a) {
					// well.
				}
			}
		}
	}
	return 0;
}

/*
Let's maintain the current depth of the list in a stack. Initially the stack is empty. For each new ai there are two options:
ai=1. In this case we just add the given number to the end of the stack and it will point to a new subitem in the list.
ai>1. In this case we need to find the subitem, the last number of which will be one less than ai. 

To do this we will remove the last elements from a stack until we find this number.
After this at the end of each iteration we will print the resulting stack as a new item in the list. 
Note that due to outputting the whole list the complexity will be quadratic.
*/

/*
my idea : 
keep an array of levels to node count.
arr[0, 1, 2... so on]

Yes, but they don't allow hard-coded list
use a stack to record the levels please.
*/

/*
memset(s, '\0', sizeof(s));
		int n; scanf("%d", &n);
		int a; scanf("%d", &a); n--;
		s[0] = '0' + a;
		printf("%s\n", s);
		int idx_s = 1;
		int cur_num = a;
		while (n--) {
			scanf("%d", &a);
			if (a <= cur_num) {
				s[idx_s++] = '.';
				s[idx_s++] = '0' + a;
				s[idx_s] = '\0';
			}
			else {
				s[idx_s - 1] = '0' + a;
				s[idx_s] = '\0';
			}
			cur_num = a;
			printf("%s\n", s);
		}
*/

/*
9
1
1
1
2
2
1
2
1
2

1
1.1
1.1.1
1.1.2
1.2
1.2.1

*/