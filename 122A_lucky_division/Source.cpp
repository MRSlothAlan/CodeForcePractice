#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

// ln: positive, decimal representation : 4 or 7
// divisible by any lucky numbers?
const int MAX = 1005;
bool isLucky[MAX];
int ptr = 0;
int lucky[MAX];

void set_isLucky() {
	memset(isLucky, false, MAX);
	memset(lucky, 0, MAX);
	ptr = 0;
	for (int num = 1; num < MAX; num++) {
		int tmp = num;
		while (tmp > 0) {
			int digit = tmp % 10;
			if (digit != 4 && digit != 7) {
				break;
			}
			tmp /= 10;
		}
		if (tmp == 0) {
			isLucky[num] = true;
			lucky[ptr] = num; 
			ptr++;
		}
	}
}

int main() {
	set_isLucky();
	int n; scanf("%d", &n);
	if (isLucky[n]) {
		printf("YES\n");
	}
	else {
		for (int i = 0; i < ptr; i++) {
			if (n % lucky[i] == 0) {
				printf("YES\n");
				return 0;
			}
		}
		printf("NO\n");
	}
	return 0;
}