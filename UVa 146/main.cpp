#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int main() {
	while (true) {
		string s;
		cin >> s;
		if (s == "#")
			return 0;
		char c[100];
		strcpy(c, s.c_str());//UVa doesnt accept strcpy_s but wont compile w/o
		if (next_permutation(c, c + s.size()))
			cout << c << endl;
		else
			cout << "No Successor" << endl;
	}
	return 0;
}