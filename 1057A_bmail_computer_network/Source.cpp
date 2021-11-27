#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 2000500;
int arr[MAX];
vector<int> vec;
int main() {
	int n; scanf("%d", &n);
	for (int num = 2; num <= n; num++) {
		scanf("%d", &arr[num]);
	}
	int cur = n;
	while (cur != 1) {
		vec.push_back(cur);
		cur = arr[cur];
	}
	vec.push_back(1);
	int len = vec.size() - 1;
	for (int i = len; i >= 0; i--) {
		printf("%d ", vec[i]);
	}
	return 0;
}