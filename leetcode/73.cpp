//
// Created by 赖於领 on 2021/8/11.
//

#include <vector>
#include <iostream>

using namespace std;

//矩阵置零



class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        vector<int> x_vector;
        vector<int> y_vector;

        //有问题 会污染数据 应该先标记再整理
//        for (int i = 0; i < matrix.size(); ++i) {
//            for (int j = 0; j < matrix[i].size(); ++j) {
//                if (matrix[i][j] == 0) {
//                    int origin_x = i, origin_y = j;
//                    do {
//                        origin_x--;
//                        matrix[origin_x][origin_y] = 0;
//                    } while (0 <= origin_x);
//                    origin_x = i;
//                    do {
//                        origin_x++;
//                        matrix[origin_x][origin_y] = 0;
//                    } while (origin_x < matrix[origin_x].size());
//                    origin_x = i;
//                    do {
//                        origin_y--;
//                        matrix[origin_x][origin_y] = 0;
//                    } while (0 <= origin_y);
//                    origin_y = j;
//                    do {
//                        origin_y++;
//                        matrix[origin_x][origin_y] = 0;
//                    } while (origin_y < matrix[origin_x].size());
//                    break;
//                }
//
//            }
//        }

        vector<vector<bool>> tip_vector(matrix.size(), vector<bool>(matrix[0].size(), false));

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    tip_vector[i][j] = true;
                }
            }
        }

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (tip_vector[i][j]) {
                    int origin_x = i, origin_y = j;
                    do {
                        origin_x--;
                        matrix[origin_x][origin_y] = 0;
                    } while (0 <= origin_x);
                    origin_x = i;
                    do {
                        origin_x++;
                        matrix[origin_x][origin_y] = 0;
                    } while (origin_x < matrix[origin_x].size());
                    origin_x = i;
                    do {
                        origin_y--;
                        matrix[origin_x][origin_y] = 0;
                    } while (0 <= origin_y);
                    origin_y = j;
                    do {
                        origin_y++;
                        matrix[origin_x][origin_y] = 0;
                    } while (origin_y < matrix[origin_x].size());
                    break;
                }

            }
        }


    }
};

