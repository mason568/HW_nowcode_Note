#include<iostream>
#include<string>
#include<vector>
using namespace std;

//递归
#if 0
bool match(const char* s, const char* p) {
	if (*s == '\0' && *p == '\0') return true;//完全匹配
	if ((*p == '\0' || *s == '\0')) return false;//不匹配
	if (*p == '?') {
		//不匹配
		if (!isalnum(*s)) return false;
		return match(s + 1, p + 1);
	}
	else if (*p == '*') {
		//多个*看成一个
		while (*p == '*') p++;
		p--;
		return match(s, p + 1) || match(s + 1, p + 1) || match(s + 1, p);//下一步匹配
	}
	else if (tolower(*s) == tolower(*p)) {
		return match(s + 1, p + 1);//下一步匹配
	}
	//其它三种情况都不满足 如 'a'不等于 '.'
	return false;//不匹配
}

int main() {
	string p, s;
	while (cin >> p >> s) {
		bool res = match(s.c_str(), p.c_str());
		if (res) cout << "true" << endl;
		else cout << "false" << endl;
	}
	return 0;
}

#endif 


//dp
#if 1

bool ismatch(string s, string p) {
	int len_s = s.size(); //字串
	int len_p = p.size(); //通配符串
	vector<vector<bool>> dp(len_p + 1, vector<bool>(len_s + 1, false));
	dp[0][0] = 1;


	for (int i = 1; i <= len_p; i++) {
		char ch_p = p[i - 1];
		//如果s为空，p只有是全'*'才有可能匹配（即全*匹配0个字符）
		dp[i][0] = dp[i - 1][0] && (ch_p == '*');
		for (int j = 1; j <= len_s; j++) {
			char ch_s = s[j - 1];
			if (ch_p == '*' && isalnum(ch_s)) {
				dp[i][j] = dp[i - 1][j] || dp[i][j - 1]; //*匹配0个||多个
			}
			else if (tolower(ch_s) == tolower(ch_p)) {  //出现其它字符，只可能是 '.'== '.'
				dp[i][j] = dp[i - 1][j - 1];
			}
			else if (ch_p == '?') {
				//只能匹配字符或者数字，一个
				if (isalnum(ch_s)) dp[i][j] = dp[i - 1][j - 1];
				else dp[i][j] = false;
			}
			else if (ch_p == '*') {// 多个*，则只有一个*起作用，即把这个*看作匹配0个
				dp[i][j] = dp[i - 1][j];
			}

		}
	}


	return dp[len_p][len_s];
}
int main() {
	string p, s;
	while (cin >> p >> s) {
		bool res = ismatch(s, p);
		if (res) cout << "true" << endl;
		else cout << "false" << endl;
	}
	return 0;
}

#endif