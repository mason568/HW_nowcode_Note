#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<int> res(n, 0);  // 也可以直接用数组来做
		if (n < 1) continue;
		//初始化res[j] = $\sum_{i=1}^{j}{i}$ for j in range(n)
		for (int j = 0; j < n; j++) {
			int sum_1_to_j = 0, t = j+1;
			while (t) sum_1_to_j += t--;
			res[j] = sum_1_to_j;
		}
		//输出
		for (int line = 1; line <= n; line++) {
			for (auto it = res.begin(); it < res.end();it++) {
				cout << *it << " ";
				if(it!= res.end()-1) *it = *(it+1) - 1;
				
			}
			res.pop_back();
			cout << endl;
			
		}
	}
	return 0;
}