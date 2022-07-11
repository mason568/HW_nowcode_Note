#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

bool isLegalIp(string ip) {
	int count = 0;
	istringstream iss(ip);
	string sub;
	while (getline(iss, sub, '.')) {
		if (count++ > 4 || sub.empty() || stoi(sub) > 255) {
			return false;
		}
	}
	return j == 4;
}
bool isLegalMask(string ip) {
	istringstream iss(ip);
	string sub;
	unsigned b = 0;
	//vector<int> v;
	while (getline(iss, sub, '.'))  b = (b << 8) + stoi(sub);
	if (!b) return false;
}
bool isPrivateIp(string ip) {

}


int main() {
	//使用getline来分割输入字符串
	string s;
	int A = 0, B = 0, C = 0, D = 0, E = 0, Error = 0, P = 0;
	while (cin >> s) {
		istringstream is(s);
		string add;
		vector<string> v;
		while (getline(is, add, '~')) {
			v.push_back(add);
			//cout << add << endl;
		}
		if (!isLegalIp(v[0]) || !isLegalMask(v[1])) {
			Error += 1;
		}
		else {
			if (!isLegalIp(v[0])) {
				Error += 1;
			}
			else {
				isPrivateIp(v[0]);
				
			}
		}
	}
	//输入完之后ctrl+Z结束cin输入循环
	cout << "quit" << endl;
	return 0;
}