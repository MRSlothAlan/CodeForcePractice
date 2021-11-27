#pragma warning(disable : 4996)
#include <cstdio>
#include <map>
#include <string>
#include <iostream>
using namespace std;

map<string, int> rec;

int main() {
	int n; scanf("%d", &n);
	string in_str;
	rec.clear();
	while (n--) {
		// scanf("%s", &in_str);
		cin >> in_str;
		if (rec.find(in_str) == rec.end()) {
			rec.insert(std::pair<string, int>(in_str, 0));
			printf("OK\n");
		}
		else {
			rec.at(in_str) += 1;
			cout << in_str << rec.at(in_str) << endl;
		}
	}
	return 0;
}