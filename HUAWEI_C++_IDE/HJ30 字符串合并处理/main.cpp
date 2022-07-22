#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
#include<bitset>
#include <sstream>
using namespace std;
map<char, char>m;

#if 0
//字典法替换 当然字典除了用map外，也可以用两个字符串
string trans(string a, string b) {
	//step1
	string ret = a+b;
	//step2
	vector<char> odds;
	vector<char> evens;
	for (int i = 0; i < ret.size();i++) {
		if (i % 2 == 0) {
			evens.push_back(ret[i]);
		}
		else {
			odds.push_back(ret[i]);
		}
	}
	sort(evens.begin(),evens.end());
	sort(odds.begin(), odds.end());
	for (int i = 0; i < ret.size(); i++) {
		if (i % 2 == 0) {
			ret[i] = evens[i/2];
		}
		else {
			ret[i] = odds[i/2];
		}
	}
	//step3
	for (int i = 0; i < ret.size(); i++) {
		if (ret[i]>='0'&&ret[i]<='9' || ret[i] >= 'a' && ret[i] <= 'f'|| ret[i] >= 'A' && ret[i] <= 'F') {
			ret[i] = m[toupper(ret[i])];
		}
		else continue;
	}

	return ret;
}

int main() {
	m['0'] = '0';
	m['1'] = '8';
	m['2'] = '4';
	m['3'] = 'C';
	m['4'] = '2';
	m['5'] = 'A';
	m['6'] = '6';
	m['7'] = 'E';
	m['8'] = '1';
	m['9'] = '9';
	m['A'] = '5';
	m['B'] = 'D';
	m['C'] = '3';
	m['D'] = 'B';
	m['E'] = '7';
	m['F'] = 'F';
	string str1,str2;
	while (cin >> str1>> str2) {
		cout << trans(str1, str2) << endl;
	}

	return 0;
}

#endif

#if 1
//直接逻辑替换 bitset
char ch_subtitude(char c) {
	int val = 0;
	unsigned char m = 0x5;
	if (c >= '0' && c <= '9') val = c - '0';
	else if (c >= 'A' && c <= 'F') val = c - 'A' + 10;
	else if (c >= 'a' && c <= 'f') val = c - 'a' + 10;
	val = val >> 1 & m | (val & m) << 1;
	val = val >> 2 | val << 2;
	val %= 16;
	return val < 10 ? val + '0' : val - 10 + 'A';
	
}

char ch_subtitude_bitset(char c) {
	int val = 0;
	if (c >= '0' && c <= '9') val = c - '0';
	else if (c >= 'A' && c <= 'F') val = c - 'A' + 10;
	else if (c >= 'a' && c <= 'f') val = c - 'a' + 10;
	bitset<4> b_val(val);
	string s_b_val =
		b_val.template to_string<char, char_traits<char>,
		allocator<char> >();
	reverse(s_b_val.begin(), s_b_val.end());
	//cout << stoi(s_b_val, 0, 2) << endl;
	std::stringstream ss;
	ss << hex << stoi(s_b_val, 0, 2);
	char s;
	ss >> s;
	return toupper(s);

}

string trans(string a, string b) {
	//step1
	string ret = a + b;
	//step2
	vector<char> odds;
	vector<char> evens;
	for (int i = 0; i < ret.size(); i++) {
		if (i % 2 == 0) {
			evens.push_back(ret[i]);
		}
		else {
			odds.push_back(ret[i]);
		}
	}
	sort(evens.begin(), evens.end());
	sort(odds.begin(), odds.end());
	for (int i = 0; i < ret.size(); i++) {
		if (i % 2 == 0) {
			ret[i] = evens[i / 2];
		}
		else {
			ret[i] = odds[i / 2];
		}
	}
	//step3
	for (int i = 0; i < ret.size(); i++) {
		if (ret[i] >= '0' && ret[i] <= '9' || ret[i] >= 'a' && ret[i] <= 'f' || ret[i] >= 'A' && ret[i] <= 'F') {
			ret[i] = ch_subtitude(ret[i]);
		}
		else continue;
	}

	return ret;
}

int main() {
	/*
	string str1, str2;
	while (cin >> str1 >> str2) {
		cout << trans(str1, str2) << endl;
	}
	*/

	char test;
	
	string s1 = "ffff";
	cout << stoi(s1,0,16) << endl;
	stringstream ss;
	string tmp;
	int a = 10;
	ss << hex << a;
	ss >> tmp;
	cout << tmp<< endl;

	bitset<6> b("10101011");//一定要是01组成的字符串否则报错，不足6位左边补0 超过6位只取高6位101010
	cout << b << endl;


	return 0;
}
#endif