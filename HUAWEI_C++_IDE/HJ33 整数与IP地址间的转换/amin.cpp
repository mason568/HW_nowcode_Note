#include<iostream>
#include<sstream>
#include<string>
using namespace std;

unsigned int ip_str2int(string ip) {
	unsigned int res=0;
	string sub;
	stringstream ss(ip);
	while (getline(ss, sub, '.'))  res = (res << 8) + stoi(sub);
	return res;

}

string ip_int2str(unsigned int ip) {
	unsigned int sub=0,a=(0xFF<<24);
	string res;
	while (ip) {
		sub = (ip & a) >> 24;
		res += to_string(sub);
		res += ".";
		ip = ip << 8;
	}
	res.pop_back();
	return res;
}

int main() {
	unsigned int int_ip;
	string str_ip;
	while (cin >> str_ip >> int_ip) {

		cout << ip_str2int(str_ip) << endl;
		cout << ip_int2str(int_ip) << endl;

	}
	return 0;
}