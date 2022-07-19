#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<string>
using namespace std;

void check_r_belongto_I(int r, vector<int>& I, map<int, int>& key_val) {
	// 遍历I中每一个元素 检查是否包含了r这个数 数字不好判断，转字符串 因为数字判断，取余不好做r=3 however 6%3=0 
	string r_s = to_string(r);
	for (int i = 0; i < I.size(); i++) {
		string i_s = to_string(I[i]);
		if (i_s.find(r_s)!=string::npos) {
			key_val.emplace(i, I[i]);
		}
	}
}

int main() {
	//输入
	int I_size, R_size, tmp;
	vector<int> I;
	set<int> R;
	cin >> I_size;
	
	vector<int> res;//输出数组
	for (int i = 0; i < I_size; i++) {
		cin >> tmp;
		I.push_back(tmp);
	}
	cin >> R_size;
	for (int i = 0; i < R_size; i++) {
		cin >> tmp;
		R.insert(tmp);
	}

	//遍历$r \in R$，检测I中包含r的元素 写成函数
	set<int>::iterator r;
	for (r = R.begin(); r != R.end(); r++) {
		map<int, int> key_val;
		check_r_belongto_I(*r, I, key_val);
		//把返回的东西加入到输出数组中
		if (key_val.size() > 0) {
			// 先输出R[i]
			res.push_back(*r);
			//再输出满足条件的I的个数
			res.push_back(key_val.size());
			//依次输出key_val中元素
			for (auto k_v : key_val) {
				res.push_back(k_v.first);
				res.push_back(k_v.second);
			}
		}
	}

	int count = res.size();//输出数组的所有元素的个数
	res.insert(res.begin(), count);
	for (auto i : res) {
		cout << i << " ";
	}
	cout << endl;
	

	return 0;
}