//
// Created by 赖於领 on 2021/8/5.
//

#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//先排序 遍历，从遍历的值与 target 相比 再从列表查找

//class Solution {
//public:
//    vector<int> twoSum(vector<int> &nums, int target) {
//
//        vector<int> _vector;
////        sort(nums.begin(), nums.end());
//
//        vector<int>::iterator iter = nums.begin();
//
//        int value;
//        vector<int>::iterator firstIter;
////        while (iter != nums.end()) {
////            value = target - *iter;
////            firstIter = find(iter, nums.end(), value);
////            if (firstIter != nums.end()) {
////                return {*firstIter, *iter};
////            }
////        }
//        for (int i = 0; i < nums.size(); ++i) {
//            firstIter = find(iter, nums.end(), target - nums[i]);
//            if (firstIter != nums.end()) {
//                return {firstIter.s,i};
//            }
//        }
//        return {};
//    }
//};


//hash

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};

