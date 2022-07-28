#include<iostream>
#include<vector>
#include<queue>
#include"assert.h"
using namespace std;

//直接模拟
#if 0
int main() {
	int n;
	string ops;
	while (cin >> n >> ops) {
		vector<int> dialog(n);
		for (int i = 0; i < n; i++) dialog[i] = i + 1;
		int it = 0;
		int len = n > 4 ? 4 : n;
		vector<int> screen(len);
		for (int j = 0; j < len; j++) screen[j] = j+1;
		if (len >= 4) {
			for (int i = 0; i < ops.size(); i++) {
				char op = ops[i];
				assert(op == 'U' || op == 'D');
				if (op == 'U') {
					if (it == 0 && screen[0] == 1) {
						it = len - 1;
						for (int j = 0; j < 4; j++) screen[j] += n - len;
					}
					else if (it == 0 && screen[0] > 1) {
						it = 0;
						for (int j = 0; j < 4; j++) screen[j] -= 1;
					}
					else {
						it--;
					}
				}
				else {
					if (it == 3 && screen[3] == n) {
						it = 0;
						for (int j = 0; j < 4; j++) screen[j] -= n - 4;
					}
					else if (it == 3 && screen[0] < n) {
						it = 3;
						for (int j = 0; j < 4; j++) screen[j] += 1;
					}
					else {
						it++;
					}

				}
			}
		}
		else {
			for (int i = 0; i < ops.size(); i++) {
				char op = ops[i];
				assert(op == 'U' || op == 'D');
				if (op == 'U') {
					if (it == 0 ) {
						it = len - 1;
					}
					else {
						it--;
					}
				}
				else {
					if (it == len-1 ) {
						it = 0;
					}
					else {
						it++;
					}

				}
			}
		}
		for (auto _ : screen) cout << _ << " ";
		cout << endl << screen[it] << endl;
	}

}
#endif
//滑动窗口

#if 1
int main() {
	int n;
	string commands;
	while (cin >> n >> commands) {
		int num = 1;//选中的歌曲
		int win_b = 1;//页面的起始
		int win_e = min(4, n);//页面的末位置 2
		for (int i = 0; i < commands.size(); i++) {
			if (commands[i] == 'U') {//向上移动一格
				num = (num - 1 - 1 + n) % n + 1;
			}
			else if (commands[i] == 'D') {//向下移动一格
				num = num % n + 1;
			}
			if (num < win_b) {//如果当前歌曲在窗口前，则将窗口往前移动
				win_b = num;
				win_e = win_b + 3;
			}
			else if (num > win_e) {//如果当前歌曲在窗口后，则将窗口往后移动
				win_e = num;
				win_b = win_e - 3;
			}
		}
		for (int i = win_b; i <= win_e; i++) {//输出当前页面
			cout << i << ' ';
		}
		cout << endl;
		cout << num << endl;//输出选中的歌曲
	}
	return 0;
}



#endif 