#include<iostream>
#include<string>
#include<vector>
using namespace std;

#if 0
//有效的回文
bool isPalindrome(string s) {
    string sgood;
    for (char ch : s) {
        if (isalnum(ch)) {
            sgood += tolower(ch);
        }
    }
    string sgood_rev(sgood.rbegin(), sgood.rend());
    return sgood == sgood_rev;
}

int main() {
    string s = "asdffdsa";
    cout << isPalindrome(s) << endl;
	return 0;
}
#endif

#if 0
//字符串中有效的回文子串数量 输入为已经处理过的字符串
//遍历每一个可能是回文中心的位置，然后向外扩散，直到两边字符不相等就停止扩散
int countSubstrings(string s) {
    int n = s.size(), ans = 0;
    //奇偶位置一次性处理
    /*
    for (int i = 0; i < 2 * n - 1; ++i) {
        int l = i / 2, r = i / 2 + i % 2;
        while (l >= 0 && r < n && s[l] == s[r]) {
            --l;
            ++r;
            ++ans;
        }
    }
    */
    //奇偶位置处理
    //子串奇数长 中心为s[i]
    //子串偶数数长 中心为s[i],s[i+1]
    for (int i = 0; i < n; i++) {
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            --l;
            ++r;
            ++ans;
        }
    }
    for (int i = 0; i < n; i++) {
        int l = i, r = i+1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            --l;
            ++r;
            ++ans;
        }
    }
    return ans;
}

int main() {
    cout << countSubstrings("asajfdsfigghhjhhgg") << endl;
}
#endif

#if 1
int longestPalindromeSubseq(string s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = n - 1; i >= 0; i--) {
        dp[i][i] = 1;
        char c1 = s[i];
        for (int j = i + 1; j < n; j++) {
            char c2 = s[j];
            if (c1 == c2) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    cout << longestPalindromeSubseq("asajfdsfigghhjhhgg") << endl;
    return 0;
}

#endif
