#include<iostream>
#include<vector>
using namespace std;

int solution(int n, int m) {
	vector<vector<int>> dp(m + 2, vector<int>(n + 2, 0));
	dp[0][1] = 1; //ªÚ’ﬂdp[1][0]=1;
	
	for (int i = 1; i <= m + 1; i++) {
		for (int j = 1; j <= n + 1; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[m + 1][n + 1];
}

int main() {
	int m, n;
	while (cin >> n >> m) {
		cout << solution(n, m) << endl;
	}
} 