//先用欧拉法建立素数表
//再暴力破解
//也可以从中间开始缩小复杂度 双指针
#include<iostream>
#include<vector>
#include"assert.h"
using namespace std;



vector<int> buildPrims(int N) {
	assert(N >= 2);
	vector<int> primes(N);
	bool *table = new bool[N];
	memset(table, 1, N);
	table[0] = table[1] = false;
	int cnt = 0;
	for (int i = 2; i < N; i++) {
		if (table[i] == true) primes[cnt++] = i;
		for (int j = 0; j < N; j++) {
			if (i * primes[j] >= N)break;
			table[i * primes[j]] = false;
			if (i % primes[j] == 0) break;
		}
	}
	delete[]table;
	primes.resize(cnt);
	return primes; 
}
#if 0
int main() {
	int n;
	while (cin >> n) {
		assert(n % 2 == 0);
		vector<int> primes = buildPrims(n);
		
		int mid = n / 2;
		//找中间（最接近n一半）的两个素数
		int i=0, j= primes.size();
		for (int k = 0; k < primes.size(); k++) {
			if (primes[k] == mid) {
				i = j = k;
				break;
			}
			if (primes[k] > mid) {
				i = k - 1;
				j = k;
				break;
			}
		}
		while (i >= 0 && j < primes.size()&&i<=j) {
			if (primes[i] + primes[j] == n) {
				cout << primes[i] << " " << primes[j] << endl;
				break;
			}
			else if (primes[i] + primes[j] > n) {
				i--;
			}
			else {
				j++;
			}
		}
	}
	return 0;
}
#endif
bool isPrime(int num) {
	if (num <= 1) return false;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) return false;
	}
	return true;
}
//不建立质数表，每次确认是否为素数
#if 1
int main() {
	int n;
	while (cin >> n) {
		assert(n % 2 == 0);
		/*
		vector<int> primes = buildPrims(n);

		int mid = n / 2;
		//找中间（最接近n一半）的两个素数
		int i = 0, j = primes.size();
		for (int k = 0; k < primes.size(); k++) {
			if (primes[k] == mid) {
				i = j = k;
				break;
			}
			if (primes[k] > mid) {
				i = k - 1;
				j = k;
				break;
			}
		}
		*/
		int i = n / 2, j = n / 2;
		while (i >= 0 && j < n && i <= j) {
			if (isPrime(i) && isPrime(j) && i + j == n) {
				cout << i << " " << j << endl;
				break;
			}
			else if (i + j > n) {
				i--;
			}
			else {
				j++;
			}
		}
	}
	return 0;
}
#endif