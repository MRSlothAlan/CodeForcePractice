#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
	string in_str;	
	while (cin >> in_str) {
		int x;
		std::stringstream ss;
		ss << std::hex << in_str;
		ss >> x;
		cout << "input as std::hex to decimal: " << x << endl;
		ss = stringstream();
		ss << std::dec << in_str;
		ss >> x;
		cout << "input as std::dec to decimal: " << x << endl;
		ss = stringstream();
		ss << std::oct << in_str;
		ss >> x;
		cout << "input as std::oct(octal) to decimal: " << x << endl;
		double test = 1232.23134243;
		printf("%.4lf", test);
	}
	return 0;
}