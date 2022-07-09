#include<iostream>
#include<bitset>
#include<vector>
#include <algorithm>
using namespace std;


#if 0
int main() {
	int N, m;
	while (cin>>N>>m) {
		//输入
		int value, proority, isAttachments;
		vector<vector<int>> data(m + 1, vector<int>(6, 0));
		for (int i = 1; i <= m; i++) {
			cin >> value >> proority >> isAttachments;
			if (isAttachments == 0) {
				data[i][0] = value;
				data[i][1] = proority;
			}
			//因为最多只有两附件
			else if (data[isAttachments][2] == 0) {
				data[isAttachments][2] = value;
				data[isAttachments][3] = proority;
			}
			else {
				data[isAttachments][4] = value;
				data[isAttachments][5] = proority;
			}
		}
		//dp[i][j]，表示前i个物品(任取)，背包容量(花销)为j的情况下能装的 最大价值(权重和)
		//递推函数为 dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[j]] + value[j])
		//01背包问题 二维数组 dp[i][j]是
		vector<vector<int>> dp(m + 1, vector<int>(N + 1, 0));
		for (int i = 1; i < m + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				
				int valuePrime = data[i][0];
				int valueAttach1 = data[i][2];
				int valueAttach2 = data[i][4];
				int prorityPrime = data[i][1];
				int prorityAttach1 = data[i][3];
				int prorityAttach2 = data[i][5];

				//对于每一个主件最多有5种情况 1不买主件(在前一种情况,那就是只剩后面四种情况) 2买主件不买附件 3买主件买附件1 4买主件买附件2 5买主件并且买两个附件
				dp[i][j] = j >= valuePrime ? max(dp[i - 1][j - valuePrime] + valuePrime * prorityPrime, dp[i - 1][j]) : dp[i - 1][j];
				dp[i][j] = j >= (valuePrime+valueAttach1) ? max(dp[i - 1][j - valuePrime- valueAttach1] + valuePrime * prorityPrime + valueAttach1 * prorityAttach1, dp[i][j]) : dp[i][j];
				dp[i][j] = j >= (valuePrime + valueAttach2) ? max(dp[i - 1][j - valuePrime- valueAttach2] + valuePrime * prorityPrime + valueAttach2 * prorityAttach2, dp[i][j]) : dp[i][j];
				dp[i][j] = j >= (valuePrime + valueAttach1 + valueAttach2) ? max(dp[i - 1][j - valuePrime- valueAttach1- valueAttach2] + valuePrime * prorityPrime + valueAttach1 * prorityAttach1 + valueAttach2 * prorityAttach2, dp[i][j]) : dp[i][j];


			}
		}

		cout << dp[m][N] << endl;
		
		//cout << N << " " << m << endl;
	}
	return 0;
}
#endif 


#if 1
//使用滚动数组讲背包问题的二维dp数组压缩成一维
int main() {
	int N, m;
	while (cin >> N >> m) {
		//输入
		int value, proority, isAttachments;
		
		vector<vector<int>> data(m + 1, vector<int>(6, 0));
		for (int i = 1; i <= m; i++) {
			cin >> value >> proority >> isAttachments;
			if (isAttachments == 0) {
				data[i][0] = value;
				data[i][1] = proority;
			}
			//因为最多只有两附件
			else if (data[isAttachments][2] == 0) {
				data[isAttachments][2] = value;
				data[isAttachments][3] = proority;
			}
			else {
				data[isAttachments][4] = value;
				data[isAttachments][5] = proority;
			}
		}
		//dp[i][j]，表示前i个物品，背包重量(花销)为j的情况下能装的最大价值 n
		//01背包问题 二维数组 dp[i][j]是

		//根据解法我们可以看到，对于任意的dp[i][j]dp[i][j]dp[i][j]它只与dp[i−1][  ]dp[i-1][\ \ ]dp[i−1][  ]（即第i−1i-1i−1行）有关。所以我们可以考虑对dp数组的大小进行优化。 使用单行的dp数组来保存上一行的dp状态，并且大小可以以输入的N为基准。
		vector<int> dp(N + 1, 0);
		for (int i = 1; i < m + 1; i++) {
			for (int j = N; j >0; j--) { //这里只能从N \to 1而不能从 1 \to N 避免溢出
				
				int valuePrime = data[i][0];
				int valueAttach1 = data[i][2];
				int valueAttach2 = data[i][4];
				int prorityPrime = data[i][1];
				int prorityAttach1 = data[i][3];
				int prorityAttach2 = data[i][5];

				//对于每一个主件最多有5种情况 1不买主件(在前一种情况) 2买主件不买附件 3买主件买附件1 4买主件买附件2 5买主件并且买两个附件
				dp[j] = j >= valuePrime ? max(dp[j - valuePrime] + valuePrime * prorityPrime, dp[j]) : dp[j];
				dp[j] = j >= (valuePrime + valueAttach1) ? max(dp[j - valuePrime- valueAttach1] + valuePrime * prorityPrime + valueAttach1 * prorityAttach1, dp[j]) : dp[j];
				dp[j] = j >= (valuePrime + valueAttach2) ? max(dp[j - valuePrime - valueAttach2] + valuePrime * prorityPrime + valueAttach2 * prorityAttach2, dp[j]) : dp[j];
				dp[j] = j >= (valuePrime + valueAttach1 + valueAttach2) ? max(dp[j - valuePrime - valueAttach1 - valueAttach2] + valuePrime * prorityPrime + valueAttach1 * prorityAttach1 + valueAttach2 * prorityAttach2, dp[j]) : dp[j];


			}
		}

		cout << dp[N] << endl;

		//cout << N << " " << m << endl;
	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>


using namespace std;

int main() {
	int N, m; // N 奖金 m 物品个数
	cin >> N >> m;
	N /= 10; // 由于所有的价格都是10的整倍数，所以可以均除10以简化运算复杂度

	int price, priority, hasAttachments;
	vector<vector<int>> data(m + 1, vector<int>(6, 0));

	for (int i = 1; i <= m; i++) {
		cin >> price >> priority >> hasAttachments;
		if (hasAttachments == 0) {
			data[i][0] = price / 10;
			data[i][1] = priority;
			// count++;
		}
		else if (data[hasAttachments][2] == 0) {
			data[hasAttachments][2] = price / 10;
			data[hasAttachments][3] = priority;
		}
		else {
			data[hasAttachments][4] = price / 10;
			data[hasAttachments][5] = priority;
		}
	}

	vector<int> dp(N + 1, 0);
	for (int i = 1; i < m + 1; i++) {
		for (int j = N; j >0; j--) {
			int pricePrime = data[i][0];
			int priceAtta1 = data[i][2];
			int priceAtta2 = data[i][4];

			int priorPrime = data[i][1];
			int priorAtta1 = data[i][3];
			int priorAtta2 = data[i][5];

			dp[j] = j >= pricePrime ? max(dp[j - pricePrime]
				+ priorPrime * pricePrime,
				dp[j]) : dp[j];
			dp[j] = j >= (pricePrime + priceAtta1) ? max(dp[j - pricePrime - priceAtta1]
				+ priorPrime * pricePrime
				+ priorAtta1 * priceAtta1,
				dp[j]) : dp[j];
			dp[j] = j >= (pricePrime + priceAtta2) ? max(dp[j - pricePrime - priceAtta2]
				+ priorPrime * pricePrime
				+ priorAtta2 * priceAtta2,
				dp[j]) : dp[j];
			dp[j] = j >= (pricePrime + priceAtta1 + priceAtta2) ?
				max(dp[j - pricePrime - priceAtta1 - priceAtta2]
					+ priorPrime * pricePrime
					+ priorAtta1 * priceAtta1
					+ priorAtta2 * priceAtta2,
					dp[j]) : dp[j];
		}
	}
	cout << dp[N] * 10 << endl;
	return 0;
}

#endif