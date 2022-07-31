#include<iostream>
#include<string>
#include<vector>

using namespace std;
vector<int> getNext(string s) {
	vector<int> next(s.size());
	int val = -1;//当前最长相等前后缀长度（-1），初始化为-1，因为一个字符没有前缀也没有后缀
	//最关键理解val的意义，从下面for循环中next[i]=val;知道，val是一个中间状态，他存的是当前最长相等前后缀长度-1，并且每匹配一个字符后，要更新它的值
	next[0] = val;
	for (int i = 1; i < s.size(); i++) {
		while (val >= 0 && s[i] != s[val + 1]) {
			val = next[val];//看看在之前字符串的最长相等前后缀为val-1的基础上，添加一个字符是不是前后缀还相等，如果不为相等的前后缀，那么就要回退到上一个比当前短一点点的字符串判断是不是添加一个字符后为相等如果还不是，继续回退，要么找到了一个短一截的相等前后缀，要么直到退不动了val=-1退出while循环，
		}
		//看看在之前字符串的最长相等前后缀为val-1的基础上，添加一个字符是不是前后缀还相等，如果是，那么val 更新为 val+1
		if (s[i] == s[val + 1]) {
			val++;
		}
		//更新val
		next[i] = val;
	}
	return next;
}

int main() {
	string S, T;
	while (cin >> S >> T) {
		if (S.size() > T.size()) continue;
		vector<int> next = getNext(S);
		int j = -1;
		bool flag = false;
		for (int i = 0; i < T.size(); i++) {
			//和之前的思路一样，不匹配的话就要找上一个位置
			while (j >= 0 && T[i] != S[j + 1]) {
				j = next[j];
			}
			if (T[i] == S[j + 1]) {
				j++;
			}
			if (j == (S.size() - 1)) {
				flag = true;
				break;
			}
		}
		if (flag) cout << "true" << endl;
		else cout << "false" << endl;
	
		
	}

	return 0;
}