//
// Created by 赖於领 on 2021/9/13.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//最长回文子串

//f[i,j]
// f[i] == f[j]  f[i+1,j-1]
// f[i] != f[j]  f[i+1,j] f[i,j-1]

class Solution {
public:
    string longestPalindrome(string s) {
        int l = 0, r = 0;
        int n = s.size();
        vector<vector<bool>> data(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            data[i][i] = true;
        }
        //先二个在三个这样 不然会有问题
        for (int L = 2; L <= n; L++) {
            for (int i = 0; i < n; i++) {
                int j = L + i - 1;
                if (j >= n) {
                    break;
                }
                if (s[i] == s[j] && (j - i) < 3) {
                    data[i][j] = true;
                    if ((j - i) > (r - l)) {
                        r = j;
                        l = i;
                    }
                    cout << "1data[" << i << "][" << j << "] = " << data[i][j] << endl;
                } else if (s[i] == s[j] && data[i + 1][j - 1]) {
                    data[i][j] = true;
                    if ((j - i) > (r - l)) {
                        r = j;
                        l = i;
                    }
                    cout << "2data[" << i << "][" << j << "] = " << data[i][j] << endl;
                } else {
                    data[i][j] = false;
                }
            }
        }
        if (r == l) {
            return s.substr(0, 1);
        }
        cout << l << " " << r << endl;
        return s.substr(l, r - l + 1);
    }
};

//class Solution {
//public:
//    string longestPalindrome(string s) {
//        int n = s.size();
//        if (n < 2) {
//            return s;
//        }
//
//        int maxLen = 1;
//        int begin = 0;
//        // dp[i][j] 表示 s[i..j] 是否是回文串
//        vector<vector<int>> dp(n, vector<int>(n));
//        // 初始化：所有长度为 1 的子串都是回文串
//        for (int i = 0; i < n; i++) {
//            dp[i][i] = true;
//        }
//        // 递推开始
//        // 先枚举子串长度
//        for (int L = 2; L <= n; L++) {
//            // 枚举左边界，左边界的上限设置可以宽松一些
//            for (int i = 0; i < n; i++) {
//                // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
//                int j = L + i - 1;
//                // 如果右边界越界，就可以退出当前循环
//                if (j >= n) {
//                    break;
//                }
//
//                if (s[i] != s[j]) {
//                    dp[i][j] = false;
//                } else {
//                    if (j - i < 3) {
//                        dp[i][j] = true;
//                    } else {
//                        dp[i][j] = dp[i + 1][j - 1];
//                    }
//                }
//
//                // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
//                if (dp[i][j] && j - i + 1 > maxLen) {
//                    maxLen = j - i + 1;
//                    begin = i;
//                }
//            }
//        }
//        return s.substr(begin, maxLen);
//    }
//};


//int main() {
//    Solution *solution = new Solution();
////    cout << solution->longestPalindrome("cbbd") << endl;
////    cout << solution->longestPalindrome("babad") << endl;
////    cout << solution->longestPalindrome("abababababa") << endl;
//    cout << solution->longestPalindrome("aacabdkacaa") << endl;
//    return 0;
//}

