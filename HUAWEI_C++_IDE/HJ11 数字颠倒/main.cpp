#include<iostream>
#include<string>
using namespace std;

int main() {
	int num;
	while (cin >> num) {
		if (num == 0) cout << 0 << endl;
		string res;
		while ( num >0 ) {
			res.append(to_string(num % 10));
			num /= 10;
		}
		//res = res+"asdas";
		cout << res << endl;
		
	}

	return 0;
}