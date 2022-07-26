#include<iostream>
#include<vector>
#include<string>

using namespace std;

int LD(string s1, string s2) {
	int n = s1.size(), m = s2.size();
	if (n == 0 || m == 0) return n + m;
	int res = 0;

	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; i++) dp[i][0] = i;
	for (int j = 1; j <= m; j++) dp[0][j] = j;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			//s[i-1]！=s[j-1]情况
			if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
			else {
				//两个字符不相等s1[i-1]==s2[j-1]情况 三种操作
				int op1 = dp[i - 1][j] + 1;
				int op2 = dp[i][j - 1] + 1;
				int op3 = dp[i - 1][j - 1] + 1;
				dp[i][j] = min(op1, min(op2, op3));
			}


		}
	}
	return dp[n][m];
}

int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {

		cout << LD(s1, s2) << endl;
	}
	return 0;
}