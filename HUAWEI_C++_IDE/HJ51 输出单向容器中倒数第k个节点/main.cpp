#include<iostream>
#include"assert.h"
using namespace std;
struct node {
	int val;
	node* next = nullptr;
};

int main() {
	int N;
	node* tmpHead = new node;
	node* p = tmpHead;
	while (cin >> N) {
		for (int i = 0; i < N; i++) {
			int t;
			cin >> t;
			node* q = new node;
			q->val = t;
			p->next = q;
			p = q;
		}
		int k;
		cin >> k;
		assert(k<=N);
		//Ë«Ö¸Õë
		node* r = tmpHead,*l = tmpHead;
		while (r->next != nullptr) {
			if (--k<=0) {
				l = l->next;
			}
			r = r->next;
			
		}
		cout << l->val << endl;
	}

	delete tmpHead;
	return 0;
}