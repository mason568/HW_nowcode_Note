#include <iostream>
#include <algorithm>
#include<time.h>
#include<vector>
#include<queue>
#include"assert.h"
using namespace std;

//重写运算符>
//方法1
class tmp1 //运算符重载<
{
public:
	int x;
	tmp1(int a) { x = a; }
	bool operator<(const tmp1& a) const //默认左边是this指针
	{
		return x < a.x; //大顶堆
	}
};

struct cmp2 {
	bool operator() (tmp1 lhs, tmp1 rhs) {
		return lhs.x > rhs.x;
	}

};


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
		priority_queue<int, vector<int>, cmp> min_queue;
		priority_queue<tmp1, vector<tmp1>, cmp2> tmp1_min_deque;
		for (int i = 0; i < n; i++) {
			cin >> t;
			nums.push_back(t);
			min_queue.push(t);
			tmp1_min_deque.push(t);
		}
		cout << "nums中的前k个值: ";
		int t = k;
		for (int i = 0; i < k; i++) {
			if (i < n) cout << nums[i] << " ";
		}
		cout << endl;
		cout << "min_queue中的前k个值: ";
		while (t-- && t <= min_queue.size()) {
			cout << min_queue.top() << " ";
			min_queue.pop();
		}
		cout << endl;
		cout << "tmp1_min_deque中的前k个值: ";
		t = k;
		while (t-- && t <= tmp1_min_deque.size()) {
			cout << tmp1_min_deque.top().x << " ";
			tmp1_min_deque.pop();
		}
		cout << endl;
	}
	//对于基础类型 默认是大顶堆 STL里面默认用的是vector 
	priority_queue<int> a;
	priority_queue<int,vector<int>,greater<int> > b; //小顶堆这样写

	//升序队列，小顶堆
	priority_queue <int, vector<int>, greater<int> > q; //注意> >括号中间的空格，没有的话编译器可能会认为是右移运算符
	//降序队列，大顶堆 默认
	priority_queue <int, vector<int>, less<int> > p;
	//其中，greater和less是std实现的两个仿函数（就是使一个类的使用看上去像一个函数。其实现就是类中实现一个operator()，这个类就有了类似函数的行为，就是一个仿函数类了

	//自定义比较函数如上面例子
	//重写比较函数
	priority_queue<int, vector<int>, cmp> min_queue;
	//对类的比较
	priority_queue<tmp1, vector<tmp1>, cmp2> tmp1_min_deque;
	return 0;

}

