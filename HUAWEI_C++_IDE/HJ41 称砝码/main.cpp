#include<iostream>
#include<map>
#include<vector>
#include<sstream>
#include<unordered_set>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		//输入
		vector<int> weight;
		vector<int> nums;
		int tmp;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			weight.push_back(tmp);
		}
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			nums.push_back(tmp);
		}
		//cout << weight.size() << " " << nums.size() << endl;
		//处理
		unordered_set<int> table;//如果set中有一个值s，那么表示从所有的数中任选几个有和为s，最后只要输出s的大小
		table.insert(0);
		//遍历每一个砝码
		for (int i = 0; i < n; i++) {
			int num = nums[i];
			int w = weight[i];
			while (num--) {
				//把新加入的砝码，加上table中的每一个元素，如果和不在table中，就把和加入table
				unordered_set<int> tmp = table;
				for (auto s : tmp) {
					table.insert(s + w);
				}
			}
		}

		cout << table.size() << endl;
		
	}
	return 0;
}