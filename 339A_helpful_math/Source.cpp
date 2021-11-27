#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const int MAX = 100;
char s[MAX];

int main() {
	scanf("%s", &s);
	vector<int> val;
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		if (s[i] != '+') {
			val.push_back((int)s[i] - '0');
		}
	}
	sort(val.begin(), val.end());
	len = val.size() - 1;
	for (int i = 0; i < len; i++) {
		printf("%d+", val[i]);
	}
	printf("%d", val[len]);
	return 0;
}