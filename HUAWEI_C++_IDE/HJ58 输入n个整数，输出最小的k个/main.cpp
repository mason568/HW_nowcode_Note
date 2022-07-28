#include <iostream>
#include <algorithm>
#include<time.h>
#include<vector>
#include<queue>
#include"assert.h"
using namespace std;


#if 0
void Qsort(vector<int>& nums,int left,int right) {
	int len = right - left;
	if (nums.empty()) return;
	if (left >= right) return;
	//随机生成一个k
	srand((unsigned int)time(NULL));
	int k = left + rand() % (len + 1);
	swap(nums[left], nums[k]);

	//执行快排
	int i = left, j = right;
	int key = nums[i];
	while (i < j) { // 
		while (i<j && nums[j]>key) --j;
		if (i < j) nums[i] = nums[j];
		while (i < j && nums[i] < key) ++i;
		if (i < j) nums[j] = nums[i];
	}
	//i=j
	nums[i] = key;
	//递归
	Qsort(nums, left, i - 1);
	Qsort(nums, j+1, right);
}


//快速排序
int main() {
	int n, k,t;
	while (cin >> n >> k) {
		vector<int> nums;
		for (int i = 0; i < n; i++) {
			cin >> t;
			nums.push_back(t);
		}
		Qsort(nums,0,nums.size()-1);
		assert(k <= n);
		for (int i = 0; i < k; i++) {
			cout << nums[i] << " ";
		}
		cout << endl;
	}
}

#endif

#if 1

//重写比较函数
struct cmp {
	bool operator() (int lhs, int rhs) {
		return lhs > rhs;
	}

};

//小顶堆
int main() {
	int n, k, t;
	while (cin >> n >> k) {
		vector<int> nums;
		priority_queue<int,vector<int>,cmp> min_queue;
		for (int i = 0; i < n; i++) {
			cin >> t;
			nums.push_back(t);
			min_queue.push(t);
		}
		while (k--&&k<=min_queue.size()) {
			cout << min_queue.top() << " ";
			min_queue.pop();
		}
	}
}

#endif