#include<iostream>
#include<iomanip>
using namespace std;

void solve() {
    int n;
    while (cin >> n) {
        int cnt = 0, sum = 0, num = 0;
        // cnt 为负数个数，sum为正数的和，num为正数的个数
        int tmp;
        // 开辟大小为 n 的数组
        for (int i = 0; i < n; i++) {
            // 边输入边统计
            cin >> tmp;
            if (tmp < 0) ++cnt;
            else if (tmp > 0) sum += tmp, ++num;
        }
        if (num) cout << cnt << " " << fixed << setprecision(1) << sum * 1.0 / num << endl;
        else cout << cnt << " " << fixed << setprecision(1) << "0.0" << endl;
        // 保留一位小数
    }
}

signed main() {
    solve();
    return 0;
}
