#pragma once
#pragma warning(disable:4996)
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

namespace SuffixArray {
	// int main(int argc, char* argv[]);
	bool sufCmp(int i, int j);
	void buildSA();
}

namespace UseSuffixArray {
	int main(int argc, char* argv[]);
}