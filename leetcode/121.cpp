//
// Created by 赖於领 on 2021/8/9.
//

#include <vector>
#include <iostream>

using namespace std;

//暴力求解 二次for循环
//一次循环 看见最小值就买入，同时将最大值置为最小值后一位，求利润最大
// min = min(已记录值，当前循环值)
// max = max(已记录值，当前循环值 - min)

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int max = 0;

        int min_index = 0, max_index = 0;
        //[7,1,5,3,6,4]    [7,2,5,3,7,1,4]  [2,1]
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[max_index]) {
                max_index = i;
            }
            if (prices[i] < prices[min_index]) {
                min_index = i;
                if (i + 1 != prices.size()) {
                    max_index = i + 1;
                }
            }
            if (min_index < max_index && max < (prices[max_index] - prices[min_index])) {
                max = prices[max_index] - prices[min_index];
            }
        }
        cout << max << endl;
        return max;
    }
};


//动态规划
class Solution2 {
public:
    int maxProfit(vector<int> &prices) {
//        int minprice = INT_MAX, maxprofit = INT_MIN;
//        for (int price: prices) {
//            maxprofit = max(maxprofit, price - minprice);
//            minprice = min(price, minprice);
//        }
//        cout << maxprofit << endl;
//        return maxprofit;

        int n = prices.size();
        vector<int> min_prices(n, 0);
        min_prices[0] = prices[0];
        int maxprofit = INT_MIN;
        for (int i = 1; i < n; ++i) {
            min_prices[i] = min(min_prices[i - 1], prices[i - 1]);
            maxprofit = max(maxprofit, prices[i] - min_prices[i]);
        }
        if (maxprofit < 0) {
            maxprofit = 0;
        }
        return maxprofit;
    }
};

//int main() {
//
//    Solution2 *solution = new Solution2();
////    vector<int> vec = {2, 5, 1, 3};
//    vector<int> vec = {7, 6, 4, 3, 1};
//    cout << solution->maxProfit(vec) << endl;
//
//    return 0;
//}
//
