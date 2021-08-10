//
// Created by 赖於领 on 2021/8/3.
//
#include <vector>
#include <set>

using namespace std;

//动态规划 max = max( f(i-1) , i )

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto &x: nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};

