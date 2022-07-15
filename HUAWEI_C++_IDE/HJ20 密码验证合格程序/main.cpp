#include<iostream>
#include<string>
#include<map>
using namespace std;

#if 0
//暴力破解找最长相同子串
string findMaxSubStr(string s) {
	string ret = "";
	
	int size = s.size();
	map<string, int> m;
	for (int len = 3; len < size; len++) { //每次check的字符串长度
		for (int pos = 0; pos < size; pos++) {//从最后一个字符串开始算起
			if (pos < size && pos + len < size) {
				string sub = s.substr(pos,len);
				m[sub]++;
			}
			

		}
	}

	for (auto i : m) {
		if (i.second >= 2) ret = i.first;
	}
	return ret;
}

//统计字符类型
int statisticStrType(string s) {
	int A = 0, B = 0, C = 0, D = 0;
	for (auto ch : s) {
		if (ch >= 'a' && ch <= 'z') A=1;
		else if (ch >= 'A' && ch <= 'Z') B=1;
		else if (ch >= '0' && ch <= '9') C=1;
		else D=1;
	}
	return (A+B+C+D);

}

int main() {
	string psd;
	while (cin >> psd) {
		if (psd.size() < 9) {
			cout << "NG" << endl;
		}
		else if (findMaxSubStr(psd).size() > 2) {
			cout << "NG" << endl;
		}
		else if (statisticStrType(psd) < 3) {
			cout << "NG" << endl;
		}
		else {
			cout << "OK" << endl;
		}

		
	}
	return 0;
}

#endif

#if 1
int main() {
	string s;
	while (cin >> s) {
		//密码长度需要大于8
		if (s.size() <= 8) {
			cout << "NG" << endl;
			continue;
		}
		//密码至少有四种类型字符的三种
		int A = 0, B = 0, C = 0, D = 0;
		bool flag = false;
		for (auto ch : s) {
			if (ch >= 'a' && ch <= 'z') A = 1;
			else if (ch >= 'A' && ch <= 'Z') B = 1;
			else if (ch >= '0' && ch <= '9') C = 1;
			else D = 1;
		}
		if (A + B + C + D >= 3) {
			flag = true;
		}
		else {
			cout << "NG" << endl;
			continue;
		}
		int size = s.size();
		map<string, int> m;
		//密码不能有大于2包含公共元素的子字符串
		//只需要遍历所有长度为3的子字符串就好 	
		for (int pos = 0; pos < size; pos++) {//从第一个字符串开始算起
			if (pos < size && pos + 3 < size) {
				string sub = s.substr(pos, 3);
				m[sub]++;
			}
		}
		for (auto i : m) {
			if (i.second >= 2) {
				flag = false;
				break;
			}
		}

			//021Aaabcbc$
		

		if (flag) {
			cout << "OK" << endl;
		}
		else {
			cout << "NG" << endl;
		}
		
	}
	return 0;
}
#endif