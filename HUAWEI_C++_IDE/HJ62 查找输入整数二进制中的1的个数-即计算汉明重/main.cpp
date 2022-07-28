#include<iostream>
#include<bitset>

using namespace std;

int hmweight_bitset(unsigned int num) {
	return bitset<32>(num).count();
}

int hmweight_caculate(unsigned int num) {
	// n = n & (n-1)
	int res = 0;
	while (num) {
		res += 1;
		num = num & (num - 1);
	}
	return res;
}

int main() {
	unsigned int num;
	while (cin >> num) {
		cout << hmweight_bitset(num) << endl;
		cout << hmweight_caculate(num) << endl;
	
	}

}