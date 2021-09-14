//
// Created by 赖於领 on 2021/9/10.
//

#include <vector>
#include <iostream>


using namespace std;

//最小路径和


class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> road(m, vector<int>(n, 0));
        road[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            road[i][0] = road[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < n; ++i) {
            road[0][i] = road[0][i - 1] + grid[0][i];
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                road[i][j] = min(road[i - 1][j], road[i][j - 1]) + grid[i][j];
            }
        }
        return road[m - 1][n - 1];
    }
};

//int main() {
//    Solution *solution = new Solution();
//    vector<vector<int>> aa = {{1, 2, 3},
//                              {4, 5, 6}};
//    cout << solution->minPathSum(aa) << endl;
//    return 0;
//}