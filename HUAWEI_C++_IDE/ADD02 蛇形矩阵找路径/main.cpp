#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

//i,j   i奇数 val = 4（i+1）- (j+1)  i偶数 val = 4i+j 
bool flag;
int n, m;
int cnt = 0;
int caculate_cal(int i, int j) {
	if (i % 2 == 0) {
		return m * i + j;
	}
	else {
		return m * (i + 1) - (j + 1);
	}
}

void backtracing(vector<vector<char>>& matrix, string target, vector<vector<bool>>& used, int step, int i, int j, vector<pair<int, int>>& path, int& ret) {

	if (step < target.size()) {

		if (target[step] == matrix[i][j]) {
			step += 1;
			path.push_back(make_pair(i, j));
			used[i][j] = true;
			if (step == target.size()) {

				cnt += 1;
				for (auto p : path) {
					ret += caculate_cal(p.first, p.second);
					flag = true;
				}
				step -= 1;
				used[i][j] = false;
				path.pop_back();
				return;
			}
			//dfs上下左右
			if (i - 1 >= 0 && used[i - 1][j] == false) {

				backtracing(matrix, target, used, step, i - 1, j, path, ret);

			}

			if (i + 1 < n && used[i + 1][j] == false) {

				backtracing(matrix, target, used, step, i + 1, j, path, ret);

			}


			if (j - 1 > 0 && used[i][j - 1] == false) {

				backtracing(matrix, target, used, step, i, j - 1, path, ret);

			}

			if (j + 1 < m && used[i][j + 1] == false) {

				backtracing(matrix, target, used, step, i, j + 1, path, ret);

			}
			//回溯
			used[i][j] = false;
			path.pop_back();
			step -= 1;
		}
		else return;

	}

}

int main() {
	string snakes;

	while (cin >> snakes) {
		cin >> m;
		int matrix_size = snakes.size();
		n = matrix_size / m;
		vector<vector<char>> matrix(n, vector<char>(m));
		int pos = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i % 2) {
					matrix[i][m - 1 - j] = snakes[pos++];
				}
				else {
					matrix[i][j] = snakes[pos++];
				}
			}
		}

		string sub;
		cin >> sub;
		flag = false;

		int ret = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				vector<pair<int, int>> path;
				vector<vector<bool>> used(n, vector<bool>(m, false));
				backtracing(matrix, sub, used, 0, i, j, path, ret);
			}
		}
		if (flag) {
			cout << ret << endl;
			flag = false;
		}
		else {
			cout << -1 << endl;
		}


	}
	return 0;
}

