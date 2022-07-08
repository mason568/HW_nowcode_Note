#include<iostream>
#include<vector>
using namespace std;


//质数分解定理 一个大于1的数其质数分解形式是唯一的。
int main() {

	int N;
	//vector<int> res;
	while (cin >> N) {
		if (N == 1) {
			cout << N << " " << N << endl;
		}
		
		for (int i = 2; i <= N / i; i++) {
			//M*能够整除i
			if (N % i == 0) {
				int cnt = 0;
				while (N % i == 0) {
					cnt++;
					//s.push_back(i);
					N /= i;
					//if (cnt) cout << i << " " << cnt << endl;
					if (cnt) cout << i << " ";
				}
			}
		}
		//if (N > 1) cout << N << " " << 1<< endl;
		if (N > 1) cout << N << endl;
	
	}

	return 0;
}
