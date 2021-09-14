//
// Created by 赖於领 on 2021/8/27.
//

#include <vector>
#include <iostream>

using namespace std;

//打家劫舍

class Solution {
public:
    int rob(vector<int> &nums) {

        if (nums.size() == 1) {
            return nums[0];
        }

        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        int max_rob[nums.size()];
        max_rob[0] = nums[0];
        max_rob[1] = nums[1];
        max_rob[2] = max(nums[2] + max_rob[0], max_rob[1]);
        for (int i = 3; i < nums.size(); ++i) {
            //i 偷
            //i 不偷
            max_rob[i] = max(max(nums[i] + max_rob[i - 2], max_rob[i - 1]), max_rob[i - 3] + nums[i]);
        }
        for (int i : max_rob) {
            cout << i << endl;
        }
        cout << "-----------" << endl;
        return max_rob[nums.size() - 1];
    }
};

/**
 * ---------------------------------官方---------------------------------------------------
 */
class Solution2 {
public:
    int rob(vector<int> &nums) {

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
        for (int i : max_rob) {
            cout << i << endl;
        }
        cout << "-----------" << endl;
        return max_rob[nums.size() - 1];
    }
};


//int main() {
//    Solution2 *solution = new Solution2();
////    vector<int> cost = {1, 2, 3, 1};
////    vector<int> cost = {2,7,9,3,1};
//    vector<int> cost = {2, 1, 1, 2};
//
//    cout << solution->rob(cost) << endl;
//    return 0;
//}

