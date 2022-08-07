#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;


//红白小球，记为RW字符串
//交换小球位置使得红球们连续在一起
//只能交换相邻的两个球
//球最小的交换次数

int count_RW_pair(string& s, int left, int right) {
	int res = 0;
	for (int i = left; i < right; i++) {
		for (int j = i; j < right; j++) {
			if (s[j] == 'W' && s[i]=='R') {
				res++;
			}
		}
	}
	return res;
}
int count_WR_pair(string& s, int left, int right) {
	int res = 0;
	for (int i = left; i < right; i++) {
		for (int j = i; j < right; j++) {
			if (s[j] == 'R' && s[i] == 'W') {
				res++;
			}
		}
	}
	return res;
}
int main() {
	//string s = "WRRWRW";
	//string s = "WWRWWWRWR";
	//string s = "WWW";
	//string s = "WR";
	string s = "WWRWWWRWRRRRRRWWWR";
	int ret = -1;
	int r = s.size() - 1, l = 0;
	vector<pair<int, int>> R_pos;
	int count = 0;
	for (int i = 0; i < s.size(); i++) {
		
		if (s[i] == 'R') {
			R_pos.push_back(make_pair(count,i));
			count++;
		} 
	}
	
	int swaps = 0;
	if (R_pos.size() == 0) ret= 0;
	else if (R_pos.size() == 1 && (s[0] == 'R' || s[s.size() - 1] == 'R')) ret = -1;
	else if (R_pos.size() == 1) ret = 0;
	else {
		int mid = R_pos[count / 2].second;
		int count_RW_left = 0, count_RW_right = 0;
		count_RW_left = count_RW_pair(s, 0, mid);
		count_RW_right = count_WR_pair(s, mid+1,s.size());
		ret = count_RW_right + count_RW_left;
		ret = ret > pow(10, 9) ? -1 : ret;
	}
	cout << ret << endl;
	return 0;
}