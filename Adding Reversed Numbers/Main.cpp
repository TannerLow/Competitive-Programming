#include <iostream>
#include <string>
using namespace std;
//add 2 strings from the front to the back
string add(string s1, string s2) {
	while (s1.size() < s2.size()) 
		s1.push_back(48);
	while (s2.size() < s1.size()) 
		s2.push_back(48);
	int i = 0, remainder = 0;
	string s3 = "";
	while (i < s1.size()) {
		s3.push_back(s1[i] + s2[i] - 48 + remainder);
		remainder = 0;
		if (s3[i] > 57) {
			s3[i] -= 10;
			remainder += 1;
		}
		i++;
	}
	if (remainder)
		s3.push_back(49);
	return s3;
}
//take 2 strings add them and print answer
int main() {
	string n1,n2,ans;
	int cases;
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		cin >> n1;
		cin >> n2;
		ans = add(n1, n2);
		while (ans[0] == '0')
			ans.erase(0, 1);
		cout << ans << endl;
	}
	return 0;
}