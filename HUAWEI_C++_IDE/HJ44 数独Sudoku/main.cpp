#include<iostream>

using namespace std;

int nums[9][9];
bool flag = false;

bool check(int n) {
    int h = n / 9;//当前行号
    int l = n % 9;//当前列号

    //同一行中不能有重复的数
    for (int i = 0; i < 9; ++i) {//同一列中不能有重复
        if (i != l && nums[h][i] == nums[h][l]) {
            return false;
        }
    }

    //同一列中不能有重复
    for (int i = 0; i < 9; ++i) {//同一列中不能有重复
        if (i != h && nums[i][l] == nums[h][l]) {
            return false;
        }
    }

    //所在九宫格不能有重复
    for (int i = h / 3 * 3; i < h / 3 * 3 + 3; i++) {
        for (int j = l / 3 * 3; j < l / 3 * 3 + 3; j++) {
            if ((i != h || j != l) && nums[i][j] == nums[h][l]) {
                return false;
            }
        }
    }
    return true;
}

//9*9=81格 递归从0-81 参数为 位置
void dfs(int n) {
    //递归结束条件
    if (n == 81) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 8; ++j) {
                cout << nums[i][j] << ' ';
            }
            cout << nums[i][8] << endl;
        }
        flag = true;
        return;
    }

    int h = n / 9;//当前行号
    int l = n % 9;//当前列号
    if (nums[h][l] == 0) { //需要填充一个正确的数到这个位置
        //枚举1-9
        for (int i = 1; i <= 9; i++) {
            nums[h][l] = i;
            //推算正误
            if (check(n)) {//当前位置是否满足条件
                dfs(n + 1);//如果满足就继续递归下一个位置

                //如果成功在回溯之前return
                if (flag) return; //减枝
            }
        }
        //如果均不满足，那肯定是前面设定的值出错了，需要回溯 恢复待定值为0
        nums[h][l] = 0;
    
    }
    else {
        dfs(n + 1);
    }



}


int main() {
	
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> nums[i][j];//输入9x9盘面
        }
    }
    dfs(0);//从左上角开始递归

    return 0;


}