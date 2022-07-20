#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//字母异位词 hash表 假设只有小写字母
bool is_bro(string a, string b) {
	if (a == b) return false;
	if (a.size() != b.size()) return false;
	int count[26] = { 0 };
	for (int i = 0; i < a.size(); i++) {
		count[a[i] - 'a']++;
		count[b[i] - 'a']--;
	}
	for (int i = 0; i < 26; i++) {
		if (count[i] != 0) return false;
	}
	return true;

}

void find_bro(string x, vector<string>& dict, vector<string>& bros) {
	for (auto s : dict) {
		if (is_bro(s,x)) {
			bros.push_back(s);
		}
	}
	sort(bros.begin(),bros.end());
}

int main() {
	int N;
	while (cin >> N) {
		//输入
		vector<string> dict;
		string tmp,x;
		int k;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			dict.push_back(tmp);
		}
		cin >> x >> k;
		//兄弟单词就是单词打乱顺序后的词，且必不相同
		//找到单词x的兄弟单词,并且排出字典序
		vector<string> bros;
		find_bro(x, dict, bros);
		cout << bros.size() << endl;
		if (bros.size() >= k) {
			cout << bros[k - 1] << endl;
		}
	}


	return 0;
}