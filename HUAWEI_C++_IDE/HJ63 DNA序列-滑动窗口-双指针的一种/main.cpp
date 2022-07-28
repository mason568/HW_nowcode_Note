#include<iostream>
#include<string>
using namespace std;
//双指针 
int main() {
	string s;
	int k;
	while (cin >> s >> k) {
		if (s.size() <= k || k <= 0) {
			cout << s << endl;
			continue;
		}
		double maxratio = 0.0;
		int pos = 0;
		int count = 0;
		for (int i = 0; i < s.size(); i++) {
			//入窗口 s[i]
			if (s[i] == 'C' || s[i] == 'G') count++;
			//出窗口 s[i - k + 1]
			if (i >= k - 1) {
				if (1.0 * count / k > maxratio) {
					pos = i - k + 1;
					maxratio = 1.0 * count / k;
				}
				if (s[i - k + 1] == 'C' || s[i - k + 1] == 'G') {
					count--;
				}

			}
		}

		cout << s.substr(pos, k) << endl;

	}
	return 0;
}