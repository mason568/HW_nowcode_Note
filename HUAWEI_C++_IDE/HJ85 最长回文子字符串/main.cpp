#include<iostream>
#include<string>
#include<vector>
#include<limits.h>
using namespace std;

string init(string s) {
	string res = "&#";
	for (int i = 0; i < s.size(); i++) {
		res += s[i] ;
		res += '#';
	}
	res += '^';
	return res;
}

int manacher(string& s) {
	vector<int> dp(s.size(),0);
	int mid, max_right = 0;
	int maxLen = INT_MIN;
	for (int i = 1; i < s.size(); i++) {
		if (i < max_right) {
			dp[i] = min(max_right - i, dp[2 * mid - i]);
		}
		else {
			dp[i] = 1;
		}

		while (s[i - dp[i]] == s[i + dp[i]]) dp[i]++;
		if (i + dp[i] > max_right) {
			max_right = i + dp[i];
			mid = i;
		}

		if (dp[i] > maxLen) {
			maxLen = dp[i];
		}
	}
	return maxLen - 1;

}

int main(){
	string s;
	while (cin >> s) {
		s = init(s);
		int maxlen = manacher(s);
		cout << maxlen << endl;
	}
	

	return 0;
}
