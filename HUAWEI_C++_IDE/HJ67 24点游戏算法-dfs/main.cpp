#include<iostream>
#include<vector>
#include"assert.h"
#include<sstream>
using namespace std;

double nums[4];
bool flag = false;
bool used[4] = { 0 };
void dfs(int step,double sum) {
	//递归结束条件
	//每个数都要被选取计算
	if (step == 4) {
		if (sum == 24) {
			flag = true;
			return;
		}
	}
	else {
		step++;
		//遍历四个数字
		for (int j = 0; j < 4; j++) {
			if (used[j] == false) {
				used[j] = true;
				dfs(step, sum + nums[j]);
				dfs(step, sum - nums[j]);
				dfs(step, sum * nums[j]);
				dfs(step, sum / nums[j]);
				//回溯
				used[j] = false;
			}

		}
		
	}

	//隐藏的return  每个数都被用了但是得不到24
}

int main() {
	for (int i = 0; i < 4; i++) {
		cin >> nums[i];
	}
	dfs(0,0);
	if (flag == true) cout << "true" << endl;
	else cout << "false" << endl;


	return 0;
}