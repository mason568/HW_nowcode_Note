#include<iostream>
#include<vector>
#include<string>
#include"assert.h"
#include<limits.h>
using namespace std;


string And = "and";
string key_words[4] = { "hundred","thousand","million","billion" };
string num_words[20] = { "zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen" };//0-19
string tens_words[10] = { "","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};


void long_2_ints(vector<int>& nums, long n) {
	while (n) {
		int tmp = n % 1000;
		nums.push_back(tmp);
		n = n / 1000;
	}
}

string num_2_words(int num) {
	assert(num >= 0 && num < 1000);
	if (num >= 0 && num <= 19) return num_words[num] + " ";
	int hunds = num/100, tens = (num%100) / 10, ones = num % 10;
	string res = "";
	if(hunds >0) res += num_words[hunds] + " " + key_words[0] + " ";
	int cutnum = num % 100;
	if (cutnum) {
		if (hunds > 0) res +=   And + " ";
		if (cutnum > 0 && cutnum <= 19) {
			res += num_words[cutnum] + " ";
			return res;
		} 
		else {
			if (tens) res +=  tens_words[tens] + " ";
			if (ones) res +=  num_words[ones] + " ";
		}

	}
	return res;
}

int main() {
	long n;
	//cout << LONG_MAX << endl;
	while (cin >> n) {
		assert(n <= LONG_MAX);//2,000,000,000
		string res = "";
		vector<int> nums;
		//cout << num_2_words(n % 1000) << endl;
		long_2_ints(nums, n);
		int cnt = 0;
		for (auto num : nums) {
			string sub = num_2_words(num);
			if (cnt > 0 && cnt < 4) {
				res = sub + key_words[cnt]+ " " + res;
			}
			else {
				res = sub;
			}
			cnt++;
		}
		cout << res << endl;
	}

}