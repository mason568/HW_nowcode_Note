#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
int main() {
	int N;
	while (cin >> N) {
		//vector<string> res;
		vector<string> s;
		for (int i = 0; i < N; i++) {
			string str;
			cin >> str;
			s.push_back(str);
		}
		sort(s.begin(), s.end());
		for (auto a : s) {
			cout << a << endl;
		}
	}


	return 0;
}