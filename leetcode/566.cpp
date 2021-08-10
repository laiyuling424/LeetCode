//
// Created by 赖於领 on 2021/8/10.
//

#include <vector>
#include <iostream>

using namespace std;

//重塑矩阵
/**
 * 判断是不是符合规则
 * 一个一个赛进去
 *
 *
 * tip : vector 初始化 容量的问题
 */

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c) {
        if ((mat.size() * mat[0].size()) != (r * c)) {
            return mat;
        }
        vector<vector<int>> result(r, vector<int>(c));

        int out_index = 0, inner_index = 0;
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[i].size(); ++j) {
//                cout << "result[" << out_index << "][" << inner_index << "] = mat[" << i << "][" << j << "]   "
//                     << mat[i][j] << endl;
                result[out_index][inner_index] = mat[i][j];
                if ((++inner_index) == c) {
                    out_index++;
                    inner_index = 0;
                }
            }
        }

        return result;
    }
};

//int main() {
//    Solution *solution = new Solution();
//    vector<vector<int>> mat = {{1, 2},
//                               {3, 4}};
//    solution->matrixReshape(mat, 1, 4);
//    return 0;
//}
