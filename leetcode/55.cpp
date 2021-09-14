//
// Created by 赖於领 on 2021/8/30.
//


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        if (nums.size() == 1) {
            return true;
        }
        int max_jump[nums.size()];
        max_jump[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (max_jump[i - 1] >= i) {
                if ((max_jump[i] = max(max_jump[i - 1], i + nums[i])) >= (nums.size() - 1)) {
                    return true;
                }
            } else{
                break;
            }
        }
        return false;
    }
};

//int main() {
//    Solution *solution = new Solution();
////    vector<int> aa = {2, 3, 1, 1, 4};
////    vector<int> aa = {3, 2, 1, 0, 4};
////    vector<int> aa = {0};
//    vector<int> aa = {0, 2, 3};
//    cout << solution->canJump(aa) << endl;
//    return 0;
//}