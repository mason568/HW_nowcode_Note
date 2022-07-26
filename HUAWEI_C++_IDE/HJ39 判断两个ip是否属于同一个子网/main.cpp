#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

//有效的ip
bool isLegalIp(string ip) {
	int count = 0;
	stringstream iss(ip);
	string sub;
	while (getline(iss, sub, '.')) {

		if (count++ > 4 || sub.empty() || (unsigned int)stoi(sub) > 255) {
			return false;
		}
	}
	return count == 4;
}

//有效的掩码
bool isLegalMask(string ip) {
	stringstream iss(ip);
	string sub;
	unsigned int b = 0;
	//vector<int> v;

	while (getline(iss, sub, '.'))  b = (b << 8) + stoi(sub);
	if (b == 0 || b == 0xFFFFFFFF || (((b ^ 0xFFFFFFFF) + 1) | b) != b) {
		return false;
	}
	return true;
}

void stringIp_2_int_intIp(vector<unsigned int>& intIp, string ip) {
	stringstream ss(ip);
	string sub;
	//unsigned int b = 0;
	//vector<int> v;
	while (getline(ss, sub, '.')) intIp.push_back(stoi(sub));
}

bool isBelongSameSubnet(string mask, string ip1, string ip2) {
	vector<unsigned int> v_mask;
	vector<unsigned int> v_ip1;
	vector<unsigned int> v_ip2;
	stringIp_2_int_intIp(v_mask,mask);
	stringIp_2_int_intIp(v_ip1, ip1);
	stringIp_2_int_intIp(v_ip2, ip2);
	for (int i = 0; i < 4; i++) {
		v_ip1[i] = v_ip1[i] & v_mask[i];
		v_ip2[i] = v_ip2[i] & v_mask[i];
		if (v_ip1[i] != v_ip2[i]) return false;
	}

	return true;
}

int main() {
	string mask,ip1,ip2;
	while (cin >> mask >> ip1 >> ip2) {
		//cout << mask <<" " << ip1 <<" " << ip2 << endl;
		if (!isLegalMask(mask) || !isLegalIp(ip1) || !isLegalIp(ip2)) {
			cout << "1" << endl;
			continue;
		}
		if (isBelongSameSubnet(mask, ip1, ip2)) cout << "0" << endl;
		else cout << "2" << endl;
	}
	
}