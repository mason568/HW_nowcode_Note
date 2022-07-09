#include<iostream>
#include<bitset>
#include<vector>
using namespace std;



int main() {
	int N, m;
	while (cin>>N>>m) {
		//输入
		int value, proority, isAttachments;
		vector<vector<int>> data(m + 1, vector<int>(6, 0));
		for (int i = 0; i < m; i++) {
			cin >> value >> proority >> isAttachments;
			if (isAttachments == 0) {
				data[i][0] = value;
				data[i][1] = proority;
			}
			//因为最多只有两附件
			else if (data[isAttachments][2] == 0) {
				data[isAttachments][2] = value;
				data[isAttachments][3] = value;
			}
			else {
				data[isAttachments][4] = value;
				data[isAttachments][5] = value;
			}
		}
		//dp[i][j]，表示前i个物品，背包重量为j的情况下能装的最大价值 n
		//01背包问题 二维数组 dp[i][j]是
		vector<vector<int>> dp(m + 1, vector<int>(N + 1, 0));
		for (int i = 1; i < m + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				//i=1,j=1时候是初始化
				int valuePrime = data[i][0];
				int valueAttach1 = data[i][2];
				int valueAttach2 = data[i][4];
				int prorityPrime = data[i][1];
				int prorityAttach1 = data[i][3];
				int prorityAttach2 = data[i][5];

				//对于每一个主件最多有5种情况 1不买主件(在前一种情况) 2买主件不买附件 3买主件买附件1 4买主件买附件2 5买主件并且买两个附件
				dp[i][j] = j >= valuePrime ? max(dp[i - 1][j - valuePrime] + valuePrime * prorityPrime, dp[i - 1][j]) : dp[i - 1][j];
				dp[i][j] = j >= (valuePrime+valueAttach1) ? max(dp[i - 1][j - valuePrime] + valuePrime * prorityPrime + valueAttach1 * prorityAttach1, dp[i][j]) : dp[i][j];
				dp[i][j] = j >= (valuePrime + valueAttach2) ? max(dp[i - 1][j - valuePrime] + valuePrime * prorityPrime + valueAttach2 * prorityAttach2, dp[i][j]) : dp[i][j];
				dp[i][j] = j >= (valuePrime + valueAttach1 + valueAttach2) ? max(dp[i - 1][j - valuePrime] + valuePrime * prorityPrime + valueAttach1 * prorityAttach1 + valueAttach2 * prorityAttach2, dp[i][j]) : dp[i][j];


			}
		}

		cout << dp[m][N] << endl;
		
		//cout << N << " " << m << endl;
	}
	return 0;
}