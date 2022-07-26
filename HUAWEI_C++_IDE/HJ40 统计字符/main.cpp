#include<iostream>
#include<string>

using namespace std;

int main() {
	string s;
	while (getline(cin, s)) {
		int count[4] = { 0 };
		for (auto ch : s) {
			if (isalpha(ch)) count[0]++;//统计字母
			else if (ch == ' ') count[1]++;//统计空格
			else if (ch >= '0' && ch <= '9') count[2]++;//统计数字
			else count[3]++;//统计其它字符
		}
		for (auto c : count) cout << c << endl;
	}
	return 0;
}