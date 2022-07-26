#include<map>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include"assert.h"
using namespace std;

bool comp(pair<char, int>& lhs, pair<char, int> &rhs) {
	return lhs.second > rhs.second;
}

int main() {
	
	int n;
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;

			int res = 0;
			//贪心计算一个字符串的漂亮度
			//先统计出现次数，记录到map中去  //用什么map,用数组更快 然后用自定义的比较函数重新对数组排序，完事
			map<char, int> m;
			for (auto ch : s) {
				m[tolower(ch)]++;
			}
			//sort只能支持数组，vector等排序 map不行，所以先把映射放到vector中
			vector<pair<char, int>> vec;
			for (auto it = m.begin(); it != m.end(); it++) {
				vec.push_back(make_pair(it->first, it->second));
			}
			sort(vec.begin(), vec.end(), comp);
			assert(vec.size() <= 26);
			int val = 26;
			for (auto it : vec) {
				res += it.second * (val--);
			}
			cout << res << endl;

		}
	}
	return 0;
}