#include<iostream>
#include<vector>
#include<map>
using namespace std;


#if 0
vector<int> nums;
int N;
vector<bool> used;
bool flag;
vector<int> group3,group5;
void dfs(int step, int sum3, int sum5) {
	if (flag) {
		return;
	}

	if (step == N ) {
		if (flag) {
			return;
		}
		else {
			if (sum3 == sum5) {
				//cout << "true" << endl;
				flag = true;
				return;
			}
			else return;
		}
		
		
	}
	else {
		step++;
		//超时了 减枝？ 
		for (int i = 0; i < N; i++) {
			if (used[i] == false) {
				used[i] = true;
				if (nums[i] !=0 && nums[i] % 5 == 0) {
					dfs(step, sum3, sum5 + nums[i]);
					//sum5 -= nums[i];  因为传入的sum5值是 + nums[i]之后的拷贝
				}
				else if (nums[i] != 0 && nums[i] % 3 == 0) {
					dfs(step, sum3 + nums[i], sum5);
					//sum3 -= nums[i];
				}
				else {
					//要么放group3//要么放group5
					dfs(step, sum3, sum5 + nums[i]);
					//sum5 -= nums[i];

					dfs(step, sum3 + nums[i], sum5);
					//sum3 -= nums[i];
				}
				used[i] = false;
			}
		}
	}

}



int main() {
	while (cin >> N) {
		int t;
		used = vector<bool>(N, false);
		flag = false;
		for (int i = 0; i < N; i++) {
			cin >> t;
			nums.push_back(t);
		}
		dfs(0, 0, 0);

		if (flag) cout << "true" << endl;
		else cout << "false" << endl;
	}

	return 0;
}


#endif
//动态规划
#if 1
int main() {
	int N;
	while (cin >> N) {
		vector<int> nums;// nims_notdevide_3_or_5
		map<int, bool> dp;

		int sum = 0;
		int sumall_div5 = 0;
		int t;
		int dp_low = 0;//dp数组的下阶
		for (int i = 0; i < N; i++) {
			cin >> t;
			if (t % 5 != 0 || t % 3 != 0) {
				nums.push_back(t);
			}
			if (t % 5 == 0) {
				sumall_div5 += t;
			}
			if (t < 0) {
				dp_low += t;
			}
			sum += t;
		}


		if ((sum % 2) == 1) {
			cout << "false" << endl;
			continue;
		}
		else {
			//dp边界
			for (int i = 0; i < nums.size(); i++) {
				dp[nums[i]] = true;
			}

			for (int i = 0; i < nums.size(); i++) {
				for (int j = sum / 2 - sumall_div5; j >= dp_low; j--) {
					dp[j] = dp[j] || dp[j - nums[i]];
				}
			}

			if (dp[sum / 2 - sumall_div5] == true) {
				cout << "true" << endl;
			}
			else {
				cout << "false" << endl;
			}
		}
		nums.clear();
	}
	



}

#endif