//
// Created by 赖於领 on 2021/9/13.
//

#include <vector>
#include <iostream>

using namespace std;


//摆动序列

// 第 i 个是摆动的尾     第 i-1 是摆动尾-1
// 第 i 个不是摆动的尾    当前 i 值变成 i++ 值
//

class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n);

        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

