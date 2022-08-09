#include<iostream>
#include<string>
using namespace std;

void Swap(string& s, int i, int j) {
	char tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
}

int main() {
	string s;
	while (getline(cin,s)) {
		for (int i = 0, j = s.size() - 1; i <= j; i++, j--) {
			Swap(s, i, j);
		}
		cout << s << endl;
	}

	return 0;
}