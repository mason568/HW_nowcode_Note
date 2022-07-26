#include<iostream>
#include<vector>
#include"assert.h"
#include<sstream>
#include<string>
using namespace std;
int main() {
	// ‰»Î
	vector<int> nums;
	string s;
	while (getline(cin, s)) {
		stringstream ss(s);
		string num;
		while(getline(ss,num,' ')) nums.push_back(stoi(num));

		for (int j = 0; j < nums.size(); j++) {
			int p0 = 0, p1 = 0;
			for (int i = 0; i < nums.size(); i++) {
				if (nums[i] == 0) {
					swap(nums[p0++], nums[i]);
					p1++;
				}
				else if (nums[i] == 1) {
					swap(nums[p1++], nums[i]);
				}
			}
		}
		for (int j = 0; j < nums.size(); j++) {
			cout << nums[j] << endl;
		}
	}


	return 0;
}