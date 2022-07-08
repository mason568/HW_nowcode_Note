#include<iostream>
#include<bitset>
using namespace std;

int hammingWeight(int num) {
//巧用 n & (n-1)  把复杂度将为 O(M) O(1)  P.S. n & (n-1) 还可以用来判断n是不是2的幂，M是汉明重 一般可以说成是O(log n)算法，最坏情况为O(N)
	int res = 0;
	while (num > 0) {
		res += 1;
		num = num & (num - 1);
	}
	return res;
}


int main() {
	int num;
	while (cin >> num) {
		//cout << ((bitset<32>)num).count() << endl; //#include<bitset>
		//cout << hammingWeight(num)<<endl; //使用自定义函数计算汉明重
		
		//trivial算法
		int count = 0;
		while (num > 0) {
			count += num % 2;
			num = num >> 1;
		}
		cout << count << endl;
	}
	return 0;
}