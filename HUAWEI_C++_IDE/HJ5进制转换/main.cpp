#include<iostream>
#include<string>
#include<cmath>
using namespace std;

//输入输出流控制
int main() {
	int res = 0;
	while (cin >> hex >> res)  //hex表示读入十六进制数
		cout << dec << res << endl; //dec表示输出十进制数
	return 0;
}


#if 0
//使用字符串类型转换接口  stoi
int main() {
	string str;
	while (cin >> str) {
		cout << stoi(str,nullptr,0) << endl;
	}

	return 0;
}
#endif


//自己实现stoi
#if 0
int main() {
	string str;
	while (cin >> str) {
		int pow_up_num = 0;
		int res = 0;
		for (int i = str.size() - 1; i > 1; i --) {
			if(str[i] >= '0' && str[i] <= '9')
			{
				res += (str[i] - '0') * pow(16, pow_up_num);
				pow_up_num++;
			}
			else if(str[i] >= 'A' && str[i] <= 'F'){
				res += (str[i] - 'A'+10) * pow(16, pow_up_num);
				pow_up_num++;
			}
			else if (str[i] >= 'a' && str[i] <= 'f') {
				res += (str[i] - 'a'+10) * pow(16, pow_up_num);
				pow_up_num++;
			}
			else {
				cout << "error input!" << endl;
				exit(-1);
			}
		}
		cout << res << endl;

	}

	return 0;
}

#endif