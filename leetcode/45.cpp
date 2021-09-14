//
// Created by 赖於领 on 2021/8/30.
//


#include <vector>
#include <iostream>

using namespace std;

// 跳跃游戏 II



class Solution {
public:
    int jump(vector<int> &nums) {
        if (nums.size() == 1) {
            return 0;
        }
        const int length = nums.size();
        vector<int> min_jump(length, INT_MAX);
//        for (int j = 0; j < nums[0]; ++j) {
//            min_jump[j] = 1;
//        }
//        for (int i = 0; i < length; ++i) {
//            for (int j = 1; j < nums[i] && i + j < length; ++j) {
//                if (min_jump[i + j] == 0) {
//                    min_jump[i + j] = min_jump[i] + 1;
//                } else {
//                    min_jump[i + j] = min_jump[i];
//                }
//            }
//        }

        min_jump[0] = 0;
        for (int i = 0; i < length; ++i) {
            for (int j = 1; j <= nums[i] && i + j < length; ++j) {
                min_jump[i + j] = min(min_jump[i] + 1, min_jump[i + j]);
            }
        }


        return min_jump[length - 1];
    }
};

//class Solution {
//public:
//    int jump(vector<int>& nums) {
//        const int n = nums.size();
//        int dp[n];
//        memset(dp, 0x3f, sizeof(dp));  //刚开始都填上inf
//        dp[0] = 0;  //0位置步数是0
//        for(int i = 0; i < n; ++i)  //遍历每一个点
//            for(int j = 1; j <= nums[i] && i + j < n; ++j) //这个点能够到达的点
//                dp[i + j] = min(dp[i + j], dp[i] + 1); //尝试更新所到之点
//        return dp[n - 1];
//
//    }
//};

//int main() {
//    Solution *solution = new Solution();
////    vector<int> aa = {1,2};
//    vector<int> aa = {2, 3, 1, 1, 4};
////    vector<int> aa = {1, 2, 1, 1, 1};
////    vector<int> aa = {7, 0, 9, 6, 9, 6, 1, 7, 9, 0, 1, 2, 9, 0, 3};
//    cout << solution->jump(aa) << endl;
////    int dp[10];
////    memset(dp, 0x3f, sizeof(dp));  //刚开始都填上inf
////    cout << dp[0] << endl;
////    cout << dp[1] << endl;
////    cout << dp[2] << endl;
//    return 0;
//}

