#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

unsigned int solution(unsigned int a, unsigned int b) {
	int i = 1, j = 1;
	while (a * i != b * j) {
		if (a * i < b * j) i++;
		else j++;
	}
	return a * i;

	
}

inline int GCD2(int a, int b) {
	return b > 0 ? GCD2(b, a % b) : a;
}

int main() {
	unsigned int a,b;
	while (cin >> a>>b) {
		int g = GCD2(a, b);
		cout <<  solution(a,b) << endl;
		cout << a*b/g << endl;
	}

}