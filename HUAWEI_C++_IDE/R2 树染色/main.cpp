#include<vector>
#include<iostream>
#include<unordered_map>
#include<set>
using namespace std;
int N;
unordered_map<int, vector<int>> m;
unordered_map<int, char> color;

vector<int> outside;
vector<int> inside;
int in_size;
bool flag;

bool check(vector<int>& inside, unordered_map<int, vector<int>>& m, unordered_map<int, char> &color) {
	
	for (auto node : inside) {
		set<char> cntRGB;
		for (auto sub : m[node])
			cntRGB.insert(color[sub]);
		if (cntRGB.size() < 2) return false;
	}
	return true;
}

void dfs(int step) {
	//ÅÐ¶ÏÊÇ·ñÂú×ãÌõ¼þ

	if (step == N + 1) {
		if (check(inside, m, color)) {
			flag = true;

			return;
		}
	}

	if(step< in_size){
		for (int i = 0; i < inside.size(); i++) {
			if (color[inside[i]] == '*') {
				color[inside[i]] = 'R';
				dfs(step++);
				color[inside[i]] = 'G';
				dfs(step++);
				color[inside[i]] = 'B';
				dfs(step++);
				color[inside[i]] = '*';
			}
		}
	}
	else {
		for (int i = 0; i < outside.size(); i++) {
			if (color[outside[i]] == '*') {
				color[outside[i]] = 'R';
				dfs(step++);
				color[outside[i]] = 'G';
				dfs(step++);
				color[outside[i]] = 'B';
				dfs(step++);
				color[outside[i]] = '*';
			}
		}
	
	}

}


int main() {
	
	
	while (cin >> N) {
		unordered_map<int, vector<int>> m;
		unordered_map<int, char> color;
		flag = false;
		for (int i = 1; i <= N; i++) {
			color[i] = '*';
		}
		int u, v;
		for(int i=0;i<N-1;i++){
			cin >> u >> v;
			m[u].push_back(v);
			m[v].push_back(u);
		}

		

		for (auto i : m) {
			if (i.second.size() == 1) {
				outside.push_back(i.first);
			}
			else {
				inside.push_back(i.first);
			}
		}
		in_size = inside.size();

		dfs(0);

		cout << endl;
	
	}

}