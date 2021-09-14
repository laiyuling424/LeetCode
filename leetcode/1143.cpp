//
// Created by 赖於领 on 2021/9/14.
//


#include <string>
#include <iostream>
#include <vector>

using namespace std;


//最长公共子序列


/**
 * 状态转移 二个字符串  i j 分别表示第几个
 * f[i][j] 表示第 i 个和第 j 个前面有几个是相同的
 * 第 i 个和第 j 个相等 ，比较 i+1 和 j+1
 * 第 i 个和第 j 个不相等 ，比较 i 和 j+1 或比较 i+1 和 j
 */

class Solution {
public:

    int longestCommonSubsequence(string a, string b) {
        int n = a.size();
        int m = b.size();
        vector<vector<int>> maxlcs(n, vector<int>(m, 0));
        for (int j = 0; j < m; ++j) {//初始化第0行：a[0..0]与b[0..j]的maxlcs
            if (a[0] == b[j]) maxlcs[0][j] = 1;
            else if (j != 0) maxlcs[0][j] = maxlcs[0][j - 1];
            else maxlcs[0][j] = 0;
        }
        for (int i = 0; i < n; ++i) {//初始化第0列：a[0..i]与b[0..0]的maxlcs
            if (a[i] == b[0]) maxlcs[i][0] = 1;
            else if (i != 0) maxlcs[i][0] = maxlcs[i - 1][0];
            else maxlcs[i][0] = 0;
        }
        for (int i = 1; i < n; ++i) { // 填表
            for (int j = 1; j < m; ++j) {
                if (a[i] == b[j])
                    maxlcs[i][j] = max(max(maxlcs[i - 1][j], maxlcs[i][j - 1]), maxlcs[i - 1][j - 1] + 1);
                else
                    maxlcs[i][j] = max(maxlcs[i - 1][j], maxlcs[i][j - 1]);
            }
        }
        return maxlcs[n - 1][m - 1];
    }
};

