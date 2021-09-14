//
// Created by 赖於领 on 2021/8/31.
//

#include <vector>
#include <iostream>

using namespace std;


//环形子数组的最大和


class Solution {
public:
    int maxSubarraySumCircular(vector<int> &nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto &x: nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
            if (maxAns == pre) {
                nums.push_back(x);
            }
        }
        return maxAns;
    }
};

