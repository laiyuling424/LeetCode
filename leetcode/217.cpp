//
// Created by 赖於领 on 2021/8/3.
//

#include <vector>
#include <set>

using namespace std;

//思路：放到同一个容器中，放相同的数值会那啥
//可以用 hash ，不能用数组 因为不知道上下限，刚开始是用数组来实现，半路发现上下限不知道


//还有就是可以排序来实现
class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        set<int> list;
        vector<int>::iterator iter = nums.begin();
        pair<set<int>::iterator, bool> a;
        while (iter != nums.end()) {
            if (!list.insert(*iter).second) {
                return true;
            }
            iter++;
        }
        return false;
    }
};