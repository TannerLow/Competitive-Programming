#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		int letters, dat[256], value;
		fill(dat, dat + 256, 0);
		char c;
		string s;
		cin >> letters;
		while (letters--) {
			cin >> c >> value;
			dat[c + 128] = value;
		}
		cin >> letters;
		int sum = 0;
		cin.ignore();
		while (letters--) {
			getline(cin, s);
			for (int i = 0; i < s.size(); i++) 
				sum += dat[s[i] + 128];
		}
		double price = (double)sum / 100.0;
		printf("%0.2f$\n", price);
	}
	return 0;
}