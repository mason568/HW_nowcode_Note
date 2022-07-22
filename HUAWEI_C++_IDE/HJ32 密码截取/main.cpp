#include<iostream>
#include<string>
#include<vector>
using namespace std;

int max_conc_plaindrome_dp(string s) {
	//dp[i][j]表示[i,j]子字符串是不是一个回文字符串
	vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
	int n = s.size();
	int maxLen = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == j) dp[j][i] = true; //奇数长度字子符串
			else if (i - j == 1) dp[j][i] = (s[i] == s[j]);//偶数长度字子符串
			else dp[j][i] = (s[i] == s[j] && dp[j + 1][i - 1]);//只有中间也是回文串，且两边两字符相等，才能是一个新的回文串 p.s.中间串的值上一轮已经确定过了
			if (dp[j][i] && i - j + 1 > maxLen) maxLen = i - j + 1;

		}
	}
	return maxLen;
}

int zxks_getmaxLen(string& s, int l, int r) {
	//看看能扩散的最大程度
	while (l >= 0 && r < s.size() && s[l] == s[r]) {
		l--;
		r++;
	}
	return r - l - 1;//因为上次相等之后就把长度加了2，所以需要减掉2
}

int max_conc_plaindrome_zxks(string s) {
	//中心扩散，回文长度分奇偶情况
	if (s.size() == 0) return 0;
	if (s.size() == 1) return 1;
	int maxLen = 1;
	for (int i = 0; i < s.size(); i++) {
		int m1 = zxks_getmaxLen(s, i, i);
		maxLen = max(m1, maxLen);
	}
	for (int i = 0; i < s.size()-1; i++) {
		int m2 = zxks_getmaxLen(s, i, i + 1);
		maxLen = max(m2, maxLen);
	}

	return maxLen;
}
int main() {
	//找最长的连续回文字符串 - 动态规划 dp[i][j]表示从[i,j]之间的最长连续回文字符串的长度  问题是要连续的回文，而并不是间断的
	string s;
	while (cin >> s) {
		//cout << max_conc_plaindrome_dp(s) << endl;
		cout << max_conc_plaindrome_zxks(s) << endl;
	}

	return 0;
}

