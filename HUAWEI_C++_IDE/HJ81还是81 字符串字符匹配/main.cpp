#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

//hash
int main() {
	string S, T;
	while (cin >> S >> T) {
		unordered_map<char,int> m;
		unordered_set<char> sset;
		for (auto t : T) m[t]++;
		for (auto ch : S) sset.insert(ch);
		for (auto s : sset) m[s]--;
		bool flag = true;
		for (auto item : m) {
			if (item.second<0) {
				flag = false;
				break;
			}
		}
		cout << boolalpha << flag << endl;

	}

	return 0;
}


// set + set.conunt()
#if 0
int main() {
	string S, T;
	while (cin >> S >> T) {
		unordered_set<char> T_set;
		for (auto t : T) T_set.insert(t);
		bool flag = true;
		for (auto ch : S) {
			if (!T_set.count(ch)) {
				flag = false;
				break;
			}
		}
		cout << boolalpha << flag << endl;

	}

	return 0;
}
#endif 