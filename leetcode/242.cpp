//
// Created by 赖於领 on 2021/8/13.
//


#include <iostream>
#include <stdio.h>

using namespace std;


//有效的字母异位词

class Solution {
public:
    bool isAnagram(string s, string t) {

        int s_array[26] = {0};
        int t_array[26] = {0};

        for (char i : s) {
            s_array[(i - 'a')]++;
        }
        for (char i : t) {
            t_array[(i - 'a')]++;
        }

        for (int i = 0; i < 26; ++i) {
            if (s_array[i] != t_array[i]) {
                return false;
            }
        }


        return true;
    }
};

//
//int main() {
//    Solution *solution = new Solution();
//    cout << solution->isAnagram("zlap", "kcqx") << endl;
//    return 0;
//}
