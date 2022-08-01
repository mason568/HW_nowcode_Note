#include<iostream>
#include<string>
#include<vector>
#include<limits.h>
using namespace std;
#if 1
//有效的回文
bool isPalindrome1(string s) {
    string sgood;
    for (char ch : s) {
        if (isalnum(ch)) { //只考虑英文字母大小写和数字，忽略其它ascii字符
            sgood += tolower(ch);
        }
    }
    string sgood_rev(sgood.rbegin(), sgood.rend()); 
    return sgood == sgood_rev;
}

bool isPalindrome2(string s) {
    int i = 0; int j = s.size() - 1;
    while (i <= j) {
        while (!isalnum(s[i])) i++;
        while (!isalnum(s[j])) j--;
        if (s[i] != s[j]) {
            return false;
        }
        else {
            i++;
            j--;
        }

    }
    return true;

}

int main() {
    string s = "asdf&&%*fbdsa";
    cout << isPalindrome1(s) << endl;
    cout << isPalindrome2(s) << endl;
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

#if 0
//最长回文子序列
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


//最长回文子串


#if 0
string init(string& s) {
    string res = "";
    res += "$#";
    for (int i = 0; i < s.size(); i++) res += s[i], res += '#';
    res += '^';
    return res;
    // 这个是在开始和结束加上通配符, 然后我们中间每个分割的地方加上#
}

void manacher(vector<int>& p, string& s) {
    int mr = 0, mid;
    // mr代表以mid为中心的最长回文的有边界
    // mid为i和j的中心点, i以mid为对称点翻折到j的位置
    for (int i = 1; i < s.size(); i++) {
        if (i < mr)
            p[i] = min(p[mid * 2 - i], mr - i);
        // 2 * mid - i为i关于mid的对称点
        else
            p[i] = 1;
        // 超过边界总共就不是回文了
        while (s[i - p[i]] == s[i + p[i]]) p[i]++;
        // 不需要判断边界, 因为我们有通配符
        if (i + p[i] > mr) {
            mr = i + p[i];
            mid = i;
        }
        // 我们每走一步i, 都要和mx比较, 我们希望mx尽可能的远
    }
}

signed main() {
    string s;
    cin >> s;
    s = init(s);
    vector<int> p(s.size());
    manacher(p, s);
    // 初始化字符串和求取出来我们的每一个位置的最长长度
    int maxx = INT_MIN;
    for (auto& it : p) maxx = max(maxx, it);
    cout << maxx - 1 << "\n";
    return 0;
}

#endif