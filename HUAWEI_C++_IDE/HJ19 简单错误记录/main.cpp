#include<iostream>
#include<string>
#include<map>
#include<deque>
#include<vector>
#include<sstream>
using namespace std;

string getFile(string path) {
	istringstream iss(path);
	string sub;
	while (getline(iss, sub, '\\')) continue;
	int size = sub.size();
	if (size > 16) {
		sub = sub.substr(size - 16, size);
	}
	return sub;
}


void recordFalt(vector<pair<pair<string, int>, int> >& record_data,string file_name,int line_num) {
	vector<pair<pair<string, int>, int> >::iterator it;
	for (it = record_data.begin(); it < record_data.end(); it++) {
		if (it->first.first == file_name && it->first.second == line_num) {
			it->second += 1;
			return ;
		}
	}
	record_data.push_back(make_pair(make_pair(file_name,line_num),1));
	return;
}
#if 0
int main() {
	string path_name;
	int line_num;
	//unordered_map<string, pair<int, int>> map;
	vector<pair<pair<string, int>, int> > record_data;//用来记录出现错误的截断内容，行号，出现的次数
	//vector<pair<string, int>> res;//记录输出截断文件名+行号
	while (cin >> path_name >> line_num) {
		string file_name = getFile(path_name);
		recordFalt(record_data, file_name, line_num);
	}
	vector<pair<pair<string, int>, int> >::iterator it1;
	if (record_data.size() < 8) {
		
		for (it1 = record_data.begin(); it1 != record_data.end(); it1++) {

			cout << it1->first.first << " " << it1->first.second << " " << it1->second << endl;
		}
	}
	else {

		for (it1 = record_data.begin()+(record_data.size()-8); it1 != record_data.end(); it1++) {

			cout << it1->first.first << " " << it1->first.second << " " << it1->second << endl;
		}
	}
	return 0;
}

#endif

#if 1
//用双端队列deque+map来做
int main() {
	//整个行输入做字符串,即file_name+line_num
	string name_line;
	//使用hash映射来存储出现的次数
	map<string, int> m;
	//使用队列维持最新的8个错误
	deque<string> res;
	while (getline(cin, name_line)) {
		//裁取截断文件名+行号
		name_line = name_line.substr(name_line.find_last_of('\\') + 1);
		int pos = name_line.find_last_of(" ");
		if (pos > 16) {
			name_line = name_line.substr(pos - 16);
		}

		//记录错误出现的次数
		if (m.find(name_line) == m.end()) {
			res.push_back(name_line);
		}
		++m[name_line];

		//维持8个在案错误
		if (res.size() > 8) {
			res.pop_front();
		}
	}

	for (auto it : res) {
		cout << it << " " << m[it] << endl;
	}


	return 0;
}

#endif