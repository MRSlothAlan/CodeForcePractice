#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	/*
	On the n * m table haha
	lunch break snack
	#~~~#
	....#
	#~~~#
	#....
	*/
	bool back = true;
	for (int r = 1; r <= n; r++) {
		if ((r & 1) == 0) {	
			if (back) {
				for (int c = 0; c < m - 1; c++) {
					printf(".");
				}
				printf("#");
			}
			else {
				printf("#");
				for (int c = 1; c < m; c++) {
					printf(".");
				}
			}
			back = !back;
		}
		else {
			for (int c = 0; c < m; c++) {
				printf("#");
			}
		}
		printf("\n");
	}

	return 0;
}