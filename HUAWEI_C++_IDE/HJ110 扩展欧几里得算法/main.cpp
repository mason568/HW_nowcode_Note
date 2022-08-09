#include<iostream>
using namespace std;


int exgcd(int a, int b, int& x, int& y)//扩展欧几里得算法
{
    if (b == 0)
    {
        x = 1; y = 0;
        return a;  //到达递归边界开始向上一层返回
    }
    int r = exgcd(b, a % b, x, y);
    int temp = y;    //把x y变成上一层的
    y = x - (a / b) * y;
    x = temp;
    return r;     //得到a b的最大公因数
}

int main() {
    int a, b;
    while (cin >> a >> b) {
        int s=0, t=0,g=0;
        g = exgcd(a, b, s, t);
        cout << g << " " << s << " " << t << endl;
    }
}
