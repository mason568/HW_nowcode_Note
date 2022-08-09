#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main() {
	int N;
	while (cin >> N) {
		vector<int> nums;
		int t;
		for (int i = 0; i < N; i++) {
			cin >> t;
			nums.push_back(t);
		}
		vector<int> dp(N,1);
		int maxLen = -1;
		for (int i = 1; i < nums.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
				maxLen = dp[i] > maxLen ? dp[i] : maxLen;
			}
		}


		cout << maxLen << endl;
	}

	return 0;
}