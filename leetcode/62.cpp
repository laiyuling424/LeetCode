//
// Created by 赖於领 on 2021/9/9.
//



//不同路径

class Solution {
public:
    int uniquePaths(int m, int n) {
        int road[m][n];
        for (int i = 0; i < m; ++i) {
            road[i][0] = 1;
        }
        for (int i = 0; i < n; ++i) {
            road[0][i] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                road[i][j] = road[i][j - 1] + road[i - 1][j];
            }
        }
        return road[m-1][n-1];
    }
};

