#include<iostream>
#include<string>
#include<vector>
using namespace std;

void solution(string& s) {
	int maxLen = -1;
	int pos = 0;
	int count = 0;
	int flag = true;
	vector<string> res;
	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i])) {
			if (flag) {
				pos = i;
				flag = false;
			}
			count++;

			if (count == maxLen) {
				res.push_back(s.substr(pos, count));
			}
			else if (count > 0 && count > maxLen) {
				res.clear();
				res.push_back(s.substr(pos, count));
				maxLen = count;
			}
			
		}
		else {
			

			flag = true;
			count = 0;

		}
	}
	
	for (auto i : res) {
		cout << i;
	}
	cout << "," << maxLen << endl;



}

int main() {
	string s;
	while (cin >> s) {
		solution(s);
	}
	
}
