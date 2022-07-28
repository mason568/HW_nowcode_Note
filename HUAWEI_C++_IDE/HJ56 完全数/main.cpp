#include<iostream>
using namespace std;

bool isPecfectNum(int n) {
	int sum = 0;
	for (int i = 1; i <= n/2; i++) {
		if (n % i == 0) sum += i;
	}
	return sum == n ? true : false;
}

int main() {
	int n;
	//cout << isPecfectNum(28) << endl;
	while (cin >> n) {
		if (n <= 0) continue;
		int cnt = 0;
		for (int i = 1; i < n; i++) {
			if (isPecfectNum(i)) {
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}