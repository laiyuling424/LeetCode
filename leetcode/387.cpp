//
// Created by 赖於领 on 2021/8/11.
//

#include <vector>
#include <list>
#include <iostream>

using namespace std;

//字符串中的第一个唯一字符

//新建 ascii 码容器， 向里面存字符的 ascii，重复的处理
//最后遍历容器 第一个就是不重复的
//容器：有顺序的 第二次存相同的会返回点不一样的东西 数组可以，set不知道

class Solution {
public:
    int firstUniqChar(string s) {
        pair<int, int> data[26];
        for (int i = 0; i < 26; i++) {
            data[i] = pair<int, int>(-1, 0);
        }
        for (int i = 0; i < s.size(); i++) {
            int index = s.at(i) - 'a';
            if (data[index].first == -1) {
                data[index] = pair<int, int>(i, 1);
            } else if (data[index].first < i) {
                data[index].second++;
            }
        }
        int first = INT_MAX;
        for (pair<int, int> item:data) {
            if (item.second != 1) {
                continue;
            }
            first = min(first, item.first);
        }
        if (first == INT_MAX) {
            return -1;
        }
        return first;
    }
};

//int main() {
//    Solution *solution = new Solution();
//    cout << solution->firstUniqChar("aabb") << endl;
//    return 0;
//}

