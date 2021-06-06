// rapheal singer, a warm-up problem in code force!
#include <iostream>
using namespace std;
#pragma warning(disable:4996)

int main() {
	int n;
	cin >> n;
	// first entry.
	int birthday = 0;
	int cur_year, cur_age;
	cin >> cur_year >> cur_age;
	n--;
	birthday = cur_year - cur_age;
	while (n--) {
		cin >> cur_year >> cur_age;
		if (birthday != cur_year - cur_age) {
			cout << "mentiu a idade" << endl;
			return 0;
		}
	}
	cout << "idades corretas" << endl;
	return 0;
}