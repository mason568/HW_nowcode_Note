#include<iostream>
#include<string>
#include"assert.h"
#include<algorithm>
using namespace std;

void cleanSpace(string& s) {
	//去除空格 双指针 顺序遍历，把有效字符往前存 
	//去除前面空格
	int slow = 0, fast = 0;
	while (s.size() > 0 && fast < s.size() && s[fast] == ' ') fast++;
	//去除中间多余空格 s
	for (; fast < s.size();fast++) {
		if (fast - 1 > 0 && s[fast - 1] == s[fast] && s[fast] == ' ') continue;
		else {
			s[slow++] = s[fast];
		}
	}

	//最后slow标记的串可能有一个空格也可能没有空格不能盲目resize(slow-1)
	if (slow - 1 > 0 && s[slow - 1] == ' ') {
		s.resize(slow - 1);
	}
	else {
		s.resize(slow);
	}
}

void reverse(string& s,int start, int end) {
	//双指针
	for (int i = start, j = end; i < j; i++, j--) {
		swap(s[i], s[j]);
	}
}

int main() {
	string s;
	while (getline(cin, s)) {
		//把所有的非字母数字字符变成空格
		for (int i = 0; i < s.size(); i++) {
			if (!isalnum(s[i])) s[i] = ' ';
		}
		//去除前后空格和多余空格
		cleanSpace(s);
		//整串逆序
		reverse(s,0,s.size()-1);
		
		//在原字符串上对单词逆序
		
		for (int pos = 0; pos < s.size();) {
			int len = 0;
			while (pos + len<s.size() && s[pos + len] != ' ') len++;
			reverse(s, pos, pos + len-1);
			pos = pos + len + 1;
		}
		
		cout << s << endl;
	}

	return 0;
}