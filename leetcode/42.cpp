//
// Created by 赖於领 on 2021/9/3.
//


#include <vector>
#include <iostream>

using namespace std;

//接雨水


class Solution {
public:
    int trap(vector<int> &height) {

        if (height.size() < 3) {
            return 0;
        }

        int n = height.size();
        vector<int> h_max(n);
        vector<int> t_max(n);
        h_max[0] = height[0];
        t_max[n - 1] = height[n - 1];
        vector<int> max_data(n);
        max_data[0] = 0;

        for (int i = 1; i < n; ++i) {
            h_max[i] = max(height[i], h_max[i - 1]);
            t_max[n - i - 1] = max(height[n - i - 1], t_max[n - i]);
        }

        for (int i = 1; i < n; ++i) {
            if (height[i] < h_max[i] && height[i] < t_max[i]) {
                max_data[i] = max_data[i - 1] + min(h_max[i], t_max[i]) - height[i];
            } else {
                max_data[i] = max_data[i - 1];
            }
            cout << "max_data[" << i << "]   " << max_data[i] << endl;
        }

        return max_data[n - 1];
    }
};

//int main() {
////    vector<int> height = {1, 2, 3, 4, 5};
//    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
//
//    Solution *solution = new Solution();
//    cout << solution->trap(height) << endl;
//    return 0;
//}