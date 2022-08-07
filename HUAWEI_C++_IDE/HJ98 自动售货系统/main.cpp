#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include<sstream>
#include"assert.h"
#include<regex>
using namespace std;

class Auto_Sale {



public:
	Auto_Sale(vector<int>& nums) {
		assert(nums.size() == 10);
		goods["A1"] = nums[0];
		goods["A2"] = nums[1];
		goods["A3"] = nums[2];
		goods["A4"] = nums[3];
		goods["A5"] = nums[4];
		goods["A6"] = nums[5];
		bank[1] = nums[6];
		bank[2] = nums[7];
		bank[5] = nums[8];
		bank[10] = nums[9];
		balance = 0;
		prices["A1"] = 2;
		prices["A2"] = 3;
		prices["A3"] = 4;
		prices["A4"] = 5;
		prices["A5"] = 8;
		prices["A6"] = 6;
		cout << errorcode[0] << endl;
	}

	~Auto_Sale() {}
	void Auto_Sale_init(vector<int>& nums) {
		assert(nums.size() == 10);
		goods["A1"] = nums[0];
		goods["A2"] = nums[1];
		goods["A3"] = nums[2];
		goods["A4"] = nums[3];
		goods["A5"] = nums[4];
		goods["A6"] = nums[5];
		bank[1] = nums[6];
		bank[2] = nums[7];
		bank[5] = nums[8];
		bank[10] = nums[9];
		balance = 0;
		prices["A1"] = 2;
		prices["A2"] = 3;
		prices["A3"] = 4;
		prices["A4"] = 5;
		prices["A5"] = 8;
		prices["A6"] = 6;
		cout << errorcode[0] << endl;
	}
	Auto_Sale(int a1, int a2, int a3, int a4, int a5, int a6, int m1, int m2, int m5, int m10 ) {
		goods["A1"] = a1;
		goods["A2"] = a2;
		goods["A3"] = a3;
		goods["A4"] = a4;
		goods["A5"] = a5;
		goods["A6"] = a6;
		bank[1]=m1;
		bank[2] = m2;
		bank[5] = m5;
		bank[10] = m10;
		balance = 0;
		prices["A1"] = 2;
		prices["A2"] = 3;
		prices["A3"] = 4;
		prices["A4"] = 5;
		prices["A5"] = 8;
		prices["A6"] = 6;
		cout << errorcode[0] << endl;
	}


	
	//投币
	void put(int m) {
		if (bank.find(m) == bank.end()) {
			cout << errorcode[3] << endl;
		}
		else if ((bank[1] + 2 * bank[2]) < m) {
			cout << errorcode[4] << endl;
		}
		else if (this->isempty()) {
			cout << errorcode[5] << endl;
		}
		else {
			bank[m]++;
			balance += m;
			cout << errorcode[1] << balance <<endl;
		}
	}
	//买东西
	void buy(string str) {
		if (goods.find(str) == goods.end()) {
			cout << errorcode[6] << endl;
		}
		else if (goods[str]==0) {
			cout << errorcode[7] << endl;
		}
		else if (balance<prices[str]) {
			cout << errorcode[8] << endl;
		}
		else {
			//bank[m]++;
			balance -= prices[str];
			goods[str]--;
			cout << errorcode[2] << balance << endl;
		}
	
	}
	//退币
	void withdrawal() {
		if (balance == 0) cout << errorcode[9] << endl;
		else {
			//退币规则
			unordered_map<int, int> wd = { {1,0},{2,0},{5,0},{10,0}};
			//从一组数中找到最小的子序列使得和为balance,找不到就递归balance-1
			while (balance > 0) {
				if (balance >= 10 && bank[10] > 0) {
					balance -= 10;
					bank[10]--;
					wd[10]++;
				}else if (balance >= 5 && bank[5] > 0) {
					balance -= 5;
					bank[5]--;
					wd[5]++;
				}
				else if (balance >= 2 && bank[2] > 0) {
					balance -= 2;
					bank[2]--;
					wd[2]++;
				}
				else if (balance >= 1 && bank[1] > 0) {
					balance -= 1;
					bank[1]--;
					wd[1]++;
				}
				else {
					balance -= 1;
				}

			}
			//输出

			cout << "1 yuan coin number=" << wd[1] << endl;
			cout << "2 yuan coin number=" << wd[2] << endl;
			cout << "5 yuan coin number=" << wd[5] << endl;
			cout << "10 yuan coin number=" << wd[10] << endl;
		}
	}
	bool cmp(pair<string, int> lhs, pair<string, int> rhs) {
		return lhs.second > rhs.second;
	}
	//查询
	void querry(int q_code) {
		if (q_code == 0) {
			unordered_map<string, int> tmp_goods(goods);
			//stable_sort(tmp_goods.begin(), tmp_goods.end());  //排序还没写啊 
			for (auto good : tmp_goods) {
				cout << good.first << " " << prices[good.first] << " " << good.second << endl;
			}
		}
		else if (q_code == 1) {
			cout << "1 yuan coin number=" << bank[0] << endl;
			cout << "2 yuan coin number=" << bank[1] << endl;
			cout << "5 yuan coin number=" << bank[2] << endl;
			cout << "10 yuan coin number=" << bank[3] << endl;
		}
		else {
			cout << this->errorcode[10] << endl;
		}
	}

	bool isempty() {
		for (auto i : goods) {
			if (i.second != 0) return false;
		}
		return true;
	}


	unordered_map<string, int> goods;
	unordered_map<string, int> prices;
	unordered_map<int,int> bank;
	int balance = 0;
	vector<string> errorcode = {
	"S001:Initialization is successful",
	"S002:Pay success,balance=",
	"S003:Buy success,balance=",
	"E002:Denomination error",
	"E003:Change is not enough, pay fail",
	"E005:All the goods sold out",
	"E006:Goods does not exist",
	"E007:The goods sold out",
	"E008:Lack of balance",
	"E009:Work failure",
	"E010:Parameter error"
	};


};





int main() {

	//Auto_Sale* SALE;// = new Auto_Sale();
	Auto_Sale* SALE = nullptr;
	string s;
	while (getline(cin, s)) {
		string sub;
		int begin = 0;

		for (int pos = 0; pos < s.size(); pos++) {
			if (s[pos]==';')
			{
				sub = s.substr(begin, pos - begin);
				//dooperation
				//cout << sub << endl;
				if (sub[0] == 'r') {
					sub = sub.substr(2);
				//初始化
					vector<int> nums;
					//stringstream ss(sub);
					string t;

					regex patten("(\\s+)");
					sub = regex_replace(sub, patten, "-");
					stringstream ss(sub);
					for (int i = 0; i < 10; i++) {
						getline(ss, t, '-');
						nums.push_back(stoi(t));
					}
					//SALE->Auto_Sale_init(nums);
					 SALE = new Auto_Sale(nums);
				}
				else if(sub[0] == 'c'){
					SALE->withdrawal();
				}
				else if (sub[0] == 'p') {
					SALE->put(stoi(sub.substr(2)));
				}
				else if (sub[0] == 'b') {
					SALE->buy(sub.substr(2));
				}
				else if (sub[0] == 'q') {
					if (sub.size() != 3) {
						SALE->querry(-1);
					}
					else {
						SALE->querry(stoi(sub.substr(2)));
					}
					
				}

				begin = pos + 1;
			}
		}
		
		

		
	}

	delete SALE;
}