#include<forward_list>
#include<iostream>

using namespace std;
#if 0
//使用c++标准库单向链表forward_list 有push_front,insert_after,begin(),end()remove()等接口
int main() {
	int N,head_val;

	cin>>N >> head_val;
	forward_list<int> flist;
	flist.push_front(head_val);
	//插入节点，注意头节点已经插入，之后只需要插入N-1个值就好
	for (int i = 1; i < N; i++) {
		int back, front;
		cin >> back >> front;
		auto it = find(flist.begin(), flist.end(),front); //#include<algorithm>
		flist.insert_after(it, back);
	}
	int delete_val;
	cin >> delete_val;
	flist.remove(delete_val);
	for (auto it = flist.begin(); it != flist.end(); it++) {
		cout << *it << " ";    //从头到尾输出链表的值
	}
	cout << endl;
	
	return 0;
}
#endif

//c++正统链表写法
struct node {
	int val;
	struct node* next = nullptr;
};

int main(){
	int n, val;
	while (cin >> n >> val) {
		//生成头节点
		node* Head = new node;
		Head->val = val;
		//插入节点
		for (int i = 1; i < n; i++) {
			int back, front;
			cin >> back >> front;
			//找到front,插入back节点
			node* back_node = new node;
			back_node->val = back;
			node* p = Head;
			while (p->val != front)
				p = p->next;
			back_node->next = p->next;
			p->next = back_node;	
		}
		//删除
		int remove_val;
		cin >> remove_val;
		node* tmp_head = new node;
		tmp_head->next = Head;
		node* cur = tmp_head;
		while (cur->next != nullptr) {
			if (cur->next->val == remove_val) {
				cur->next = cur->next->next;
				break;
			}
			cur = cur->next;
		}
		
		//输出
		while (tmp_head->next != nullptr) {
			cout << tmp_head->next->val << " ";
			tmp_head = tmp_head->next;
		}
		cout << endl;
		delete Head,tmp_head;
	}

	return 0;
}