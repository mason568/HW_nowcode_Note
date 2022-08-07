#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

int main() {
	int N, M;
	while (cin >> N) {
		map<string, int> m;
		vector<string> man;
		for (int i = 0; i < N; i++) {
			string conditate;
			cin >> conditate;
			m[conditate] = 0;
			man.push_back(conditate);
		}
		cin >> M;
		int Invalid = 0;
		for (int i = 0; i < M; i++) {
			string vote;
			cin >> vote;
			if (m.find(vote) != m.end()) m[vote]++;
			else Invalid++;
		}

		for (auto c : man) {
			cout << c << " : " << m[c] << endl;
		}
		cout << "Invalid : " << Invalid << endl;
	}

}