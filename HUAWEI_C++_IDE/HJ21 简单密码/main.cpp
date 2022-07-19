#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

#if 0
int main() {
	string pwd;
	string res = "";
	while (cin >> pwd) {
		for (auto ch : pwd) {
			if (ch == '1') res+=ch;
			else if (ch == '1') continue;
			else if (ch >= 'a' && ch <= 'c') res += '2';
			else if (ch >= 'd' && ch <= 'f') res += '3';
			else if (ch >= 'g' && ch <= 'i') res += '4';
			else if (ch >= 'j' && ch <= 'l') res += '5';
			else if (ch >= 'm' && ch <= 'o') res += '6';
			else if (ch >= 'p' && ch <= 's') res += '7';
			else if (ch >= 't' && ch <= 'v') res += '8';
			else if (ch >= 'w' && ch <= 'z') res += '9';
			else if (ch >= 'A' && ch <= 'Z') {
				ch = tolower(ch) + 1;
				if (ch == '{') ch = 'a';
				res += ch;
			}
			else res += ch;
		}
		cout << pwd << endl;
	}
	return 0;
}
#endif

#if 1
//使用map只需要判断大小写
int main() {
	string s;
	unordered_map<char, char> m;
	m['a'] = m['b'] = m['c'] = '2';
	m['d'] = m['e'] = m['f'] = '3';
	m['g'] = m['h'] = m['i'] = '4';
	m['j'] = m['k'] = m['l'] = '5';
	m['m'] = m['n'] = m['o'] = '6';
	m['p'] = m['q'] = m['r'] = m['s'] = '7';
	m['t'] = m['u'] = m['v'] = '8';
	m['w'] = m['x'] = m['y'] = m['z'] = '9';
	while (cin >> s) {
		//原地修改节省空间
		for (int i = 0; i < s.size(); i++) {
			if (islower(s[i])) s[i] = m[s[i]];
			else if (isupper(s[i]) && s[i]!='Z') {
				s[i] = s[i] - 'A' + 'a' + 1;
			}
			if (s[i] == 'Z') s[i] = 'a';
		}
		cout << s << endl;
	}

	return 0;
}
#endif

