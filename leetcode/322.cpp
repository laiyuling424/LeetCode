//
// Created by 赖於领 on 2021/9/14.
//
#include <string>
#include <iostream>
#include <vector>

using namespace std;


//零钱兑换


class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        sort(coins.begin(), coins.end());
        if (coins[0] > amount) {
            return -1;
        }
        vector<int> _min(amount + 1, INT_MAX);
        int n = coins.size();
        _min[0] = 0;
        _min[*coins.begin()] = 1;
        for (int i = *coins.begin() + 1; i <= amount; ++i) {
            for (int j = 0; j < n; ++j) {
                if (coins[j] > i) {
                    break;
                }
                if (_min[i - coins[j]] == INT_MAX) {
                    continue;
                }
                _min[i] = min(_min[i], _min[i - coins[j]] + 1);
            }
        }
        if (_min[amount] == INT_MAX) {
            return -1;
        } else {
            return _min[amount];
        }
    }
};

int main() {
    Solution *solution = new Solution();
//    vector<int> aa = {1, 2, 5};
//    cout << solution->coinChange(aa, 11) << endl;
//    vector<int> aa = {2};
//    cout << solution->coinChange(aa, 1) << endl;
    vector<int> aa = {474,83,404,3};
    cout << solution->coinChange(aa, 264) << endl;
    return 0;
}

