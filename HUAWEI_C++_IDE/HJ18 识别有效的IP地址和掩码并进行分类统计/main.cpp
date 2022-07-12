#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
bool isIgnore(string ip) {
	istringstream iss(ip);
	string sub;
	//getline(iss, sub, '.');
	int first = stoi(ip.substr(0, ip.find_first_of('.')));
	if (first==127||first==0) {
		return true;
	}
	return false;

}

bool isLegalIp(string ip) {
	int count = 0;
	istringstream iss(ip);
	string sub;
	while (getline(iss, sub, '.')) {
		if (count++ > 4 || sub.empty() || stoi(sub) > 255) {
			return false;
		}
	}
	return count == 4;
}
bool isLegalMask(string ip) {
	istringstream iss(ip);
	string sub;
	unsigned int b = 0;
	//vector<int> v;
	
	while (getline(iss, sub, '.'))  b = (b << 8) + stoi(sub);
	if (b == 0 || b == 0xFFFFFFFF || (((b ^ 0xFFFFFFFF) + 1) | b) != b) {
		return false;
	}
	return true;
	
	/*
	while(getline(iss,sub,'.')) b = (b << 8) + stoi(sub);
    if(!b) return false;
    b = ~b + 1;
    if(b == 1) return false;
    if((b & (b-1)) == 0) return true;
	return false;
	*/

	
}
bool isPrivateIp(string ip) {
	istringstream iss(ip);
	string sub;
	vector<int> sub_vec;
	while (getline(iss, sub, '.')) sub_vec.push_back(stoi(sub));
	if (sub_vec[0]==10) return true;
	if (sub_vec[0] == 172 && (sub_vec[1] >= 16 && sub_vec[1] <= 31)) return true;
	if (sub_vec[0] == 192 && sub_vec[1]==168 ) return true;
	return false;
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
		//int first_0_127 = stoi(v[0].subStr(0, v[0].find_first_of('.')));
		if (isLegalIp(v[0]) && isIgnore(v[0])) continue;
		if (!isLegalIp(v[1]) || !isLegalMask(v[1])) {
			Error += 1;
		}
		else {
			if (!isLegalIp(v[0])) {
				Error += 1;
			}
			else {
				int first = stoi(v[0].substr(0,v[0].find_first_of('.')));
				//if (first == 127 || first == 0) continue;
				if (isPrivateIp(v[0])) P++;
				if (first > 0 && first < 127) A++;
				else if (first > 127 && first < 192) B++;
				else if (first > 191 && first < 224) C++;
				else if (first > 223 && first < 240) D++;
				else if(first > 239 && first < 256) E++;
				
			}
		}
	}
	//输入完之后ctrl+Z结束cin输入循环
	//cout << "quit" << endl;
	cout << A << " " << B<<" "<<C<<" "<<D<<" "<<E<<" "<<Error<<" "<<P<<" " << endl;
	return 0;
}


