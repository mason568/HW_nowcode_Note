#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

#if 0
//sort重写比较函数 vector<pair<string name, int mark>>做记录学生信息
bool cmp1(pair<string, int> lhs, pair<string, int> rhs) {
		return lhs.second > rhs.second;
}

bool cmp2(pair<string, int> lhs, pair<string, int> rhs) {
		return lhs.second < rhs.second;
}

int main() {
	int N,rule;
	while (cin >> N >> rule) {
		string name;
		int mark;
		vector<pair<string, int>> Student;
		for (int i = 0; i < N; i++) {
			cin >> name >> mark;
			Student.push_back(make_pair(name,mark));
		}
		if (rule) { 
			stable_sort(Student.begin(), Student.end(), cmp2); 
		}
		else {
			stable_sort(Student.begin(), Student.end(), cmp1);
		}
		
		for (auto s : Student) {
			cout << s.first << " " << s.second << endl;
		}
	}
}

#endif 

#if 1
//使用学生类写法和上面略有不同 还是用stabel_sort

class Student {
public:
	Student(string n, int m):
		name(n),mark(m)
	{}
public:
	string name;
	int mark;
};

//定义类的比较函数
bool cmp3(Student lhs, Student rhs) {
	return rhs.mark > lhs.mark;
}
bool cmp4(Student lhs, Student rhs) {
	return rhs.mark < lhs.mark;
}

int main() {
	int N, rule;
	while (cin >> N >> rule) {
		string name;
		int mark;
		vector<Student> students;
		for (int i = 0; i < N; i++) {
			cin >> name >> mark;
			students.push_back(Student(name, mark));
		}
		if (rule) {
			stable_sort(students.begin(), students.end(), cmp3);
		}
		else {
			stable_sort(students.begin(), students.end(), cmp4);
		}

		for (auto s : students) {
			cout << s.name << " " << s.mark << endl;
		}
	}
}

#endif