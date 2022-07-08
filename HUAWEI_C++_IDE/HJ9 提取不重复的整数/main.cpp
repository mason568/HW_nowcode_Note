#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
	int num;
	while (cin >> num) {
		int map[10] = {0};
		//unordered_map<int, int> m;
		int res = 0;
		while (num > 0) {
			//map[num % 10] += 1;
			if (map[num % 10] == 0) {
				res = res * 10 + (num % 10);
				map[num % 10] += 1;
			}
			//m[num % 10] += 1;
			num /= 10;
		}
		/*
		for (int i = 0; i < 10;i++) {
			if (map[i] != 0) {
				res = res * 10 + i;
			}
		}
		*/
		/*
		for (auto it : m) {
			res = res * 10 + it.first;
		}
		*/
		cout << res << endl;
	
	}
	return 0;
}