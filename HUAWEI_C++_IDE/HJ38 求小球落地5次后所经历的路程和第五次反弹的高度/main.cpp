#include<iostream>
using namespace std;
int main() {
	double high;
	
	while (cin >> high) {
		double dist = 0.0;
		//求第五次到最高点时
		for (int i = 0; i < 5; i++) {
			dist += high * 1.5;
			high *= 0.5;
		}
		//第五次落地时要把路程减小目前高度为这么多

		cout << dist-high << endl << high << endl;
	}
	
	return 0;
}