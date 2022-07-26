#include<iostream>
using namespace std;

#if 1
int main() {
	int n;
	while (cin >> n) {
		int A = 1, B = 0, C = 0;//初始化一个月的兔子为1 B=C=0分别是两个月、三个月及以上的兔子
		//从第二个月开始起
		for (int i = 1; i < n; i++) {
			//int tmp = C;
			C = C + B;
			B = A;
			A = C;
			//结束每个月 如5的话，循环体循环4次
		}

		cout << (A + B + C) << endl;
	}
	return 0;
}
#endif
