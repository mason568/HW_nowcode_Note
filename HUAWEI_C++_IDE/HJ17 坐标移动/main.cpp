#include<iostream>
#include<string>
#include<regex>
#include <vector>
#include<sstream>
using namespace std;


#if 0
//字符串分割函数
vector<string> split(string str, string pattern)
{
    std::string::size_type pos;
    std::vector<std::string> result;
    str += pattern;//扩展字符串以方便操作
    int size = str.size();
    for (int i = 0; i < size; i++)
    {
        pos = str.find(pattern, i);
        if (pos < size)
        {
            std::string s = str.substr(i, pos - i);
            if(s!="") result.push_back(s);
            i = pos + pattern.size() - 1;
        }
    }
    return result;
}


bool isLegal(string s) {
    bool res = false;
    if (s[0] == 'A' || s[0] == 'W' || s[0] == 'S' || s[0] == 'D') {
        for (int i = 1; i < s.size(); i++) {
            if (s[i] >= '0' && s[i]<='9') {
                res = true;
            }
            else {
                res = false;
                return res;
            }
        }
    }
    return res;
}

int main() {

	string s;
    
	while (cin >> s) {
        pair<int, int> pos(0, 0);
        vector<string> res = split(s, ";");
        for (auto str : res) {
            //cout <<str<<" "<<isLegal(str) << endl;
            if (isLegal(str)) {
                int num = 0;
                for (int j = 1; j < str.size(); j++) {
                    num = num*10 + (str[j] - '0');
                }
                switch (str[0]) {
                case 'A': pos.first -= num;
                    break;
                case 'D': pos.first += num;
                    break;
                case 'S': pos.second -= num;
                    break;
                case 'W': pos.second += num;
                    break;


                }
            }

        }
        cout << pos.first<<"," <<pos.second<< endl;
	
	}
	return 0;
}

#endif

#if 0
//正则表达式求解


int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0), cout.tie(0);
    string s, t;
    while (getline(cin, s)) {
        stringstream ss(s);
        pair<int, int> p(0, 0);
        while (getline(ss, t, ';')) {
            if (t.empty())
                continue;
            string _ = t.substr(1);
            if (regex_match(_, regex("[0-9]*"))) {
                switch (t[0]) {
                case 'A': p.first -= stoi(_); break; //左移
                case 'D': p.first += stoi(_); break; //右移
                case 'W': p.second += stoi(_); break; //上移
                case 'S': p.second -= stoi(_); break; //下移
                default: break; //无效
                }
            }
        }
        cout << p.first << "," << p.second << endl;
    }
    return 0;
}

#endif


#if 1
int main() {
    string s;

    cin >> s;
    cout << s.substr(1) << endl;


    return 0;
}
#endif