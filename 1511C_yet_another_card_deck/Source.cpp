#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;
deque<int> Dq;

int main() {
	int n, q; scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) {
		int ai; scanf("%d", &ai); Dq.push_back(ai);
	}
	for (int j = 0; j < q; j++) {
		int ti; scanf("%d", &ti);
		auto itr = Dq.begin(); int idx = 1;
		for (; itr != Dq.end() && *itr != ti; itr++) { idx++; }
		printf("%d ", idx);
		Dq.erase(itr);
		Dq.push_front(ti);
	}
	return 0;
}

/*
other people's submissions for references

#include<iostream>
using namespace std;
int i,x,f[51],n;
main()
{
	cin>>n>>x;
	while(n--)
		cin>>x,f[x]+=(!f[x])*(++i);
	while(cin>>x)
	{
		cout<<f[x]<<" ";
		for(auto &y:f)y+=y<f[x];
		f[x]=1;
	}
}

*/