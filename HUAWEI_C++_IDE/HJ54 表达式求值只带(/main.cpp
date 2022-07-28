#include<iostream>
#include<string>
#include<stack>
#include"assert.h"
using namespace std;

void caculate_num_op_num(stack<int>& num_st, stack<char> &op_st) {
	if (num_st.size() < 2 || op_st.empty()) return;
	int rhs = num_st.top();
	num_st.pop();
	int lhs = num_st.top();
	num_st.pop();
	char op = op_st.top();
	op_st.pop();
	if (op == '+') num_st.push(lhs + rhs);
	else if (op == '-') num_st.push(lhs - rhs);
	else if (op == '*') num_st.push(lhs * rhs);
	else if (op == '/' && rhs != 0) num_st.push(lhs / rhs);
}

bool priority(char in_stack, char into_stack) {
	if (in_stack == '(') return false;
	else if ((in_stack == '+' || in_stack == '-') && (into_stack == '*' || into_stack == '/')) return false;
	return true;
}

int caculateVal(string s) {
	stack<int> num_st;
	stack<char> op_st;
	int res = 0;
	bool flag = false;
	op_st.push('(');
	s += ')';
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			op_st.push(s[i]);
		}
		else if (s[i] == ')') {
			while (op_st.top() != '(') caculate_num_op_num(num_st, op_st);
			op_st.pop();
		}
		else if(flag) {
			//操作符
			while(!op_st.empty()&&priority(op_st.top(),s[i])) caculate_num_op_num(num_st, op_st);  //算完  这里的while很重要，不能是if
			if (s[i] == '+') op_st.push('+');
			else if (s[i] == '-') op_st.push('-');
			else if (s[i] == '*') op_st.push('*');
			else if (s[i] == '/') op_st.push('/');
			flag = false;
		}
		else {
			//操作数
			int num =  stoi(s.substr(i));
			num_st.push(num);
			int len = to_string(num).size();
			i += len - 1;
			flag = true;
		}
	}
	return num_st.top();
}

int main() {
	string s;
	while (cin >> s) {

		cout << caculateVal(s) << endl;
	
	}
	return 0;
}