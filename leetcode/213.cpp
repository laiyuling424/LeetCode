//
// Created by 赖於领 on 2021/8/30.
//

#include <vector>

using namespace std;


//打家劫舍 II


class Solution {
public:
    int max_rob(vector<int> &nums) {

        if (nums.size() == 1) {
            return nums[0];
        }

        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        int max_rob[nums.size()];
        max_rob[0] = nums[0];
        max_rob[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            //i 偷
            //i 不偷
            max_rob[i] = max(nums[i] + max_rob[i - 2], max_rob[i - 1]);
        }
        return max_rob[nums.size() - 1];
    }

    int rob(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        vector<int> first(nums.begin(), --nums.end());
        vector<int> second(nums.begin() + 1, nums.end());
        return max(max_rob(first), max_rob(second));
    }
};

