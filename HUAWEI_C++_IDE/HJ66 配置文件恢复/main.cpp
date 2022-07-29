#include<iostream>
#include<string>
#include"assert.h"
#include<sstream>
using namespace std;

string input1_cmd[6] = { "reset",
						"reset",
						"board",
						"board",
						"reboot",
						"backplane" };

string input2_cmd[6] = { "",
						"board",
						"add",
						"delete",
						"baclplane",
						"abort" };

string out_cmd[6] = { "reset what",
						"board fault",
						"where to add",
						"no board at all",
						"ompossible",
						"install first" };

string unknow_cmd = "unknown command";



int main() {
	string s;
	while (getline(cin,s)) {
		stringstream ss(s);
		string key1, key2;
		getline(ss, key1, ' ');
		getline(ss, key2, ' ');
		int count = 0;//统计两个key匹配了几条命令
		string res = "";
		for (int i = 0; i < 6; i++) {
			int match1_pos = input1_cmd[i].find(key1);
			int match2_pos;
			if (key2 != "") {
				match2_pos = input2_cmd[i].find(key2);
			}
			else if (key2 == "" && input2_cmd[i]=="") {
				match2_pos = 0;
			}
			else {
				match2_pos = -1;
			}
			if (match1_pos == 0 && match2_pos == 0) {
				count++;
				res = out_cmd[i];
			} 
			
			
		}
	
		if (count == 1) {
			cout << res << endl;
		}
		else {
			cout << unknow_cmd << endl;
		}

	}

	return 0;
}