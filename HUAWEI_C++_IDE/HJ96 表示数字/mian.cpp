#include<iostream>
#include<string>

using namespace std;


//又臭又长方法
#if 0
int main() {
	string s;
	while (cin >> s) {
		int cnt = 0;
		int slow = s.size() - 1;
		bool flag = false;
		for (auto i : s) {
			if (isdigit(i)) {
				if (!flag) {
					flag = true;
					cnt++;
				} 
			}
			else {
				if (flag) flag = false;
			}
		}
		s.resize(s.size() + 2 * cnt);
		int fast = s.size() - 1;
		flag = false;
		while (fast!=slow)
		{
			if (isdigit(s[slow])) {
				if (!flag) {
					s[fast] = '*';
					s[fast - 1] = s[slow];
					fast -= 2;
					flag = true;
				}
				else {
					s[fast ] = s[slow];
					fast -= 1;
				}
				
			}
			else {
				if (flag) {
					s[fast] = '*';
					s[fast-1] = s[slow];
					fast -= 2;
					flag = false;
				}
				else {
					s[fast] = s[slow];
					fast -= 1;
				}

			}
			slow--;
		}
		cout << s << endl;
	
	}
	return 0;
}

#endif

//正则匹配任意个数字
#include<regex>
int main() {
	string s;
	while (cin >> s) {
		regex patten("(\\d+)");
		s = regex_replace(s, patten, "\*$1\*");
		cout << s << endl;
	
	}
	return 0;
}