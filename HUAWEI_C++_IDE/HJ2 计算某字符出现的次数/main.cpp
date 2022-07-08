#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
/*hash*/
#if 0
int main(){
	char ch;
	unordered_map<char, int> map;
	do {
		ch = toupper(getchar());
		map[ch]++;
	} while(ch != '\n');
	char a = toupper(getchar());
	if (map.find(a) != map.end()) {
		cout << map[a] << endl;
	}
	else {
		cout << "0" << endl;
	}

	return 0;
}
#endif

#if 0
int main() {
	string s ;
	char c;
	getline(cin, s) >> c;
	
	//cout << s << " - " << c << endl;
	unordered_map<char, int> map;
	for (auto ch : s) {
		map[tolower(ch)]++;
	}
	cout << map[tolower(c)] << endl;
	return 0;
}
#endif

/*counter 最快的方法*/
int main() {
	
	string s;
	getline(cin, s);
	char ch = tolower(getchar());
	int n = 0;
	for (auto c : s) {
		if (tolower(c) == ch) n++;
	}
	cout << n << endl;

	return 0;
}