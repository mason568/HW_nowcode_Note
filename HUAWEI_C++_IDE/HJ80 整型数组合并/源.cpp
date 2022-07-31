#include<iostream>
#include<set>
#include<string>
using namespace std;

int main() {
	int size1, size2,t;
	while (cin >> size1) {
		set<int> nums;
		for (int i = 0; i < size1; i++) {
			cin >> t;
			nums.insert(t);
		}
		cin >> size2;
		for (int i = 0; i < size2; i++) {
			cin >> t;
			nums.insert(t);
		}
		string res = "";
		for (auto num : nums) {
			res += to_string(num);
		}
		cout << res << endl;
	}
	return 0;
}