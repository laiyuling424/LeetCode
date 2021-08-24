//
// Created by 赖於领 on 2021/8/12.
//

#include <vector>
#include <iostream>

using namespace std;


//赎金信

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        int m_array[26] = {0};

        for (char i : magazine) {
            m_array[(i - 'a')]++;
        }

        for (char i : ransomNote) {
            m_array[(i - 'a')]--;
            if ((m_array[(i - 'a')]) < 0) {
                return false;
            }
        }
        return true;
    }
};

//int main() {
//    Solution *solution = new Solution();
//    cout << solution->canConstruct("aa", "ab") << endl;
//    return 0;
//}