//
// Created by 赖於领 on 2021/9/7.
//

#include <vector>
#include <iostream>

using namespace std;



//杨辉三角 II


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> result(rowIndex + 1);
        result[0] = {1};
        if (rowIndex == 0){
            return result[0];
        }
        result[1] = {1,1};
        if (rowIndex == 1){
            return result[1];
        }
        for (int i = 2; i <= rowIndex; ++i) {
            result[i].push_back(1);
            for (int j = 0; j < (result[i - 1].size() - 1); ++j) {
                result[i].push_back(result[i - 1][j] + result[i - 1][j + 1]);
            }
            result[i].push_back(1);
        }
        return result[rowIndex];
    }
};

