#include<iostream>
#include<deque>
#include<sstream>
#include<vector>
using namespace std;
vector<int> get_maxVal_in_wind(vector<int>& nums, int k) {
	vector<int> res;
	//维护一个单调的队列 队列中放着滑窗中前最大的几个元素，长度取决于下一个进入窗口的值
	deque<int> monoQueue;
	int n = nums.size();
	for (int i = -k+1; i < n - k+1; i++) { //O(n)复杂度
		int j = i + k - 1;//才是用来读取容器的整数
		//出窗元素nums[i-1]， i>0 
		if (i > 0 && nums[i-1] == monoQueue.front()) monoQueue.pop_front();
		//维护单调
		while (!monoQueue.empty()&& nums[j] >= monoQueue.back()) {
			monoQueue.pop_back();
		}
		//入窗元素nums[j]
		monoQueue.push_back(nums[j]);
		
		if (i >= 0) {
			res.push_back(monoQueue.front());
		}
	}
	return res;
}


int main() {
	//输入
	string s;
	while (getline(cin,s)) {
		vector<int> nums;
		string num;
		stringstream ss(s);
		while (getline(ss, num, ' ')) {
			nums.push_back(stoi(num));
		}

		int k = nums[nums.size()-1];
		nums.pop_back();
		
		//处理
		vector<int> res = get_maxVal_in_wind(nums, k);
		for (auto i : res) {
			cout << i << endl;
		}
		
	}
	return 0;
}