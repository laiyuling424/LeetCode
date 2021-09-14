//
// Created by 赖於领 on 2021/9/2.
//


#include <vector>
#include <iostream>

using namespace std;

//买卖股票的最佳时机含手续费

//第i天没有股票 = 前一天没有股票  前一天有股票今天卖了    dp[i][0] = max( dp[i-1][0] , dp[i-1][1] + prices[i] - fee );
//第i天持有股票 = 前一天持有股票  前一天没有股票今天买入  dp[i][1] = max( dp[i-1][1] , dp[i-1][0] - prices[i] );


class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {

        int n = prices.size();
        int dp[n][2];

        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        return dp[n - 1][0];

    }
};

