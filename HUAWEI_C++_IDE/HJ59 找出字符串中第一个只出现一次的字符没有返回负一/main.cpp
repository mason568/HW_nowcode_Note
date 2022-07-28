#include<string>
#include<iostream>
using namespace std;

#if 0
int main() {
	string s;
	while (cin >> s) {
		//用数组做hash表,下标对应ascii字符，值对应出现次数
		int table[128] = { 0 };
		for (int i = 0; i < s.size(); i++) {
			table[s[i]]++;
		}
		char ch = NULL;
		for (int i = 0; i < s.size(); i++) {
			if (table[s[i]] == 1) {
				ch= s[i];
				break;
			}
		}
		if (ch!=NULL) cout << ch << endl;
		else cout << -1 << endl;


	}
	return 0;
}
#endif
int Count(string& s, char ch) {
	int table[128] = { 0 };
	for (int i = 0; i < s.size(); i++) {
		table[s[i]]++;
	}
	return table[ch];

}
int main() {
	string s;
	while (cin >> s) {
		//用数组做hash表,下标对应ascii字符，值对应出现次数
		char ch = 'b';
		cout << Count(s, ch) << endl;
	}
	return 0;
}
