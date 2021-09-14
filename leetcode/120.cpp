//
// Created by 赖於领 on 2021/9/7.
//


#include <vector>
#include <iostream>

using namespace std;


//三角形最小路径和


//状态转移 f(i,j) = min( f(i-1,j-1) , f(i-1,j) )
// j-1 j 注意边间

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {

        vector<int> min_road(triangle[triangle.size() - 1].size(), 0);

        min_road[0] = triangle[0][0];

        for (int i = 1; i < triangle.size(); ++i) {
            for (int j = triangle[i].size() - 1; j >= 0; --j) {
                if (j == 0) {
                    min_road[j] = triangle[i][0] + min_road[0];
                } else if (j == (triangle[i].size() - 1)) {
                    min_road[j] = triangle[i][j] + min_road[j - 1];
                } else {
                    min_road[j] = min(min_road[j], min_road[j - 1]) + triangle[i][j];
                }
                cout << "min_road[" << j << "] = " << min_road[j] << endl;
            }
            cout << "-----" << endl;
        }
        int m = INT_MAX;
        for (int i = 0; i < min_road.size(); ++i) {
            m = min(m, min_road[i]);
        }
        return m;
    }
};


//int main() {
//    Solution *solution = new Solution();
//    vector<vector<int>> a = {{2},
//                             {3, 4},
//                             {6, 5, 7},
//                             {4, 1, 8, 3}};
//    solution->minimumTotal(a);
//    return 0;
//}