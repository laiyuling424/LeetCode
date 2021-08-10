//
// Created by 赖於领 on 2021/8/5.
//


#include <vector>
#include <iostream>

//做过有印象 是吧一个数组数据放在最后在比较排序

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {

        if (n == 0) {
            return;
        }

        if (m == 0) {
            nums1 = nums2;
            return;
        }

        for (int i = m - 1, j = m + n - 1; i >= 0; i--, j--) {
            nums1[j] = nums1[i];
        }


        int indexNums1 = 0, indexNums2 = 0, index = 0;
        while (indexNums1 < m && indexNums2 < n) {

            if (nums1[n + indexNums1] > nums2[indexNums2]) {
                nums1[index] = nums2[indexNums2];
                indexNums2++;
            } else {
                nums1[index] = nums1[n + indexNums1];
                indexNums1++;
            }
            index++;
        }

        while (indexNums1 < m) {
            nums1[index] = nums1[indexNums1 + n];
            indexNums1++;
            index++;
        }

        while (indexNums2 < n) {
            nums1[index] = nums2[indexNums2];
            indexNums2++;
            index++;
        }

    }
};
//
//int main() {
//
//    Solution *solution = new Solution();
//
//    vector<int> num1 = {1,2,4,5,6,0};
//    vector<int> num2 = {3};
//
//    solution->merge(num1, 5, num2, 1);
//
//    return 0;
//};
