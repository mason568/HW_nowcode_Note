#include<iostream>
#include<string>
#include<unordered_map>
#include<map>
#include <algorithm>
using namespace std;


#if 0
//±©Á¦½â·¨
int main() {
	string s;
	while (cin >> s) {
		if (s.size() <= 20) {
			string delete_chs = "";
			unordered_map<char, int> m;
			for (auto ch : s) {
				m[ch]++;
			}
			int min_value = INT_MAX;
			for (auto item : m) {
				if (item.second < min_value) {
					min_value = item.second;
					delete_chs = "";
					delete_chs += item.first;
				}
				else if (item.second == min_value) {
					delete_chs += item.first;
				}
				else;
				
			}
			//cout << delete_chs << endl;
			string res = "";
			for (auto ch : s) {
				if (delete_chs.find(ch) == string::npos) {
					res += ch;
				}
			}
			cout << res << endl;
		}
	}
	return 0;
}
#endif 

#if 1
bool cmp_value(const pair<char, int> left, const pair<char, int> right) {
	return left.second < right.second;
}

int main() {
	string s;
	while (cin >> s) {
		if (s.size() <= 20) {
			string res = "";
			unordered_map<char, int> m;
			for (auto ch : s) {
				m[ch]++;
			}
			int min_value;
			auto item = min_element(m.begin(), m.end(), cmp_value);
			min_value = item->second;
			//cout << min_value << endl;
			for (auto ch : s) {
				if (m[ch] != min_value) {
					res += ch;
				}
			}
			cout << res << endl;
		}
	}
	return 0;
}
#endif