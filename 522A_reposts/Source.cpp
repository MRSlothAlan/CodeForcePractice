#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
/*
Polycarp measures the popularity of the joke as the 
length of the largest repost chain. 
Print the popularity of Polycarp's joke.
*/
using namespace std;
map<string, int> M;
string a, b, word;

int id;
const int MAX = 500;
vector<int> conn[MAX];

int getID(string in_str) {
	std::transform(in_str.begin(), in_str.end(), in_str.begin(),
		[](unsigned char c) { return std::tolower(c); });
	if (M.find(in_str) == M.end()) {
		M.insert(pair<string, int>(in_str, id));
		id++;
	}
	return M.at(in_str);
}


int main() {
	id = 0;
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> a >> word >> b;
		int a_id = getID(a); int b_id = getID(b);
		conn[a_id].push_back(b_id);
	}
	int res_len = 0;
	for (int i = 0; i < id; i++) {
		int cur_id = i; int tmp_len = 0;
		if (conn[cur_id].size() == 0) {
			tmp_len = 1;
		}
		else {
			tmp_len = 2; cur_id = conn[cur_id][0];
			while (conn[cur_id].size() > 0) {
				cur_id = conn[cur_id][0];
				tmp_len++;
			}
		}
		res_len = res_len > tmp_len ? res_len : tmp_len;
	}
	printf("%d", res_len);
	return 0;
}

/*
It is guaranteed that for each string "name1 reposted name2" user "name1" didn't have the joke in his feed yet, and "name2" already had it in his feed by the moment of repost
*/