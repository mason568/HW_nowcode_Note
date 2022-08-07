#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	int N;
	while(cin >> N) {
		vector<int> nums;
		int t;
		for (int i = 0; i < N; i++) {
			cin >> t;
			nums.push_back(t);
		}
		int flag;
		cin >> flag;
		if (flag) {
			sort(nums.begin(), nums.end(), greater<int>());
		}
		else {
			sort(nums.begin(), nums.end());
		}

		for (auto num : nums) cout << num << " ";
		
	}
	return 0;
}
