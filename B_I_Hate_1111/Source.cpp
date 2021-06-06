#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int number;
		cin >> number;
		// combination of 11, 111, ... ?
		/*
		learnt:
			find general form of problem.
			e.g. 11 * a = n - 11 * 10 * b + b
			assume that n can ALWAYS be formed by 111 and 11;
		*/
		int b = number % 11;
		int a = number - b * 111;
		if (a >= 0 && a % 11 == 0)
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
	return 0;
}