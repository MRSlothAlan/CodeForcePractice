#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

char in_str[2000];

int main() {
	// warm-ups.
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%s", &in_str);

	}
	return 0;
}
/*
good if no 010 or 101 as subsequence
can flip the character at the index.
1001, has 101 as subsequence.
e.g. 00110000000, has two 010.
000111101001011001111

Key Idea: There are two types of good strings: 
Those which start with a series of 1's followed by 0's (such as 1111100) 
and those which start with a series of 0's followed by 1's (such as 00111). 

Note that there are strings which do belong to both categories (such as 000, 111).
*/