//
// Created by 赖於领 on 2021/9/14.
//

#include <string>

using namespace std;


//判断子序列


/**
 * 这个是贪心 不是动态规划
 * 想想动态规划怎么做
 */


class Solution {
public:
    bool isSubsequence(string s, string t) {

        int index = 0;
        int maxlen = s.size();
        if (maxlen == 0) {
            return true;
        }
        int n = t.size();

        for (int i = 0; i < n; ++i) {
            if (s.at(index) == t.at(i)) {
                index++;
                if (maxlen == index) {
                    return true;
                }
            }
        }
        return false;
    }
};

