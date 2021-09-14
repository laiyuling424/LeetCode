//
// Created by 赖於领 on 2021/9/10.
//


#include <vector>
#include <iostream>


using namespace std;

//最大正方形


class Solution {

public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();


        vector<vector<pair<int, int>>> road(m, vector<pair<int, int>>(n, pair<int, int>(0, 0)));
        int a;
        int max_rect = 0;
        if (matrix[0][0] == '1') {
            a = 1;
            max_rect = 1;
        } else {
            a = 0;
        }
        road[0][0] = pair<int, int>(a, a);

        for (int i = 1; i < m; ++i) {
            if (matrix[i][0] == '0') {
                road[i][0] = pair<int, int>(0, 0);
            } else {
                road[i][0] = pair<int, int>(road[i - 1][0].first + 1, 1);
                max_rect = 1;
            }
        }
        for (int i = 1; i < n; ++i) {
            if (matrix[0][i] == '0') {
                road[0][i] = pair<int, int>(0, 0);
            } else {
                road[0][i] = pair<int, int>(1, road[0][i - 1].second + 1);
                max_rect = 1;
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == '0') {
                    road[i][j] = pair<int, int>(0, 0);
                } else {
                    int x = min(road[i - 1][j].first, road[i - 1][j].second);
                    int y = min(road[i][j - 1].first, road[i][j - 1].second);
                    int z = min(road[i - 1][j - 1].first, road[i - 1][j - 1].second);
                    int m = min(z, min(x, y)) + 1;
                    max_rect = max(max_rect, m);
                    road[i][j] = pair<int, int>(m, m);
                }
            }
        }
        return max_rect * max_rect;
    }
};

//int main() {
//    Solution *solution = new Solution();
////    vector<vector<char>> bb = {{'1', '0', '1', '0', '0'},
////                               {'1', '0', '1', '1', '1'},
////                               {'1', '1', '1', '1', '1'},
////                               {'1', '0', '0', '1', '0'}};
////    vector<vector<char>> bb = {{'0'}};
////    vector<vector<char>> bb = {{'0', '1'},
////                               {'1', '0'}};
//    vector<vector<char>> bb = {{'1', '0', '1', '0'},
//                               {'1', '0', '1', '1'},
//                               {'1', '0', '1', '1'},
//                               {'1', '1', '1', '1'}};
//    cout << solution->maximalSquare(bb) << endl;
//
//
//    return 0;
//}