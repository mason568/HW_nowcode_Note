#include<iostream>

#include<vector>

using namespace std;
int main() {
	int n;
	while (cin >> n) {
		if (n <= 2) {
			cout << "-1" << endl;
			continue;
		}
		int tmp = (n - 2) % 4;
		switch (tmp) {
			case 1:cout << "2" << endl; break;
			case 2:cout << "3" << endl; break;
			case 3:cout << "2" << endl; break;
			case 0:cout << "4" << endl; break;
		}
		/*
		vector<vector<int>> res;
		res.push_back({ 1 });
		res.push_back({ 1,1,1 });
		cout << "-1" << endl;
		cout << "-1" << endl;
		for (int i = 2; i < n; i++) {
			vector<int> tmp;
			tmp.push_back(1);
			tmp.push_back(res[i-1][0]+ res[i - 1][1]);
			for (int j = 2; j < 2 * i - 1; j++) {
				
				tmp.push_back(res[i - 1][j-2] + res[i - 1][j-1] + res[i - 1][j]);
			}
			tmp.push_back(tmp[1]);
			tmp.push_back(tmp[0]);
			res.push_back(tmp);
			
			for (int t = 0; t < tmp.size(); t++) {
				if (tmp[t] % 2 == 0) {
					cout << t+1 << endl;
					break;
				}
			}

		}

		*/
		
		
	}
	return 0;
}