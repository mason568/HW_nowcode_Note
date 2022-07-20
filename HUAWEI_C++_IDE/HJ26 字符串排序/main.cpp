#include<iostream>
#include<string>
using namespace std;

int main(){
	string s;
	while (getline(cin, s)) {
		//先把所有的英文字母找出来
		string alpha_str = "";
		for (int i = 0; i < 26;i++ ) {
			for (auto ch : s) {
				if (isalpha(ch) && (ch == 'A' + i || ch == 'a' + i)) alpha_str += ch;
			}
		}
		int t = 0;
		for (int j = 0; j < s.size(); j++) {
			if (isalpha(s[j])) s[j] = alpha_str[t++];
		}

		cout << s <<endl;
	
	}
	return 0;
}