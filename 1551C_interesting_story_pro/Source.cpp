#pragma warning(disable : 4996)
#include <stdio.h>
#include <algorithm>

using namespace std;

int Ref;

struct item { int Sum, d[5]; };
bool operator < (const item &A, const item &B) { return (A.d[Ref] - (A.Sum - A.d[Ref])) > (B.d[Ref] - (B.Sum - B.d[Ref])); }

const int MAX = 450000;

int N, Ans, Val;
item Cnt[MAX], Bnk;

void process() {
	int i, u;
	char in[MAX];

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%s", in);
		for (u = 0, Cnt[i] = Bnk; in[u]; u++) Cnt[i].d[in[u] - 'a']++, Cnt[i].Sum++;
	}

	for (Ref = Ans = 0; Ref < 5; Ref++) {
		sort(Cnt, Cnt + N);

		for (i = Val = 0; i < N; i++) {
			if (Cnt[i].d[Ref] > Cnt[i].Sum - Cnt[i].d[Ref]) Val += (Cnt[i].d[Ref]) - (Cnt[i].Sum - Cnt[i].d[Ref]);
			else break;
		}

		for (; i < N; i++) {
			if (Val + (Cnt[i].d[Ref]) - (Cnt[i].Sum - Cnt[i].d[Ref]) <= 0) break;
			Val += (Cnt[i].d[Ref]) - (Cnt[i].Sum - Cnt[i].d[Ref]);
		}

		Ans = (Ans > i) ? Ans : i;
	}

	printf("%d\n", Ans);
}

int main() {
	int T;

	scanf("%d", &T);
	while (T--) process();

	return 0;
}