#include<iostream>
#include<vector>
#include"assert.h"
#include<sstream>
#include<string>
using namespace std;
int main() {

	vector<int> nums;
	string s = "aaa-2asdjh";
	cout << stoi(s.substr(3)) << endl;


	return 0;
}