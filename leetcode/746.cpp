//
// Created by 赖於领 on 2021/8/27.
//

#include <vector>
#include <iostream>

using namespace std;

//使用最小花费爬楼梯


class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {

        int min_cost[cost.size() + 1];
        min_cost[0] = cost[0];
        min_cost[1] = cost[1];
        for (int i = 2; i < cost.size() + 1; i++) {
            if (i == cost.size()) {

                min_cost[i] = min(min_cost[i - 2], min_cost[i - 1]);
                cout << i;
                cout << "-----------" << endl;
            } else {
                min_cost[i] = min(cost[i] + min_cost[i - 2], cost[i] + min_cost[i - 1]);
            }


        }
        for (int i : min_cost) {
            cout << i << endl;
        }
        cout << "-----------" << endl;
        return min_cost[cost.size()];
    }
};

//int main() {
//    Solution *solution = new Solution();
//    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
////    vector<int> cost = {10, 15, 20};
//
//    cout << solution->minCostClimbingStairs(cost) << endl;
//    return 0;
//}