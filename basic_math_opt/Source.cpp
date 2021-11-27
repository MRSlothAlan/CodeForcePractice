#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

int modPowerOfTwo(int x, int mod) {
	return x & (mod - 1);
}

int Abs(int n) {
	return (n ^ (n >> 31)) - (n >> 31);
}

// 如果 a>=b,(a-b)>>31 为 0，否则为 -1
int max(int a, int b) { return b & ((a - b) >> 31) | a & (~(a - b) >> 31); }
int min(int a, int b) { return a & ((a - b) >> 31) | b & (~(a - b) >> 31); }

bool isSameSign(int x, int y) {  // 有 0 的情况例外
	return (x ^ y) >= 0;
}

// can only swap integers.
void swap(int &a, int &b) { a ^= b ^= a ^= b; }

// 获取 a 的第 b 位，最低位编号为 0
// get the bit value at position b of number a.
int getBit(int a, int b) { return (a >> b) & 1; }

// 将 a 的第 b 位设置为 0 ，最低位编号为 0
int unsetBit(int a, int b) { return a & ~(1 << b); }

// 将 a 的第 b 位设置为 1 ，最低位编号为 0
int setBit(int a, int b) { return a | (1 << b); }

// 将 a 的第 b 位取反 ，最低位编号为 0
int flapBit(int a, int b) { return a ^ (1 << b); }

/*
int __builtin_ffs(int x) ：返回  的二进制末尾最后一个  的位置，位置的编号从  开始（最低位编号为  ）。当  为  时返回  。

int __builtin_clz(unsigned int x) ：返回  的二进制的前导  的个数。当  为  时，结果未定义。

int __builtin_ctz(unsigned int x) ：返回  的二进制末尾连续  的个数。当  为  时，结果未定义。

int __builtin_clrsb(int x) ：当  的符号位为  时返回  的二进制的前导  的个数减一，否则返回  的二进制的前导  的个数减一。

int __builtin_popcount(unsigned int x) ：返回  的二进制中  的个数。

int __builtin_parity(unsigned int x) ：判断  的二进制中  的个数的奇偶性。
*/

// https://graphics.stanford.edu/~seander/bithacks.html


int main() {
	int t; scanf("%d", &t);
	int res = modPowerOfTwo(t, 2);
	printf("%d", res);
	return 0;
}