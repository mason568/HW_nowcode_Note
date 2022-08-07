#include<iostream>
#include<bitset>
#include<string>

using namespace std;

int main() {
	unsigned int num;
	while (cin >> num) {
		int max = -1;
		int tmp = 0;
		while (num > 0) {
			if (num % 2 == 1) {
				tmp++;
				num = num>>1;
				if (tmp > max) max = tmp;
			}
			else {
				tmp = 0;
				num = num >> 1;
			}
		}
		cout << max << endl;
	}

	return 0;

}