#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	int m;
	while (cin >> m) {
		if (m <= 0) continue;
		string res = "";
		int begin = pow(m, 2) - m + 1;
		for (int i = 0; i < m;i++) {
			res += to_string(begin + 2 * i);
			res += "+";
		}
		res.pop_back();
		cout << res << endl;

		
	}
	return 0;
}