//
// Created by 赖於领 on 2021/9/9.
//

#include <vector>
#include <iostream>

using namespace std;

//不同路径 II


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> road(m, vector<int>(n, 0));
        road[0][0] = 1;
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] == 1) {
                break;
            } else {
                road[i][0] = road[i - 1][0];
            }
        }
        for (int i = 1; i < n; ++i) {
            if (obstacleGrid[0][i] == 1) {
                break;
            } else {
                road[0][i] = road[0][i - 1];
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    road[i][j] = 0;
                } else {
                    road[i][j] = road[i][j - 1] + road[i - 1][j];
                }
            }
        }
        return road[m - 1][n - 1];
    }
};

//int main() {
//    Solution *solution = new Solution();
//    vector<vector<int>> aa = {
//            {0, 0, 0},
//            {0, 1, 0},
//            {0, 0, 0}
//    };
//    cout << solution->uniquePathsWithObstacles(aa) << endl;
//    return 0;
//}