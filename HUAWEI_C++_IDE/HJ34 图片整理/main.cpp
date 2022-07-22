#include <iostream>
#include <string>
#include <algorithm>
#include"time.h"
using  namespace std;

void qucik_sort(string& s, int left, int right) {
	if (s == "") return;
	if (left >= right) return;
	srand((unsigned)time(NULL));
	int len = right - left;
	int kindex = left + rand() % (len + 1);
	swap(s[left],s[kindex]);

	int key = s[left];
	int i = left, j = right;
	while (i < j) {
		while (s[j] >= key && i < j) --j;
		if (i < j)s[i] = s[j];//从j往左把遇到的第一个小于哨兵的数往前扔，哨兵被覆盖，但是备份到key了  被扔的这个位置就空出来了
		while (s[i] < key && i < j) ++i;
		if (i < j) s[j] = s[i];//从i往右把遇到的第一个大于等于哨兵的数往刚刚空出的位置加塞，这时候的这个位置s[i]其实是需要放一个元素进来的（如果有比哨兵小的当然好，实在找不到了,把备份的哨兵放进来）
	}

	s[i] = key;
	qucik_sort(s, left, i - 1);
	qucik_sort(s, j + 1, right);
}


int main() {
	string s;
	while (cin >> s) {
		qucik_sort(s,0,s.size()-1);



		cout << s << endl;
	}
}