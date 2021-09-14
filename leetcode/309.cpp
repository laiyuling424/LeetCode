//
// Created by 赖於领 on 2021/9/2.
//

#include <vector>
#include <iostream>

using namespace std;

//最佳买卖股票时机含冷冻期


//第i天持有股票        =   前一天没有持有股票  前一天持有股票         f[i][0] = max( f[i-1][2] - price[i], f[i-1][0] )
//第i天不能买股票      =   前一天持有股票                          f[i][1] = max( f[i-1][0] + price[i] )
//第i天没有持有股票     =   前一天是冷冻期     前一天没有持有股票      f[i][2] = max( f[i-1][1] , f[i-1][2] )

class Solution {
public:
    int maxProfit(vector<int> &prices) {

        if (prices.empty()) {
            return 0;
        }

        int n = prices.size();
        int dp[n][3];
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;

        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][2] - prices[i], dp[i - 1][0]);
            dp[i][1] = dp[i - 1][0] + prices[i];
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
        }

        return max(dp[n - 1][1], dp[n - 1][2]);
    }
};

