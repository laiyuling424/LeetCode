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
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int inf = 1e9;
//        int minprice = inf, maxprofit = 0;
//        for (int price: prices) {
//            maxprofit = max(maxprofit, price - minprice);
//            minprice = min(price, minprice);
//        }
//        cout << maxprofit << endl;
//        return maxprofit;
//    }
//};

//int main() {
//
//    Solution *solution = new Solution();
//    vector<int> vec = {2, 5, 1, 3};
//
//    solution->maxProfit(vec);
//
//    return 0;
//}
//
