//
// Created by 赖於领 on 2021/9/1.
//


#include <vector>
#include <iostream>

using namespace std;

//最佳观光组合


class Solution {
public:
    int maxScoreSightseeingPair(vector<int> &values) {
//        if (values.size() == 2) {
//            return values[0] + values[1] - 1;
//        }
        //values[i]+values[j]+i-j =
        int n = values.size();
        vector<int> r(n, 0);
        vector<int> sums(n, 0);
        r[0] = values[0];
        sums[0] = INT_MIN;


        for (int i = 1; i < n; i++) {
            r[i] = max(r[i - 1], values[i - 1]) - 1;
            sums[i] = max(sums[i - 1], r[i] + values[i]);
            cout << "i is " << i << "   " << r[i] << "   " << sums[i] << endl;
        }

        return sums[n - 1];
    }
};

//int main() {
//
//    Solution *solution = new Solution();
////    vector<int> a = {8, 1, 5, 2, 6};
//    vector<int> a = {1, 2};
////    vector<int> a = {1, 3, 5};
//    cout << solution->maxScoreSightseeingPair(a) << endl;
//
//    return 0;
//}