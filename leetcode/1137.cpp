//
// Created by 赖於领 on 2021/8/27.
//


#include <iostream>

using namespace std;

//第 N 个泰波那契数


//泰波那契序列 Tn 定义如下： 
//
//T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0 的条件下 Tn+3 = Tn + Tn+1 + Tn+2
//
//给你整数 n，请返回第 n 个泰波那契数 Tn 的值。
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1 || n == 2) {
            return 1;
        }
        int data[n + 1];
        data[0] = 0;
        data[1] = 1;
        data[2] = 1;
        for (int i = 3; i <= n; ++i) {
            data[i] = data[i - 1] + data[i - 2] + data[i - 3];
        }
        return data[n];
    }
};

//int main() {
//    Solution *solution = new Solution();
//    cout << solution->tribonacci(4) << endl;
//    return 0;
//}

