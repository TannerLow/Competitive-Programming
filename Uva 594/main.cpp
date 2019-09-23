#include <iostream>
#include <bitset>
using namespace std;

int main() {
	int in;
	bitset<32> large;
	large.set(31, 1);
	unsigned long int l = large.to_ulong();
	while (cin >> in) {
		bitset<32> bits(in);
		bitset<32> Ebits;
		bool neg = bits[7] == 1;
		if (neg)
			bits.set(7, 0);
		for (int i = 0; i < 8; i++) {
			Ebits.set(24 + i, bits[i]);
		}
		for (int i = 8; i < 16; i++) {
			Ebits.set(8 + i, bits[i]);
		}
		for (int i = 16; i < 24; i++) {
			Ebits.set(i - 8, bits[i]);
		}
		for (int i = 24; i < 32; i++) {
			Ebits.set(i - 24, bits[i]);
		}
		if (neg)
			cout << in << " converts to -" << l - Ebits.to_ulong() << endl;
		else
			cout << in << " converts to " << Ebits.to_ulong() << endl;
	}
	return 0;
}