#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		if (s1.size() > s2.size()) { //保证s2更长  用0补齐s1, 后面只写一个循环
			string tmp = s1;
			s1 = s2;
			s2 = tmp;
		}
		string s0 = string(s2.size() - s1.size(), '0');
		s1 = s0 + s1;

		bool carryBit = false;
		string res = "";
		for (int i = s1.size() - 1; i >= 0; i--) {
			int sum = (s1[i] - '0') + (s2[i] - '0') + carryBit;
			if (sum >= 10) {
				carryBit = true;
			}
			else {
				carryBit = false;
			}
			res += '0' + sum % 10;
		}
		if (carryBit) res += '1';
		//cout << res << endl;
		reverse(res.begin(), res.end());
		cout << res << endl;

	}
	return 0;
}