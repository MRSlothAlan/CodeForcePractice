#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
// #define MAX(a, b) a > b ? a : b;
const int MAX = 200000;
long long int arr[MAX];
long long int cur_val, tmp, t_max;
int zero_cnt = 0;

bool com(const long long int l, const long long int r) {
	return abs(l) > abs(r);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		zero_cnt = 0; t_max = -100000000;
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lld", &arr[i]);
			if (arr[i] == 0) zero_cnt++;
			t_max = t_max < arr[i] ? arr[i] : t_max;
		}
		cur_val = 1;
		// for (int i = 0; i < 5; i++) { cur_val *= arr[i]; }
		if (n == 5) {
			cur_val = arr[0] * arr[1] * arr[2] * arr[3] * arr[4];
			printf("%lld\n", cur_val);
		}
		else {
			// check whether 0 is included in the interval.
			if (n - zero_cnt < 5) {
				printf("0\n");
			}
			else {
				sort(arr, arr + n, com);
				if (t_max < 0) {
					cur_val = 1;
					for (int i = 1; i <= 5; i++) {
						cur_val *= arr[n - i];
					}
					printf("%lld\n", cur_val);
				}
				else {
					cur_val = arr[0] * arr[1] * arr[2] * arr[3] * arr[4];
					for (int i = 5; i < n; i++) {
						for (int j = 0; j < 5; j++) {
							tmp = arr[i];
							for (int k = 0; k < 5; k++) {
								if (k != j)
									tmp *= arr[k];
							}
							cur_val = cur_val < tmp ? tmp : cur_val;
						}
					}
					printf("%lld\n", cur_val);
				}
			}
		}
	}
	return 0;
}

/*
Come back to this later.

#include<bits/stdc++.h>
using namespace std;
long long ans,a[100005];
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		long long mx=-1e9;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]),mx=max(mx,a[i]);
		sort(a+1,a+n+1,[](long long x,long long y){return abs(x)>abs(y);});
		if(mx<0){
			cout<<a[n]*a[n-1]*a[n-2]*a[n-3]*a[n-4]<<'\n';
			continue;
		}
		ans=a[1]*a[2]*a[3]*a[4]*a[5];
		for(int i=6;i<=n;i++){
			for(int j=1;j<=5;j++){
				long long tmp=a[i];
				for(int k=1;k<=5;k++){
					if(k!=j)tmp*=a[k];
				}
				ans=max(ans,tmp);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

*/

/*
int i = 0;
int tmp_cnt = 0;
for (; i < n && tmp_cnt < 5; i++) {
	if (arr[i] != 0) {
		cur_val *= arr[i]; tmp_cnt++;
	}
}
tmp = cur_val;
for (; i < n && arr[i - 1] != 0; i++) {
	tmp /= arr[i - 1];	// not really works everytime.
	tmp *= arr[i];
	cur_val = cur_val > tmp ? cur_val : tmp;
}
printf("%lld\n", cur_val);
*/