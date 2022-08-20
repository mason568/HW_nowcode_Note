#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
//二叉树结构体
struct Treenode {
	int val;
	Treenode* left;
	Treenode* right;
	Treenode(int v) :val(v), left(nullptr), right(nullptr) {}
};

//DFS前中后序输出链表的元素到链表并打印
//前序遍历
void range_tree_flr(Treenode* cur, vector<int>& nums) {
	if (cur == nullptr) return;
	nums.push_back(cur->val);
	range_tree_flr(cur->left, nums);
	range_tree_flr(cur->right, nums);
}
//中序遍历
void range_tree_lfr(Treenode* cur, vector<int>& nums) {
	if (cur == nullptr) return;
	range_tree_lfr(cur->left, nums);
	nums.push_back(cur->val);
	range_tree_lfr(cur->right, nums);

}
//后序遍历
void range_tree_lrf(Treenode* cur, vector<int>& nums) {
	if (cur == nullptr) return;
	range_tree_lrf(cur->left, nums);
	range_tree_lrf(cur->right, nums);
	nums.push_back(cur->val);
}

//用一个链表创建二叉树
//给层序序遍历生成的列表  使用前序遍历来创建树
Treenode* buildtree_flr(vector<int> nums, int index) {
	Treenode* root = nullptr;
	if (index < nums.size()) {
		root = new Treenode(nums[index]);
		root->left = buildtree_flr(nums, 2 * index + 1);
		root->right = buildtree_flr(nums, 2 * index + 2);
	}
	return root;
}


//BFS层序遍历
void range_tree_bfs(Treenode* root, vector<vector<int>>& nums) {
	queue<Treenode*> queueNode;
	if (root != nullptr) queueNode.push(root);
	while (!queueNode.empty()) {
		int layer_size = queueNode.size();
		vector<int> layer_nums;
		for (int i = 0; i < layer_size; i++) {
			Treenode* tmp = queueNode.front();
			layer_nums.push_back(tmp->val);
			queueNode.pop();
			if (tmp->left) queueNode.push(tmp->left);
			if (tmp->right) queueNode.push(tmp->right);
		}
		nums.push_back(layer_nums);
	}
}


//二叉树的迭代遍历方式
//前序
vector<int> range_tree_stack_flr(Treenode* root) {
	stack<Treenode*> st;
	vector<int> ret;
	st.push(root);
	while (!st.empty()) {
		Treenode* tmp = st.top();
		st.pop();
		ret.push_back(tmp->val);
		if (tmp->right) st.push(tmp->right);
		if (tmp->left) st.push(tmp->left);
	}
	return ret;
}

//后序
vector<int> range_tree_stack_lrf(Treenode* root) {
	stack<Treenode*> st;
	vector<int> ret;
	st.push(root);
	while (!st.empty()) {
		Treenode* tmp = st.top();
		st.pop();
		ret.push_back(tmp->val);
		if (tmp->left) st.push(tmp->left);
		if (tmp->right) st.push(tmp->right);
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

//中序
vector<int> range_tree_stack_lfr(Treenode* root) {
	stack<Treenode*> st;
	vector<int> ret;
	Treenode* cur = root;
	while (cur != nullptr || !st.empty()) {
		//一直找到左叶子节点
		if (cur != nullptr) {
			st.push(cur);
			cur = cur->left;
		}
		else {
			//处理父节点
			cur = st.top();
			st.pop();
			ret.push_back(cur->val);
			//处理右儿子节点
			cur = cur->right;
		}
	}
	return ret;
}


//N叉树的结构体(类)与层序遍历与 给定边的 构建方法
//N叉树类定义
class Ntreenode {
public:
	int val;
	vector<Ntreenode*> children;
	Ntreenode() {}
	Ntreenode(int v) :val(v) {}
	Ntreenode(int v, vector<Ntreenode*> c) {
		val = v;
		children = c;
	}
};
//n叉树层序遍历
void range_Ntree_bfs(Ntreenode* root, vector<vector<int>>& nums) {
	if (root == nullptr) return;
	queue<Ntreenode*> que;
	que.push(root);
	while (!que.empty()) {
		int layersize = que.size();
		vector<int> layer_nums;
		for (int i = 0; i < layersize; i++) {
			Ntreenode* tmp_node = que.front();
			que.pop();
			layer_nums.push_back(tmp_node->val);
			for (int j = 0; j < tmp_node->children.size(); j++) {
				if (tmp_node->children[j]) que.push(tmp_node->children[j]);
			}
		}
		nums.push_back(layer_nums);
	}
}

//给定无序边，生成所有的关联集合
typedef pair<int, int> PAIR;
map<int, vector<int>> gene_edges(vector<pair<int, int>>& maps) {
	map<int, vector<int>> m;
	if (maps.empty()) return m;
	for (auto edge : maps) {
		m[edge.first].push_back(edge.second);
		m[edge.second].push_back(edge.first);
	}
	return m;
}




//给定无序边集合，构建以任意节点为根节点的一棵树
void buildtree(Ntreenode* root, map<int, vector<int>>& edge, vector<bool>& used) {
	for (int i = 0; i < edge[root->val].size(); i++) {
		if (0 == used[edge[root->val][i]]) {
			used[edge[root->val][i]] = 1;
			Ntreenode* son = new Ntreenode(edge[root->val][i]);
			root->children.push_back(son);
			buildtree(root->children[root->children.size() - 1], edge, used);
		}
	}
}

/*
	map<int, vector<int>> edge;
	for (int i = 0; i < N; i++) {
		edge[A[i]].push_back(B[i]);
		edge[B[i]].push_back(A[i]);
	}

	Ntreenode* root = new Ntreenode(0);
	vector<bool> used(N+1,false);
	used[0] = true;

	buildtree(root, edge, used);


*/






int main() {
	cout << "假设层序遍历的二叉树得到的列表是:" << endl;
	vector<int> Layer = { 1,2,4, };
	for (auto num : Layer) {
		cout << num << " ";
	}
	cout << endl;
	cout << "使用前序遍历方式来构造一棵树..." << endl;
	//用列表前序遍历构建一棵树，然后用前序遍历打印出来，用层序遍历打印出来
	Treenode* root_flr = buildtree_flr(Layer, 0);
	//dfs前序遍历
	cout << "前序遍历结果:" << endl;
	vector<int> L_flr;
	range_tree_flr(root_flr, L_flr);
	for (auto num : L_flr) {
		cout << num << " ";
	}
	cout << endl;
	//栈迭代前序遍历
	vector<int> L_stack_flr;
	L_stack_flr = range_tree_stack_flr(root_flr);
	for (auto num : L_stack_flr) {
		cout << num << " ";
	}
	cout << endl;
	//后序遍历+迭代后序遍历
	cout << "后序遍历结果:" << endl;
	vector<int> L_lrf;
	range_tree_lrf(root_flr, L_lrf);
	for (auto num : L_lrf) {
		cout << num << " ";
	}
	cout << endl;
	//栈迭代前序遍历
	vector<int> L_stack_lrf;
	L_stack_lrf = range_tree_stack_lrf(root_flr);
	for (auto num : L_stack_lrf) {
		cout << num << " ";
	}
	cout << endl;
	cout << "中序遍历结果:" << endl;
	//中序遍历+迭代中序遍历
	vector<int> L_lfr;
	range_tree_lfr(root_flr, L_lfr);
	for (auto num : L_lfr) {
		cout << num << " ";
	}
	cout << endl;
	//栈迭代前序遍历
	vector<int> L_stack_lfr;
	L_stack_lfr = range_tree_stack_lfr(root_flr);
	for (auto num : L_stack_lfr) {
		cout << num << " ";
	}
	cout << endl;



	cout << "层序遍历结果:" << endl;
	//层序遍历
	vector<vector<int>> layer_nums;
	range_tree_bfs(root_flr, layer_nums);
	for (auto layer : layer_nums) {
		for (auto num : layer) {
			cout << num << " ";
		}
	}
	cout << endl;
	layer_nums.clear();

	int N;
	int a, b;
	vector<PAIR> pairs;
	while (cin >> N) {
		Ntreenode* head = nullptr;

		map<int, bool> used;
		for (int i = 0; i < N; i++) {
			cin >> a >> b;
			pairs.push_back(make_pair(a, b));
			used[a] = false;
			used[b] = false;
		}
		map<int, vector<int>> edges = gene_edges(pairs);
		buildNtree_flr(head, edges, used);
		vector<vector<int>> nums4;
		range_Ntree_bfs(head, nums4);
		for (auto layer : nums4) {
			for (auto num : layer) {
				cout << num << " ";
			}
		}
		cout << endl;
		nums4.clear();
	}


	return 0;
}




