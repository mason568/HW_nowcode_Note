#include<iostream>
using namespace std;

#if 0
int main() {
	float a;

	while (cin >> a) {
		if (a > 0) {
			if (int(a * 2) >= (int(a) * 2 + 1)) {
				cout << int(a) + 1 << endl;
			}
			else {
				cout << int(a)<< endl;
			}
			
		}
	}

	return 0;
}
#endif

int main() {
	float a;

	while (cin >> a) {
		if (a > 0) {
			cout << int(a + 0.5) << endl;
		}
	}

	return 0;
}