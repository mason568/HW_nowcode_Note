#include<iostream>
#include<numeric>
#include<vector>
#include<algorithm>
using namespace std;

void fun(int i)
{
    cout << i << endl;
}

int main()
{
    int a[] = { 1, 2, 3, 4 };
    vector<int> v(a, a + sizeof(a) / sizeof(int));
    for_each(v.begin(), v.end(), fun);
}
