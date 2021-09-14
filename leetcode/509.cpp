//
// Created by 赖於领 on 2021/8/27.
//

//斐波那契


//F(0) = 0，F(1) = 1
//F(n) = F(n - 1) + F(n - 2)，其中 n > 1

/**
 * 可以优化 备忘录优化 但是会导致空间变大 参考 1137
 *
 * 下面的做法空间最小
 */
class Solution {
public:
    int fib(int n) {
        if (n < 2) {
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }
};