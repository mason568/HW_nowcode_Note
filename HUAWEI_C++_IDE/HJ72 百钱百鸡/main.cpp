#include<iostream>

using namespace std;

int main() {
	int ok;
	while (cin >> ok) {
		//数学式判断后，鸡公数量a一定是4的倍数，且小于等于20
		//鸡母数量b = 25 - (7*a)/4 > 0 
		//小鸡数量c = 100 +a -b
		//所以a只能取 0 4 8 12 （16就不能取了，因为 25 - 28 = -3< 0
		for (int k = 0; k <= 3; k++) {
			int a = 4 * k;
			int b = 25 - (7 * a) / 4;
			int c = 100 - a - b;
			cout << a << " " << b << " " << c << endl;
		}

	}
	return 0;
}

//当然，还可以用暴力破解，O(n^3)复杂度 
//for a [0,20]
	//for b [0,33]
		//for c [0,100]
			//if(a+b+c==100 && (5*a + 3*b + c/3 ==100))