//
// Created by 赖於领 on 2021/9/6.
//

#include <string>
#include <vector>

using namespace std;


//解码方法


class Solution {
public:
    int numDecodings(string s) {

        int n = s.size();
        vector<int> data(n + 1, 0);
        data[0] = 1;
        for (int i = 1; i <= n; ++i) {
            //是一个字符      101   202    1103
            if ('0' != s.at(i - 1)) {
                data[i] += data[i - 1];
            }
            //是二个字符
            if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)) {
                data[i] += data[i - 2];
            }

        }

        return data[n];
    }
};

