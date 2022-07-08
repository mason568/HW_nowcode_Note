#include<iostream>
#include<string>
#include<vector>
using namespace std;


//字符串中的某一个字串全替换为另一个串
string& replace_all(string& src, const string& old_value, const string& new_value) {
	// 每次重新定位起始位置，防止上轮替换后的字符串形成新的old_value
	for (string::size_type pos(0); pos != string::npos; pos += new_value.length()) {
		if ((pos = src.find(old_value, pos)) != string::npos) {
			src.replace(pos, old_value.length(), new_value);
		}
		else break;
	}
	return src;

}

#if 0
//string substr ( size_t pos = 0, size_t n = npos ) const; 获取子字符串
int main() {
	string s;

	while (getline(cin, s)) {
		int pos = 0;
		vector<string> res;
		//处理整除
		while (pos + 8 < s.size()) {
			string sub = s.substr(pos,8);
			res.push_back(sub);
			pos += 8;
		}

		//处理剩下不够整除字符串
		//int l = s.size() - pos;
		string sub = s.substr(pos, s.size());
		string sub_end(8-sub.size(), '0');
		sub += sub_end;
//		sub = editstr(sub);
		res.push_back(sub);

		for (auto strs : res) {
			cout << strs << endl;
		}
	}
	
	
	
	
	return 0;
}

#endif

#if 0
//进行一个cout之光的沾
//使用输入输出标准库自带的功能。使用cout对象的成员函数width()指定输出域宽，使用成员函数fill()指定填充字符，使用流操纵符left指定左对齐。
//注意，即使str剩余的字符串长度不足8，str.substr(0, 8)也能正常获取剩余的字符，不会报错。
int main()
{
	string str;
	while (cin >> str)
	{
		int len = str.size();
		for (int i = 0; i < len; i += 8)
		{
		
			cout.width(8);
			cout.fill('0');
			cout << left << str.substr(i, 8) << endl;

			
		}
	}
	return 0;
}
#endif

#if 1
int main()
{
	string str;
	string str1;
	int num;
	char ch;
	ch=cin.get();
	cout << ch << endl;

	

	return 0;
}
#endif