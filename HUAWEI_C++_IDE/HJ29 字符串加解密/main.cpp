#include<iostream>
#include<string>
#include"string.h"
#include "assert.h"
using namespace std;

string enc(string pt) {
	string ret = "";
	for (auto ch : pt) {
		if (islower(ch) && ch != 'z') ret += 'A' + ch - 'a' + 1;
		else if (isupper(ch) && ch != 'Z') ret += 'a' + ch - 'A' + 1;
		else if (ch >= '0' && ch <= '9') ret += '0' + (ch - '0' + 11) % 10;
		else if (islower(ch) && ch == 'z') ret += 'A';
		else if (isupper(ch) && ch == 'Z') ret += 'a';
		else ret += ch;
	}
	return ret;
}
string dec(string ct) {
	string ret = "";
	for (auto ch : ct) {
		if (islower(ch) && ch != 'a') ret += 'A' + ch - 'a' - 1;
		else if (isupper(ch) && ch != 'A') ret += 'a' + ch - 'A' - 1;
		else if (ch >= '0' && ch <= '9') ret += '0' + (ch - '0' + 9) % 10;
		else if (islower(ch) && ch == 'a') ret += 'Z';
		else if (isupper(ch) && ch == 'A') ret += 'z';
		else ret += ch;
	}
	return ret;
}

int main() {
	string plaintext;
	string ciphertext;
	while (cin >> plaintext >> ciphertext) {
		cout << enc(plaintext) << endl;
		cout << dec(ciphertext) << endl;
	}
	return 0;
}