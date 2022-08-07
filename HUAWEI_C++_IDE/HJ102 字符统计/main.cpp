#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<vector>
using namespace std;

typedef pair<char, int> PAIR;
struct cmp  //自定义比较规则
{
	bool operator() (const PAIR& lhs, const PAIR& rhs)
	{
		return lhs.second < rhs.second;
	}
};

bool cmp2 (const PAIR& lhs, const PAIR& rhs)
{
	return lhs.second > rhs.second;
}


int main() {
	string s;
	while (cin >> s) {
		map<char,int> m;
		for (auto ch : s) {
			m[ch]++;
		}
		vector<PAIR> tmp;
		for (auto i : m) {
			tmp.push_back(i);
		}
		stable_sort(tmp.begin(), tmp.end(), cmp2);
		for (auto ch : tmp) {
			cout << ch.first;
		}
		cout << endl;
	}
}