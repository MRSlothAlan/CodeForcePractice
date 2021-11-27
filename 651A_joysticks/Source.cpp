#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
int a1, a2;
// tf is this? 
// WELL.
void well() {
	int min = 0;
	while (a1 > 0 && a2 > 0) {
		if (a1 < a2) {
			a1++; a2 -= 2;
		}
		else {
			a1 -= 2; a2++;
		}
		min++;
	}
	if (a1 < 0 || a2 < 0) min--; 
	printf("%d\n", min);
}

int main() {
	scanf("%d %d", &a1, &a2);
	well();
	return 0;
}