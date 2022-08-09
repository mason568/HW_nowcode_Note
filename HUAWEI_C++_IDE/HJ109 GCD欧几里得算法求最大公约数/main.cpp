#include<iostream>

using namespace std;

inline int GCD(int a, int b) {
	int r;
	while (b > 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;

}

inline int GCD2(int a, int b) {
	return b > 0 ? GCD2(b,a%b): a;
}


int main() {
	int a, b;
	while (cin >> a >> b) {
		cout << GCD(a, b) << endl;
		cout << GCD2(a, b) << endl;
	}

}