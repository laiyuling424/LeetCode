//
// Created by 赖於领 on 2021/9/13.
//

#include <vector>
#include <iostream>

using namespace std;

//最长递增子序列

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
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


//int main() {
//    Solution *solution = new Solution();
//    vector<int> aa = {0, 1, 0, 3, 2, 3};
////    vector<int> aa = {10, 9, 2, 5, 3, 7, 101, 18};
//    cout << solution->lengthOfLIS(aa) << endl;
//    return 0;
//}
//
