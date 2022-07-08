#include<iostream>
#include<map>
using namespace std;

int main() {
	int N;
	while (cin >> N) {
		map<int, int> map;
		int k, v;
		for (int i = 0; i < N; i++) {
			cin >> k >> v;
			//if (map.find(k) != map.end()) {
				map[k] += v;
			//}
			//else {
			//	map[k] = v;
			//}
		}

		for (auto it : map) {
			cout << it.first << " " << it.second << endl;
		}
	
	}


	return 0;
}