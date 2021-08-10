//
// Created by 赖於领 on 2021/8/9.
//

#include <vector>
#include <iostream>


using namespace std;

//求二个数组的交集

//先排序，遍历长度较短的数组，同时比较长度较长的数组的值

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {

        cout << "intersect" << endl;

        if (nums1.empty() || nums2.empty()) {
            return {};
        }

        int nums1_size = nums1.size();
        int nums2_size = nums2.size();

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> result;
        int max_index = 0;
        int nums1_temp = 0, nums2_temp = 0;

        if (nums1_size > nums2_size) {
            for (int i = 0; i < nums2_size; ++i) {
                nums2_temp = nums2[i];
//                cout << max_index << endl;
                for (; max_index < nums1_size && (nums1_temp = nums1[max_index]) <= nums2_temp; ++max_index) {
                    if (nums1_temp == nums2_temp) {
                        result.push_back(nums1_temp);
                        max_index++;
                        cout << nums1_temp << endl;
                        break;
                    }
                }
            }
        } else {
            for (int i = 0; i < nums1_size; ++i) {
                nums1_temp = nums1[i];
                for (; max_index < nums2_size &&(nums2_temp = nums2[max_index]) <= nums1_temp; ++max_index) {
                    if (nums1_temp == nums2_temp) {
                        result.push_back(nums1_temp);
                        cout << nums1_temp << endl;
                        break;
                    }
                }
            }
        }

        return result;
    }
};


//int main() {
//
//    Solution *solution = new Solution();
//
//    vector<int> num1 = {1,2,1,2};
//    vector<int> num2 = {2,2};
//
//    solution->intersect(num1, num2);
//
//
//    return 0;
//};
