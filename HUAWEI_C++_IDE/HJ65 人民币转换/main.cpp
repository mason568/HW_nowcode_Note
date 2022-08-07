#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string> single = { "零", "壹", "贰", "叁", "肆",
                         "伍", "陆", "柒", "捌", "玖" };

void sayPre(string& pre) {
    if (pre == "0") return;
    // 判断小数点前面是不是空的
    for (int i = 0, j = pre.size() - 1; i < pre.size(); i++, j--) {
        // i代表的是我们遍历的字符串, j是我们i后面有几个数
        if (pre[i] != '0' and not(pre[i] == '1' and j % 4 == 1))
            cout << single[pre[i] - '0'];
        // 转换中文
        if (j != 0 and j % 8 == 0 and j >= 8)
            cout << "亿";
        if (j != 0 and j % 4 == 0 and j % 8 != 0)
            pre[i + 1] == '0' ? cout << "万零" : cout << "万";
        if (j != 0 and j % 4 == 3 and pre[i] != '0')
            pre[i + 1] == '0' and pre[i + 2] != '0' ? cout << "仟零" : cout << "仟";
        if (j != 0 and j % 4 == 2 and pre[i] != '0')
            pre[i + 1] == '0' and pre[i + 2] != '0' ? cout << "佰零" : cout << "佰";
        if (j != 0 and j % 4 == 1 and pre[i] != '0')
            cout << "拾";
    }
    // 上面的if分别对应后面输出的亿万千百十
    cout << "元";
    // 最后我们输出元
}

void sayEnd(string& end) {
    if (end == "00")
        cout << "整\n";
    else if (end[0] == '0')
        cout << single[end[1] - '0'] << "分\n";
    else if (end[1] == '0')
        cout << single[end[0] - '0'] << "角\n";
    else
        cout << single[end[0] - '0'] << "角" << single[end[1] - '0'] << "分\n";
    // 分类讨论, 讨论我们小数点后两位的所有情况
}

signed main() {
    string s;
    while (cin >> s) {
        string pre = "", end = "";
        bool okk = false;
        for (auto& it : s) {
            if (it == '.') {
                okk = true;
                continue;
            }
            okk ? end += it : pre += it;
        }
        // 这里我们以小数点为分隔, 把小数点前面的存储到了pre里面,
        // 小数点后面的存储到了end里面
        cout << "人民币";
        sayPre(pre), sayEnd(end);
    }
    return 0;
}
