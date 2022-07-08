#include<iostream>
#include<string>
using namespace std;

#if 0
int main() {
	
	string s;
	//while (getline(cin,s)) {
	while (cin>>s) {
		int map[128] = { 0 };
		int res = 0;
		for (auto ch : s) {
			if (map[ch] == 0) {
				map[ch] += 1;
				res += 1;
			}
		}
		cout << res << endl;
	}
	return 0;
}

#endif

#if 1
int main() {

	string s;
	//while (getline(cin,s)) {
	while (cin >> s) {
		bool map[128] = { false };
		int res = 0;
		for (auto ch : s) {
			if (map[ch] == false) {
				map[ch] = true;
				res += 1;
			}
		}
		cout << res << endl;
	}
	return 0;
}

#endif