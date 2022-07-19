#include<iostream>
using namespace std;

#if 0
//模拟解法
int main() {
	int n;
	while (cin >> n) {
		if (n == 0) continue;
		int m = 0;
		int res = 0;
		while (n / 3 > 0) {
			m = n / 3;
			n = m + n % 3;
			res += m;
		}
		if (n == 2) res += 1;
		cout << res << endl;
	}

	return 0;
}
#endif

#if 1
//裂开解法
int main() {
	int n;
	while (cin >> n) {
		cout << n / 2 << endl;
	}
}
#endif