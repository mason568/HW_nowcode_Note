#include<iostream>
#include<sstream>
#include<string>
using namespace std;



bool isLegalIp(string ip) {
	int count = 0;
	stringstream iss(ip);
	string sub;
	while (getline(iss, sub, '.')) {
		if (count++ > 4 || sub.empty() || stoi(sub) > 255 || sub.size()!=to_string(stoi(sub)).size()) {
			return false;
		}
	}
	return count == 4;
}

int main() {

	string s;
	while (getline(cin,s)) {
		if (isLegalIp(s)) cout << "YES" << endl;
		else  cout << "NO" << endl;
	}
}