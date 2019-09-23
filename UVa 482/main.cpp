#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	string line;
	int cases;
	cin >> cases;
	getchar();
	while (cases--) {
		getchar();
		int idx[5000], n = 1, i = 1;
		string x[5000];
		getline(cin, line);
		stringstream sin;
		sin << line;
		while (sin >> idx[n]) {
			n++;
		}
		sin.clear();
		getline(cin, line);
		sin << line;
		while (sin >> x[idx[i]]) {
			i++;
		}
		for (int j = 1; j < n; j++) {
			cout << x[j] << endl;
		}
		if (cases)
			cout << endl;
	}
	return 0;
}