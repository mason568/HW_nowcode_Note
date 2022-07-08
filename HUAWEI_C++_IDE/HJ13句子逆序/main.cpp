#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

void reverse_string(string& s, int start, int end) {
	while (start < end) {
		swap(s[start++], s[end--]);
	}
}


int main() {
	string s;
	while (getline(cin,s)) {
		//反转整个字符串
		reverse(s.begin(), s.end());
		//反转单词，确定单词起始位置
		for (int i = 0; i < s.size(); i++) {
			int j = i;
			while (j < s.size() && s[j] != ' ') j++;
			reverse_string(s, i, j-1);
			i = j;
		}
		cout << s << endl;
		
	}

	return 0;
}