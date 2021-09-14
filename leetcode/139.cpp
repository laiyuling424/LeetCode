//
// Created by 赖於领 on 2021/9/3.
//

#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;




//单词拆分


class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        auto wordDictSet = unordered_set<string>();
        for (auto word: wordDict) {
            wordDictSet.insert(word);
        }

        auto dp = vector<bool>(s.size() + 1);
        dp[0] = true;
        //s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
        for (int i = 1; i <= s.size(); ++i) {
            cout << " i is " << i << endl;
            for (int j = 0; j < i; ++j) {
                cout << " j is " << j << ",dp[j] is " << dp[j] << ",s.substr(j, i - j) is " << s.substr(j, i - j)
                     << endl;
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    cout << " dp[" << i << "] is " << dp[i] << endl;
                    break;
                }
            }
            cout << endl;
            cout << endl;
        }

        return dp[s.size()];
    }
};


class Solution2 {
public:
    bool wordBreak(string s, vector<string> &wordDict) {

        int n = s.size();
        vector<bool> result(n + 1, false);
        result[0] = true;
        auto wordDictSet = unordered_set<string>();
        for (auto word: wordDict) {
            wordDictSet.insert(word);
        }

        for (int i = 1; i < n + 1; ++i) {

            for (int j = 0; j < i; ++j) {
                if (result[j] && (wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end())) {
                    result[i] = true;
                    break;
                }
            }
        }

        return result[n];
    }
};

//int main() {
////s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
//
//    Solution *solution = new Solution();
//    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
//    solution->wordBreak("catsandog", wordDict);
//
//    return 0;
//}
