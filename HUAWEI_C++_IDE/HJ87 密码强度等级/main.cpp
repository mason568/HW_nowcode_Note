#include<iostream>
#include<vector>
#include<string>

using namespace std;

string level[7] = {
	"VERY_SECURE",
	"SECURE",
	"VERY_STRONG",
	"STRONG",
	"AVERAGE",
	"WEAK",
	"VERY_WEAK"
};

int main() {
	string s;
	while (cin >> s) {
		int len = s.size();
		int low = 0;
		int up = 0;
		int digit = 0;
		int others = 0;
		for (int i = 0; i < s.size(); i++) {
			if (islower(s[i])) low++;
			else if (isupper(s[i])) up++;
			else if (isdigit(s[i])) digit++;
			else others++;
		}

		int sum = 0;
		//¸öÊý
		if (len <= 4) sum += 5;
		else if (len >= 5 && len <= 7) sum += 10;
		else sum += 25;

		//Êý×Ö
		if (digit == 0) sum += 0;
		else if (digit == 1) sum += 10;
		else sum += 20;

		//×ÖÄ¸
		if (low == 0 && up == 0) sum += 0;
		else if (low == 0 || up == 0) sum += 10;
		else sum += 20;

		//·ûºÅ
		if (others == 0) sum += 0;
		else if (others == 1) sum += 10;
		else sum += 25;


		//½±Àø
		if ((low > 0 && up > 0) && digit > 0 && others > 0) sum += 5;
		else if ((low > 0 || up > 0) && digit > 0 && others > 0)  sum += 3;
		else if ((low > 0 || up > 0) && digit > 0) sum += 2;


		if (sum >= 90) cout << level[0] << endl;
		else if (sum >= 80) cout << level[1] << endl;
		else if (sum >= 70) cout << level[2] << endl;
		else if (sum >= 60) cout << level[3] << endl;
		else if (sum >= 50) cout << level[4] << endl;
		else if (sum >= 25) cout << level[5] << endl;
		else if (sum >= 0) cout << level[6] << endl;

	}

	return 0;

}