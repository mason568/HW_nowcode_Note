#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

double solution(double b) {
	double a = 0.0;
	if (b == 0 || b == 1 || b == -1) return b;
	//确定起始左右区间
	double left = b > 0 ? min(b, 1.0) : min(b, -1.0);
	double right = b > 0 ? max(b, 1.0) : max(b, -1.0);
	//保留一位小数,0.1;那么我们的精度比这高就好 abs(b_t-b)<0.01就返回

	while (abs(left - right) > 0.01) {
		a = (left + right) / 2;
		if (a * a * a > b) {
			right = a;
		}
		else if (a * a * a == b) {
			break;
		}
		else {
			left = a;
		}
	}
	return a;
}

int main() {
	double b;
	while (cin >> b) {
		cout << fixed << setprecision(1) << solution(b) << endl;
	}

}