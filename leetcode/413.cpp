//
// Created by 赖於领 on 2021/9/4.
//

#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;



//等差数列划分


class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        int n = nums.size();
        if (n < 3) {
            return 0;
        }
        int differ = nums[1] - nums[0];
        int len = 2;
        vector<int> num(n, 0);
        for (int i = 2; i < n; ++i) {
            if (differ == (nums[i] - nums[i - 1])) {
                len++;
                num[i] = num[i - 1] + len - 2;
            } else {
                num[i] = num[i - 1];
                len = 2;
                differ = (nums[i] - nums[i - 1]);
            }
        }

        return num[n - 1];
    }
};

//int main() {
//
//    Solution *solution = new Solution();
////    vector<int> aa = {1, 2, 3, 4};
////    vector<int> aa = {1};
//    vector<int> aa = {1,2,3,8,9,10};
//    cout << solution->numberOfArithmeticSlices(aa) << endl;
//
//    return 0;
//}
