//
// Created by 赖於领 on 2021/8/10.
//

#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:

    void print(vector<vector<int>> &num) {
        cout << "{";
        for (int i = 0; i < num.size(); ++i) {
            cout << "{";
            for (int j = 0; j < num[i].size(); ++j) {
                cout << num[i][j] << ",";
            }
            cout << "}";
        }
        cout << "}" << endl;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        result[0] = {1};
        if (numRows == 1) {
            return result;
        }
        result[1] = {1, 1};
        if (numRows == 2) {
            return result;
        }
        for (int i = 3; i <= numRows; ++i) {
            result[i - 1].push_back(1);
            for (int j = 0; j < (result[i - 2].size() - 1); ++j) {
                result[i - 1].push_back(result[i - 2][j] + result[i - 2][j + 1]);
            }
            result[i - 1].push_back(1);
        }
        return result;
    }
};

//int main() {
//    Solution *solution = new Solution();
//    solution->generate(5);
//    return 0;
//}

