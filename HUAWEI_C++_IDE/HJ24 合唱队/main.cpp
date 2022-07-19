#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N;
	while (cin >> N) {
		//输入
		vector<int> tall;
		for (int i = 0; i < N; i++) {
			int t;
			cin >> t;
			tall.push_back(t);
		}
		//最长严格递增子序列+最长严格递减子序列->动态规划
		vector<int> dp_h(N, 1), dp_t(N, 1);
		//分两步生成dp数组
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < i; j++) {
				if (tall[i] > tall[j]) {
					dp_h[i] = max(dp_h[i],dp_h[j]+1);//这个加1是加的第i个人，因为他比之前的i-1个人（包括j）都高
				}
			}
		}

		for (int i = N-1; i >= 0; i--) {
			for (int j = N - 1; j > i; j--) {
				if (tall[i] > tall[j]) {
					dp_t[i] = max(dp_t[i], dp_t[j] + 1);
				}
				
			}
		}
		//求和得到最长先增后减子序列长度，但是因为多加了自身一次，要在减去1
		int maxNum = 0;
		for (int i = 0; i < N; i++) {
			if (dp_h[i] + dp_t[i] - 1 > maxNum) {
				maxNum = dp_h[i] + dp_t[i] - 1;
			}
		}
		cout << N - maxNum << endl;

	}

	return 0;
}