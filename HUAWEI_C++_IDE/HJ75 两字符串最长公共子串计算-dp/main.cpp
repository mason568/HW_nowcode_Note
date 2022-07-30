#include<iostream>
#include<string>
#include<vector>

using namespace std;
int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		if (s1.size() > s2.size()) swap(s1, s2);
		vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
		int maxLen = 0;
		for (int i = 1; i <= s1.size(); i++) {
			for (int j = 1; j <= s2.size(); j++) {
				if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
				else dp[i][j] = 0;

				if (dp[i][j]>maxLen) {
					maxLen = dp[i][j];
				}
			}
		}
		cout << maxLen << endl;
	}
	return 0;
}