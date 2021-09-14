//
// Created by 赖於领 on 2021/9/7.
//


#include <vector>
#include <iostream>

using namespace std;

//下降路径最小和

//状态转移 f(i,j) = min( f(i-1,j-1) , f(i-1,j) , f(i-1,j+1) )
// j-1 j j+1 注意边间

class Solution {
public:
    int minFallingPathSum(vector<vector<int>> &matrix) {

        vector<vector<int>> road(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix[0].size(); ++i) {
            road[0][i] = matrix[0][i];
        }

        for (int i = 1; i < matrix.size(); ++i) {

            for (int j = 0; j < matrix[0].size(); ++j) {
                if (j == 0) {
                    road[i][j] = min(road[i - 1][j], road[i - 1][j + 1]) + matrix[i][j];
                } else if (j == matrix[0].size() - 1) {
                    road[i][j] = min(road[i - 1][j], road[i - 1][j - 1]) + matrix[i ][j];
                } else {
                    road[i][j] = min(road[i - 1][j], min(road[i - 1][j - 1], road[i - 1][j + 1])) + matrix[i][j];
                }
                cout << "road[" << i << "][" << j << "] = " << road[i][j] << endl;
            }
        }
        int m = INT_MAX;
        for (int i = 0; i < matrix[0].size(); ++i) {
            m = min(m, road[matrix.size() - 1][i]);
        }
        return m;
    }
};

//int main() {
//    Solution *solution = new Solution();
//    vector<vector<int>> a = {{2, 1, 3},
//                             {6, 5, 4},
//                             {7, 8, 9}};
//    solution->minFallingPathSum(a);
//    return 0;
//}