//
// Created by 赖於领 on 2021/8/27.
//

#include <iostream>

using namespace std;

//爬楼梯


//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//
//每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
//
//注意：给定 n 是一个正整数。



/**
 * 思路：1 层：0-》1              1 种方法
 *      2 层：0-》2  1-》2       2 种
 *      3 层：从1层爬2个台阶或从2层爬一个台阶   1层的方法 + 2层的方法
 *      4 层：从2层爬2个台阶或从3层爬一个台阶   2层的方法 + 3层的方法
 *      .
 *      .
 *      .
 *      n层:                               n-2 + n-1
 */
class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) {
            return n;
        }
        int methods[n + 1];
        methods[0] = 1;
        methods[1] = 1;
        for (int i = 2; i <= n; ++i) {
            methods[i] = methods[i - 1] + methods[i - 2];
        }
        return methods[n];
    }
};

//int main() {
//    Solution *solution = new Solution();
//    cout << solution->climbStairs(3) << endl;
//    return 0;
//}