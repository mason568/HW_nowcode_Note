#include<iostream>
#include<string>
#include<stack>
using namespace std;
#if 1
//双栈法  好理解
void caxulate(stack<int>& st_num, stack<char>& st_op) {
	if (st_num.size() < 2 || st_op.empty()) return;
	int rhs = st_num.top();
	st_num.pop();
	int lhs = st_num.top();
	st_num.pop();
	char op = st_op.top();
	st_op.pop();
	if (op == '+') st_num.push(lhs + rhs);
	else if (op == '-') st_num.push(lhs - rhs);
	else if (op == '*') st_num.push(lhs * rhs);
	else if (op == '/' && rhs != 0) st_num.push(lhs / rhs);
}


bool priority(char m, char n) { //比较运算符优先级

	if (m == '(') 
		return false;
	else if ((m == '+' || m == '-') && (n == '*' || n == '/')) //加减法小于乘除法
		return false;
	return true; //n 的优先级高
}


int caculateVal(string s) {
	stack<int> st_num;//存储操作数
	stack<char> st_op;//存储操作符或者括号
	st_op.push('(');
	s += ')';
	bool flag = false;//只有再加了一个操作数后才能加运算符 + - * /
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
			st_op.push('(');
		}
		else if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
			while (st_op.top() != '(') caxulate(st_num, st_op);
			st_op.pop();
		}
		else if (flag) {
			//如果前一个操作符是括号，那么括号要保留，直接加上当前操作符-*/+
			//如果前一个操作符不是括号，当前要加入的操作符又比前一个操作符优先级高，当前的s[i]为*或/，前一个操作符为-或+，那么前面的操作符-或+也得保留，直接加上当前操作符
			//否则的话，要么两种操作符优先级相同，要么前面的操作符优先级比新加的操作符优先级高，就要先算，算完之后再加上当前的操作符
			while(priority(st_op.top(),s[i])) caxulate(st_num, st_op);
			st_op.push(s[i]);
			//新加入一个操作符后，必须加一个操作数，flag重置为false
			flag = false;
		}
		else {
			st_num.push(stoi(s.substr(i)));
			int len = to_string(stoi(s.substr(i))).size();
			i += len - 1;
			flag = true;
		}
	}


	return st_num.top();
}

int main() {
	string s;
	while (cin >> s) {
		cout << caculateVal(s) << endl;
	}
	return 0;
}
#endif

//递归法
#if 0
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int compute(string& s, int left, int right) {
	char op = '+'; //默认加开始
	int num = 0;
	vector<int> st;
	for (int i = left; i <= right; i++) {
		if (isdigit(s[i])) //数字
			num = num * 10 + s[i] - '0'; //计算该部分数字总和
		if (s[i] == '{' || s[i] == '[' || s[i] == '(') { //进入左括号
			int layer = 0; //统计左括号层数
			int j = i;
			while (j <= right) { //遍历到右边
				if (s[j] == '{' || s[j] == '[' || s[j] == '(')
					layer++; //遇到左括号，层数累加
				else if (s[j] == '}' || s[j] == ']' || s[j] == ')') {
					layer--; //遇到右括号层数递减
					if (layer == 0) //直到层数为0
						break;
				}
				j++;
			}
			num = compute(s, i + 1, j - 1); //递归计算括号中的部分
			i = j + 1;
		}
		if (!isdigit(s[i]) || i == right) { //遇到运算符或者结尾
			switch (op) { //根据运算符开始计算
			case '+': st.push_back(num); break; //加减法加入到末尾
			case '-': st.push_back(-num); break;
			case '*': st.back() *= num; break; //乘除法与末尾计算
			case '/': st.back() /= num; break;
			}
			op = s[i]; //修改为下一次的运算符  重中之重昂，草
			num = 0;
		}
	}
	int res = 0;
	for (int x : st) //累加和
		res += x;
	return res;
}
int main() {
	string s;
	while (cin >> s) {
		cout << compute(s, 0, s.length() - 1) << endl;
	}
	return 0;
}


#endif