#include<iostream>
#include<vector>
#include"assert.h"

using namespace std;

int main() {
	int x, y, z;
	while (cin >> x >> y >> z) {
		vector<vector<int>> A(x, vector<int>(y));
		vector<vector<int>> B(y, vector<int>(z));
		vector<vector<int>> C(x, vector<int>(z));
		int t;
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				cin >> t;
				A[i][j] = t;
			}
		}

		for (int i = 0; i < y; i++) {
			for (int j = 0; j < z; j++) {
				cin >> t;
				B[i][j] = t;
			}
		}

		//º∆À„æÿ’Û≥À∑®C=A*B
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < z; j++) {
				int sum = 0;
				for (int k = 0; k < y; k++) {
					sum += A[i][k] * B[k][j];
				}
				C[i][j] = sum;
			}
		}

		// ‰≥ˆ
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < z; j++) {
				cout << C[i][j] << " ";
			}
			cout << endl;
		}

	}


	return 0;
}