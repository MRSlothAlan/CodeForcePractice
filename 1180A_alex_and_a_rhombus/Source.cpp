#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

// nth order rhombus
int main() {
	int n; scanf("%d", &n);
	int res_val = 1;
	for (int i = 1; i < n; i++) {
		res_val += i * 4;
	}
	printf("%d\n", res_val);
	return 0;
}