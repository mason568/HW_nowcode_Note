#include<iostream>
#include<string>
#include<vector>
#include<limits.h>
using namespace std;


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
