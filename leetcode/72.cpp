//
// Created by 赖於领 on 2021/9/14.
//

#include <string>
#include <iostream>
#include <vector>

using namespace std;

//编辑距离


class Solution {
public:
    int minDistance(string a, string b) {
        int n = a.size();
        int m = b.size();
        if (m == 0){
            return n;
        }
        if (n == 0){
            return m;
        }
        vector<vector<int>> minDist(n, vector<int>(m, 0));
        for (int j = 0; j < m; ++j) { // 初始化第0行:a[0..0]与b[0..j]的编辑距离
            if (a[0] == b[j]) minDist[0][j] = j;
            else if (j != 0) minDist[0][j] = minDist[0][j - 1] + 1;
            else minDist[0][j] = 1;
        }
        for (int i = 0; i < n; ++i) { // 初始化第0列:a[0..i]与b[0..0]的编辑距离
            if (a[i] == b[0]) minDist[i][0] = i;
            else if (i != 0) minDist[i][0] = minDist[i - 1][0] + 1;
            else minDist[i][0] = 1;
        }
        for (int i = 1; i < n; ++i) { // 按行填表
            for (int j = 1; j < m; ++j) {
                if (a[i] == b[j])
                    minDist[i][j] = min(min(minDist[i - 1][j] + 1, minDist[i][j - 1] + 1), minDist[i - 1][j - 1]);
                else
                    minDist[i][j] = min(min(minDist[i - 1][j] + 1, minDist[i][j - 1] + 1), minDist[i - 1][j - 1] + 1);
            }
        }
        return minDist[n - 1][m - 1];
    }
};