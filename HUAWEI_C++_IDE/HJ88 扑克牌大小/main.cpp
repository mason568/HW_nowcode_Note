#include<unordered_map>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

bool isbomb(vector<string>& subS) {
	if (subS.size() == 4 && (subS[0] == subS[1]) && (subS[1] == subS[2]) && (subS[2] == subS[3])) return true;
	return false;
}

int main() {
	string s;
	while (getline(cin, s)) {

		unordered_map<string, int> m;
		m["3"] = 1;
		m["4"] = 2;
		m["5"] = 3;
		m["6"] = 4;
		m["7"] = 5;
		m["8"] = 6;
		m["9"] = 7;
		m["10"] = 8;
		m["J"] = 9;
		m["Q"] = 10;
		m["K"] = 11;
		m["A"] = 12;
		m["2"] = 13;
		m["joker"] = 14;
		m["JOKER"] = 15;
		string s1, s2;
		int pos = s.find_first_of('-');
		s1 = s.substr(0, pos);
		s2 = s.substr(pos + 1);


		//getline(ss, s1, '-');
		//getline(ss, s2, '-');
		if (s1 == "joker JOKER" || s2 == "joker JOKER") {
			cout << "joker JOKER" << endl;
			continue;
		}
		int len_s1 = s1.size(), len_s2 = s2.size();
		string sub;
		vector<string> subS1, subS2;
		stringstream ss;
		ss = stringstream(s1);
		while (getline(ss, sub, ' ')) subS1.push_back(sub);
		ss = stringstream(s2);
		while (getline(ss, sub, ' ')) subS2.push_back(sub);

		if (isbomb(subS1) && !isbomb(subS2)) {
			cout << s1 << endl;
		}
		else if (!isbomb(subS1) && isbomb(subS2)) {
			cout << s2 << endl;
		}
		else if (subS1.size() != subS2.size()) {
			cout << "ERROR" << endl;
			continue;
		}
		else {
			if (m[subS1[0]] > m[subS2[0]]) {
				cout << s1 << endl;
			}
			else {
				cout << s2 << endl;
			}
		}

	}

	return 0;
}